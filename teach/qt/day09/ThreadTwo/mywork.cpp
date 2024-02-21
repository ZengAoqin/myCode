#include "mywork.h"

MyWork::MyWork(QObject* parent) : QObject(parent)
{

}

//自定义的槽函数
void MyWork::work_send()
{
    int n = 0;
    QString strSendText;
    for(;;)
    {
        //延迟
        QThread::sleep(1);
        //打印运行
        qDebug() << QString::fromLocal8Bit("正在运行的线程") << QString::fromLocal8Bit(",n的数字为:") << n++ << endl;
        strSendText = QString::fromLocal8Bit("正在运行的线程,n的数字为:%1").arg(n);
        emit send_str(strSendText);
    }
}
