#ifndef MYTHREAD_H
#define MYTHREAD_H
#include <QThread>
#include <QTime>
#include <QDebug>

class MyThread : public QThread
{
    Q_OBJECT  //��Ҫʹ���ź���ۺ���
public:
    explicit MyThread(QObject* parent = nullptr);   //���캯��
    ~MyThread();                                    //��������

signals:
    void sendStrTime(QString);                      //���巢���ַ���ʱ���ź�

protected:
    virtual void run();                             //��дrun����

};

#endif // MYTHREAD_H
