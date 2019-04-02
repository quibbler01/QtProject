#include "paintarea.h"

PaintArea::PaintArea(QWidget *parent) : QWidget(parent)
{
    this->setPalette(QPalette(Qt::white));
    this->setAutoFillBackground(true);
    this->resize(400,400);
}

void PaintArea::setShape(PaintArea::Shape shape)
{
    this->shape = shape;
    this->update();
}

void PaintArea::setPen(QPen pen)
{
    this->pen = pen;
    update();
}

void PaintArea::setBrush(QBrush brush)
{
    this->brush = brush;
    update();
}

void PaintArea::setFillRule(Qt::FillRule fillRule)
{
    this->fillRule = fillRule;
    update();
}
/*
    update()会触发paintEvent事件
*/
void PaintArea::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event)
    QPainter p(this);
    p.setPen(this->pen);
    p.setBrush(this->brush);
    QRect rect(50,100,300,200);
    static const QPoint points[4]={
        QPoint(150,100),
        QPoint(300,150),
        QPoint(350,250),
        QPoint(100,300)
    };
    int startAngle  =30*16;
    int spanAngle = 120*16;
    QPainterPath path;
    path.addRect(150,150,100,100);
    path.moveTo(100,100);
    path.cubicTo(300,100,200,200,300,300);
    path.cubicTo(100,300,200,200,100,100);
    path.setFillRule(this->fillRule);
    switch (shape) {
    case Shape::Line:
        p.drawLine(rect.topLeft(),rect.bottomRight());
        break;
    case Rectangle:
        p.drawRect(rect);break;
    case RoundRect:
        p.drawRoundRect(rect);break;
    case Ellipse:
        p.drawEllipse(rect);break;
    case Polygon:
        p.drawPolygon(points,4);break;
    case Polyline:
        p.drawPolyline(points,4);break;
    case Points:
        p.drawPoints(points,4);break;
    case Arc:
        p.drawArc(rect,startAngle,spanAngle);break;
    case Path:
        p.drawPath(path);break;
    case Text:
        p.drawText(rect,Qt::AlignCenter,tr("Hello Qt!"));break;
    case Pixmap:
        p.drawPixmap(150,150,QPixmap(":/img/color_palette_1876px_1202956_easyicon.net.png"));break;
    default:
        break;
    }
}

