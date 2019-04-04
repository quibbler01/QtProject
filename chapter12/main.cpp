#include "mainwindow.h"
#include "threaddlg.h"
#include "dialog.h"
#include "timeclient.h"
#include <QApplication>
#include <QWaitCondition>
#include <QThread>
#include <QMutex>
#include <stdio.h>

const int DataSize = 1000;
const int BufferSize = 80;

int buffer[BufferSize];
QWaitCondition bufferEmpty;
QWaitCondition bufferFull;
QMutex mutex;
int numUsedBytes = 0;
int rIndex = 0;

class Producer :public QThread
{
public:
    Producer();
    void run();
};

Producer::Producer(){

}
void Producer::run(){
    for(int i = 0;i<DataSize;++i){
        mutex.lock();
        if(numUsedBytes==BufferSize){
            bufferEmpty.wait(&mutex);
        }
        buffer[i%BufferSize] = numUsedBytes;
        ++numUsedBytes;
        bufferFull.wakeAll();
        mutex.unlock();
    }
}


class Consumer:public QThread{
public:
    Consumer()
    {

    }
    void run()
    {
        forever{
        mutex.lock();
        if(numUsedBytes==0){
            bufferFull.wait(&mutex);
        }
        printf("%ul::[%d]=%d\n",currentThreadId(),rIndex,buffer[rIndex]);
        rIndex = (++rIndex)%BufferSize;
        --numUsedBytes;
        bufferEmpty.wakeAll();
        mutex.unlock();
        }
        printf("\n");
    }

};


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
//    ThreadDlg w;
//    w.show();
    /**
      生产者和消费者
      **/
//    Producer producer;
//    Consumer consumerA,consumerB;
//    producer.start();
//    consumerA.start();
//    consumerB.start();
//    producer.wait();
//    consumerA.wait();
//    consumerB.wait();

    Dialog d;
    d.show();

    TimeClient c;
    c.show();

    return a.exec();
}
