﻿#include "udpserver.h"

UDPServer::UDPServer(QDialog *parent) : QDialog(parent)
{
    this->setWindowTitle((tr("UDP Server")));
    TimerLabel = new QLabel(tr("计时器:"));
    TextLineEdit = new QLineEdit;
    StartBtn = new QPushButton(tr("开始"));
    mainLayout = new QVBoxLayout(this);
    mainLayout->addWidget(TimerLabel);
    mainLayout->addWidget(TextLineEdit);
    mainLayout->addWidget(StartBtn);

    connect(StartBtn,SIGNAL(clicked()),this,SLOT(StartBtnClicked()));
    port = 5555;
    isStarted = false;
    udpSocket = new QUdpSocket(this);
    timer = new QTimer(this);

    connect(timer,SIGNAL(timeout()),this,SLOT(timeout()));


}

UDPServer::~UDPServer()
{

}

void UDPServer::StartBtnClicked()
{
    if(!isStarted){
        StartBtn->setText(tr("停止"));
        timer->start(1000);
        isStarted  =true;
        TextLineEdit->setReadOnly(true);
    }else{
        StartBtn->setText(tr("开始"));
        isStarted = false;
        timer->stop();
        TextLineEdit->setReadOnly(false);
    }
}

void UDPServer::timeout()
{
    QString msg = TextLineEdit->text();
    int length = 0;
    if(msg == ""){
        return;
    }
    if((length = udpSocket->writeDatagram(msg.toLatin1(),msg.length(),QHostAddress::Broadcast,port))!=msg.length()){
        return;
    }
}
