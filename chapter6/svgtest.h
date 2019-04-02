#ifndef SVGTEST_H
#define SVGTEST_H

#include <QMainWindow>
#include <QtSvg>
#include <QSvgWidget>
#include <QSvgRenderer>

class SVGTest : public QSvgWidget
{
    Q_OBJECT
public:
    explicit SVGTest(QWidget *parent = nullptr);
    void wheelEvent(QWheelEvent *event);
signals:

public slots:

private:
    QSvgRenderer *render;
};

#endif // SVGTEST_H
