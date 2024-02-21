#ifndef THREADMUTEX_H
#define THREADMUTEX_H

#include <QWidget>
#include "workthread.h"

namespace Ui
{
class ThreadMutex;
}

class ThreadMutex : public QWidget
{
    Q_OBJECT

public:
    explicit ThreadMutex(QWidget* parent = nullptr);
    ~ThreadMutex();

private slots:
    void on_btnStart_clicked();

    void on_btnKill_clicked();

    void showMsg(QString msg);

private:
    Ui::ThreadMutex* ui;
    //实例化线程对象
    WorkThread1* m_th1;
    WorkThread2* m_th2;
};

#endif // THREADMUTEX_H
