#include "mytcp.h"

MyTcp::MyTcp(QObject *parent) : QObject(parent)
{
    m_socket = new QTcpSocket;

    //监听服务器发送消息信号 执行读取信息槽函数
    connect(m_socket, &QTcpSocket::readyRead, this, &MyTcp::recvData);
}

MyTcp::~MyTcp()
{
    delete m_socket;
}

//连接服务器
void MyTcp::connectServer()
{
    QString port = SERVER_PORT;
    m_socket->connectToHost(SERVER_IP, port.toUShort());
}

//发送数据
void MyTcp::sendData(QJsonObject jsonObj)
{
    //将JSON数据转换为字节数组
    QJsonDocument jsonDoc(jsonObj);
    QByteArray byteArr = jsonDoc.toJson();

    //发送给服务器
    m_socket->write(byteArr);
}

//接收数据槽函数
void MyTcp::recvData()
{
    //通过套接字读取数据
    QByteArray byteArr = m_socket->readAll();
    QJsonDocument jsonDoc = QJsonDocument::fromJson(byteArr);
    QJsonObject jsonObj = jsonDoc.object();

    //触发recvTcpJsonObj信号
    emit recvTcpJsonObj(jsonObj);
}

