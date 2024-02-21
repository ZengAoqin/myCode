#ifndef WELCOME_H
#define WELCOME_H

#include <QWidget>
#include "view.h"
#include "mainwindow.h"


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
    void on_returnFromViewPage();
    void on_pushButton_2_clicked();
    void on_pushButton_3_clicked();
    void on_pushButton_4_clicked();
    void on_pushButton_5_clicked();
    void on_pushButton_6_clicked();
    void on_pushButton_7_clicked();

private:
    Ui::Welcome *ui;
    View* v;
    MainWindow* m;
    QString userName;
};

#endif // WELCOME_H
