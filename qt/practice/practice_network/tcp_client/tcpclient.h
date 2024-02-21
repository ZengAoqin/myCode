#ifndef TCPCLIENT_H
#define TCPCLIENT_H

#include <QWidget>
#include <QTcpSocket>

namespace Ui {
class TcpClient;
}

class TcpClient : public QWidget
{
    Q_OBJECT

public:
    explicit TcpClient(QWidget *parent = nullptr);
    ~TcpClient();

private slots:
    void on_btnConnect_clicked();
    void on_btnSend_clicked();
    void on_btnClear_clicked();
    void read_msg();

private:
    Ui::TcpClient *ui;
    QTcpSocket m_socket;
};

#endif // TCPCLIENT_H
