#include "stackwindow.h"
#include <QHBoxLayout>

StackWindow::StackWindow(QDialog *parent):QDialog (parent)
{
    setWindowTitle("StackedWidget");
    list = new QListWidget(this);
    list->insertItem(0,"Window1");
    list->insertItem(1,"Window2");
    list->insertItem(2,"Window3");

    label1 = new QLabel("WindowTest1");
    label2 = new QLabel("WindowTest2");
    label3 = new QLabel("WindowTest3");

    stack = new QStackedWidget(this);
    stack->addWidget(label1);
    stack->addWidget(label2);
    stack->addWidget(label3);

    QHBoxLayout *mainLayout = new QHBoxLayout(this);

    mainLayout->setMargin(5);
    mainLayout->setSpacing(5);
    mainLayout->addWidget(list);
    mainLayout->addWidget(stack,0,Qt::AlignHCenter);
    mainLayout->setStretchFactor(list,1);
    mainLayout->setStretchFactor(stack,3);
    connect(list,SIGNAL(currentRowChanged(int)),stack,SLOT(setCurrentIndex(int)));

}

StackWindow::~StackWindow()
{

}
