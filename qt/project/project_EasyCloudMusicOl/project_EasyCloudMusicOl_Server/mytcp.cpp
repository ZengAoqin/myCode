#include "mytcp.h"

MyTcp::MyTcp(QObject *parent) : QObject(parent)
{
    m_server = new QTcpServer;
    m_on = false;

    //绑定新连接进入的信号与客户端新连接槽函数
//    connect(m_server, &QTcpServer::newConnection, this, &TcpServer::new_client);
}
