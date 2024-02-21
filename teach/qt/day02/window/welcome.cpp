#include "welcome.h"
#include "ui_welcome.h"

Welcome::Welcome(QWidget* parent) :
    QMainWindow(parent),
    ui(new Ui::Welcome)
{
    ui->setupUi(this);
    m_strText = "";
    m_ptrLED = new LED(this);
    connect(m_ptrLED, &LED::returnBack, this, &Welcome::on_backUp);
}

Welcome::~Welcome()
{
    delete ui;
    delete m_ptrLED;
}

void Welcome::setStrText(const QString strText)
{
    m_strText = strText;
    ui->label_text->setText(m_strText);
}

void Welcome::on_pushButton_clicked()
{
    //显示子界面
    m_ptrLED->show();
    //隐藏主界面
    this->hide();
}

void Welcome::on_backUp()
{
    //主界面显示
    this->show();
    //子界面隐藏
    m_ptrLED->hide();
}
