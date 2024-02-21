#ifndef MAINWINDOWS_H
#define MAINWINDOWS_H

#include <QWidget>
#include <QThread>
#include "mywork.h"

namespace Ui
{
class MainWindows;
}

class MainWindows : public QWidget
{
    Q_OBJECT

public:
    explicit MainWindows(QWidget* parent = nullptr);
    ~MainWindows();

private slots:
    void on_btnStart_clicked();

    void recv_myWork(QString);

    void on_btnKill_clicked();

signals:
    void start_th();

private:
    Ui::MainWindows* ui;
    //实例化线程对象
    QThread* m_pThread;
    //实例化QObject派生类的对象
    MyWork* m_pWork;
};

#endif // MAINWINDOWS_H
