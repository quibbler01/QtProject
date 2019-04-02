#include "svgtest.h"

SVGTest::SVGTest(QWidget *parent) : QSvgWidget(parent)
{
    this->render = renderer();
}

void SVGTest::wheelEvent(QWheelEvent *event)
{
    const double diff = 0.1;
    QSize size = render->defaultSize();
    int width = size.width();
    int height = size.height();
    if(event->delta()>0){
        width = int(this->width()+this->width()*diff);
        height = int(this->height()+this->height()*diff);
    }else{
        width = int(this->width()-this->width()*diff);
        height = int(this->height()-this->height()*diff);
    }
    resize(width,height);
}
