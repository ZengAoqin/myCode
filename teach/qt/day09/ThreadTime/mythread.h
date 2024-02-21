#ifndef MYTHREAD_H
#define MYTHREAD_H
#include <QThread>
#include <QTime>
#include <QDebug>

class MyThread : public QThread
{
    Q_OBJECT  //需要使用信号与槽函数
public:
    explicit MyThread(QObject* parent = nullptr);   //构造函数
    ~MyThread();                                    //析构函数

signals:
    void sendStrTime(QString);                      //定义发送字符串时间信号

protected:
    virtual void run();                             //重写run函数

};

#endif // MYTHREAD_H
