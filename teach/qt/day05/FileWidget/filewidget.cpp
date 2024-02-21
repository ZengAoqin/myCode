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
    //�趨������
    QString filter = QString("*.c *.cpp *.h *.txt *.pro");
    //�򿪶���ļ�
    m_filepaths = QFileDialog::getOpenFileNames(this, QString::fromLocal8Bit("ѡ���ļ�"), ".", filter);

    //��ӵ�listwidget�ؼ�
    int i = 0;
    QString filename;
    for(i = 0; i < m_filepaths.size(); ++i)
    {
        QFileInfo info(m_filepaths.at(i));
        filename = info.fileName(); //��ȡ�ļ���
        ui->listWidget->addItem(filename);
    }
}

void FileWidget::on_listWidget_itemDoubleClicked(QListWidgetItem* item)
{
    Q_UNUSED(item)
    //��ȡ��Ŀ�����к�
    int row = ui->listWidget->currentRow();
    // �ļ�����
    QFile file(m_filepaths.at(row));
    file.open(QIODevice::ReadOnly);
    QString text = file.readAll();
    ui->textBrowser->setText(text);
    file.close();
}
