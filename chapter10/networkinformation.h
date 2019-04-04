#ifndef NETWORKINFORMATION_H
#define NETWORKINFORMATION_H

#include <QWidget>
#include <QLabel>
#include <QPushButton>
#include <QLineEdit>
#include <QVBoxLayout>
#include <QGridLayout>
#include <QHostInfo>
#include <QHostAddress>
#include <QNetworkInterface>
#include <QMessageBox>
#include <QDebug>

class NetworkInformation : public QWidget
{
    Q_OBJECT
public:
    explicit NetworkInformation(QWidget *parent = nullptr);
    ~NetworkInformation();
    void getHostInfomation();

signals:

public slots:
    void slotShowInfomation();
private:
    QLabel *PcNameLabel;
    QLabel *IPAddressLabel;
    QLineEdit *pcNameLineEdit;
    QLineEdit *ipAddressLineEdit;
    QPushButton *getMoreInfomationBtn;
};

#endif // NETWORKINFORMATION_H
