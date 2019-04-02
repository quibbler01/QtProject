#include "butterfly.h"

ButterFly::ButterFly(QObject *parent) : QObject(parent)
{
    up = true;
    pix_up.load(":/img/delicacy_Butterfly_386.64480874317px_1163157_easyicon.net.png");
    pix_down.load(":/img/feminine_Butterfly_218.34962406015px_1163158_easyicon.net.png");
    this->startTimer(300);
}

void ButterFly::timerEvent(QTimerEvent *)
{
    qreal edgex = scene()->sceneRect().right()+boundingRect().width()/2;
    qreal edgetop = scene()->sceneRect().top()+boundingRect().height()/2;
    qreal edgebottom = scene()->sceneRect().bottom()+boundingRect().height()/2;
    if(pos().x()>=edgex){
        setPos(scene()->sceneRect().left(),pos().y());
    }
    if(pos().y()<=edgetop){
        setPos(pos().x(),scene()->sceneRect().bottom());
    }
    if(pos().y()>=edgebottom){
        setPos(pos().x(),scene()->sceneRect().top());
    }
    angle+=(qrand()%10)/20.0;
    qreal dx = fabs(sin(angle*M_PI)*10.0);
    qreal dy = (qrand()%20)-10.0;
    setPos(mapToParent(dx,dy));

}

QRectF ButterFly::boundingRect() const
{
    qreal adjust = 2;
    return QRectF(-pix_up.width()/2-adjust,-pix_up.height()/2-adjust,pix_up.width()+adjust*2,pix_up.height()+adjust*2);
}

void ButterFly::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    if(up){
        painter->drawPixmap(boundingRect().topLeft(),pix_up);
        up=!up;
    }else{
        painter->drawPixmap(boundingRect().topLeft(),pix_down);
        up=!up;
    }
}
