#include "view.h"
#include "ui_view.h"
#include "welcome.h"
#include <QDebug>


View::View(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::View),
    m_pBtnGroup(new QButtonGroup),
    m_pCalBtnGroup(new QButtonGroup)
{
    ui->setupUi(this);

    m_firstNum = "";
    m_secondNum = "";
    m_text = "";
    m_cal = 0;

    m_pBtnGroup->addButton(ui->pb_0, 0);
    m_pBtnGroup->addButton(ui->pb_1, 1);
    m_pBtnGroup->addButton(ui->pb_2, 2);
    m_pBtnGroup->addButton(ui->pb_3, 3);
    m_pBtnGroup->addButton(ui->pb_4, 4);
    m_pBtnGroup->addButton(ui->pb_5, 5);
    m_pBtnGroup->addButton(ui->pb_6, 6);
    m_pBtnGroup->addButton(ui->pb_7, 7);
    m_pBtnGroup->addButton(ui->pb_8, 8);
    m_pBtnGroup->addButton(ui->pb_9, 9);

    m_pCalBtnGroup->addButton(ui->pb_add, 1);
    m_pCalBtnGroup->addButton(ui->pb_min, 2);
    m_pCalBtnGroup->addButton(ui->pb_mul, 3);
    m_pCalBtnGroup->addButton(ui->pb_div, 4);

    //信号与槽函数的绑定
    connect(m_pBtnGroup, SIGNAL(buttonClicked(int)), this, SLOT(num_button_clicked(int)));
    connect(m_pCalBtnGroup, SIGNAL(buttonClicked(int)), this, SLOT(calc_button_clicked(int)));
}

View::~View()
{
    delete ui;
    delete m_pBtnGroup;
    delete m_pCalBtnGroup;
}

void View::on_pushButton_clicked()
{
    // 触发返回到Welcome页面的信号
    emit returnToWelcome();
}

void View::num_button_clicked(int num)
{
    qDebug() << "num:" << num;

    if(m_cal == 0)      //第一个数
    {
        m_firstNum.append(QString::number(num));
        m_text = m_firstNum;
        ui->lineEdit->setText(m_text);
    }
    else                //第二个数
    {
        m_secondNum.append(QString::number(num));
        m_text.append(QString::number(num));
        ui->lineEdit->setText(m_text);
    }
}

void View::calc_button_clicked(int num)
{
    qDebug() << "num:" << num;

    if(m_cal != 0)
    {
        m_firstNum = QString::number(on_pb_equal_clicked());
        m_text.append(m_firstNum);
    }

    m_cal = num;
    switch (m_cal)
    {
        case 1:
        {
            m_text.append("+");
            break;
        }
        case 2:
        {
            m_text.append("-");
            break;
        }
        case 3:
        {
            m_text.append("*");
            break;
        }
        case 4:
        {
            m_text.append("/");
            break;
        }
    }
    ui->lineEdit->setText(m_text);
}

void View::on_pb_clear_clicked()
{
    ui->lineEdit->clear();
    m_firstNum.clear();
    m_secondNum.clear();
    m_text.clear();
    m_cal = 0;
}

int View::on_pb_equal_clicked()
{
    int result = 0;
    switch (m_cal)
    {
        case 1:
        {
            result = m_firstNum.toInt() + m_secondNum.toInt();
            break;
        }
        case 2:
        {
            result = m_firstNum.toInt() - m_secondNum.toInt();
            break;
        }
        case 3:
        {
            result = m_firstNum.toInt() * m_secondNum.toInt();
            break;
        }
        case 4:
        {
            result = m_firstNum.toInt() / m_secondNum.toInt();
            break;
        }
    }
    ui->lineEdit->setText(QString::number(result));
    m_firstNum.clear();
    m_secondNum.clear();
    m_text.clear();
    m_cal = 0;

    return result;
}
