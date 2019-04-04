#include "tcpserversocket.h"

TCPServerSocket::TCPServerSocket(QObject *parent,int port) : QTcpServer(parent)
{
    listen(QHostAddress::Any,port);
}

TCPServerSocket::~TCPServerSocket()
{

}

void TCPServerSocket::updateClients(QString msg, int length)
{
    emit updateServer(msg,length);
    for(int i = 0;i<tcpClientSocketList.count();++i){
        QTcpSocket *item = tcpClientSocketList.at(i);
        if(item->write(msg.toLatin1(),length)!=length){
            continue;
        }
    }
}

void TCPServerSocket::slotDisconnected(int socketDescriptor)
{
    for(int i = 0;i<tcpClientSocketList.count();++i){
        QTcpSocket *item = tcpClientSocketList.at(i);
        if(item->socketDescriptor()==socketDescriptor){
            tcpClientSocketList.removeAt(i);
            return;
        }
    }
    return ;
}

void TCPServerSocket::incomingConnection(int socketDescriptor)
{
    TCPClientSocket *tcpClientSocket = new TCPClientSocket(this);
    connect(tcpClientSocket,SIGNAL(updateClients(QString,int)),this,SLOT(updateClients(QString,int)));
    connect(tcpClientSocket,SIGNAL(disconnected(int)),this,SLOT(slotDisconnected(int)));
    tcpClientSocket->setSocketDescriptor(socketDescriptor);
    tcpClientSocketList.append(tcpClientSocket);
}
