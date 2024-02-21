#ifndef FILETEXT_H
#define FILETEXT_H

#include <QMainWindow>
#include <QTextEdit>

namespace Ui
{
class FileText;
}

class FileText : public QMainWindow
{
    Q_OBJECT

public:
    explicit FileText(QWidget* parent = nullptr);
    ~FileText();

private slots:
    void on_actionopen_triggered();

    void on_actionsave_triggered();

    void on_actionsaveas_triggered();

    void on_actionquit_triggered();

private:
    Ui::FileText* ui;
    QString m_filePath;         //ÎÄ¼þÂ·¾¶
};

#endif // FILETEXT_H
