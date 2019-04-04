#include "workthread.h"

WorkThread::WorkThread(QObject *parent) : QThread(parent)
{

}

WorkThread::~WorkThread()
{

}

void WorkThread::run()
{
    while(true){
        for(int i = 0;i<10;++i){
            qDebug()<<i<<i<<i<<i<<endl;
        }
    }
}
