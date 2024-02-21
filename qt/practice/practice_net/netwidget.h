#ifndef NETWIDGET_H
#define NETWIDGET_H

#include <QWidget>
#include <QHostInfo>
#include <QNetworkInterface>
#include <QHostAddress>
#include <QDebug>

namespace Ui {
class NetWidget;
}

class NetWidget : public QWidget
{
    Q_OBJECT

public:
    explicit NetWidget(QWidget *parent = nullptr);
    ~NetWidget();

private slots:
    void on_pushButton_clicked();

private:
    Ui::NetWidget *ui;
};

#endif // NETWIDGET_H
