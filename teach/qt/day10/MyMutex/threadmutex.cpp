#include "threadmutex.h"
#include "ui_threadmutex.h"

ThreadMutex::ThreadMutex(QWidget* parent) :
    QWidget(parent),
    ui(new Ui::ThreadMutex)
{
    ui->setupUi(this);
    //��ʼ��
    m_th1 = new WorkThread1;
    m_th2 = new WorkThread2;
    //��
    connect(m_th1, &WorkThread1::sendmsg, this, &ThreadMutex::showMsg);
}

ThreadMutex::~ThreadMutex()
{
    delete ui;
    delete m_th1;
    delete m_th2;
}

void ThreadMutex::on_btnStart_clicked()
{
    m_th1->start();
    m_th2->start();
}

void ThreadMutex::on_btnKill_clicked()
{
    m_th1->terminate();
    m_th2->terminate();
}

void ThreadMutex::showMsg(QString msg)
{
    ui->textBrowser->append(msg);
}
