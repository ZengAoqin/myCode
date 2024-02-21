#ifndef MYWIDGET_H
#define MYWIDGET_H

#include <QWidget>
#include <thread.h>
#include <mytask.h>
#include <QThreadPool>

namespace Ui {
class MyWidget;
}

class MyWidget : public QWidget
{
    Q_OBJECT

public:
    explicit MyWidget(QWidget *parent = nullptr);
    ~MyWidget();
private slots:
    void showmsg(QString msg);

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::MyWidget *ui;
    Thread1* m_t1;
    Thread2* m_t2;
};

#endif // MYWIDGET_H
