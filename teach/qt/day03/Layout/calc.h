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
    QButtonGroup* m_pBtnGroup;      //���ְ�ť��ָ��
    QButtonGroup* m_pCalcBtnGroup;  //���㰴ťָ��
    QString m_num;                  //���������
    QString m_sendNum;              //����ڶ�������
    int m_calc;                     //�����������
};

#endif // CALC_H
