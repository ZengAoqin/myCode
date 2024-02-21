#include "treadpoolwindow.h"
#include "ui_treadpoolwindow.h"

TreadPoolWindow::TreadPoolWindow(QWidget* parent) :
    QWidget(parent),
    ui(new Ui::TreadPoolWindow)
{
    ui->setupUi(this);
    int number = 0, i = 0;
    //�ֲ��̳߳�
    QThreadPool* pool = new QThreadPool;
    for(i = 0; i < 10; ++i)
    {
        //������񲢵���
        pool->start(new MyTask(QString::fromLocal8Bit("����") + QString::number(number)));
        number++;
    }
}

TreadPoolWindow::~TreadPoolWindow()
{
    delete ui;
}

void TreadPoolWindow::on_pushButton_clicked()
{
    //������������
    MyTask* pTask = new MyTask(ui->lineEdit->text());
    //��ȡȫ���̳߳�
    QThreadPool* pool = QThreadPool::globalInstance();
    //���̳߳���ִ������
    pool->start(pTask);
}
