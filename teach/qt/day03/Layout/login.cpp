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
    //判断用户名和密码是否登录成功
    QString name = ui->lineEdit_name->text();
    QString pwd = ui->lineEdit_pwd->text();

    if(name == "admin" && pwd == "123456")
    {
        int ret = showBox(QString::fromLocal8Bit("登录提示框"), QString::fromLocal8Bit("欢迎用户:") + name);
        qDebug() << "ret = " << ret;
        if(ret == 0) //点击确认按钮
        {
            //调用自定义函数设置内容
            m_pMainWin->setNameText(name);
            //展示主窗口
            m_pMainWin->show();
            //关闭登录窗口
            this->close();
        }
        else
        {
            ui->lineEdit_pwd->clear(); //清除密码
        }
    }
}

int Login::showBox(QString title, QString text)
{
    //实例化类对象
    QMessageBox box;
    //设置消息盒子的标题
    box.setWindowTitle(title);
    //添加消息盒子的内容
    box.setText(text);
    //添加一个确认按钮
    box.addButton(QString::fromLocal8Bit("确认"), QMessageBox::AcceptRole);
    //添加哪一个取消按钮
    box.addButton(QString::fromLocal8Bit("取消"), QMessageBox::RejectRole);
    //显示消息盒子
    int ret = box.exec();
    return ret;
}
