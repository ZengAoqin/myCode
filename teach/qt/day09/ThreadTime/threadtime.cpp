#include "threadtime.h"
#include "ui_threadtime.h"

ThreadTime::ThreadTime(QWidget* parent) :
    QWidget(parent),
    ui(new Ui::ThreadTime), m_pThread(new MyThread)
{
    ui->setupUi(this);
    //�����̣߳������߳����ݸ���ui�߳�����
    //connect(m_pThread, SIGNAL(sendStrTime(QString)), this, SLOT(on_RecvTimeShow(QString)));
    connect(m_pThread, &MyThread::sendStrTime, this, &ThreadTime::on_RecvTimeShow);
}

ThreadTime::~ThreadTime()
{
    delete ui;
    delete m_pThread;
}

//��������̰߳�ť
void ThreadTime::on_btnStart_clicked()
{
    m_pThread->start();
}

//����ر��̰߳�ť
void ThreadTime::on_btnKill_clicked()
{
    m_pThread->terminate();
}

void ThreadTime::on_RecvTimeShow(QString strTime)
{
    ui->lcdNumber->display(strTime);
}
