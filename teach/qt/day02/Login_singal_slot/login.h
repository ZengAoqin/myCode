#ifndef LOGIN_H
#define LOGIN_H

#include <QWidget>
#include "welcome.h"

namespace Ui
{
    class Login;
}

class Login : public QWidget
{
    Q_OBJECT

public:
    explicit Login(QWidget* parent = nullptr);
    ~Login();

private slots:
    void on_pBtn_login_clicked();

    void set_pBtn_cannel();

    void show_mysingal();

    //�Զ����ź�
signals:    //�źŲ�������ͨ����һ��ʹ�ã�����ҪȨ������
    void mysingnal();

private:
    Ui::Login* ui;
    welcome* w;
};

#endif // LOGIN_H
