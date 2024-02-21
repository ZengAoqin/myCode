#ifndef MYTCP_H
#define MYTCP_H

#include <QObject>
#include <QTcpServer>
#include <QTcpSocket>

class MyTcp : public QObject
{
    Q_OBJECT

//成员函数
public:
    explicit MyTcp(QObject *parent = nullptr);
    ~MyTcp();
    void startServer();

signals:

public slots:

//成员变量
private:
    QTcpServer* m_server;
    bool m_on;

};

#endif // MYTCP_H
