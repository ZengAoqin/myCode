#include "itemform.h"
#include "ui_itemform.h"

ItemForm::ItemForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ItemForm)
{
    ui->setupUi(this);
}

//设置自定义窗口条目的图片和消息
void ItemForm::setInfo(QString pic, QString info)
{
    //实例化类对象
    QPixmap pix(pic);
    //将显示的大小设置为label框的大小
    pix = pix.scaled(ui->label_img->size());
    //显示数据到label框上
    ui->label_img->setPixmap(pix);
    //显示数据到label文本
    ui->label_text->setText(info);
}

ItemForm::~ItemForm()
{
    delete ui;
}
