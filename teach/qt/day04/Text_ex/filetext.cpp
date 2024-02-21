#include "filetext.h"
#include "ui_filetext.h"
#include <QFileDialog>
#include <QMessageBox>
#include <QDebug>
#include <QFontDialog>
#include <QColorDialog>

FileText::FileText(QWidget* parent) :
    QMainWindow(parent),
    ui(new Ui::FileText)
{
    ui->setupUi(this);
    m_filePath = "";
    //设置tabWidget移动模式有效
    ui->tabWidget->setMovable(true);
    //设置tabWidget关闭模式有效
    ui->tabWidget->setTabsClosable(true);
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
    //ui->textEdit->setText(text);
    //5.关闭文件
    file.close();

    //定义文本框显示数据
    QTextEdit* edit = new QTextEdit;
    edit->setText(text);

    //把Edit和文件路径加入到容器里面使用
    m_edits.insert(edit, m_filePath);
    //把Edit添加到tabwidget对应的控件索信号
    int index = ui->tabWidget->addTab(edit, filename);
    //设置当前控件
    ui->tabWidget->setCurrentIndex(index);
}

//保存
void FileText::on_actionsave_triggered()
{
    //获取选择的窗口，获取里面的文本框
    QTextEdit* edit = dynamic_cast<QTextEdit*>(ui->tabWidget->currentWidget());
    //1.通过文件路径实例化文件对象
    QString filePath = m_edits.value(edit);
    QFile file(filePath);
    //    QFile file(m_filePath);
    //2.打开设置操作权限
    file.open(QIODevice::WriteOnly); //写入数据
    //3.准备要写入的数据
    QString text = edit->toPlainText();
    //4.将内容写入到文件
    file.write(text.toUtf8());
    //5.关闭文件
    file.close();
}

//另存为
void FileText::on_actionsaveas_triggered()
{
    QTextEdit* edit = dynamic_cast<QTextEdit*>(ui->tabWidget->currentWidget());
    //需要重新选择保存的路径
    QString filename = QFileDialog::getSaveFileName(this);
    //1.通过文件路径实例化文件对象
    QFile file(filename);
    //2.打开设置操作权限
    file.open(QIODevice::WriteOnly); //写入数据
    //3.准备要写入的数据
    QString text = edit->toPlainText();
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

//关闭tabwidget产生的窗口
void FileText::on_tabWidget_tabCloseRequested(int index)
{
    //消息盒子
    int ret = QMessageBox::information(this, QString::fromLocal8Bit("提示"), QString::fromLocal8Bit("是否保存文件"),
                                       QMessageBox::Yes, QMessageBox::No);
    //根据索引号来获取窗口对象
    QTextEdit* edit = dynamic_cast<QTextEdit*>(ui->tabWidget->widget(index));

    if(ret == QMessageBox::Yes)
    {
        //1.通过文件路径实例化文件对象
        //edit
        QString filePath = m_edits.value(edit);
        QFile file(filePath);
        //        QFile file(m_filePath);
        //2.打开设置操作权限
        file.open(QIODevice::WriteOnly); //写入数据
        //3.准备要写入的数据
        QString text = edit->toPlainText();
        //4.将内容写入到文件
        file.write(text.toUtf8());
        //5.关闭文件
        file.close();
    }

    //获取当前正在操作的窗口的索引号
    ui->tabWidget->removeTab(index);

    m_edits.remove(edit); //从容器中删除数据
    delete edit; //释放编辑框的指针
}

//字体设置
void FileText::on_actionfont_triggered()
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
void FileText::on_actioncolor_triggered()
{
    //获取选择的窗口，获取里面的文本框
    QTextEdit* edit = dynamic_cast<QTextEdit*>(ui->tabWidget->currentWidget());

    //获取当前控件的颜色
    QColor oldFont = edit->palette().color(QPalette::Text); //获取文本颜色
    QColor oldbg = edit->palette().background().color(); //获取背景色
    //通过QColorDialog获取颜色
    QColor color = QColorDialog::getColor(oldbg, this, QString::fromLocal8Bit("选择背景色"));
    QColor old = QColorDialog::getColor(oldFont, this, QString::fromLocal8Bit("选择字体色"));
    //打包颜色生成的样式
    QString qss = QString("color:%1;background-color:%2;").arg(old.name()).arg(color.name());

    //再设置文件颜色
    edit->setStyleSheet(qss);
}
