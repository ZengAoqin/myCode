#ifndef TCPSERVERWINDOW_H
#define TCPSERVERWINDOW_H

#include <QWidget>
#include <QTcpServer>
#include <QTcpSocket>
#include <QDebug>

namespace Ui
{
class TcpServerWindow;
}

class TcpServerWindow : public QWidget
{
    Q_OBJECT

public:
    explicit TcpServerWindow(QWidget* parent = nullptr);
    ~TcpServerWindow();

private slots:
    void on_btnStart_clicked();
    void new_client();              //获取新的连接客户端
    void read_data();               //读取客户端发送消息

private:
    Ui::TcpServerWindow* ui;
    //实例化服务器对象
    QTcpServer m_server;
    bool m_falg;                    //false:初始没有启动服务器 true:启动了服务器
};

#endif // TCPSERVERWINDOW_H
