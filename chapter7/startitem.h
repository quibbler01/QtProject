#ifndef STARTITEM_H
#define STARTITEM_H

#include <QObject>
#include <QGraphicsItem>
#include <QPixmap>
#include <QRectF>
#include <QPainter>
#include <QDebug>

class StartItem : public QObject,public QGraphicsItem
{
    Q_OBJECT
public:
    StartItem();
    QRectF boundingRect() const;
    void paint(QPainter *painter,const QStyleOptionGraphicsItem *option,QWidget *widget);
private:
    QPixmap pix;
signals:

public slots:
};

#endif // STARTITEM_H
