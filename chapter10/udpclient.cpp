#include "udpclient.h"

UDPClient::UDPClient(QWidget *parent) : QDialog(parent)
{
    this->setWindowTitle((tr("UDP Client")));
    ReceiveTextEdit = new QTextEdit;
    ReceiveTextEdit->setReadOnly(true);
    CloseBtn = new QPushButton(tr("Close"));

    mainLayout = new QVBoxLayout(this);
    mainLayout->addWidget(ReceiveTextEdit);
    mainLayout->addWidget(CloseBtn);

    port = 5555;
    udpClient = new QUdpSocket(this);
    connect(CloseBtn,SIGNAL(clicked()),this,SLOT(CloseBtnClicked()));
    connect(udpClient,SIGNAL(readyRead()),this,SLOT(dataReceived()));

    bool result = udpClient->bind(port);
    if(!result){
        QMessageBox::information(this,tr("Error"),tr("Udp Socket create error!"));
    }
    return;
}

UDPClient::~UDPClient()
{

}

void UDPClient::CloseBtnClicked()
{
    this->close();
}

void UDPClient::dataReceived()
{
    while(udpClient->hasPendingDatagrams()){
        QByteArray datagram;
        datagram.resize(udpClient->pendingDatagramSize());
        udpClient->readDatagram(datagram.data(),datagram.size());
        QString msg = datagram.data();
        ReceiveTextEdit->insertPlainText(msg);
    }
}
