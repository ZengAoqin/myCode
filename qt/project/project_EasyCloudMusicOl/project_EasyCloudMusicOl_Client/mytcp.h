#ifndef MYTCP_H
#define MYTCP_H

#include <QObject>
#include <QTcpSocket>

#include "config.h"

extern QByteArray receivedData;            // 接收到的数据缓冲区

class MyTcp : public QObject
{
    Q_OBJECT 

//成员函数
public:
    explicit MyTcp(QObject *parent = nullptr);
    ~MyTcp();
    void connectServer();

signals:
    void recvTcpJsonObj(QJsonObject jsonObj);

public slots:
    void sendData(QJsonObject jsonObj);
    void recvData();

//成员变量
private:
    QTcpSocket* m_socket;
};

#endif // MYTCP_H
