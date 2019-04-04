#include "dialog.h"
#include "timeserver.h"
#include <QMessageBox>

Dialog::Dialog(QWidget *parent) : QWidget(parent)
{
    this->setWindowTitle(tr("多线程时间服务器"));
    label1 = new QLabel(tr("服务器端口"));
    label2 = new QLabel(tr("第次请求完毕"));
    quitBtn = new QPushButton(tr("退出"));
    QHBoxLayout *BtnLayout = new QHBoxLayout;
    BtnLayout->addStretch(1);
    BtnLayout->addWidget(quitBtn);
    BtnLayout->addStretch(1);
    QVBoxLayout *mainLayout = new QVBoxLayout(this);
    mainLayout->addWidget(label1);
    mainLayout->addWidget(label2);
    mainLayout->addLayout(BtnLayout);
    connect(quitBtn,SIGNAL(clicked()),this,SLOT(close()));

    count = 0;
    timeServer = new TimeServer(this);
    if(!timeServer->listen()){
        QMessageBox::critical(this,tr("多线程服务器"),tr("无法启动服务：%1").arg(timeServer->errorString()));
        close();
        return;
    }
    label1->setText(tr("服务器端口:%1").arg(timeServer->serverPort()));
}

Dialog::~Dialog()
{

}

void Dialog::slotShow()
{
    qDebug()<<count+1;
    label2->setText(tr("第%1次请求完毕").arg(++count));
}
