#ifndef TIMETHREAD_H
#define TIMETHREAD_H

#include <QObject>
#include <QWidget>
#include <QThread>
#include <QTcpSocket>
#include <QtNetwork>

class TimeThread : public QThread
{
    Q_OBJECT
public:
    explicit TimeThread(int socketDescriptor,QObject *parent = nullptr);
    ~TimeThread();
    void run();

signals:
    void error(QTcpSocket::SocketError socketError);
private:
    int socketDescriptor;

public slots:
};

#endif // TIMETHREAD_H
