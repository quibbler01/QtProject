#ifndef TIMECLIENT_H
#define TIMECLIENT_H

#include <QWidget>
#include <QTcpSocket>
#include <QLabel>
#include <QPushButton>
#include <QLineEdit>
#include <QDateTimeEdit>
#include <QAbstractSocket>

class TimeClient : public QWidget
{
    Q_OBJECT
public:
    explicit TimeClient(QWidget *parent = nullptr);
    ~TimeClient();

signals:

public slots:
    void enableGetBtn();
    void getTime();
    void readTime();
    void showError(QAbstractSocket::SocketError socketError);

private:
    QLabel *serverNameLabel;
    QLineEdit *serverNameLineEdit;
    QLabel *portLabel;
    QLineEdit *portLineEdit;
    QDateTimeEdit *dateTimeEdit;
    QLabel *stateLabel;
    QPushButton *getBtn;
    QPushButton *quitBtn;
    uint time2u;
    QTcpSocket *tcpSocket;
};

#endif // TIMECLIENT_H
