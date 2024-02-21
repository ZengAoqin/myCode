#ifndef TCPCLIENTWINDOW_H
#define TCPCLIENTWINDOW_H

#include <QWidget>
#include <QTcpSocket>

namespace Ui
{
class TcpClientWindow;
}

class TcpClientWindow : public QWidget
{
    Q_OBJECT

public:
    explicit TcpClientWindow(QWidget* parent = nullptr);
    ~TcpClientWindow();

private slots:
    void on_btnConnect_clicked();

    void on_btnSend_clicked();

    void on_btnClear_clicked();

    void read_msg();

private:
    Ui::TcpClientWindow* ui;
    //实例化套接字对象
    QTcpSocket m_socket;
};

#endif // TCPCLIENTWINDOW_H
