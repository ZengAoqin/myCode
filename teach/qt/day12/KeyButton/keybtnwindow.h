#ifndef KEYBTNWINDOW_H
#define KEYBTNWINDOW_H

#include <QWidget>

namespace Ui {
class KeyBtnWindow;
}

class KeyBtnWindow : public QWidget
{
    Q_OBJECT

public:
    explicit KeyBtnWindow(QWidget *parent = nullptr);
    ~KeyBtnWindow();

private:
    Ui::KeyBtnWindow *ui;
};

#endif // KEYBTNWINDOW_H
