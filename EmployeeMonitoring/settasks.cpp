#include "settasks.h"
#include "ui_settasks.h"

SetTasks::SetTasks(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::SetTasks)
    , chosenWorkerParent(qobject_cast<ChosenWorker*>(parent))
{
    ui->setupUi(this);
    int num = chosenWorkerParent->mainWindow->cur_worker_num;
    QString name = chosenWorkerParent->mainWindow->names_[num];
    QString text = chosenWorkerParent->mainWindow->worker_sockets_[name]->tasks_;
    ui->textEdit->setText(text);
    ui->textEdit->moveCursor(QTextCursor::End);
}

void SetTasks::on_pushButton_clicked()
{
    int num = chosenWorkerParent->mainWindow->cur_worker_num;
    QString name = chosenWorkerParent->mainWindow->names_[num];
    chosenWorkerParent->mainWindow->worker_sockets_[name]->tasks_ = ui->textEdit->toPlainText();
    chosenWorkerParent->mainWindow->SendToClient("3", ui->textEdit->toPlainText());

    qDebug() << "tasks editing";
}

SetTasks::~SetTasks()
{
    delete ui;
}
