#include "tcpclientsocket.h"

TCPClientSocket::TCPClientSocket(QObject *parent) : QTcpSocket(parent)
{
    connect(this,SIGNAL(readyRead()),this,SLOT(dataReceived()));
    connect(this,SIGNAL(disconnected()),this,SLOT(slotDisconnected()));
}

TCPClientSocket::~TCPClientSocket()
{

}

void TCPClientSocket::dataReceived()
{
    while(bytesAvailable()>0){
        int length = bytesAvailable();
        char buf[1024];
        read(buf,length);
        QString msg = buf;
        emit updateClients(msg,length);
    }
}

void TCPClientSocket::slotDisconnected()
{
    emit disconnected(this->socketDescriptor());
}
