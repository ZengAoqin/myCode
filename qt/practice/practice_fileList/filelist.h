#ifndef FILELIST_H
#define FILELIST_H

#include <QMainWindow>
#include <QListWidgetItem>

namespace Ui {
class FileList;
}

class FileList : public QMainWindow
{
    Q_OBJECT

public:
    explicit FileList(QWidget *parent = nullptr);
    ~FileList();

private slots:
    void on_pushButton_clicked();

    void on_listWidget_itemClicked(QListWidgetItem *item);

    void on_listWidget_itemDoubleClicked(QListWidgetItem *item);

private:
    Ui::FileList *ui;
    QStringList m_filePaths;
};

#endif // FILELIST_H
