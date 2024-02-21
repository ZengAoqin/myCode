#include "filetext.h"
#include "ui_filetext.h"
#include <QFileDialog>
#include <QDebug>

FileText::FileText(QWidget* parent) :
    QMainWindow(parent),
    ui(new Ui::FileText)
{
    ui->setupUi(this);
    m_filePath = "";
}

FileText::~FileText()
{
    delete ui;
}

//打开文件的槽函数
void FileText::on_actionopen_triggered()
{
    //设置文件过滤器
    QString filter = "*.txt *.c *.cpp *.h";
    //获取文件路径
    m_filePath = QFileDialog::getOpenFileName(this, QString::fromLocal8Bit("选择文件"), "./", filter);

    if(m_filePath.isEmpty())
    {
        return;
    }

    //获取文件名
    QFileInfo info(m_filePath);
    QString filename = info.fileName(); //获取文件名
    qDebug() << filename;

    //将整个文件路径放到任务栏
    ui->statusBar->showMessage(m_filePath);


    //1.通过文件路径实例化文件对象
    QFile file(m_filePath);
    //2.打开设置操作权限
    file.open(QIODevice::ReadOnly);
    //3.将读取的内容放置到text
    QString text = file.readAll();
    //4.在textEdit的控件上显示内容
    ui->textEdit->setText(text);
    //5.关闭文件
    file.close();
}

//保存
void FileText::on_actionsave_triggered()
{
    //1.通过文件路径实例化文件对象
    QFile file(m_filePath);
    //2.打开设置操作权限
    file.open(QIODevice::WriteOnly); //写入数据
    //3.准备要写入的数据
    QString text = ui->textEdit->toPlainText();
    //4.将内容写入到文件
    file.write(text.toUtf8());
    //5.关闭文件
    file.close();
}

//另存为
void FileText::on_actionsaveas_triggered()
{
    //需要重新选择保存的路径
    QString filename = QFileDialog::getSaveFileName(this);
    //1.通过文件路径实例化文件对象
    QFile file(filename);
    //2.打开设置操作权限
    file.open(QIODevice::WriteOnly); //写入数据
    //3.准备要写入的数据
    QString text = ui->textEdit->toPlainText();
    //4.将内容写入到文件
    file.write(text.toUtf8());
    //5.关闭文件
    file.close();
}

//退出
void FileText::on_actionquit_triggered()
{
    this->close();
}
