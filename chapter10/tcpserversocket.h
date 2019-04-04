#ifndef TCPSERVERSOCKET_H
#define TCPSERVERSOCKET_H
#include "tcpclientsocket.h"
#include <QTcpServer>
#include <QList>

class TCPServerSocket : public QTcpServer
{
    Q_OBJECT
public:
    explicit TCPServerSocket(QObject *parent,int port);
    ~TCPServerSocket();
    QList<TCPClientSocket*> tcpClientSocketList;

signals:
    void updateServer(QString ,int);
public slots:
    void updateClients(QString,int);
    void slotDisconnected(int);
protected:
    void incomingConnection(int socketDescriptor);

};

#endif // TCPSERVERSOCKET_H
