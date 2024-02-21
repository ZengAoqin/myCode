#include "welcome.h"
#include "ui_welcome.h"
#include "login.h"
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

void Welcome::on_pushButton_2_clicked()
{
    QString filename = QFileDialog::getOpenFileName(this, "选择文件");
    ui->label_5->setText(filename);
}

void Welcome::on_pushButton_3_clicked()
{
    QColor color = QColorDialog::getColor(Qt::red, this, "调色板");
    QString qss = QString("background-color:%1").arg(color.name());
    ui->label_5->setStyleSheet(qss);
}

void Welcome::on_pushButton_4_clicked()
{
    bool ok = false;
    QFont font = QFontDialog::getFont(&ok, this);
    if(ok)
    {
        ui->label_5->setFont(font);
    }
}

void Welcome::on_pushButton_5_clicked()
{
    QString input = QInputDialog::getText(this, "文本输入", "请输入：", QLineEdit::Normal);
    ui->label_5->setText(input);
}

void Welcome::on_pushButton_6_clicked()
{
    QDialog dialog;
    dialog.setWindowTitle("对话框");
    dialog.resize(400, 200);

    QPushButton yesBtn("确定", &dialog);
    yesBtn.setGeometry(50, 100, 100, 50);

    connect(&yesBtn, &QPushButton::clicked, &dialog, &QDialog::accept);

    int ret = dialog.exec();
    if(ret == QDialog::Accepted)
    {
        qDebug() << "yes";
    }

}

void Welcome::on_pushButton_7_clicked()
{
    m->show();
    this->hide();
}
