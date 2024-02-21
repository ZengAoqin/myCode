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
    QTcpServer m_server;        //ʵ��������������
    QFile m_file;               //ʵ�����ļ�����
    QString m_fileName;         //�ļ���
    qint64 m_fileSize;          //�ļ���С
    qint64 m_recvSize;          //���յ��ļ���С
};

#endif // FILERECVWINDOW_H
