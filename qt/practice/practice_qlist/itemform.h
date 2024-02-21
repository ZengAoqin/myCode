#ifndef ITEMFORM_H
#define ITEMFORM_H

#include <QWidget>
#include <QPixmap>


namespace Ui {
class ItemForm;
}

class ItemForm : public QWidget
{
    Q_OBJECT

public:
    explicit ItemForm(QWidget *parent = nullptr);
    void setInfo(QString pic, QString info);
    ~ItemForm();

private:
    Ui::ItemForm *ui;
};

#endif // ITEMFORM_H
