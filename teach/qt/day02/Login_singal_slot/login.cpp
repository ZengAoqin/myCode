#include "login.h"
#include "ui_login.h"

#include <QDebug>
#include <QMessageBox>

Login::Login(QWidget* parent) :
    QWidget(parent),
    ui(new Ui::Login)
{
    ui->setupUi(this);
    //绑定取消按钮和槽函数
    connect(ui->pBtn_cannel, SIGNAL(clicked()), this, SLOT(set_pBtn_cannel()));
    //自定义信号和自定义槽函数的绑定
    connect(this, &Login::mysingnal, this, &Login::show_mysingal);
}

Login::~Login()
{
    delete w;
    delete ui;
}

void Login::on_pBtn_login_clicked()
{
    QString str = QString::fromLocal8Bit("点击登录按钮");
    qDebug() << str;
    //获取账号和密码
    QString name = ui->lineEdit_Name->text();
    QString pwd = ui->lineEdit_PWD->text();

    //判断账号和密码是否正确
    if(name == "admin" && pwd == "123456")
    {
        /*
        int ret = QMessageBox::information(this, "登录提示框", "尊敬的用户", name + "登录成功",
                                           QMessageBox::Yes, QMessageBox::No);
                                           */
        QMessageBox box;
        //添加消息盒子的标题
        box.setWindowTitle(QString::fromLocal8Bit("登录提示框"));
        //添加消息盒子的内容
        box.setText(QString::fromLocal8Bit("欢迎用户：") + name);
        //添加一个确认按钮
        box.addButton(QString::fromLocal8Bit("确认"), QMessageBox::AcceptRole);
        //添加一个取消按钮
        box.addButton(QString::fromLocal8Bit("取消"), QMessageBox::RejectRole);
        int ret = box.exec();
        qDebug() << ret;

        //判断是否操作
        if(ret == 0)
        {
            QMessageBox::about(this, QString::fromLocal8Bit("登录成功"), QString::fromLocal8Bit("您已登录"));
            w = new welcome;
            //主界面显示
            w->show();
            //登录界面隐藏
            this->hide();
        }
        else
        {
            ui->lineEdit_PWD->clear();
        }
    }
    else
    {
        //提示对话框
        QMessageBox::information(this, QString::fromLocal8Bit("登录提示"), QString::fromLocal8Bit("账号和密码不一致"));
    }
}

void Login::set_pBtn_cannel()
{
    qDebug() << QString::fromLocal8Bit("点击了取消按钮");
    //发送自定义信号
    emit mysingnal();
}

void Login::show_mysingal()
{
    qDebug() << QString::fromLocal8Bit("处理mysingnal信号");
}
