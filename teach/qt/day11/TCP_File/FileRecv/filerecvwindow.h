#ifndef FILERECVWINDOW_H
#define FILERECVWINDOW_H

#include <QWidget>
#include <QTcpSocket>
#include <QFileDialog>
#include <QFileInfo>
#include <QFile>
#include <QTcpServer>

namespace Ui
{
class FileRecvWindow;
}

class FileRecvWindow : public QWidget
{
    Q_OBJECT

public:
    explicit FileRecvWindow(QWidget* parent = nullptr);
    ~FileRecvWindow();

private slots:
    void new_client();
    void read_data();
private:
    Ui::FileRecvWindow* ui;
    QTcpServer m_server;        //实例化服务器对象
    QFile m_file;               //实例化文件对象
    QString m_fileName;         //文件名
    qint64 m_fileSize;          //文件大小
    qint64 m_recvSize;          //接收的文件大小
};

#endif // FILERECVWINDOW_H
