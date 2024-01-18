#ifndef TASKWINDOW_H
#define TASKWINDOW_H

#include "mainwindow.h"

#include <QDialog>

class ChatWithBoss;

namespace Ui {
class TaskWindow;
}

class TaskWindow : public QDialog
{
    Q_OBJECT

public:
    friend class MainWindow;
    friend class ChatWithBoss;

    explicit TaskWindow(QWidget *parent = nullptr);
    ~TaskWindow();

private slots:
    void on_pushButton_clicked();

private:
    Ui::TaskWindow *ui;

    ChatWithBoss* chat_ = nullptr;

    MainWindow* mainWindow = nullptr;
};

#endif // TASKWINDOW_H
