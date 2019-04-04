#ifndef TCPCLIENTSOCKET_H
#define TCPCLIENTSOCKET_H

#include <QObject>
#include <QTcpSocket>

class TCPClientSocket : public QTcpSocket
{
    Q_OBJECT
public:
    explicit TCPClientSocket(QObject *parent = nullptr);
    ~TCPClientSocket();

signals:
    void updateClients(QString,int);
    void disconnected(int);


public slots:
    void dataReceived();
    void slotDisconnected();

};

#endif // TCPCLIENTSOCKET_H
