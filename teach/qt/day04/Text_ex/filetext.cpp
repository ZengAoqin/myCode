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
    //����tabWidget�ƶ�ģʽ��Ч
    ui->tabWidget->setMovable(true);
    //����tabWidget�ر�ģʽ��Ч
    ui->tabWidget->setTabsClosable(true);
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
    //ui->textEdit->setText(text);
    //5.�ر��ļ�
    file.close();

    //�����ı�����ʾ����
    QTextEdit* edit = new QTextEdit;
    edit->setText(text);

    //��Edit���ļ�·�����뵽��������ʹ��
    m_edits.insert(edit, m_filePath);
    //��Edit��ӵ�tabwidget��Ӧ�Ŀؼ����ź�
    int index = ui->tabWidget->addTab(edit, filename);
    //���õ�ǰ�ؼ�
    ui->tabWidget->setCurrentIndex(index);
}

//����
void FileText::on_actionsave_triggered()
{
    //��ȡѡ��Ĵ��ڣ���ȡ������ı���
    QTextEdit* edit = dynamic_cast<QTextEdit*>(ui->tabWidget->currentWidget());
    //1.ͨ���ļ�·��ʵ�����ļ�����
    QString filePath = m_edits.value(edit);
    QFile file(filePath);
    //    QFile file(m_filePath);
    //2.�����ò���Ȩ��
    file.open(QIODevice::WriteOnly); //д������
    //3.׼��Ҫд�������
    QString text = edit->toPlainText();
    //4.������д�뵽�ļ�
    file.write(text.toUtf8());
    //5.�ر��ļ�
    file.close();
}

//���Ϊ
void FileText::on_actionsaveas_triggered()
{
    QTextEdit* edit = dynamic_cast<QTextEdit*>(ui->tabWidget->currentWidget());
    //��Ҫ����ѡ�񱣴��·��
    QString filename = QFileDialog::getSaveFileName(this);
    //1.ͨ���ļ�·��ʵ�����ļ�����
    QFile file(filename);
    //2.�����ò���Ȩ��
    file.open(QIODevice::WriteOnly); //д������
    //3.׼��Ҫд�������
    QString text = edit->toPlainText();
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

//�ر�tabwidget�����Ĵ���
void FileText::on_tabWidget_tabCloseRequested(int index)
{
    //��Ϣ����
    int ret = QMessageBox::information(this, QString::fromLocal8Bit("��ʾ"), QString::fromLocal8Bit("�Ƿ񱣴��ļ�"),
                                       QMessageBox::Yes, QMessageBox::No);
    //��������������ȡ���ڶ���
    QTextEdit* edit = dynamic_cast<QTextEdit*>(ui->tabWidget->widget(index));

    if(ret == QMessageBox::Yes)
    {
        //1.ͨ���ļ�·��ʵ�����ļ�����
        //edit
        QString filePath = m_edits.value(edit);
        QFile file(filePath);
        //        QFile file(m_filePath);
        //2.�����ò���Ȩ��
        file.open(QIODevice::WriteOnly); //д������
        //3.׼��Ҫд�������
        QString text = edit->toPlainText();
        //4.������д�뵽�ļ�
        file.write(text.toUtf8());
        //5.�ر��ļ�
        file.close();
    }

    //��ȡ��ǰ���ڲ����Ĵ��ڵ�������
    ui->tabWidget->removeTab(index);

    m_edits.remove(edit); //��������ɾ������
    delete edit; //�ͷű༭���ָ��
}

//��������
void FileText::on_actionfont_triggered()
{
    //ͨ������Ի����ȡ������Ķ���
    bool ok = false;
    QFont font = QFontDialog::getFont(&ok, this);
    if(ok)
    {
        //��ȡѡ��Ĵ��ڣ���ȡ������ı���
        QTextEdit* edit = dynamic_cast<QTextEdit*>(ui->tabWidget->currentWidget());
        edit->setFont(font);
    }
}

//������ɫ
void FileText::on_actioncolor_triggered()
{
    //��ȡѡ��Ĵ��ڣ���ȡ������ı���
    QTextEdit* edit = dynamic_cast<QTextEdit*>(ui->tabWidget->currentWidget());

    //��ȡ��ǰ�ؼ�����ɫ
    QColor oldFont = edit->palette().color(QPalette::Text); //��ȡ�ı���ɫ
    QColor oldbg = edit->palette().background().color(); //��ȡ����ɫ
    //ͨ��QColorDialog��ȡ��ɫ
    QColor color = QColorDialog::getColor(oldbg, this, QString::fromLocal8Bit("ѡ�񱳾�ɫ"));
    QColor old = QColorDialog::getColor(oldFont, this, QString::fromLocal8Bit("ѡ������ɫ"));
    //�����ɫ���ɵ���ʽ
    QString qss = QString("color:%1;background-color:%2;").arg(old.name()).arg(color.name());

    //�������ļ���ɫ
    edit->setStyleSheet(qss);
}
