#include "startitem.h"

StartItem::StartItem()
{
    qDebug()<<"load start pixmap";
    pix.load(":/img/star_783px_1221876_easyicon.net.png");
}

QRectF StartItem::boundingRect() const
{
    return QRectF(-pix.width()/2,-pix.height()/2,pix.width(),pix.height());
}

void StartItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->drawPixmap(boundingRect().topLeft(),pix);
}
