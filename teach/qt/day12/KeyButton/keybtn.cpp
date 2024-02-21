#include "keybtn.h"

//子类实现父类的构造函数
KeyBtn::KeyBtn(QWidget* parent):
    QPushButton(parent)
{
    //绑定clicked信号与槽函数btn_clk
    connect(this, &KeyBtn::clicked, this, &KeyBtn::btn_clk);
}

KeyBtn::KeyBtn(const QString& text, QWidget* parent):
    QPushButton(text, parent)
{
    //绑定clicked信号与槽函数btn_clk
    connect(this, &KeyBtn::clicked, this, &KeyBtn::btn_clk);
}

KeyBtn::KeyBtn(const QIcon& icon, const QString& text, QWidget* parent):
    QPushButton(icon, text, parent)
{
    //绑定clicked信号与槽函数btn_clk
    connect(this, &KeyBtn::clicked, this, &KeyBtn::btn_clk);
}

//自定义的槽函数，获取按键上的字符数据
//当按钮被按下会发clicked信号 触发槽函数获取字符
void KeyBtn::btn_clk()
{
    //获取键盘上的字符串 "A" 'A' '\0'
    QString ch = this->text();
    char c = ch[0].toLatin1();  //将Qt字符转化为char字符
    //    char c = ch.at(0).toLatin1();
    //实例化一个按键事件，界面可以接受按下的事件
    QKeyEvent* key = new QKeyEvent(QKeyEvent::KeyPress, c, Qt::NoModifier, ch);
    //发送按键事件
    QApplication::postEvent(QApplication::focusWidget(), key);
}
