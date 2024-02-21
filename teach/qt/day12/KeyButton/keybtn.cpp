#include "keybtn.h"

//����ʵ�ָ���Ĺ��캯��
KeyBtn::KeyBtn(QWidget* parent):
    QPushButton(parent)
{
    //��clicked�ź���ۺ���btn_clk
    connect(this, &KeyBtn::clicked, this, &KeyBtn::btn_clk);
}

KeyBtn::KeyBtn(const QString& text, QWidget* parent):
    QPushButton(text, parent)
{
    //��clicked�ź���ۺ���btn_clk
    connect(this, &KeyBtn::clicked, this, &KeyBtn::btn_clk);
}

KeyBtn::KeyBtn(const QIcon& icon, const QString& text, QWidget* parent):
    QPushButton(icon, text, parent)
{
    //��clicked�ź���ۺ���btn_clk
    connect(this, &KeyBtn::clicked, this, &KeyBtn::btn_clk);
}

//�Զ���Ĳۺ�������ȡ�����ϵ��ַ�����
//����ť�����»ᷢclicked�ź� �����ۺ�����ȡ�ַ�
void KeyBtn::btn_clk()
{
    //��ȡ�����ϵ��ַ��� "A" 'A' '\0'
    QString ch = this->text();
    char c = ch[0].toLatin1();  //��Qt�ַ�ת��Ϊchar�ַ�
    //    char c = ch.at(0).toLatin1();
    //ʵ����һ�������¼���������Խ��ܰ��µ��¼�
    QKeyEvent* key = new QKeyEvent(QKeyEvent::KeyPress, c, Qt::NoModifier, ch);
    //���Ͱ����¼�
    QApplication::postEvent(QApplication::focusWidget(), key);
}
