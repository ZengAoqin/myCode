#ifndef MYTHREAD_H
#define MYTHREAD_H

#include <QThread>
#include <QDebug>

class MyThread: public QThread
{
public:
    explicit MyThread(QObject* parent = nullptr);       //构造函数
    ~MyThread();                                        //析构函数
    virtual void run();                                 //重现run函数
};

#endif // MYTHREAD_H
