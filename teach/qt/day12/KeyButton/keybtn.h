#ifndef KEYBTN_H
#define KEYBTN_H
#include <QPushButton>      //按钮类
#include <QApplication>     //应用程序管理类
#include <QKeyEvent>        //键盘类

class KeyBtn : public QPushButton
{
public:
    explicit KeyBtn(QWidget* parent = nullptr);
    explicit KeyBtn(const QString& text, QWidget* parent = nullptr);
    KeyBtn(const QIcon& icon, const QString& text, QWidget* parent = nullptr);
    ~KeyBtn() {}
    //自定义槽函数实现控制
private slots:
    void btn_clk();
};

#endif // KEYBTN_H
