#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>
#include <QDebug>
#include <QMessageBox>
#include <QFontDialog>
#include <QColorDialog>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    m_filePath("")
{
    ui->setupUi(this);
    //设置tabWidget移动模式有效
    ui->tabWidget->setMovable(true);
    //设置tabWidget关闭模式有效
    ui->tabWidget->setTabsClosable(true);
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

    //定义文本框对象
    QTextEdit* edit = new QTextEdit();
    edit->setText(text);

    //把Edit和文件路径加入到容器里面使用
    m_edits.insert(edit, m_filePath);
    //把Edit添加到tabwidget对应的控件索信号
    int index = ui->tabWidget->addTab(edit, fileName);
    //设置当前控件
    ui->tabWidget->setCurrentIndex(index);
}

//保存
void MainWindow::on_actionsave_triggered()
{
    //获取选择的窗口，获取里面的文本框
    QTextEdit* edit = dynamic_cast<QTextEdit*>(ui->tabWidget->currentWidget());
    //新建文件对象
    QFile file(m_edits.value(edit));
    //打开设置权限
    file.open(QIODevice::WriteOnly);
    //获得写入数据
    QString text = edit->toPlainText();
    //写入文件
    file.write(text.toUtf8());
    //关闭文件
    file.close();
}

//另存为
void MainWindow::on_actionsaveas_triggered()
{
    //获取选择的窗口，获取里面的文本框
    QTextEdit* edit = dynamic_cast<QTextEdit*>(ui->tabWidget->currentWidget());
    QString filename = QFileDialog::getSaveFileName(this);
    //新建文件对象
    QFile file(filename);
    //打开设置权限
    file.open(QIODevice::WriteOnly);
    //获得写入数据
    QString text = edit->toPlainText();
    //写入文件
    file.write(text.toUtf8());
    //关闭文件
    file.close();
}

//退出
void MainWindow::on_actionquit_triggered()
{
    this->close();
}

//关闭tab
void MainWindow::on_tabWidget_tabCloseRequested(int index)
{
    //消息盒子
    int ret = QMessageBox::information(this, "提示", "是否保存文件", QMessageBox::Yes, QMessageBox::No);

    //获取文本对象
    QTextEdit* edit = dynamic_cast<QTextEdit*>(ui->tabWidget->widget(index));

    if(ret == QMessageBox::Yes)
    {
        //通过文件路径实例化文件对象
        QFile file(m_edits.value(edit));
        //打开设置操作权限
        file.open(QIODevice::WriteOnly); //写入数据
        //准备要写入的数据
        QString text = edit->toPlainText();
        //将内容写入到文件
        file.write(text.toUtf8());
        //关闭文件
        file.close();
    }

    //移除tab
    ui->tabWidget->removeTab(index);
    //map容器移除
    m_edits.remove(edit);
    delete edit;
}

//设置字体
void MainWindow::on_actionfont_triggered()
{
    //通过字体对话框获取字体类的对象
        bool ok = false;
        QFont font = QFontDialog::getFont(&ok, this);
        if(ok)
        {
            //获取选择的窗口，获取里面的文本框
            QTextEdit* edit = dynamic_cast<QTextEdit*>(ui->tabWidget->currentWidget());
            edit->setFont(font);
        }
}

//设置颜色
void MainWindow::on_actioncolor_triggered()
{
    //获取选择的窗口，获取里面的文本框
    QTextEdit* edit = dynamic_cast<QTextEdit*>(ui->tabWidget->currentWidget());

    //获取当前控件的颜色
    QColor oldFont = edit->palette().color(QPalette::Text); //获取文本颜色
    QColor oldbg = edit->palette().background().color(); //获取背景色

    //通过QColorDialog获取颜色
    QColor color = QColorDialog::getColor(oldbg, this, "选择背景色");
    QColor old = QColorDialog::getColor(oldFont, this, "选择字体色");

    //打包颜色生成的样式
    QString qss = QString("color:%1;background-color:%2;").arg(old.name()).arg(color.name());

    //再设置文件颜色
    edit->setStyleSheet(qss);
}
