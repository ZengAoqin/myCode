#include "welcome.h"
#include "ui_welcome.h"
#include "login.h"
#include <QDebug>
#include <iostream>


Welcome::Welcome(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Welcome)
{
    ui->setupUi(this);
    this->v = new View;

    // 连接View页面的信号与Welcome页面的槽函数
    connect(v, &View::returnToWelcome, this, &Welcome::on_returnFromViewPage);
}

void Welcome::setUserName(QString userName)
{
    this->userName = userName;
    ui->label_3->setText(userName);
}

Welcome::~Welcome()
{
    delete v;
    delete ui;
}

void Welcome::on_pushButton_clicked()
{
    v->show();
    this->hide();
}

void Welcome::on_returnFromViewPage()
{
    this->show();
    v->hide();
}
