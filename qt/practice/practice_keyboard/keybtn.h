#ifndef KEYBTN_H
#define KEYBTN_H

#include <QPushButton>
#include <QApplication>
#include <QKeyEvent>


class KeyBtn : public QPushButton
{
public:
    explicit KeyBtn(QWidget *parent = nullptr);
    explicit KeyBtn(const QString &text, QWidget *parent = nullptr);
    KeyBtn(const QIcon& icon, const QString &text, QWidget *parent = nullptr);

private slots:
    void btn_click();
};

#endif // KEYBTN_H
