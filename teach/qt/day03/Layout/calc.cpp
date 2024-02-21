#include "calc.h"
#include "ui_calc.h"
#include <QDebug>

Calc::Calc(QWidget* parent) :
    QWidget(parent),
    ui(new Ui::Calc),
    m_pBtnGroup(new QButtonGroup),
    m_pCalcBtnGroup(new QButtonGroup)
{
    ui->setupUi(this);
    setWindowTitle(QString::fromLocal8Bit("������"));
    m_num = "";
    m_sendNum = "";
    m_calc = 0;
    m_pBtnGroup->addButton(ui->btn0, 0);
    m_pBtnGroup->addButton(ui->btn1, 1);
    m_pBtnGroup->addButton(ui->btn2, 2);
    m_pBtnGroup->addButton(ui->btn3, 3);
    m_pBtnGroup->addButton(ui->btn4, 4);
    m_pBtnGroup->addButton(ui->btn5, 5);
    m_pBtnGroup->addButton(ui->btn6, 6);
    m_pBtnGroup->addButton(ui->btn7, 7);
    m_pBtnGroup->addButton(ui->btn8, 8);
    m_pBtnGroup->addButton(ui->btn9, 9);

    m_pCalcBtnGroup->addButton(ui->btnAdd, 1);
    m_pCalcBtnGroup->addButton(ui->btnSub, 2);
    m_pCalcBtnGroup->addButton(ui->btnMul, 3);
    m_pCalcBtnGroup->addButton(ui->btnDiv, 4);

    //���ְ�ť���µ��ź���ۺ����İ�
    connect(m_pBtnGroup, SIGNAL(buttonClicked(int)), this, SLOT(num_button_clicked(int)));
    connect(m_pCalcBtnGroup, SIGNAL(buttonClicked(int)), this, SLOT(calc_button_clicked(int)));
}

//��ʵ�ۺ���
void Calc::num_button_clicked(int num)
{
    qDebug() << num;
    if(m_calc == 0)
    {
        m_num.append(QString::number(num));
        ui->lineEdit->setText(m_num);
    }
    else
    {
        QString strText = m_num;
        m_sendNum.append(QString::number(num));
        switch(m_calc)
        {
            case 1: //�Ӻ�
            {
                strText.append("+");
                break;
            }
            case 2: //����
            {
                strText.append("-");
                break;
            }
            case 3: //�˷�
            {
                strText.append("*");
                break;
            }
            case 4: //����
            {
                strText.append("/");
                break;
            }
            default:
                break;
        }
        strText.append(m_sendNum);
        ui->lineEdit->setText(strText);
    }
}

//ʵ��������ţ�+ - * /���Ĳۺ���
void Calc::calc_button_clicked(int calcType)
{
    m_calc = calcType;
    QString strText = m_num;
    switch(m_calc)
    {
        case 1: //�Ӻ�
        {
            strText.append("+");
            break;
        }
        case 2: //����
        {
            strText.append("-");
            break;
        }
        case 3: //�˷�
        {
            strText.append("*");
            break;
        }
        case 4: //����
        {
            strText.append("/");
            break;
        }
        default:
            break;
    }
    ui->lineEdit->setText(strText);
}

Calc::~Calc()
{
    delete ui;
    delete m_pBtnGroup;
    delete m_pCalcBtnGroup;
}

//������
void Calc::on_btnResult_clicked()
{
    QString strResult;
    int nResult;
    QString calc;
    switch(m_calc)
    {
        case 1: //��
        {
            nResult = m_num.toInt() + m_sendNum.toInt();
            calc = "+";
            break;
        }
        case 2: //��
        {
            nResult = m_num.toInt() - m_sendNum.toInt();
            calc = "-";
            break;
        }
        case 3: //��
        {
            nResult = m_num.toInt() * m_sendNum.toInt();
            calc = "*";
            break;
        }
        case 4: //��
        {
            nResult = m_num.toInt() / m_sendNum.toInt();
            calc = "/";
            break;
        }
        default:
        {
            nResult = 0; // ��Чֵ
            break;
        }
    }
    //��ʾ���ݼ���
    strResult = m_num + calc + m_sendNum + "=" + QString::number(nResult);
    ui->lineEdit->setText(strResult);
}

void Calc::on_btnClear_clicked()
{
    ui->lineEdit->clear();
    m_num.clear();
    m_sendNum.clear();
    m_calc = 0;
}
