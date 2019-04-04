#include "threaddlg.h"

ThreadDlg::ThreadDlg(QWidget *parent) : QWidget(parent)
{
    this->setWindowTitle(tr("线程"));
    this->startBtn = new QPushButton(tr("开始"));
    startBtn->setEnabled(true);
    stopBtn = new QPushButton(tr("停止"));
    stopBtn->setEnabled(false);
    quitBtn = new QPushButton(tr("退出"));
    mainLayout=  new QHBoxLayout(this);
    mainLayout->addWidget(startBtn);
    mainLayout->addWidget(stopBtn);
    mainLayout->addWidget(quitBtn);

    connect(startBtn,SIGNAL(clicked()),this,SLOT(slotStartThread()));
    connect(stopBtn,SIGNAL(clicked()),this,SLOT(slotStopThread()));
    connect(quitBtn,SIGNAL(clicked()),this,SLOT(slotQuit()));

}

ThreadDlg::~ThreadDlg()
{

}

void ThreadDlg::slotStartThread()
{
    for(int i = 0;i<MAXSIZE;++i){
        workThreads[i] = new WorkThread;
    }
    for(int i = 0;i<MAXSIZE;++i){
        workThreads[i]->start();
    }
    startBtn->setEnabled(false);
    stopBtn->setEnabled(true);
}

void ThreadDlg::slotStopThread()
{
    for(int i = 0;i<MAXSIZE;++i){
        workThreads[i]->terminate();
        workThreads[i]->wait();
    }
    startBtn->setEnabled(true);
    startBtn->setEnabled(false);
}

void ThreadDlg::slotQuit()
{
    this->close();
}
