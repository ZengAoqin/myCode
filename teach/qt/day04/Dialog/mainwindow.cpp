#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>
#include <QColorDialog>
#include <QFontDialog>
#include <QInputDialog>
#include <QDebug>

MainWindow::MainWindow(QWidget* parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_btnFile_clicked() //自定槽函数
{
    //默认路径
    QString filepath = "C:/Users/RD/Desktop/Share/QT/day03/Layout";
    //过滤器
    QString filter = "select file(*.cpp *.h *.pro)";
    //通过文件对话框获取文件路径
    QString filename = QFileDialog::getOpenFileName(this, QString::fromLocal8Bit("选择文件"),
                       filepath, filter);
    //将获取文件路径显示label上
    ui->label->setText(filename);
    //在任务栏显示路径
    ui->statusBar->showMessage(filename);
}

void MainWindow::on_btnColor_clicked()
{
    //通过颜色对话框获取选择颜色
    QColor color = QColorDialog::getColor(Qt::red, this, QString::fromLocal8Bit("调色板"));
    //准备背景样式
    QString qss = QString("background-color: %1").arg(color.name());
    //设置label的背景颜色
    ui->label->setStyleSheet(qss);
}

void MainWindow::on_btnFont_clicked()
{
    bool ok = false;
    //获取字体对话框
    QFont font = QFontDialog::getFont(&ok, this);
    if(ok) //如果为真 就设置字体
    {
        ui->label->setFont(font);
    }
}

void MainWindow::on_btnInput_clicked()
{
    //获取输入框的内容
    QString strText = QInputDialog::getText(this, QString::fromLocal8Bit("信息录入"),
                                            QString::fromLocal8Bit("请输入姓名"), QLineEdit::PasswordEchoOnEdit);
    //显示在label
    ui->label->setText(strText);
}

void MainWindow::on_btnDialog_clicked()
{
    //实例化对话框的对象
    QDialog dialog;
    dialog.setWindowTitle(QString::fromLocal8Bit("自定义对话框")); //设置标题
    dialog.resize(200, 100); //设置控件宽和高

    //创建按钮对象
    QPushButton yesBt(QString::fromLocal8Bit("是"), &dialog);
    yesBt.setGeometry(0, 40, 100, 40);
    QPushButton noBt(QString::fromLocal8Bit("否"), &dialog);
    noBt.setGeometry(100, 40, 100, 40);
    //绑定按钮对象和自定义对话框
    connect(&yesBt, &QPushButton::clicked, &dialog, &QDialog::accept);
    connect(&noBt, &QPushButton::clicked, &dialog, &QDialog::reject);
    //执行
    int ret = dialog.exec();
    if(QDialog::Accepted == ret)
    {
        qDebug() << QString::fromLocal8Bit("点击是") << endl;
    }
    else if(QDialog::Rejected == ret)
    {
        qDebug() << QString::fromLocal8Bit("点击否") << endl;
        //dialog.close();
    }
}
