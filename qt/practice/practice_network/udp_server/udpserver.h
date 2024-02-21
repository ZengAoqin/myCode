#ifndef UDPSERVER_H
#define UDPSERVER_H

#include <QWidget>
#include <QUdpSocket>


namespace Ui {
class UdpServer;
}

class UdpServer : public QWidget
{
    Q_OBJECT

public:
    explicit UdpServer(QWidget *parent = nullptr);
    ~UdpServer();

private slots:
    void on_pushButton_clicked();
    void on_checkBox_clicked(bool checked);
    void read_data();

private:
    Ui::UdpServer *ui;
    QUdpSocket m_socket;      //实例化对象
};

#endif // UDPSERVER_H
