#ifndef BUTTERFLY_H
#define BUTTERFLY_H

#include <QObject>
#include <QGraphicsItem>
#include <QPainter>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <math.h>

class ButterFly : public QObject,public QGraphicsItem
{
    Q_OBJECT
public:
    explicit ButterFly(QObject *parent = nullptr);
    void timerEvent(QTimerEvent*);
    QRectF boundingRect() const;

signals:

public slots:
    void paint(QPainter *painter,const QStyleOptionGraphicsItem *option,QWidget *widget);
private:
    bool up;
    QPixmap pix_up;
    QPixmap pix_down;
    qreal angle;
};

#endif // BUTTERFLY_H
