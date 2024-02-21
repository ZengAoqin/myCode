#include "myprocess.h"
#include "ui_myprocess.h"
#include <QDebug>


MyProcess::MyProcess(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MyProcess)
{
    ui->setupUi(this);

    t1 = new MyThread;
    t2 = new MyThread;
    t3 = new TimeThread;

    t1->setObjectName("线程1");
    t2->setObjectName("线程2");

    connect(t1, &MyThread::started, this, &MyProcess::showStart);
    connect(t1, &MyThread::finished, this, &MyProcess::showFinish);
//    connect(t3, SIGNAL(sendStrTime(QString)), this, SLOT(on_recieveStrTime(QString)));
    connect(t3, &TimeThread::sendStrTime, this, &MyProcess::on_recieveStrTime);
}

void MyProcess::showStart()
{
    qDebug() << "收到start信号";
}

void MyProcess::showFinish()
{
    qDebug() << "收到Finish信号";
}

MyProcess::~MyProcess()
{
    delete ui;
    delete t1;
    delete t2;
    delete t3;
}

void MyProcess::on_pushButton_clicked()
{
    this->close();
    QStringList args;
    args << "file.txt" << "file1.txt";
    int exitCode = QProcess::execute("D:/program file/Notepad++/notepad++.exe", args);
    qDebug() << "ret:" << exitCode;
    this->show();
}

void MyProcess::on_pushButton_2_clicked()
{
    m_process.start("calc");
    qDebug() << "start";
    m_process.waitForFinished();
    qDebug() << "finish";
}

void MyProcess::on_pushButton_3_clicked()
{
    QString command = "ping www.baidu.com";
    m_process.start(command);
    QByteArray output = m_process.readAllStandardOutput();
    QString msg = QString::fromLocal8Bit(output);
    qDebug() << "msg:" << msg;
}

void MyProcess::on_pushButton_4_clicked()
{
    t2->start();
    t1->start();
    //在启动之后设置优先级
    t1->setPriority(QThread::HighPriority);
}

void MyProcess::on_pushButton_5_clicked()
{
    t1->terminate();
    t2->terminate();
    qDebug() << "线程关闭";
}


void MyProcess::on_pushButton_6_clicked()
{
    t3->start();
}

void MyProcess::on_pushButton_7_clicked()
{
    t3->terminate();
}

void MyProcess::on_recieveStrTime(QString strTime)
{
    qDebug() << strTime;
    ui->lcdNumber->display(strTime);
}
