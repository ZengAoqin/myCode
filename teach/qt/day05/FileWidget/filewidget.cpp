#include "filewidget.h"
#include "ui_filewidget.h"

FileWidget::FileWidget(QWidget* parent) :
    QWidget(parent),
    ui(new Ui::FileWidget)
{
    ui->setupUi(this);
    m_filepaths.clear();
}

FileWidget::~FileWidget()
{
    delete ui;
}

void FileWidget::on_btnFile_clicked()
{
    //设定过滤器
    QString filter = QString("*.c *.cpp *.h *.txt *.pro");
    //打开多个文件
    m_filepaths = QFileDialog::getOpenFileNames(this, QString::fromLocal8Bit("选择文件"), ".", filter);

    //添加到listwidget控件
    int i = 0;
    QString filename;
    for(i = 0; i < m_filepaths.size(); ++i)
    {
        QFileInfo info(m_filepaths.at(i));
        filename = info.fileName(); //获取文件名
        ui->listWidget->addItem(filename);
    }
}

void FileWidget::on_listWidget_itemDoubleClicked(QListWidgetItem* item)
{
    Q_UNUSED(item)
    //获取条目所在行号
    int row = ui->listWidget->currentRow();
    // 文件操作
    QFile file(m_filepaths.at(row));
    file.open(QIODevice::ReadOnly);
    QString text = file.readAll();
    ui->textBrowser->setText(text);
    file.close();
}
