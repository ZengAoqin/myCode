#include "filelist.h"
#include "ui_filelist.h"
#include <QFileDialog>


FileList::FileList(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::FileList)
{
    ui->setupUi(this);
}

FileList::~FileList()
{
    delete ui;
}

void FileList::on_pushButton_clicked()
{
//    QString filePath = QFileDialog::getOpenFileName(this, "选择文件");
    QString filter = QString("*.txt *.c *.cpp *.h");
    m_filePaths = QFileDialog::getOpenFileNames(this, "选择文件", ".", filter);

    for(int i = 0; i < m_filePaths.size(); ++i)
    {
        //获取文件名
        QFileInfo info(m_filePaths.at(i));
        QString fileName = info.fileName();
        //添加到listWidget
        ui->listWidget->addItem(fileName);
    }
}

void FileList::on_listWidget_itemClicked(QListWidgetItem *item)
{
    int row = ui->listWidget->currentRow();
    //新建文件对象
    QFile file(m_filePaths.at(row));
    //打开设置权限
    file.open(QIODevice::ReadOnly);
    //读取文件
    QString text = file.readAll();
    //关闭文件
    file.close();

    ui->textBrowser->setText(text);
}

void FileList::on_listWidget_itemDoubleClicked(QListWidgetItem *item)
{
    delete item;
}
