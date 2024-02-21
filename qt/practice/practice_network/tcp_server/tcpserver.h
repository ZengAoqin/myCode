#ifndef TCPSERVER_H
#define TCPSERVER_H

#include <QWidget>
#include <QTcpServer>
#include <QTcpSocket>

namespace Ui {
class TcpServer;
}

class TcpServer : public QWidget
{
    Q_OBJECT

public:
    explicit TcpServer(QWidget *parent = nullptr);
    ~TcpServer();

private slots:
    void on_btnStart_clicked();
    void new_client();                  //获取新连接客户端
    void read_data();                   //读取客户端发送的消息
    void client_disconnected();

private:
    Ui::TcpServer *ui;
    QTcpServer* m_server;
    bool m_on;
};

#endif // TCPSERVER_H
