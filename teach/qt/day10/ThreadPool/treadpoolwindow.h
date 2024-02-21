#ifndef TREADPOOLWINDOW_H
#define TREADPOOLWINDOW_H

#include <QWidget>
#include <QThreadPool>
#include "mytask.h"

namespace Ui
{
class TreadPoolWindow;
}

class TreadPoolWindow : public QWidget
{
    Q_OBJECT

public:
    explicit TreadPoolWindow(QWidget* parent = nullptr);
    ~TreadPoolWindow();

private slots:
    void on_pushButton_clicked();

private:
    Ui::TreadPoolWindow* ui;
};

#endif // TREADPOOLWINDOW_H
