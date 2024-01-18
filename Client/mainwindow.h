#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTcpSocket>
#include <QMessageBox>

class TaskWindow;

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    friend class TaskWindow;
    friend class ChatWithBoss;

    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

public slots:
    void onSocketStateChanged(QAbstractSocket::SocketState socketState);

private slots:
    void on_pushButton_2_clicked();
    void on_lineEdit_returnPressed();

    void handleConnected();

    void SendToServer(QString command, QString str);
    void SendToServer(QString command, QByteArray data);

private:
    Ui::MainWindow *ui;
    QTcpSocket *socket;

    QByteArray Data;
    quint32 m_nNextВlockSize = 0;
    bool boss_is_busy = 0;

    TaskWindow* taskWindow = nullptr;

public slots:
    void slotReadyRead();
};
#endif // MAINWINDOW_H
