#include "mykeyboard.h"
#include "ui_mykeyboard.h"

MyKeyboard::MyKeyboard(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MyKeyboard)
{
    ui->setupUi(this);
}

MyKeyboard::~MyKeyboard()
{
    delete ui;
}
