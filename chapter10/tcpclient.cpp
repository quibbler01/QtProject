﻿#include "tcpclient.h"

TCPClient::TCPClient(QWidget *parent) : QWidget(parent)
{
    this->setWindowTitle(tr("TCP Client"));
    contentListWidget = new QListWidget;
    sendLineEdit = new QLineEdit;
    sendBtn = new QPushButton(tr("发送"));
    userNameLabel = new QLabel(tr("用户名:"));
    userNameLineEdit = new QLineEdit;
    serverIPLabel = new QLabel(tr("服务器地址:"));
    serverIPLineEdit = new QLineEdit;
    portLabel = new QLabel(tr("端口:"));
    portLineEdit = new QLineEdit();
    enterBtn = new QPushButton(tr("进入聊天室"));
    mainLayout = new QGridLayout(this);
    mainLayout->addWidget(contentListWidget,0,0,1,2);
    mainLayout->addWidget(sendLineEdit,1,0);
    mainLayout->addWidget(sendBtn,1,1);
    mainLayout->addWidget(userNameLabel,2,0);
    mainLayout->addWidget(userNameLineEdit,2,1);
    mainLayout->addWidget(serverIPLabel,3,0);
    mainLayout->addWidget(serverIPLineEdit,3,1);
    mainLayout->addWidget(portLabel,4,0);
    mainLayout->addWidget(portLineEdit,4,1);
    mainLayout->addWidget(enterBtn,5,0,1,2);

    status = false;
    port = 8010;
    portLineEdit->setText(QString::number(port));
    serverIP = new QHostAddress();
    connect(enterBtn,SIGNAL(clicked()),this,SLOT(slotEnter()));
    connect(sendBtn,SIGNAL(clicked()),this,SLOT(slotSend()));
    sendBtn->setEnabled(false);
}

TCPClient::~TCPClient()
{

}

void TCPClient::slotEnter()
{
    if(!status){
        QString ip = serverIPLineEdit->text();
        if(!serverIP->setAddress(ip)){
            QMessageBox::information(this,tr("error"),tr("server ip address error!"));
            return;
        }
        if(userNameLineEdit->text()==""){
            QMessageBox::information(this,tr("error"),tr("User Name Empty!"));
            return;
        }
        userName = userNameLineEdit->text();
        tcpSocket = new QTcpSocket(this);
        connect(tcpSocket,SIGNAL(connected()),this,SLOT(slotConnected()));
        connect(tcpSocket,SIGNAL(disconnected()),this,SLOT(slotDisconnected()));
        connect(tcpSocket,SIGNAL(readyRead()),this,SLOT(dataReceived()));

        tcpSocket->connectToHost(*serverIP,port);
        status = true;
    }else{
        int length = 0;
        QString msg = userName + tr(":Leave Char Room");
        if((length=tcpSocket->write(msg.toLatin1(),msg.length()))!=msg.length()){
            return;
        }
        tcpSocket->disconnectFromHost();
        status = false;
    }
}

void TCPClient::slotConnected()
{
    sendBtn->setEnabled(true);
    enterBtn->setText(tr("离开聊天室"));
    int length = 0;
    QString msg = userName +":"+tr("Enter Char Room");
    if((length = tcpSocket->write(msg.toLatin1(),msg.length()))!=msg.length()){
        return;
    }
}

void TCPClient::slotDisconnected()
{
    sendBtn->setEnabled(false);
    enterBtn->setText(tr("进入聊天室"));
}

void TCPClient::slotReceived()
{
    while(tcpSocket->bytesAvailable()>0){
        QByteArray datagram;
        datagram.resize(tcpSocket->bytesAvailable());
        tcpSocket->read(datagram.data(),datagram.size());
        QString msg = datagram.data();
        contentListWidget->addItem(msg.left(datagram.size()));
    }
}

void TCPClient::slotSend()
{
    if(sendLineEdit->text()==""){
        return;
    }
    QString msg = userName+":"+sendLineEdit->text();
    tcpSocket->write(msg.toLatin1(),msg.length());
    sendLineEdit->clear();
}

void TCPClient::dataReceived()
{

}
