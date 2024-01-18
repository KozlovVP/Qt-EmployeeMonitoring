#ifndef CHOSENWORKER_H
#define CHOSENWORKER_H

#include "mainwindow.h"
#include "settasks.h"

#include <QDialog>
#include <QMessageBox>

class SetTasks;
class ChatWithWorker;

namespace Ui {
class ChosenWorker;
}

class ChosenWorker : public QDialog
{
    Q_OBJECT

public:
    friend class MainWindow;
    friend class SetTasks;
    friend class ChatWithWorker;

    explicit ChosenWorker(QWidget *parent = nullptr);
    ~ChosenWorker();
private slots:
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();
    void on_pushButton_3_clicked();
    void on_pushButton_4_clicked();

private:
    Ui::ChosenWorker *ui;

    MainWindow* mainWindow = nullptr;
    SetTasks* tasks_;
    ChatWithWorker* chat_ = nullptr;

};

#endif // CHOSENWORKER_H
