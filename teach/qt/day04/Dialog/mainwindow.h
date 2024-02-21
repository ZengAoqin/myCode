#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui
{
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget* parent = nullptr);
    ~MainWindow();

private slots:
    void on_btnFile_clicked();

    void on_btnColor_clicked();

    void on_btnFont_clicked();

    void on_btnInput_clicked();

    void on_btnDialog_clicked();

private:
    Ui::MainWindow* ui;
};

#endif // MAINWINDOW_H
