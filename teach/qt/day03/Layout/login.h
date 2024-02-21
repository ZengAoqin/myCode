#ifndef LOGIN_H
#define LOGIN_H

#include <QWidget>
#include "mainwindow.h"

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
    void on_pushButton_login_clicked();

private:
    int showBox(QString title, QString text);

private:
    Ui::Login* ui;
    MainWindow* m_pMainWin;     //Ö÷½çÃæ
};

#endif // LOGIN_H
