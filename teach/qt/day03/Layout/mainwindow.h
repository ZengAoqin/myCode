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

    //��������
    void setNameText(const QString name);

private slots:
    void on_btnCalc_clicked();

private:
    Ui::MainWindow* ui;
    QString m_strName;
    Calc* m_pCalc;          //���������ָ��
};

#endif // MAINWINDOW_H
