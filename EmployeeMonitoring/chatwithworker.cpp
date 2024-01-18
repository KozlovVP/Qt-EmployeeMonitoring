#include "chatwithworker.h"
#include "ui_chatwithworker.h"

ChatWithWorker::ChatWithWorker(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::ChatWithWorker)
    , chosenWorker(qobject_cast<ChosenWorker*>(parent))
{
    ui->setupUi(this);
    ui->textBrowser->setText("No messages yet");
    ui->textEdit->setPlaceholderText("Type here..");
}

ChatWithWorker::~ChatWithWorker()
{
    delete ui;
    chosenWorker->chat_ = nullptr;
}

void ChatWithWorker::on_pushButton_clicked()
{
    QString text = "Y: " + ui->textEdit->toPlainText();
    ui->textBrowser->append(text);
    chosenWorker->mainWindow->SendToClient("9", ui->textEdit->toPlainText());
    ui->textEdit->clear();
    ui->textEdit->setPlaceholderText("Type here..");

    qDebug() << "sending message";
}

void ChatWithWorker::closeEvent(QCloseEvent *event) {
    chosenWorker->mainWindow->SendToClient("11", "chat disconnected");
    event->accept();
}

void ChatWithWorker::keyPressEvent(QKeyEvent *event) {
    if (event->key() == Qt::Key_Escape) {
        chosenWorker->mainWindow->SendToClient("11", "chat disconnected");
        event->accept();
        close();
    }
}
