#include "window.h"
#include "ui_window.h"

window::window(QWidget* parent) :
    QMainWindow(parent),
    ui(new Ui::window)
{
    ui->setupUi(this);
    m_ptrWelcome = new Welcome;
}

window::~window()
{
    delete ui;
    delete m_ptrWelcome;
}

void window::on_pushButton_clicked()
{
    QString strText = ui->lineEdit->text();
    m_ptrWelcome->setStrText(strText); //让我们显示label显示内容
    //显示主界面
    m_ptrWelcome->show();
    //关闭登录界面
    this->close();
}
