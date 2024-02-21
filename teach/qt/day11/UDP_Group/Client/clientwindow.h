#ifndef CLIENTWINDOW_H
#define CLIENTWINDOW_H

#include <QWidget>
#include <QUdpSocket>

namespace Ui
{
class ClientWindow;
}

class ClientWindow : public QWidget
{
    Q_OBJECT

public:
    explicit ClientWindow(QWidget* parent = nullptr);
    ~ClientWindow();

private slots:
    void on_btnSend_clicked();

private:
    Ui::ClientWindow* ui;
    //实例化udp套接字对象
    QUdpSocket m_socket;
};

#endif // CLIENTWINDOW_H
