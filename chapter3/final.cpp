#include "final.h"

Final::Final(QWidget *parent) : QWidget(parent)
{
    QGridLayout *layout = new QGridLayout(this);
    splitterMain = new QSplitter(Qt::Horizontal,nullptr);
    splitterMain->setOpaqueResize(true);
    list = new QListWidget(splitterMain);
    list->insertItem(0,tr("基本信息"));
    list->insertItem(1,tr("联系方式"));
    list->insertItem(2,tr("详细信息"));
    content = new Content(splitterMain);
    connect(list,SIGNAL(currentRowChanged(int)),content->stack,SLOT(setCurrentIndex(int)));
    //splitterMain->setWindowTitle(tr("修改用户资料"));
    //splitterMain->setSizePolicy(QSizePolicy::Fixed);
    layout->addWidget(splitterMain);
    layout->setSizeConstraint(QLayout::SetFixedSize);
}
