#ifndef SERVERWINDOW_H
#define SERVERWINDOW_H

#include <QWidget>
#include <QUdpSocket>

namespace Ui
{
class ServerWindow;
}

class ServerWindow : public QWidget
{
    Q_OBJECT

public:
    explicit ServerWindow(QWidget* parent = nullptr);
    ~ServerWindow();

private slots:
    void on_btnBind_clicked();
    void read_data();

private:
    Ui::ServerWindow* ui;
    QUdpSocket m_socket;        //ʵ��������
};

#endif // SERVERWINDOW_H
