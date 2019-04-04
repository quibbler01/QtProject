#include "timeserver.h"
#include "timethread.h"
#include "dialog.h"
#include <QDebug>


TimeServer::TimeServer(QObject *parent):QTcpServer (parent)
{
    dlg = (Dialog*)parent;
}

void TimeServer::incomingConnection(int socketDescriptor)
{
    qDebug()<<"收到一次请求";
    TimeThread *thread = new TimeThread(socketDescriptor,nullptr);
    connect(thread,SIGNAL(finished()),dlg,SLOT(slotShow()));
    connect(thread,SIGNAL(finished()),thread,SLOT(deleteLater()),Qt::DirectConnection);
    thread->start();
}
