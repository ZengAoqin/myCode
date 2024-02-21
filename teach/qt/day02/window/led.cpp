#include "led.h"
#include "ui_led.h"

LED::LED(QWidget* parent) :
    QMainWindow(parent),
    ui(new Ui::LED)
{
    ui->setupUi(this);
}

LED::~LED()
{
    delete ui;
}

void LED::on_pushButton_clicked()
{
    emit returnBack();
}
