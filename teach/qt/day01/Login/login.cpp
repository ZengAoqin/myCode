#include "login.h"
#include "ui_login.h"

Login::Login(QWidget* parent) :
    QWidget(parent),
    ui(new Ui::Login)
{
    ui->setupUi(this);
    //    ui->label_image->setStyleSheet(QString("QLabel{   \
    //                                           border:2px solid#ff0000; \
    //                                           border-radius:60px;\
    //                                           border-image: url(:/image/1.jpg); \
    //                                           }"));
}

Login::~Login()
{
    delete ui;
}
