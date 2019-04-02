#include "drawwidget.h"
#include <QtGui>

DrawWidget::DrawWidget(QWidget *parent) : QWidget(parent)
{
    this->setAutoFillBackground(true);
    this->setPalette(QPalette(Qt::white));
    pix = new QPixmap(this->size());
    pix->fill(Qt::white);
    this->setMinimumSize(600,400);
}

DrawWidget::~DrawWidget()
{
    //delete pix;
}

void DrawWidget::mouseMoveEvent(QMouseEvent *mouseMoveEvent)
{
    QPainter *painter = new QPainter;
    QPen pen;
    pen.setStyle(static_cast<Qt::PenStyle>(style));
    pen.setWidth(wide);
    pen.setColor(color);
    painter->begin(pix);
    painter->setPen(pen);
    painter->drawLine(startPos,mouseMoveEvent->pos());
    painter->end();
    //printf("Draw:%i,%i",mouseMoveEvent->pos().x(),mouseMoveEvent->pos().y());
    startPos = mouseMoveEvent->pos();
    update();
}

void DrawWidget::mousePressEvent(QMouseEvent *mousePressEvent)
{
    startPos = mousePressEvent->pos();
}
//update()
void DrawWidget::paintEvent(QPaintEvent *paintEvent)
{
    QPainter *painter = new QPainter(this);
    painter->drawPixmap(QPoint(0,0),*pix);
}

void DrawWidget::resizeEvent(QResizeEvent *resizeEvent)
{
    if(this->height() >pix->height()|| this->width() >pix->width()){
        QPixmap *newPix = new QPixmap(this->size());
        QPainter p(newPix);
        p.drawPixmap(QPoint(0,0),*pix);
        pix = newPix;
    }
    QWidget::resizeEvent(resizeEvent);
}

void DrawWidget::setStyle(int style)
{
    this->style = style;
}

void DrawWidget::setWidth(int width)
{
    this->wide = width;
}

void DrawWidget::setColor(QColor color)
{
    this->color = color;
}

void DrawWidget::clear()
{
    QPixmap *clearMap = new QPixmap;
    clearMap->fill(Qt::white);
    pix = clearMap;
    //调用update()会触发paintEvent();
    update();
}
