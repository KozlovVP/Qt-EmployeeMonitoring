#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "taskwindow.h"
#include "ui_taskwindow.h"
#include "chatwithboss.h"
#include "ui_chatwithboss.h"

#include <QGuiApplication>
#include <QScreen>
#include <QPixmap>
#include <QBuffer>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->label_2->setVisible(false);
    socket = new QTcpSocket(this);
    connect(socket, &QTcpSocket::readyRead, this, &MainWindow::slotReadyRead);
    connect(socket, &QTcpSocket::disconnected, socket, &QTcpSocket::deleteLater);
    connect(socket, &QTcpSocket::connected, this, &MainWindow::handleConnected);
    connect(socket, SIGNAL(stateChanged(QAbstractSocket::SocketState)), this, SLOT(onSocketStateChanged(QAbstractSocket::SocketState)));
}

void MainWindow::SendToServer(QString command, QString str)
{
    QByteArray arrBlock;
    QDataStream out(&arrBlock, QIODevice::WriteOnly);
    out.setVersion(QDataStream::Qt_6_2);
    out << quint32(0) << command << str;

    out.device()->seek(0);
    out << quint32(arrBlock.size() - sizeof(quint32));
    socket->write(arrBlock);
}

void MainWindow::SendToServer(QString command, QByteArray data) {
    QByteArray arrBlock;
    QDataStream out(&arrBlock, QIODevice::WriteOnly);
    out.setVersion(QDataStream::Qt_6_2);
    out << quint32(0) << command << data;

    out.device()->seek(0);
    out << quint32(arrBlock.size() - sizeof(quint32));
    socket->write(arrBlock);
    socket->waitForBytesWritten();
}

void MainWindow::slotReadyRead()
{
    QDataStream in(socket);
    in.setVersion(QDataStream::Qt_6_2);

    if (in.status() == QDataStream::Ok) {
        QString command, str;

        for (;;) {
            if (!m_nNextВlockSize) {
                if (socket->bytesAvailable() < sizeof(quint32)) {
                    break;
                }
            in >> m_nNextВlockSize;
            }
            if (socket->bytesAvailable() < m_nNextВlockSize) {
                break;
            }
            in >> command >> str;
            m_nNextВlockSize = 0;
        }

        qDebug() << command << str;

        if (command == "1") {
            QScreen *screen = QGuiApplication::primaryScreen();
            QPixmap ScreenImage = screen->grabWindow(0);

            Data.clear();
            QBuffer buffer(&Data);
            buffer.open(QIODevice::WriteOnly);
            ScreenImage.save(&buffer, "PNG");

            qDebug() << "sending screenshot of size" << Data.size();
            SendToServer("5", Data);
        }
        else if (command == "3") {
            qDebug() << "task section changed";
            taskWindow->ui->textBrowser->clear();
            taskWindow->ui->textBrowser->setText(str);
        }
        else if (command == "7") {
            qDebug() << "starting chat";
            ChatWithBoss* chat = new ChatWithBoss(taskWindow);
            chat->ui->label->setText("Boss started chat");
            taskWindow->chat_ = chat;
            chat->setModal(true);
            chat->show();
        }
        else if (command == "9"){
            qDebug() << "new message from boss";
            QString text = "B: " + str;
            taskWindow->chat_->ui->textBrowser->append(text);
        }
        else if (command == "11") {
            qDebug() << "boss ended chat";
            taskWindow->chat_->ui->pushButton->hide();
            taskWindow->chat_->ui->label->setText("Boss has disconected");
            taskWindow->chat_->ui->textEdit->hide();
        }
        else if (command == "15") {
            boss_is_busy = 1;
        }
    }
}

void MainWindow::handleConnected() {
    ui->label_2->setVisible(false);
    SendToServer("1", ui->lineEdit->text());

    TaskWindow task_window(this);
    taskWindow = &task_window;
    task_window.setModal(true);
    task_window.exec();
}

void MainWindow::on_pushButton_2_clicked()
{
    socket->connectToHost("127.0.0.1", 2323);
    ui->label_2->setVisible(true);
    ui->label_2->setText("Server is not started");
}


void MainWindow::on_lineEdit_returnPressed()
{
    emit on_pushButton_2_clicked();
}

void MainWindow::onSocketStateChanged(QAbstractSocket::SocketState socketState) {
    if (socketState == QAbstractSocket::UnconnectedState)
    {
        if (taskWindow == nullptr) {
            QMessageBox::information(this, "Information", "Server disconnected\nTry later please");
        }
        else {
            if (taskWindow->chat_ == nullptr) {
                QMessageBox::information(taskWindow, "Information", "Server disconnected\nTry later please");
                taskWindow->ui->pushButton->setVisible(false);
            }
            else {
                QMessageBox::information(taskWindow->chat_, "Information", "Server disconnected\nTry later please");
                taskWindow->chat_->ui->pushButton->setVisible(false);
                taskWindow->ui->pushButton->setVisible(false);
            }
        }
    }
}


MainWindow::~MainWindow()
{
    qDebug() << "destructor called";
    delete ui;
}
