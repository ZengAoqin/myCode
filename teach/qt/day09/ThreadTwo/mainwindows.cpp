#include "mainwindows.h"
#include "ui_mainwindows.h"

MainWindows::MainWindows(QWidget* parent) :
    QWidget(parent),
    ui(new Ui::MainWindows),
    m_pThread(new QThread), m_pWork(new MyWork)
{
    ui->setupUi(this);
    //��m_pWork������ʵ���ƶ����߳�m_pThread�Ĺ�����Χ
    m_pWork->moveToThread(m_pThread);
    //��
    connect(this, SIGNAL(start_th()), m_pWork, SLOT(work_send()));
    connect(m_pWork, SIGNAL(send_str(QString)), this, SLOT(recv_myWork(QString)));

}

MainWindows::~MainWindows()
{
    delete ui;
}

void MainWindows::on_btnStart_clicked()
{
    m_pThread->start();     //�����߳�
    qDebug() << "start_th";
    emit start_th();        //�����ź�
}

void MainWindows::recv_myWork(QString strText)
{
    ui->label->setText(strText);
}

void MainWindows::on_btnKill_clicked()
{
    m_pThread->terminate(); //�ر��߳�
}
