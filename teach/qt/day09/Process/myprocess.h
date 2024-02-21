#ifndef MYPROCESS_H
#define MYPROCESS_H

#include <QWidget>
#include <QProcess>
#include <QDebug>

namespace Ui
{
class MyProcess;
}

class MyProcess : public QWidget
{
    Q_OBJECT

public:
    explicit MyProcess(QWidget* parent = nullptr);
    ~MyProcess();

private slots:
    void on_pushButton_clicked();
    void on_finished(int exitCode, QProcess::ExitStatus exitStatus);

private:
    Ui::MyProcess* ui;
    QProcess m_process;
};

#endif // MYPROCESS_H
