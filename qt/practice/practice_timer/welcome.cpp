#include "welcome.h"
#include "ui_welcome.h"
#include "login.h"
#include "timer.h"
#include <QDebug>
#include <iostream>
#include <QFileDialog>
#include <QColorDialog>
#include <QFontDialog>
#include <QInputDialog>
#include <QDialog>


Welcome::Welcome(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Welcome)
{
    ui->setupUi(this);
    this->v = new View;
    this->m = new MainWindow;
    this->t = new Timer;

    // 连接View页面的信号与Welcome页面的槽函数
    connect(v, &View::returnToWelcome, this, &Welcome::on_returnFromView);
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

void Welcome::on_returnFromView()
{
    this->show();
    v->hide();
}

void Welcome::on_pushButton_7_clicked()
{
    m->show();
}

void Welcome::on_pushButton_8_clicked()
{
    t->show();
}
