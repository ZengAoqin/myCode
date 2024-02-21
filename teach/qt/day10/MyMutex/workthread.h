#ifndef WORKTHREAD1_H
#define WORKTHREAD1_H
#include <QThread>
#include "data.h"

class WorkThread1 : public QThread
{
    Q_OBJECT
public:
    explicit WorkThread1(QObject* parent = nullptr);        //���캯��
    ~WorkThread1();                                         //��������
    virtual void run();                                     //��дrun����
signals:
    void sendmsg(QString);
};

class WorkThread2 : public QThread
{
    Q_OBJECT
public:
    explicit WorkThread2(QObject* parent = nullptr);        //���캯��
    ~WorkThread2();                                         //��������
    virtual void run();                                     //��дrun����
};

#endif // WORKTHREAD1_H
