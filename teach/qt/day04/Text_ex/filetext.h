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

    void on_tabWidget_tabCloseRequested(int index);

    void on_actionfont_triggered();

    void on_actioncolor_triggered();

private:
    Ui::FileText* ui;
    QString m_filePath;         //�ļ�·��
    //��������
    QMap<QTextEdit*, QString> m_edits;  //����༭����ļ�·��
};

#endif // FILETEXT_H
