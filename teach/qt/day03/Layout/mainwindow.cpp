#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget* parent) :
    QWidget(parent),
    ui(new Ui::MainWindow),
    m_pCalc(new Calc)
{
    ui->setupUi(this);
    m_pCalc->hide();
    //设置title标题
    setWindowTitle(QString::fromLocal8Bit("主界面"));
}

MainWindow::~MainWindow()
{
    delete ui;
    delete m_pCalc;
}

void MainWindow::setNameText(const QString name)
{
    ui->label_Text->setText(QString::fromLocal8Bit("欢迎") + name + QString::fromLocal8Bit("用户回归!"));
}

void MainWindow::on_btnCalc_clicked()
{
    //展示计算器
    m_pCalc->show();
    this->hide();
}
