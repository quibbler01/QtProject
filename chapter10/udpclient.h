#ifndef UDPCLIENT_H
#define UDPCLIENT_H

#include <QObject>
#include <QDialog>
#include <QLabel>
#include <QPushButton>
#include <QVBoxLayout>
#include <QTextEdit>
#include <QUdpSocket>
#include <QMessageBox>

class UDPClient : public QDialog
{
    Q_OBJECT
public:
    explicit UDPClient(QWidget *parent = nullptr);
    ~UDPClient();

signals:

public slots:
    void CloseBtnClicked();
    void dataReceived();

private:
    QTextEdit *ReceiveTextEdit;
    QPushButton *CloseBtn;
    QVBoxLayout *mainLayout;

    int port;
    QUdpSocket *udpClient;

};

#endif // UDPCLIENT_H
