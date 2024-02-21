#ifndef CALC_H
#define CALC_H

#include <QWidget>
#include <QButtonGroup>

namespace Ui
{
class Calc;
}

class Calc : public QWidget
{
    Q_OBJECT

public:
    explicit Calc(QWidget* parent = nullptr);
    ~Calc();

private slots:
    void num_button_clicked(int num);
    void calc_button_clicked(int calcType);

    void on_btnResult_clicked();

    void on_btnClear_clicked();

private:
    Ui::Calc* ui;
    QButtonGroup* m_pBtnGroup;      //数字按钮组指针
    QButtonGroup* m_pCalcBtnGroup;  //运算按钮指针
    QString m_num;                  //输入的数据
    QString m_sendNum;              //输入第二次数据
    int m_calc;                     //输入符号数据
};

#endif // CALC_H
