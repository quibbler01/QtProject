#include "svgwindown.h"

SvgWindown::SvgWindown(QWidget *parent):QScrollArea (parent)
{
    svgTest = new SVGTest;
    this->setWidget(svgTest);
}

void SvgWindown::setFile(QString fileName)
{
    svgTest->load(fileName);
    QSvgRenderer *render = svgTest->renderer();
    svgTest->resize(render->defaultSize());
}

void SvgWindown::mousePressEvent(QMouseEvent *event)
{
    mousePressPos = event->pos();
    scrollBarValueOnMousePress.rx() = horizontalScrollBar()->value();
    scrollBarValueOnMousePress.ry() = verticalScrollBar()->value();
    event->accept();
}

void SvgWindown::mouseMoveEvent(QMouseEvent *event)
{
    horizontalScrollBar()->setValue(scrollBarValueOnMousePress.x()-event->pos().x()+mousePressPos.x());
    verticalScrollBar()->setValue(scrollBarValueOnMousePress.y()-event->pos().y()+mousePressPos.y());
    horizontalScrollBar()->update();
    verticalScrollBar()->update();
    event->accept();
}
