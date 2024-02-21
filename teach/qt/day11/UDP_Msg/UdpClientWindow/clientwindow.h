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
    void read_data();

private:
    Ui::ClientWindow* ui;
    QUdpSocket m_scoket;        //ʵ��������
};

#endif // CLIENTWINDOW_H
