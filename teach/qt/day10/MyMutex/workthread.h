#ifndef WORKTHREAD1_H
#define WORKTHREAD1_H
#include <QThread>
#include "data.h"

class WorkThread1 : public QThread
{
    Q_OBJECT
public:
    explicit WorkThread1(QObject* parent = nullptr);        //构造函数
    ~WorkThread1();                                         //析构函数
    virtual void run();                                     //重写run函数
signals:
    void sendmsg(QString);
};

class WorkThread2 : public QThread
{
    Q_OBJECT
public:
    explicit WorkThread2(QObject* parent = nullptr);        //构造函数
    ~WorkThread2();                                         //析构函数
    virtual void run();                                     //重写run函数
};

#endif // WORKTHREAD1_H
