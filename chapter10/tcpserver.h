#ifndef TCPSERVER_H
#define TCPSERVER_H

#include <QWidget>
#include <QTcpServer>
#include <QLabel>
#include <QPushButton>
#include <QLineEdit>
#include <QVBoxLayout>
#include <QGridLayout>
#include <QListWidget>

#include "tcpserversocket.h"

class TCPServer : public QWidget
{
    Q_OBJECT
public:
    explicit TCPServer(QWidget *parent = nullptr);
    ~TCPServer();
signals:

public slots:
    void slotCreateServer();
    void updateServer(QString,int);
private:
    QListWidget *ContentListWidget;
    QLabel *ProtLabel;
    QLineEdit *PortLineEdit;
    QPushButton *CreateBtn;
    QGridLayout *mainLayout;

    int port;
    TCPServerSocket *serverSocket;
};

#endif // TCPSERVER_H
