#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTextEdit>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_actionaction_triggered();

    void on_actionsave_triggered();

    void on_actionsaveas_triggered();

    void on_actionquit_triggered();

private:
    Ui::MainWindow *ui;
    QString m_filePath;
};

#endif // MAINWINDOW_H
