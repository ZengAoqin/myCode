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

    void on_tabWidget_tabCloseRequested(int index);

    void on_actionfont_triggered();

    void on_actioncolor_triggered();

private:
    Ui::MainWindow *ui;
    QString m_filePath;
    QMap<QTextEdit*, QString> m_edits;
};

#endif // MAINWINDOW_H
