#include "baseinfo.h"

BaseInfo::BaseInfo(QWidget *parent) : QWidget(parent)
{
    /***********************Left*****************/
    UserNameLabel = new QLabel(tr("用户名："));
    UserNameLineEdit = new QLineEdit();
    NameLabel = new QLabel(tr("姓名："));
    NameLineEdit = new QLineEdit();
    SexLabel = new QLabel(tr("性别："));
    SexComboBox = new QComboBox;
    SexComboBox->addItem(tr("男"));
    SexComboBox->addItem(tr("女"));
    DepartmentLabe = new QLabel(tr("部门"));
    DeaprtmentTextEdit = new QTextEdit;
    AgeLabel = new QLabel(tr("年龄："));
    AgeLienEdit = new QLineEdit;
    OtherLabel = new QLabel(tr("其它："));
    OtherLabel->setFrameStyle(QFrame::Sunken|QFrame::Panel);
    LeftLayout = new QGridLayout;
    LeftLayout->addWidget(UserNameLabel,0,0);
    LeftLayout->addWidget(UserNameLineEdit,0,1);
    LeftLayout->addWidget(NameLabel,1,0);
    LeftLayout->addWidget(NameLineEdit,1,1);
    LeftLayout->addWidget(SexLabel,2,0);
    LeftLayout->addWidget(SexComboBox,2,1);
    LeftLayout->addWidget(DepartmentLabe,3,0);
    LeftLayout->addWidget(DeaprtmentTextEdit,3,1);
    LeftLayout->addWidget(AgeLabel,4,0);
    LeftLayout->addWidget(AgeLienEdit,4,1);
    LeftLayout->addWidget(OtherLabel,5,0,1,2);
    //设置第一列和第二列占比1:3
    LeftLayout->setColumnStretch(0,1);
    LeftLayout->setColumnStretch(1,3);
    /**********************Right*****************/
    HeadLabel = new QLabel(tr("头像："));
    HeadIconLabel = new QLabel;
    QPixmap icon(":/img/H:/Backup/证件照.jpg");
    HeadIconLabel->setPixmap(icon);
    HeadIconLabel->resize(icon.width(),icon.height());
    UpdateHeadButton = new QPushButton(tr("更换头像"));
    TopRightLayout = new QHBoxLayout;
    TopRightLayout->setSpacing(20);
    TopRightLayout->addWidget(HeadLabel);
    TopRightLayout->addWidget(HeadIconLabel);
    TopRightLayout->addWidget(UpdateHeadButton);

    IntroductionLabel = new QLabel(tr("个人说明："));
    IntroductionTextEdit = new QTextEdit;
    RightLayout = new QVBoxLayout;
    RightLayout->setMargin(10);
    RightLayout->addLayout(TopRightLayout);
    RightLayout->addWidget(IntroductionLabel);
    RightLayout->addWidget(IntroductionTextEdit);
    /******************************************************/
    QGridLayout *mainLayout = new QGridLayout(this);
    mainLayout->setMargin(15);
    mainLayout->setSpacing(10);
    mainLayout->addLayout(LeftLayout,0,0);
    mainLayout->addLayout(RightLayout,0,1);
    //设置窗体固定大小
    mainLayout->setSizeConstraint(QLayout::SetFixedSize);


}

BaseInfo::~BaseInfo()
{

}
