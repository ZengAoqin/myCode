#ifndef MYWORK_H
#define MYWORK_H

#include <QObject>
#include <QThread>
#include <QDebug>

class MyWork : public QObject
{
    Q_OBJECT
public:
    explicit MyWork(QObject* parent = nullptr);

signals:
    void send_str(QString);

public slots:   //自定义槽函数，完成事件
    void work_send();
};

#endif // MYWORK_H
