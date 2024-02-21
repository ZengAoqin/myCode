#include "login.h"
#include "ui_login.h"

#include <QDebug>
#include <QMessageBox>

Login::Login(QWidget* parent) :
    QWidget(parent),
    ui(new Ui::Login)
{
    ui->setupUi(this);
    //��ȡ����ť�Ͳۺ���
    connect(ui->pBtn_cannel, SIGNAL(clicked()), this, SLOT(set_pBtn_cannel()));
    //�Զ����źź��Զ���ۺ����İ�
    connect(this, &Login::mysingnal, this, &Login::show_mysingal);
}

Login::~Login()
{
    delete w;
    delete ui;
}

void Login::on_pBtn_login_clicked()
{
    QString str = QString::fromLocal8Bit("�����¼��ť");
    qDebug() << str;
    //��ȡ�˺ź�����
    QString name = ui->lineEdit_Name->text();
    QString pwd = ui->lineEdit_PWD->text();

    //�ж��˺ź������Ƿ���ȷ
    if(name == "admin" && pwd == "123456")
    {
        /*
        int ret = QMessageBox::information(this, "��¼��ʾ��", "�𾴵��û�", name + "��¼�ɹ�",
                                           QMessageBox::Yes, QMessageBox::No);
                                           */
        QMessageBox box;
        //�����Ϣ���ӵı���
        box.setWindowTitle(QString::fromLocal8Bit("��¼��ʾ��"));
        //�����Ϣ���ӵ�����
        box.setText(QString::fromLocal8Bit("��ӭ�û���") + name);
        //���һ��ȷ�ϰ�ť
        box.addButton(QString::fromLocal8Bit("ȷ��"), QMessageBox::AcceptRole);
        //���һ��ȡ����ť
        box.addButton(QString::fromLocal8Bit("ȡ��"), QMessageBox::RejectRole);
        int ret = box.exec();
        qDebug() << ret;

        //�ж��Ƿ����
        if(ret == 0)
        {
            QMessageBox::about(this, QString::fromLocal8Bit("��¼�ɹ�"), QString::fromLocal8Bit("���ѵ�¼"));
            w = new welcome;
            //��������ʾ
            w->show();
            //��¼��������
            this->hide();
        }
        else
        {
            ui->lineEdit_PWD->clear();
        }
    }
    else
    {
        //��ʾ�Ի���
        QMessageBox::information(this, QString::fromLocal8Bit("��¼��ʾ"), QString::fromLocal8Bit("�˺ź����벻һ��"));
    }
}

void Login::set_pBtn_cannel()
{
    qDebug() << QString::fromLocal8Bit("�����ȡ����ť");
    //�����Զ����ź�
    emit mysingnal();
}

void Login::show_mysingal()
{
    qDebug() << QString::fromLocal8Bit("����mysingnal�ź�");
}
