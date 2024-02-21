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
    void new_client();              //��ȡ�µ����ӿͻ���
    void read_data();               //��ȡ�ͻ��˷�����Ϣ

private:
    Ui::TcpServerWindow* ui;
    //ʵ��������������
    QTcpServer m_server;
    bool m_falg;                    //false:��ʼû������������ true:�����˷�����
};

#endif // TCPSERVERWINDOW_H
