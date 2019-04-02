﻿#ifndef PIXITEM_H
#define PIXITEM_H

#include <QObject>
#include <QGraphicsItem>
#include <QPixmap>
#include <QPainter>

class PixItem : public QObject,public QGraphicsItem
{
    Q_OBJECT
public:
    //explicit PixItem(QObject *parent = nullptr);
    PixItem(QPixmap *pixmap);
    QRectF boundingRect() const;
    void paint(QPainter *painter,const QStyleOptionGraphicsItem *option,QWidget *widget);
private:
    QPixmap pix;
signals:

public slots:
};

#endif // PIXITEM_H
