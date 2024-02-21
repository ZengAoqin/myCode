#include "keybtnwindow.h"
#include "ui_keybtnwindow.h"

KeyBtnWindow::KeyBtnWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::KeyBtnWindow)
{
    ui->setupUi(this);
}

KeyBtnWindow::~KeyBtnWindow()
{
    delete ui;
}
