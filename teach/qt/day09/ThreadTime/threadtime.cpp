#include "threadtime.h"
#include "ui_threadtime.h"

ThreadTime::ThreadTime(QWidget* parent) :
    QWidget(parent),
    ui(new Ui::ThreadTime), m_pThread(new MyThread)
{
    ui->setupUi(this);
    //绑定子线程，用子线程数据更新ui线程数据
    //connect(m_pThread, SIGNAL(sendStrTime(QString)), this, SLOT(on_RecvTimeShow(QString)));
    connect(m_pThread, &MyThread::sendStrTime, this, &ThreadTime::on_RecvTimeShow);
}

ThreadTime::~ThreadTime()
{
    delete ui;
    delete m_pThread;
}

//点击开启线程按钮
void ThreadTime::on_btnStart_clicked()
{
    m_pThread->start();
}

//点击关闭线程按钮
void ThreadTime::on_btnKill_clicked()
{
    m_pThread->terminate();
}

void ThreadTime::on_RecvTimeShow(QString strTime)
{
    ui->lcdNumber->display(strTime);
}
