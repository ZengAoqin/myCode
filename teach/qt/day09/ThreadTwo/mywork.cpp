#include "mywork.h"

MyWork::MyWork(QObject* parent) : QObject(parent)
{

}

//�Զ���Ĳۺ���
void MyWork::work_send()
{
    int n = 0;
    QString strSendText;
    for(;;)
    {
        //�ӳ�
        QThread::sleep(1);
        //��ӡ����
        qDebug() << QString::fromLocal8Bit("�������е��߳�") << QString::fromLocal8Bit(",n������Ϊ:") << n++ << endl;
        strSendText = QString::fromLocal8Bit("�������е��߳�,n������Ϊ:%1").arg(n);
        emit send_str(strSendText);
    }
}
