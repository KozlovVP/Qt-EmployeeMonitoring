#ifndef SETTASKS_H
#define SETTASKS_H

#include "mainwindow.h"
#include "chosenworker.h"

#include <QDialog>

class ChosenWorker;

namespace Ui {
class SetTasks;
}

class SetTasks : public QDialog
{
    Q_OBJECT

public:
    explicit SetTasks(QWidget *parent = nullptr);
    ~SetTasks();

private slots:
    void on_pushButton_clicked();

private:
    Ui::SetTasks *ui;

    ChosenWorker* chosenWorkerParent;
};

#endif // SETTASKS_H
