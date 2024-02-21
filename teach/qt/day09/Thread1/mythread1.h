#ifndef MYTHREAD1_H
#define MYTHREAD1_H

#include <QWidget>
#include "mythread.h"

namespace Ui
{
class MyThread1;
}

class MyThread1 : public QWidget
{
    Q_OBJECT

public:
    explicit MyThread1(QWidget* parent = nullptr);
    ~MyThread1();

private slots:
    void on_BtnStart_clicked();

    void on_BtnKill_clicked();

    void showStart();
    void showFinished();
private:
    Ui::MyThread1* ui;
    //实例化子线程对象
    MyThread* m_th1;
    MyThread* m_th2;
};

#endif // MYTHREAD1_H
