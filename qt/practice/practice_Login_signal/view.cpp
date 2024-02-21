#include "view.h"
#include "ui_view.h"
#include "welcome.h"


View::View(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::View)
{
    ui->setupUi(this);
}

View::~View()
{
    delete ui;
}

void View::on_pushButton_clicked()
{
    // 触发返回到Welcome页面的信号
    emit returnToWelcome();
}
