#ifndef CHATWITHWORKER_H
#define CHATWITHWORKER_H

#include "chosenworker.h"

#include <QDialog>
#include <QCloseEvent>

namespace Ui {
class ChatWithWorker;
}

class ChatWithWorker : public QDialog
{
    Q_OBJECT

public:
    friend class MainWindow;
    friend class ChosenWorker;

    explicit ChatWithWorker(QWidget *parent = nullptr);
    ~ChatWithWorker();

private slots:
    void on_pushButton_clicked();

    void closeEvent(QCloseEvent *event);
    void keyPressEvent(QKeyEvent *event);

private:
    Ui::ChatWithWorker *ui;

    ChosenWorker* chosenWorker;
};

#endif // CHATWITHWORKER_H
