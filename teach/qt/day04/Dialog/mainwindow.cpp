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

void MainWindow::on_btnFile_clicked() //�Զ��ۺ���
{
    //Ĭ��·��
    QString filepath = "C:/Users/RD/Desktop/Share/QT/day03/Layout";
    //������
    QString filter = "select file(*.cpp *.h *.pro)";
    //ͨ���ļ��Ի����ȡ�ļ�·��
    QString filename = QFileDialog::getOpenFileName(this, QString::fromLocal8Bit("ѡ���ļ�"),
                       filepath, filter);
    //����ȡ�ļ�·����ʾlabel��
    ui->label->setText(filename);
    //����������ʾ·��
    ui->statusBar->showMessage(filename);
}

void MainWindow::on_btnColor_clicked()
{
    //ͨ����ɫ�Ի����ȡѡ����ɫ
    QColor color = QColorDialog::getColor(Qt::red, this, QString::fromLocal8Bit("��ɫ��"));
    //׼��������ʽ
    QString qss = QString("background-color: %1").arg(color.name());
    //����label�ı�����ɫ
    ui->label->setStyleSheet(qss);
}

void MainWindow::on_btnFont_clicked()
{
    bool ok = false;
    //��ȡ����Ի���
    QFont font = QFontDialog::getFont(&ok, this);
    if(ok) //���Ϊ�� ����������
    {
        ui->label->setFont(font);
    }
}

void MainWindow::on_btnInput_clicked()
{
    //��ȡ����������
    QString strText = QInputDialog::getText(this, QString::fromLocal8Bit("��Ϣ¼��"),
                                            QString::fromLocal8Bit("����������"), QLineEdit::PasswordEchoOnEdit);
    //��ʾ��label
    ui->label->setText(strText);
}

void MainWindow::on_btnDialog_clicked()
{
    //ʵ�����Ի���Ķ���
    QDialog dialog;
    dialog.setWindowTitle(QString::fromLocal8Bit("�Զ���Ի���")); //���ñ���
    dialog.resize(200, 100); //���ÿؼ���͸�

    //������ť����
    QPushButton yesBt(QString::fromLocal8Bit("��"), &dialog);
    yesBt.setGeometry(0, 40, 100, 40);
    QPushButton noBt(QString::fromLocal8Bit("��"), &dialog);
    noBt.setGeometry(100, 40, 100, 40);
    //�󶨰�ť������Զ���Ի���
    connect(&yesBt, &QPushButton::clicked, &dialog, &QDialog::accept);
    connect(&noBt, &QPushButton::clicked, &dialog, &QDialog::reject);
    //ִ��
    int ret = dialog.exec();
    if(QDialog::Accepted == ret)
    {
        qDebug() << QString::fromLocal8Bit("�����") << endl;
    }
    else if(QDialog::Rejected == ret)
    {
        qDebug() << QString::fromLocal8Bit("�����") << endl;
        //dialog.close();
    }
}
