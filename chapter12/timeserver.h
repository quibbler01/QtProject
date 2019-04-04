#ifndef TIMESERVER_H
#define TIMESERVER_H

#include <QTcpServer>
#include "dialog.h"

class TimeServer : public QTcpServer
{
public:
    TimeServer(QObject *parent = nullptr);
    void  incomingConnection(int socketDescriptor);
    Dialog *dlg;
};

#endif // TIMESERVER_H
