#ifndef FILEWIDGET_H
#define FILEWIDGET_H

#include <QWidget>
#include <QFileDialog>
#include <QListWidgetItem>

namespace Ui
{
class FileWidget;
}

class FileWidget : public QWidget
{
    Q_OBJECT

public:
    explicit FileWidget(QWidget* parent = nullptr);
    ~FileWidget();

private slots:
    void on_btnFile_clicked();

    void on_listWidget_itemDoubleClicked(QListWidgetItem* item);

private:
    Ui::FileWidget* ui;
    QStringList m_filepaths;            //Â·¾¶×Ö·û´®ÁÐ±í
};

#endif // FILEWIDGET_H
