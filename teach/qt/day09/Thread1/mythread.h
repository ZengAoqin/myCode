#ifndef MYTHREAD_H
#define MYTHREAD_H

#include <QThread>
#include <QDebug>

class MyThread: public QThread
{
public:
    explicit MyThread(QObject* parent = nullptr);       //���캯��
    ~MyThread();                                        //��������
    virtual void run();                                 //����run����
};

#endif // MYTHREAD_H
