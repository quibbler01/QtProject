#ifndef UDPSERVER_H
#define UDPSERVER_H

#include <QDialog>
#include <QLabel>
#include <QPushButton>
#include <QLineEdit>
#include <QVBoxLayout>
#include <QUdpSocket>
#include <QTimer>

class UDPServer : public QDialog
{
    Q_OBJECT
public:
    explicit UDPServer(QDialog *parent = nullptr);
    ~UDPServer();

signals:

public slots:
    void StartBtnClicked();
    void timeout();

private:
    QLabel *TimerLabel;
    QLineEdit *TextLineEdit;
    QPushButton *StartBtn;
    QVBoxLayout *mainLayout;

    int port;
    bool isStarted;
    QUdpSocket *udpSocket;
    QTimer *timer;
};

#endif // UDPSERVER_H
