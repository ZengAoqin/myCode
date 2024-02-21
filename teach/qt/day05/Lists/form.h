#ifndef FORM_H
#define FORM_H

#include <QWidget>
#include <QPixmap>  //ͼƬ

namespace Ui
{
class Form;
}

class Form : public QWidget
{
    Q_OBJECT

public:
    explicit Form(QWidget* parent = nullptr);

    void setInfo(QString pic, QString info);
    ~Form();

private:
    Ui::Form* ui;
};

#endif // FORM_H
