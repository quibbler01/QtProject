#ifndef TCPCLIENT_H
#define TCPCLIENT_H

#include <QWidget>
#include <QListWidget>
#include <QLabel>
#include <QPushButton>
#include <QLineEdit>
#include <QGridLayout>
#include <QTcpSocket>
#include <QHostAddress>
#include <QMessageBox>
#include <QHostInfo>

class TCPClient : public QWidget
{
    Q_OBJECT
public:
    explicit TCPClient(QWidget *parent = nullptr);
    ~TCPClient();

signals:

public slots:
    void slotEnter();
    void slotConnected();
    void slotDisconnected();
    void slotReceived();
    void slotSend();
    void dataReceived();

private:
    QListWidget *contentListWidget;
    QLineEdit *sendLineEdit;
    QPushButton *sendBtn;
    QLabel *userNameLabel;
    QLineEdit *userNameLineEdit;
    QLabel *serverIPLabel;
    QLineEdit *serverIPLineEdit;
    QLabel *portLabel;
    QLineEdit *portLineEdit;
    QPushButton *enterBtn;
    QGridLayout *mainLayout;

    bool status;
    int port;
    QString userName;
    QHostAddress *serverIP;
    QTcpSocket *tcpSocket;
};

#endif // TCPCLIENT_H
