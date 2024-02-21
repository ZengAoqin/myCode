#ifndef WELCOME_H
#define WELCOME_H

#include <QWidget>
#include "view.h"


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

private:
    Ui::Welcome *ui;
    View* v;
    QString userName;
};

#endif // WELCOME_H
