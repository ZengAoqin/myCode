#include "form.h"
#include "ui_form.h"

Form::Form(QWidget* parent) :
    QWidget(parent),
    ui(new Ui::Form)
{
    ui->setupUi(this);
}

//设置自定义窗口条目的图片和消息
void Form::setInfo(QString pic, QString info)
{
    //实例化类对象
    QPixmap pix(pic);
    //将显示的大小设置为label框的大小
    pix = pix.scaled(ui->labelimg->size());
    //显示数据到label框上
    ui->labelimg->setPixmap(pix);
    //显示数据到label文本
    ui->labelText->setText(info);
}

Form::~Form()
{
    delete ui;
}
