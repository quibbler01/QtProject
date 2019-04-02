#include "messagedialog.h"

MessageDialog::MessageDialog(QWidget *parent):QWidget (parent)
{
    this->setWindowTitle(tr("标准消息对话框实例"));
    label = new QLabel(tr("选择一条消息框"));
    questionBtn  =new QPushButton(tr("Question Msg"));
    informationBtn = new QPushButton(tr("Information Msg"));
    warningBtn = new QPushButton(tr("Warning Msg"));
    criticalBtn = new QPushButton(tr("Critaical Msg"));
    aboutBtn = new QPushButton(tr("About Msg"));
    aboutQtBtn = new QPushButton(tr("About Qt Msg"));
    customBtn = new QPushButton(tr("定制消息框"));
    /****************************Layout******************************/
    mainLayout = new QGridLayout(this);
    mainLayout->addWidget(label,0,0,1,2);
    mainLayout->addWidget(questionBtn,1,0);
    mainLayout->addWidget(informationBtn,1,1);
    mainLayout->addWidget(warningBtn,2,0);
    mainLayout->addWidget(criticalBtn,2,1);
    mainLayout->addWidget(aboutBtn,3,0);
    mainLayout->addWidget(aboutQtBtn,3,1);
    mainLayout->addWidget(customBtn,4,0,1,1);
    /*****************************Connect SIGNAL and SLOT*****************************/
    connect(questionBtn,&QPushButton::clicked,[&](){
        QMessageBox::question(this,tr("Question对话框"),tr("结束程序？"),QMessageBox::Ok|QMessageBox::Cancel,QMessageBox::Ok);
    });

    connect(informationBtn,&QPushButton::clicked,[&](){
        QMessageBox::information(this,tr("消息"),tr("提示信息"));
    });

    connect(warningBtn,&QPushButton::clicked,[&](){
        auto result = QMessageBox::warning(this,tr("警告"),tr("未保存"),QMessageBox::Save|QMessageBox::Discard|QMessageBox::Cancel,QMessageBox::Save);
        switch(result){
            case QMessageBox::Save :
                qDebug()<<tr("保存");
                break;
        case QMessageBox::Cancel:
            qDebug()<<tr("取消");
            break;
        case QMessageBox::Discard:
            qDebug()<<tr("放弃修改");
            break;
        default:
            break;
        }

    });

    connect(criticalBtn,&QPushButton::clicked,[&](){
        QMessageBox::critical(this,tr("Critical消息"),tr("Critaical!!!"));
        return;
    });

    connect(aboutBtn,&QPushButton::clicked,[&](){
        QMessageBox::about(this,tr("关于"),tr("这是Chapter About"));
    });

    connect(aboutQtBtn,&QPushButton::clicked,[&](){
        QMessageBox::aboutQt(this,tr("关于Qt消息框"));
    });

    connect(customBtn,&QPushButton::clicked,[&](){
        QMessageBox customMessageBox;
        customMessageBox.setWindowTitle(tr("用户自定义消息框"));
        QPushButton *yesBtn = customMessageBox.addButton(tr("Yes"),QMessageBox::ActionRole);
        QPushButton *noBtn = customMessageBox.addButton(tr("No"),QMessageBox::ActionRole);
        QPushButton *cancleBtn =  customMessageBox.addButton(QMessageBox::Cancel);
        customMessageBox.setText(tr("这是一条用户自定义的消息框，请选择"));
        customMessageBox.setIconPixmap(QPixmap(":/img/message_warning_128px_1228659_easyicon.net.ico"));
        customMessageBox.exec();

        if(customMessageBox.clickedButton()==yesBtn){
            qDebug()<<"Yes";
        }else if(customMessageBox.clickedButton()==noBtn){
            qDebug()<<"No";
        }else{
            qDebug()<<"Cancel";
        }

    });
}
