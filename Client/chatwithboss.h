#ifndef CHATWITHBOSS_H
#define CHATWITHBOSS_H

#include "taskwindow.h"

#include <QDialog>
#include <QCloseEvent>

namespace Ui {
class ChatWithBoss;
}

class ChatWithBoss : public QDialog
{
    Q_OBJECT

public:
    friend class MainWindow;
    friend class TaskWindow;

    explicit ChatWithBoss(QWidget *parent = nullptr);
    ~ChatWithBoss();

private slots:
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();

    void closeEvent(QCloseEvent *event);
    void keyPressEvent(QKeyEvent *event);

private:
    Ui::ChatWithBoss *ui;
    TaskWindow* taskWindow;
};

#endif // CHATWITHBOSS_H
