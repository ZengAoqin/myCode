#include "keybtn.h"



KeyBtn::KeyBtn(QWidget *parent): QPushButton(parent)
{
    //绑定clicked信号与槽函数btn_clk
    connect(this, &KeyBtn::clicked, this, &KeyBtn::btn_click);
}

KeyBtn::KeyBtn(const QString &text, QWidget *parent): QPushButton(parent)
{
    //绑定clicked信号与槽函数btn_clk
    connect(this, &KeyBtn::clicked, this, &KeyBtn::btn_click);
}

KeyBtn::KeyBtn(const QIcon &icon, const QString &text, QWidget *parent): QPushButton(parent)
{
    //绑定clicked信号与槽函数btn_clk
    connect(this, &KeyBtn::clicked, this, &KeyBtn::btn_click);
}

//ui设置 focus不聚焦 提升为本类
//键盘按钮点击
void KeyBtn::btn_click()
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
