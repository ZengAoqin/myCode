#ifndef VIEW_H
#define VIEW_H

#include <QWidget>
#include <QButtonGroup>

namespace Ui {
class View;
}

class View : public QWidget
{
    Q_OBJECT

signals:
    void returnToWelcome();

public:
    explicit View(QWidget *parent = nullptr);
    ~View();

private slots:
    void on_pushButton_clicked();
    void num_button_clicked(int num);
    void calc_button_clicked(int num);
    void on_pb_clear_clicked();
    int on_pb_equal_clicked();

private:
    Ui::View *ui;
    QButtonGroup* m_pBtnGroup;
    QButtonGroup* m_pCalBtnGroup;
    QString m_firstNum;
    QString m_secondNum;
    QString m_text;
    int m_cal;
};

#endif // VIEW_H
