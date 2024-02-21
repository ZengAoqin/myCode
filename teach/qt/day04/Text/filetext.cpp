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

//���ļ��Ĳۺ���
void FileText::on_actionopen_triggered()
{
    //�����ļ�������
    QString filter = "*.txt *.c *.cpp *.h";
    //��ȡ�ļ�·��
    m_filePath = QFileDialog::getOpenFileName(this, QString::fromLocal8Bit("ѡ���ļ�"), "./", filter);

    if(m_filePath.isEmpty())
    {
        return;
    }

    //��ȡ�ļ���
    QFileInfo info(m_filePath);
    QString filename = info.fileName(); //��ȡ�ļ���
    qDebug() << filename;

    //�������ļ�·���ŵ�������
    ui->statusBar->showMessage(m_filePath);


    //1.ͨ���ļ�·��ʵ�����ļ�����
    QFile file(m_filePath);
    //2.�����ò���Ȩ��
    file.open(QIODevice::ReadOnly);
    //3.����ȡ�����ݷ��õ�text
    QString text = file.readAll();
    //4.��textEdit�Ŀؼ�����ʾ����
    ui->textEdit->setText(text);
    //5.�ر��ļ�
    file.close();
}

//����
void FileText::on_actionsave_triggered()
{
    //1.ͨ���ļ�·��ʵ�����ļ�����
    QFile file(m_filePath);
    //2.�����ò���Ȩ��
    file.open(QIODevice::WriteOnly); //д������
    //3.׼��Ҫд�������
    QString text = ui->textEdit->toPlainText();
    //4.������д�뵽�ļ�
    file.write(text.toUtf8());
    //5.�ر��ļ�
    file.close();
}

//����Ϊ
void FileText::on_actionsaveas_triggered()
{
    //��Ҫ����ѡ�񱣴��·��
    QString filename = QFileDialog::getSaveFileName(this);
    //1.ͨ���ļ�·��ʵ�����ļ�����
    QFile file(filename);
    //2.�����ò���Ȩ��
    file.open(QIODevice::WriteOnly); //д������
    //3.׼��Ҫд�������
    QString text = ui->textEdit->toPlainText();
    //4.������д�뵽�ļ�
    file.write(text.toUtf8());
    //5.�ر��ļ�
    file.close();
}

//�˳�
void FileText::on_actionquit_triggered()
{
    this->close();
}