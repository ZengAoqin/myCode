#ifndef WELCOME_H
#define WELCOME_H

#include <QWidget>
#include "view.h"
#include "mainwindow.h"
#include "timer.h"


namespace Ui {
class Welcome;
}

class Welcome : public QWidget
{
    Q_OBJECT

public:
    explicit Welcome(QWidget *parent = nullptr);
    void setUserName(QString userName);
    ~Welcome();

private slots:
    void on_pushButton_clicked();
    void on_returnFromView();
    void on_pushButton_7_clicked();

    void on_pushButton_8_clicked();

private:
    Ui::Welcome *ui;
    View* v;
    MainWindow* m;
    QString userName;
    Timer* t;
};

#endif // WELCOME_H
