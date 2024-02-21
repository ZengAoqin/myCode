#ifndef FILESENDWINDOW_H
#define FILESENDWINDOW_H

#include <QWidget>
#include <QTcpSocket>
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

    void on_btnConect_clicked();

    void send_fileInfo();
    void send_fileText(qint64 bytes);
private:
    Ui::FileSendWindow* ui;
    QTcpSocket m_scoket;        //ʵ�����׽��ֶ���
    QFile m_file;               //ʵ�����ļ�����
    QString m_fileName;         //�ļ���
    qint64 m_fileSize;          //�ļ���С
    qint64 m_sendSize;          //���͵��ļ���С
};

#endif // FILESENDWINDOW_H