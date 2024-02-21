#include "login.h"
#include "ui_login.h"
#include <QDebug>
#include <QMessageBox>


Login::Login(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Login)
{
    ui->setupUi(this);
    this->w = new Welcome;
}

Login::~Login()
{
    delete w;
    delete ui;
}

void Login::on_pushButton_clicked()
{
    qDebug() << QString::fromUtf8("点击登录按钮") << endl;

    QString name = ui->lineEdit->text();
    QString pwd = ui->lineEdit_2->text();

    if("123456" == pwd)
    {
        QMessageBox::information(this, "登录提示框", "用户:" + name + " 登录成功！！",
                                       QMessageBox::Yes);

        this->w->setUserName(name);
        w->show();
        this->hide();
    }
    else
    {
        QMessageBox::information(this, "登录提示框", "登录失败！！",
                                       QMessageBox::Yes);
        ui->lineEdit_2->clear();
    }

}
