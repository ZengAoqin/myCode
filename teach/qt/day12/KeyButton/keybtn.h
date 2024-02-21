#ifndef KEYBTN_H
#define KEYBTN_H
#include <QPushButton>      //��ť��
#include <QApplication>     //Ӧ�ó��������
#include <QKeyEvent>        //������

class KeyBtn : public QPushButton
{
public:
    explicit KeyBtn(QWidget* parent = nullptr);
    explicit KeyBtn(const QString& text, QWidget* parent = nullptr);
    KeyBtn(const QIcon& icon, const QString& text, QWidget* parent = nullptr);
    ~KeyBtn() {}
    //�Զ���ۺ���ʵ�ֿ���
private slots:
    void btn_clk();
};

#endif // KEYBTN_H
