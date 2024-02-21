#ifndef WELCOME_H
#define WELCOME_H

#include <QMainWindow>
#include "led.h"

namespace Ui
{
class Welcome;
}

class Welcome : public QMainWindow
{
    Q_OBJECT

public:
    explicit Welcome(QWidget* parent = nullptr);
    ~Welcome();
    //…Ë÷√œ‘ æ
    void setStrText(const QString strText);

private slots:
    void on_pushButton_clicked();
    void on_backUp();

private:
    Ui::Welcome* ui;
    QString m_strText;
    LED* m_ptrLED;
};

#endif // WELCOME_H
