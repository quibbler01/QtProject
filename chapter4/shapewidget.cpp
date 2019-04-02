#include "shapewidget.h"

ShapeWidget::ShapeWidget(QWidget *parent) : QWidget(parent)
{
    //QPixmap pix;
    pix.load(":/img/frame/butterfly.png",0,Qt::AvoidDither|Qt::ThresholdDither|Qt::ThresholdAlphaDither);
    this->resize(pix.size());
    //设置Widget蒙版
    this->setMask(QBitmap(pix.mask()));
}

void ShapeWidget::mousePressEvent(QMouseEvent *event)
{
    if(event->button()==Qt::LeftButton){
        dragPosition = event->globalPos()-frameGeometry().topLeft();
        event->accept();
    }
    if(event->button()==Qt::RightButton){
        this->close();
    }
}

void ShapeWidget::mouseMoveEvent(QMouseEvent *event)
{
    if(event->buttons()&Qt::LeftButton){
        move(event->globalPos()-dragPosition);
        event->accept();
    }
}

void ShapeWidget::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    painter.drawPixmap(0,0,pix);
}

ShapeWidget::~ShapeWidget()
{

}
