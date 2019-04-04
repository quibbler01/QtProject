#include "networkinformation.h"

NetworkInformation::NetworkInformation(QWidget *parent) : QWidget(parent)
{
    PcNameLabel = new QLabel(tr("主机名:"));
    pcNameLineEdit = new QLineEdit;
    pcNameLineEdit->setReadOnly(true);
    IPAddressLabel = new QLabel(tr("IP地址:"));
    ipAddressLineEdit =  new QLineEdit;
    ipAddressLineEdit->setReadOnly(true);
    getMoreInfomationBtn = new QPushButton(tr("详细"));
    QGridLayout *infoLayout = new QGridLayout;
    infoLayout->addWidget(PcNameLabel,0,0);
    infoLayout->addWidget(pcNameLineEdit,0,1);
    infoLayout->addWidget(IPAddressLabel,1,0);
    infoLayout->addWidget(ipAddressLineEdit,1,1);
    QVBoxLayout *mainLayout = new QVBoxLayout(this);
    mainLayout->addLayout(infoLayout);
    mainLayout->addWidget(getMoreInfomationBtn);

    this->setWindowTitle(tr("NetWorkInformation"));

    getHostInfomation();
    connect(getMoreInfomationBtn,SIGNAL(clicked()),this,SLOT(slotShowInfomation()));

}

NetworkInformation::~NetworkInformation()
{

}

void NetworkInformation::getHostInfomation()
{
    QString localHostName = QHostInfo::localHostName();
    pcNameLineEdit->setText(localHostName);
    QHostInfo hostInfo = QHostInfo::fromName(localHostName);
    QList<QHostAddress> listAddress = hostInfo.addresses();

    qDebug()<<listAddress.count()<<endl;
    for(int i = 0;i<listAddress.count();++i){
        qDebug()<<listAddress.at(i).toString();
    }

    if(!listAddress.isEmpty()){

        ipAddressLineEdit->setText(listAddress.at(2).toString());
    }
}

void NetworkInformation::slotShowInfomation()
{
    QString detail = "";
    QList<QNetworkInterface> list = QNetworkInterface::allInterfaces();
    for(int i = 0;i<list.count();++i){
        QNetworkInterface interface = list.at(i);
        detail = detail + tr("设备:") +interface.name()+"\n";
        detail = detail +tr("硬件地址:")+interface.hardwareAddress()+"\n";
        QList<QNetworkAddressEntry> entryList = interface.addressEntries();
        for(int j = 0;j<entryList.count();++j){
            QNetworkAddressEntry entry = entryList.at(j);
            detail = detail +"\t"+tr("IP地址:")+entry.ip().toString()+"\n";
            detail = detail + "\t" +tr("子网掩码:")+entry.netmask().toString()+"\n";
            detail = detail + "\t" +tr("广播地址:")+entry.broadcast().toString()+"\n";
        }
    }
    QMessageBox::information(this,tr("详细信息"),detail);
}
