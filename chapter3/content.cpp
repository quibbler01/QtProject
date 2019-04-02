#include "content.h"

Content::Content(QWidget *parent) : QWidget(parent)
{
    stack = new QStackedWidget(this);
    stack->setFrameStyle(QFrame::Panel|QFrame::Raised);
    /*******************三个页面,放入Stack***************************/
    baseInfo = new BaseInfo;
    contact = new Contact;
    detail = new Detail;
    stack->addWidget(baseInfo);
    stack->addWidget(contact);
    stack->addWidget(detail);
    /***************Create two Button******************/
    AmendBtn = new QPushButton(tr("修改"));
    CloseBtn = new QPushButton(tr("关闭"));
    QHBoxLayout *BtnLayout = new QHBoxLayout;
    BtnLayout->addStretch(1);
    BtnLayout->addWidget(AmendBtn);
    BtnLayout->addWidget(CloseBtn);
    /********************Total Layout***********************/
    QVBoxLayout *Mainlayout = new QVBoxLayout(this);
    Mainlayout->setMargin(10);
    Mainlayout->setSpacing(5);
    Mainlayout->addWidget(stack);
    Mainlayout->addLayout(BtnLayout);
}

Content::~Content()
{

}
