#ifndef NETWORKWINDOW_H
#define NETWORKWINDOW_H

#include <QWidget>
#include <QHostAddress>
#include <QHostInfo>
#include <QNetworkInterface>
#include <QDebug>

namespace Ui
{
class NetWorkWindow;
}

class NetWorkWindow : public QWidget
{
    Q_OBJECT

public:
    explicit NetWorkWindow(QWidget* parent = nullptr);
    ~NetWorkWindow();

private slots:
    void on_pushButton_clicked();

private:
    Ui::NetWorkWindow* ui;
};

#endif // NETWORKWINDOW_H
