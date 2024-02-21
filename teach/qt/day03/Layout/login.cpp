#include "login.h"
#include "ui_login.h"
#include <QMessageBox>
#include <QDebug>

Login::Login(QWidget* parent) :
    QWidget(parent),
    ui(new Ui::Login),
    m_pMainWin(new MainWindow)
{
    ui->setupUi(this);
}

Login::~Login()
{
    delete ui;
    delete m_pMainWin;
}

void Login::on_pushButton_login_clicked()
{
    //�ж��û����������Ƿ��¼�ɹ�
    QString name = ui->lineEdit_name->text();
    QString pwd = ui->lineEdit_pwd->text();

    if(name == "admin" && pwd == "123456")
    {
        int ret = showBox(QString::fromLocal8Bit("��¼��ʾ��"), QString::fromLocal8Bit("��ӭ�û�:") + name);
        qDebug() << "ret = " << ret;
        if(ret == 0) //���ȷ�ϰ�ť
        {
            //�����Զ��庯����������
            m_pMainWin->setNameText(name);
            //չʾ������
            m_pMainWin->show();
            //�رյ�¼����
            this->close();
        }
        else
        {
            ui->lineEdit_pwd->clear(); //�������
        }
    }
}

int Login::showBox(QString title, QString text)
{
    //ʵ���������
    QMessageBox box;
    //������Ϣ���ӵı���
    box.setWindowTitle(title);
    //�����Ϣ���ӵ�����
    box.setText(text);
    //���һ��ȷ�ϰ�ť
    box.addButton(QString::fromLocal8Bit("ȷ��"), QMessageBox::AcceptRole);
    //�����һ��ȡ����ť
    box.addButton(QString::fromLocal8Bit("ȡ��"), QMessageBox::RejectRole);
    //��ʾ��Ϣ����
    int ret = box.exec();
    return ret;
}
