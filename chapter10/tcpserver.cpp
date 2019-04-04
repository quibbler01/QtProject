#include "tcpserver.h"

TCPServer::TCPServer(QWidget *parent) : QWidget(parent)
{
    this->setWindowTitle(tr("TCP Server"));
    ContentListWidget = new QListWidget;
    ProtLabel = new QLabel(tr("端口:"));
    PortLineEdit = new QLineEdit;
    CreateBtn = new QPushButton(tr("创建聊天室"));
    mainLayout = new QGridLayout(this);
    mainLayout->addWidget(ContentListWidget,0,0,1,2);
    mainLayout->addWidget(ProtLabel,1,0);
    mainLayout->addWidget(PortLineEdit,1,1);
    mainLayout->addWidget(CreateBtn,2,0,1,2);

    port = 8010;
    PortLineEdit->setText(QString::number(port));
    connect(CreateBtn,SIGNAL(clicked()),this,SLOT(slotCreateServer()));
}

TCPServer::~TCPServer()
{

}

void TCPServer::slotCreateServer()
{
    serverSocket = new TCPServerSocket(this,port);
    connect(serverSocket,SIGNAL(updateServer(QString,int)),this,SLOT(updateServer(QString,int)));
    CreateBtn->setEnabled(false);
}

void TCPServer::updateServer(QString msg, int length)
{
    ContentListWidget->addItem(msg.left(length));
}
