#include "mainwindow.h"
#include "ui_chosenworker.h"
#include "ui_mainwindow.h"
#include "chosenworker.h"
#include "chatwithworker.h"
#include "ui_chatwithworker.h"

#include <QDebug>
#include <QHostAddress>
#include <QAbstractSocket>
#include <QPixmap>
#include <QBuffer>
#include <QScreen>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    server_(this)
{
    ui->setupUi(this);
    ui->textBrowser->setText("No workers yet");
    server_.listen(QHostAddress::Any, 2323);
    connect(&server_, SIGNAL(newConnection()), this, SLOT(onNewConnection()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::onNewConnection()
{
    QTcpSocket *clientSocket = server_.nextPendingConnection();
    connect(clientSocket, SIGNAL(readyRead()), this, SLOT(onReadyRead()));
    connect(clientSocket, SIGNAL(stateChanged(QAbstractSocket::SocketState)), this, SLOT(onSocketStateChanged(QAbstractSocket::SocketState)));

    sockets_.push_back(clientSocket);
    qDebug() << clientSocket << "connected";
}

void MainWindow::onSocketStateChanged(QAbstractSocket::SocketState socketState)
{
    if (socketState == QAbstractSocket::UnconnectedState)
    {
        QTcpSocket* pClientSocket = static_cast<QTcpSocket*>(QObject::sender());

        QString temp_name;
        for (QString name : worker_sockets_.keys()) {
            if (worker_sockets_.value(name)->worker_socket_ == pClientSocket) {
                temp_name = name;
                break;
            }
        }
        worker_sockets_.remove(temp_name);
        names_.removeOne(temp_name);
        sockets_.removeOne(pClientSocket);
        if (cur_worker_socket == pClientSocket) {
            cur_worker_socket = nullptr;
        }

        ui->textBrowser->clear();
        QString text;
        for (int i = 0; i < names_.size(); i++) {
            QString num = QString::number(i+1);
            text+=num + " - " + names_[i] + "\n";
        }
        ui->textBrowser->setText(text);
    }
}

void MainWindow::onReadyRead()
{
    QTcpSocket* pClientSocket = (QTcpSocket*)sender();
    QDataStream in(pClientSocket);
    in.setVersion(QDataStream::Qt_6_2);

    QString command, str;
    QByteArray array;
    for (;;) {
        if (!m_nNextВlockSize) {
            if (pClientSocket->bytesAvailable() < sizeof(quint32)) {
                break;
            }
            in >> m_nNextВlockSize;
        }
        if (pClientSocket->bytesAvailable() < m_nNextВlockSize) {
            break;
        }
        in >> command;
        if (command == "5") {
            in >> array;
        }
        else {
            in >> str;
        }
        m_nNextВlockSize = 0;
    }

    if (command == "1") {
        qDebug() << "worker with name" << str << "connected";
        MyWorker* worker = new MyWorker(pClientSocket);
        names_.append(str);
        worker_sockets_[str] = worker;

        ui->textBrowser->clear();
        QString text;
        for (int i = 0; i < names_.size(); i++) {
            QString num = QString::number(i+1);
            text+=num + " - " + names_[i] + "\n";
        }
        ui->textBrowser->setText(text);
    }
    else if (command == "5") {
        QImage receivedImage;
        receivedImage.loadFromData(array);
        QPixmap pixmap = QPixmap::fromImage(receivedImage);
        int w = chosen_->ui->label->width();
        int h = chosen_->ui->label->height();

        chosen_->ui->label->setVisible(true);
        chosen_->ui->label->setPixmap(pixmap.scaled(w, h, Qt::KeepAspectRatio, Qt::SmoothTransformation));
        qDebug() << "got screenshot from " << pClientSocket;
    }
    else if (command == "7") {
        if (chosen_ == nullptr) {
            int temp_pos = 0, pos;
            for (QString name : worker_sockets_.keys()) {
                temp_pos+=1;
                if (worker_sockets_.value(name)->worker_socket_ == pClientSocket) {
                    pos = temp_pos;
                    break;
                }
            }
            cur_worker_num =  pos - 1;
            cur_worker_socket = sockets_[cur_worker_num];

            ChosenWorker* chosen_worker = new ChosenWorker(this);
            chosen_ = chosen_worker;
            chosen_worker->setModal(true);
            chosen_worker->show();
        }
        else {
            if (chosen_->chat_ != nullptr) {
                SendToClient("15", "I am busy");
                return;
            }
        }

        ChatWithWorker* chat = new ChatWithWorker(chosen_);
        chosen_->chat_ = chat;
        QString name = names_[cur_worker_num];
        QString text = name + " started chat";
        chat->ui->label->setText(text);
        chat->setModal(true);
        chat->open();

        qDebug() << pClientSocket << "started chat";
    }
    else if (command == "9") {
        QString text = "W: " + str;
        chosen_->chat_->ui->textBrowser->append(text);

        qDebug() << "got message from" << pClientSocket;
    }
    else if (command == "11") {
        chosen_->chat_->ui->pushButton->hide();
        QString name = names_[cur_worker_num];
        chosen_->chat_->ui->label->setText(name + " has disconnected");
        chosen_->chat_->ui->textEdit->hide();

        qDebug() << pClientSocket << "ended chat";
    }
}

void MainWindow::SendToClient(QString command, QString str)
{
    QByteArray arrBlock;
    QDataStream out(&arrBlock, QIODevice::WriteOnly);
    out.setVersion(QDataStream::Qt_6_2);
    out << quint32(0) << command << str;

    out.device()->seek(0);
    out << quint32(arrBlock.size() - sizeof(quint32));
    sockets_[cur_worker_num]->write(arrBlock);
}

bool MainWindow::CheckWorkerNum(int num) {
    return num > names_.size() || num < names_.size();
}

void MainWindow::on_pushButton_clicked()
{
    if (names_.size() == 0) {
        QMessageBox::warning(this, "Warning", "No workers yet");
        return;
    }
    int chosen_num = ui->lineEdit->text().toInt();

    if (CheckWorkerNum(chosen_num)) {
        QMessageBox::warning(this, "Warning", "No such worker");
        return;
    }

    cur_worker_num =  chosen_num - 1;
    cur_worker_socket = sockets_[cur_worker_num];

    ChosenWorker chosen_worker(this);
    chosen_ = &chosen_worker;
    chosen_worker.setModal(true);
    chosen_worker.exec();
}

void MainWindow::on_lineEdit_returnPressed() {
    emit on_pushButton_clicked();
}
