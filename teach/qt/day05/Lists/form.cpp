#include "form.h"
#include "ui_form.h"

Form::Form(QWidget* parent) :
    QWidget(parent),
    ui(new Ui::Form)
{
    ui->setupUi(this);
}

//�����Զ��崰����Ŀ��ͼƬ����Ϣ
void Form::setInfo(QString pic, QString info)
{
    //ʵ���������
    QPixmap pix(pic);
    //����ʾ�Ĵ�С����Ϊlabel��Ĵ�С
    pix = pix.scaled(ui->labelimg->size());
    //��ʾ���ݵ�label����
    ui->labelimg->setPixmap(pix);
    //��ʾ���ݵ�label�ı�
    ui->labelText->setText(info);
}

Form::~Form()
{
    delete ui;
}
