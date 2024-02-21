#ifndef MYKEYBOARD_H
#define MYKEYBOARD_H

#include <QWidget>

namespace Ui {
class MyKeyboard;
}

class MyKeyboard : public QWidget
{
    Q_OBJECT

public:
    explicit MyKeyboard(QWidget *parent = nullptr);
    ~MyKeyboard();

private:
    Ui::MyKeyboard *ui;
};

#endif // MYKEYBOARD_H
