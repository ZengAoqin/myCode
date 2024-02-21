#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    m_filePath = "";
}

MainWindow::~MainWindow()
{
    delete ui;
}

//打开文件
void MainWindow::on_actionaction_triggered()
{
    //文件类型
    QString filter = "*.txt *.c *.cpp *.h";
    m_filePath = QFileDialog::getOpenFileName(this, "选择文件", "./", filter);

    if(m_filePath.isEmpty())
    {
        return;
    }

    //任务栏显示路径
    ui->statusbar->showMessage(m_filePath);

    //获取文件名
    QFileInfo info(m_filePath);
    QString fileName = info.fileName();
    //新建文件对象
    QFile file(m_filePath);
    //打开设置权限
    file.open(QIODevice::ReadOnly);
    //读取文件
    QString text = file.readAll();
    //关闭文件
    file.close();

    ui->textEdit->setText(text);
}

//保存
void MainWindow::on_actionsave_triggered()
{
    //新建文件对象
    QFile file(m_filePath);
    //打开设置权限
    file.open(QIODevice::WriteOnly);
    //获得写入数据
    QString text = ui->textEdit->toPlainText();
    //写入文件
    file.write(text.toUtf8());
    //关闭文件
    file.close();
}

//另存为
void MainWindow::on_actionsaveas_triggered()
{
    QString filename = QFileDialog::getSaveFileName(this);
    //新建文件对象
    QFile file(filename);
    //打开设置权限
    file.open(QIODevice::WriteOnly);
    //获得写入数据
    QString text = ui->textEdit->toPlainText();
    //写入文件
    file.write(text.toUtf8());
    //关闭文件
    file.close();
}

void MainWindow::on_actionquit_triggered()
{

}
