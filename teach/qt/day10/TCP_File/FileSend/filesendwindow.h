#ifndef FILESENDWINDOW_H
#define FILESENDWINDOW_H

#include <QWidget>
#include <QFileDialog>
#include <QFileInfo>
#include <QFile>

namespace Ui
{
class FileSendWindow;
}

class FileSendWindow : public QWidget
{
    Q_OBJECT

public:
    explicit FileSendWindow(QWidget* parent = nullptr);
    ~FileSendWindow();

private slots:
    void on_btnFile_clicked();

private:
    Ui::FileSendWindow* ui;
    QFile m_file;               //实例化文件对象
    QString m_fileName;         //文件名
    qint64 m_fileSize;          //文件大小
    qint64 m_sendSize;          //发送的文件大小
};

#endif // FILESENDWINDOW_H
