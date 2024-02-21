#ifndef LED_H
#define LED_H

#include <QMainWindow>

namespace Ui
{
class LED;
}

class LED : public QMainWindow
{
    Q_OBJECT

public:
    explicit LED(QWidget* parent = nullptr);
    ~LED();

private slots:
    void on_pushButton_clicked();

signals:
    void returnBack();

private:
    Ui::LED* ui;
};

#endif // LED_H
