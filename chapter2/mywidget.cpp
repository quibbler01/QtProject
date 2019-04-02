#include "mywidget.h"
#include <QDebug>

MyWidget::MyWidget(QWidget *parent):QWidget (parent)
{
    this->setMinimumSize(200,120);
    this->setMaximumSize(200,120);
    QPushButton *quit = new QPushButton("Quit",this);
    quit->setGeometry(62,40,75,30);
    quit->setFont(QFont("Times",18,QFont::Bold));
    connect(quit,SIGNAL(clicked()),this,SLOT(close()));
    connect(quit,&QPushButton::clicked,[=](){
        qDebug()<<"Quit Clicked";
    });
}

MyWidget::~MyWidget()
{

}
