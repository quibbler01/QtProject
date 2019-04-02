#ifndef SVGWINDOWN_H
#define SVGWINDOWN_H

#include <QScrollArea>
#include "svgtest.h"

class SvgWindown : public QScrollArea
{
    Q_OBJECT
public:
    SvgWindown(QWidget *parent = nullptr);
    void setFile(QString);
    void mousePressEvent(QMouseEvent*);
    void mouseMoveEvent(QMouseEvent*);
private:
    SVGTest *svgTest;
    QPoint mousePressPos;
    QPoint scrollBarValueOnMousePress;
};

#endif // SVGWINDOWN_H
