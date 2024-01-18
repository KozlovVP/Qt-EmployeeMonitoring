#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTcpServer>
#include <QTcpSocket>
#include <QMessageBox>

class ChosenWorker;

class MyWorker
{
public:
    QTcpSocket* worker_socket_;
    QString tasks_ = "Do something";

    MyWorker(QTcpSocket* socket) {
        worker_socket_ = socket;
    }
};

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    friend class ChosenWorker;
    friend class SetTasks;
    friend class ChatWithWorker;

    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    QTcpSocket *socket;

public slots:
    void onNewConnection();
    void onSocketStateChanged(QAbstractSocket::SocketState socketState);
    void onReadyRead();

private slots:
    void on_pushButton_clicked();
    void on_lineEdit_returnPressed();

    void SendToClient(QString command, QString str);
    bool CheckWorkerNum(int num);

private:
    Ui::MainWindow *ui;
    QTcpServer  server_;

    QList<QTcpSocket*>  sockets_;
    QMap<QString, MyWorker*> worker_sockets_;
    QVector<QString> names_;

    QByteArray data_;
    quint32 m_nNextВlockSize = 0;
    qint8 cur_worker_num;
    QTcpSocket* cur_worker_socket = nullptr;

    ChosenWorker* chosen_ = nullptr;
};

#endif // MAINWINDOW_H
