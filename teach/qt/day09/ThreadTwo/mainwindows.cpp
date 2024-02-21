#include "mainwindows.h"
#include "ui_mainwindows.h"

MainWindows::MainWindows(QWidget* parent) :
    QWidget(parent),
    ui(new Ui::MainWindows),
    m_pThread(new QThread), m_pWork(new MyWork)
{
    ui->setupUi(this);
    //将m_pWork的内容实现移动到线程m_pThread的工作范围
    m_pWork->moveToThread(m_pThread);
    //绑定
    connect(this, SIGNAL(start_th()), m_pWork, SLOT(work_send()));
    connect(m_pWork, SIGNAL(send_str(QString)), this, SLOT(recv_myWork(QString)));

}

MainWindows::~MainWindows()
{
    delete ui;
}

void MainWindows::on_btnStart_clicked()
{
    m_pThread->start();     //开启线程
    qDebug() << "start_th";
    emit start_th();        //发送信号
}

void MainWindows::recv_myWork(QString strText)
{
    ui->label->setText(strText);
}

void MainWindows::on_btnKill_clicked()
{
    m_pThread->terminate(); //关闭线程
}
