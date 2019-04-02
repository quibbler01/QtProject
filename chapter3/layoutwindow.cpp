#include "layoutwindow.h"

LayoutWindow::LayoutWindow(QDialog *parent) : QDialog(parent)
{
    this->setWindowTitle("UserInfo");

    UserNameLabel = new QLabel(tr("用户名:"));
    UserNameLineEdit = new QLineEdit();
    NameLabel = new QLabel(tr("姓名:"));
    NameLineEdit = new QLineEdit();
    SexLabel = new QLabel(tr("性别:"));
    SexComboBox = new QComboBox();
    SexComboBox->addItem(tr("男"));
    SexComboBox->addItem(tr("女"));
    DepartmentLabel = new QLabel(tr("部门:"));
    DepartmentTextEdit = new QTextEdit();
    AgeLabel = new QLabel(tr("年龄:"));
    AgeLineEdit = new QLineEdit();
    OtherLabel = new QLabel(tr("其它:"));
    OtherLabel->setFrameStyle(QFrame::Panel|QFrame::Sunken);

    LeftLayout = new QGridLayout();
    LeftLayout->addWidget(UserNameLabel,0,0);
    LeftLayout->addWidget(UserNameLineEdit,0,1);
    LeftLayout->addWidget(NameLabel,1,0);
    LeftLayout->addWidget(NameLineEdit,1,1);
    LeftLayout->addWidget(SexLabel,2,0);
    LeftLayout->addWidget(SexComboBox,2,1);
    LeftLayout->addWidget(DepartmentLabel,3,0);
    LeftLayout->addWidget(DepartmentTextEdit,3,1);
    LeftLayout->addWidget(AgeLabel,4,0);
    LeftLayout->addWidget(AgeLineEdit,4,1);
    LeftLayout->addWidget(OtherLabel,5,0,1,2);
    LeftLayout->setColumnStretch(0,1);
    LeftLayout->setColumnStretch(1,3);
    /*********/
    HeadLabel = new QLabel(tr("头像:"));
    HeadIconLael = new QLabel();
    QPixmap icon(":/img/H:/Backup/证件照.jpg");
    HeadIconLael->setPixmap(icon);
    //HeadIconLael->setSizePolicy(QSizePolicy::Fixed);
    HeadIconLael->resize(icon.width(),icon.height());
    qDebug()<<icon.width()<<" "<<icon.height();
    UpdateHeadButton = new QPushButton(tr("更新"));
    //
    TopRightLayout = new QHBoxLayout();
    TopRightLayout->setSpacing(20);
    TopRightLayout->addWidget(HeadLabel);
    TopRightLayout->addWidget(HeadIconLael);
    TopRightLayout->addWidget(UpdateHeadButton);
    IntroductionLabel = new QLabel(tr("个人说明:"));
    IntroductionTextEdit = new QTextEdit();
    //
    RightLayout = new QVBoxLayout();
    RightLayout->setMargin(10);
    RightLayout->addLayout(TopRightLayout);
    RightLayout->addWidget(IntroductionLabel);
    RightLayout->addWidget(IntroductionTextEdit);
    /*****************************/
    OkButton = new QPushButton(tr("确定:"));
    CancelButton = new QPushButton(tr("取消"));
    //添加两个按钮
    ButtonLayout = new QHBoxLayout();
    ButtonLayout->addStretch();
    ButtonLayout->addWidget(OkButton);
    ButtonLayout->addWidget(CancelButton);
    /**************************MainLayout********************/
    QGridLayout *mainLayout = new QGridLayout(this);
    mainLayout->setMargin(15);
    mainLayout->setSpacing(10);
    mainLayout->addLayout(LeftLayout,0,0);
    mainLayout->addLayout(RightLayout,0,1);
    mainLayout->addLayout(ButtonLayout,1,0,1,2);
    mainLayout->setSizeConstraint(QLayout::SetFixedSize);
    connect(CancelButton,SIGNAL(clicked()),this,SLOT(close()));
    connect(OkButton,&QPushButton::clicked,[=](){
       qDebug()<<"保存信息";
       this->close();
    });
    connect(UpdateHeadButton,&QPushButton::clicked,[&](){
        QString headIcon = QFileDialog::getOpenFileName(this,tr("选择头像"),tr("/home"),tr("Images(*jpg *png *ico)"));
        qDebug()<<headIcon;
        if(headIcon==""){
            return ;
        }
        QPixmap icon = QPixmap(headIcon);
        QPixmap scaledIcon = icon.scaled(HeadIconLael->width(),HeadIconLael->height(),Qt::KeepAspectRatio,Qt::SmoothTransformation);
        //qDebug()<<HeadIconLael->width()<<" "<<HeadIconLael->height();
        HeadIconLael->setPixmap(scaledIcon);
    });
}
