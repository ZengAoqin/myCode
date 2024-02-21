#ifndef SENDFILE_H
#define SENDFILE_H

#include <QWidget>
#include <QFileDialog>
#include <QFileInfo>
#include <QFile>
#include <QTcpSocket>
#include <QDebug>
#include <QDataStream>

namespace Ui {
class SendFile;
}

class SendFile : public QWidget
{
    Q_OBJECT

public:
    explicit SendFile(QWidget *parent = nullptr);
    ~SendFile();

private slots:
    void on_btnChoose_clicked();
    void on_btnConnect_clicked();
    void send_fileInfo();
    void send_fileText(qint64 bytes);

private:
    Ui::SendFile *ui;
    QTcpSocket m_socket;
    QFile m_file;               //实例化文件对象
    QString m_fileName;         //文件名
    qint64 m_fileSize;          //文件大小
    qint64 m_sendSize;          //发送的文件大小
};

#endif // SENDFILE_H
