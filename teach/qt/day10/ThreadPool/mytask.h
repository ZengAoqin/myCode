#ifndef MYTASK_H
#define MYTASK_H

#include <QRunnable>
#include <QString>
#include <QDebug>
#include <QThread>

class MyTask : public QRunnable
{
public:
    explicit MyTask(QString name);              //构造函数
    virtual void run();                         //重写run函数，实现纯虚函数
private:
    QString m_name; //任务名字
};

#endif // MYTASK_H
