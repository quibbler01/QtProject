#include "contact.h"

Contact::Contact(QWidget *parent) : QWidget(parent)
{
    EmailLabel = new QLabel(tr("电子邮件："));
    EmailLineEdit = new QLineEdit;
    AddressLabel = new QLabel(tr("地址："));
    AddressLineEdit = new QLineEdit;
    ZooCode = new QLabel(tr("邮编："));
    ZooCodeLineEdit = new QLineEdit;
    MobileLabel = new QLabel(tr("手机："));
    MobileLineEdit = new QLineEdit;
    CheckMessageCheckBox = new QCheckBox(tr("允许联系我"));
    OfficeTellLabel = new QLabel(tr("办公室电话："));
    OfficeTellLineEdit = new QLineEdit;

    MainLayout = new QGridLayout(this);
    MainLayout->setSpacing(10);
    MainLayout->addWidget(EmailLabel,0,0);
    MainLayout->addWidget(EmailLineEdit,0,1);
    MainLayout->addWidget(AddressLabel,1,0);
    MainLayout->addWidget(AddressLineEdit,1,1);
    MainLayout->addWidget(ZooCode,2,0);
    MainLayout->addWidget(ZooCodeLineEdit,2,1);
    MainLayout->addWidget(MobileLabel,3,0);
    MainLayout->addWidget(MobileLineEdit,3,1);
    MainLayout->addWidget(CheckMessageCheckBox,3,2);
    MainLayout->addWidget(OfficeTellLabel,4,0);
    MainLayout->addWidget(OfficeTellLineEdit,4,1);
}

Contact::~Contact(){

}
