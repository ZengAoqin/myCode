#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QWidget>
#include "calc.h"

namespace Ui
{
class MainWindow;
}

class MainWindow : public QWidget
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget* parent = nullptr);
    ~MainWindow();

    //申明函数
    void setNameText(const QString name);

private slots:
    void on_btnCalc_clicked();

private:
    Ui::MainWindow* ui;
    QString m_strName;
    Calc* m_pCalc;          //定义计算器指针
};

#endif // MAINWINDOW_H
