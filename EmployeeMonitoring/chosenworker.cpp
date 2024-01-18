#include "chosenworker.h"
#include "ui_chosenworker.h"
#include "chatwithworker.h"
#include "ui_chatwithworker.h"

#include <QCloseEvent>

ChosenWorker::ChosenWorker(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::ChosenWorker)
    , mainWindow(qobject_cast<MainWindow*>(parent))
{
    ui->setupUi(this);
    ui->label_2->setText(mainWindow->names_[mainWindow->cur_worker_num]);
    ui->label->setVisible(false);
}

ChosenWorker::~ChosenWorker()
{
    delete ui;
    mainWindow->chosen_ = nullptr;
}

void ChosenWorker::on_pushButton_clicked()
{
    if (mainWindow->cur_worker_socket == nullptr) {
        QMessageBox::warning(this, "Warning", "Worker has disconnected\nGo back to other workers please");
        return;
    }
    mainWindow->SendToClient("1", "send me screenshot");
}

void ChosenWorker::on_pushButton_2_clicked()
{
    if (mainWindow->cur_worker_socket == nullptr) {
        QMessageBox::warning(this, "Warning", "Worker has disconnected\nGo back to other workers please");
        return;
    }
    SetTasks set_tasks(this);
    tasks_ = &set_tasks;
    set_tasks.setModal(true);
    set_tasks.exec();
}


void ChosenWorker::on_pushButton_3_clicked()
{
    if (mainWindow->cur_worker_socket == nullptr) {
        QMessageBox::warning(this, "Warning", "Worker has disconnected\nGo back to other workers please");
        return;
    }
    mainWindow->SendToClient("7", "Open chat window");
    ChatWithWorker* chat = new ChatWithWorker(this);
    chat_ = chat;
    QString name = mainWindow->names_[mainWindow->cur_worker_num];
    QString text = "You started chat with " + name;
    chat->ui->label->setText(text);
    chat->setModal(true);
    chat->show();
}


void ChosenWorker::on_pushButton_4_clicked()
{
    close();
}

