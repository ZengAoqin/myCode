#ifndef MYTHREAD_H
#define MYTHREAD_H
#include <QThread>
#include <QDebug>

class MyThread: public QThread
{
    Q_OBJECT
public:
    explicit MyThread(QObject* parent = nullptr);
    ~MyThread();
    virtual void run();

};

#endif // MYTHREAD_H
