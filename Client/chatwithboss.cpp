#include "chatwithboss.h"
#include "ui_chatwithboss.h"

ChatWithBoss::ChatWithBoss(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::ChatWithBoss)
    , taskWindow(qobject_cast<TaskWindow*>(parent))
{
    ui->setupUi(this);
    ui->textEdit->setPlaceholderText("Type here..");
    ui->textBrowser->setText("No messages yet");
}

ChatWithBoss::~ChatWithBoss()
{
    delete ui;
    taskWindow->chat_ = nullptr;
}

void ChatWithBoss::on_pushButton_clicked()
{
    QString text = "Y: " + ui->textEdit->toPlainText();
    ui->textBrowser->append(text);
    qDebug() << "sending message to boss";
    taskWindow->mainWindow->SendToServer("9", ui->textEdit->toPlainText());
    ui->textEdit->clear();
    ui->textEdit->setPlaceholderText("Type here..");
}

void ChatWithBoss::closeEvent(QCloseEvent *event) {
    taskWindow->mainWindow->SendToServer("11", QString("chat disconnected"));
    event->accept();
}

void ChatWithBoss::keyPressEvent(QKeyEvent *event) {
    if (event->key() == Qt::Key_Escape) {
        taskWindow->mainWindow->SendToServer("11", QString("chat disconnected"));
        event->accept();
        close();
    }
}

void ChatWithBoss::on_pushButton_2_clicked()
{
    close();
}

