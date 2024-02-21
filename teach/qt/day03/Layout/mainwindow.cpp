#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget* parent) :
    QWidget(parent),
    ui(new Ui::MainWindow),
    m_pCalc(new Calc)
{
    ui->setupUi(this);
    m_pCalc->hide();
    //����title����
    setWindowTitle(QString::fromLocal8Bit("������"));
}

MainWindow::~MainWindow()
{
    delete ui;
    delete m_pCalc;
}

void MainWindow::setNameText(const QString name)
{
    ui->label_Text->setText(QString::fromLocal8Bit("��ӭ") + name + QString::fromLocal8Bit("�û��ع�!"));
}

void MainWindow::on_btnCalc_clicked()
{
    //չʾ������
    m_pCalc->show();
    this->hide();
}
