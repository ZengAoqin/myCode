#ifndef MYTASK_H
#define MYTASK_H

#include <QRunnable>
#include <QString>
#include <QDebug>
#include <QThread>

class MyTask : public QRunnable
{
public:
    explicit MyTask(QString name);              //���캯��
    virtual void run();                         //��дrun������ʵ�ִ��麯��
private:
    QString m_name; //��������
};

#endif // MYTASK_H
