#ifndef WINDOW_H
#define WINDOW_H

#include <QMainWindow>
#include "welcome.h"

namespace Ui
{
class window;
}

class window : public QMainWindow
{
    Q_OBJECT

public:
    explicit window(QWidget* parent = nullptr);
    ~window();

private slots:
    void on_pushButton_clicked();

private:
    Ui::window* ui;
    Welcome* m_ptrWelcome;
};

#endif // WINDOW_H
