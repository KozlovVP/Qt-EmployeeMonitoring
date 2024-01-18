#include "taskwindow.h"
#include "ui_taskwindow.h"
#include "chatwithboss.h"
#include "ui_chatwithboss.h"

TaskWindow::TaskWindow(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::TaskWindow)
    , mainWindow(qobject_cast<MainWindow*>(parent))
{
    setWindowTitle("Coffee");

    ui->setupUi(this);
    ui->textBrowser->setText("No tasks yet");
}

TaskWindow::~TaskWindow()
{
    delete ui;
    mainWindow->taskWindow = nullptr;
    mainWindow->close();
}


void TaskWindow::on_pushButton_clicked()
{
    if (mainWindow->boss_is_busy == 1) {
        QMessageBox::warning(this, "Warning", "Try later please\nBoss is texting\nwith someone else");
        mainWindow->boss_is_busy = 0;
        return;
    }
    qDebug() << "I started chat";
    mainWindow->SendToServer("7", QString("Open chat with me"));
    ChatWithBoss* chat = new ChatWithBoss(this);
    chat->ui->label->setText("You started chat");
    chat_ = chat;
    chat->setModal(true);
    chat->open();
}

