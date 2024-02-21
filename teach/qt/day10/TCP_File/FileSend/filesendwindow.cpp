#include "filesendwindow.h"
#include "ui_filesendwindow.h"

FileSendWindow::FileSendWindow(QWidget* parent) :
    QWidget(parent),
    ui(new Ui::FileSendWindow)
{
    ui->setupUi(this);
}

FileSendWindow::~FileSendWindow()
{
    delete ui;
}

//获取文件路径
void FileSendWindow::on_btnFile_clicked()
{

}
