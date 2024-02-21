#ifndef UDPCLIENT_H
#define UDPCLIENT_H

#include <QWidget>
#include <QUdpSocket>

namespace Ui {
class UdpClient;
}

class UdpClient : public QWidget
{
    Q_OBJECT

public:
    explicit UdpClient(QWidget *parent = nullptr);
    ~UdpClient();

private slots:
    void on_pushButton_clicked();

private:
    Ui::UdpClient *ui;
    QUdpSocket m_socket;
};

#endif // UDPCLIENT_H
