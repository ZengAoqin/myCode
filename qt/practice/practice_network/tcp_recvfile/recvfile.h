#ifndef RECVFILE_H
#define RECVFILE_H

#include <QWidget>
#include <QFileDialog>
#include <QFileInfo>
#include <QFile>
#include <QTcpSocket>
#include <QTcpServer>
#include <QDebug>
#include <QDataStream>

namespace Ui {
class RecvFile;
}

class RecvFile : public QWidget
{
    Q_OBJECT

public:
    explicit RecvFile(QWidget *parent = nullptr);
    ~RecvFile();

private slots:
    void new_client();
    void read_data();

private:
    Ui::RecvFile *ui;
    QTcpServer m_server;
    QFile m_file;               //实例化文件对象
    QString m_fileName;         //文件名
    qint64 m_fileSize;          //文件大小
    qint64 m_recvSize;          //发送的文件大小
};

#endif // RECVFILE_H
