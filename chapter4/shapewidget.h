#ifndef SHAPEWIDGET_H
#define SHAPEWIDGET_H

#include <QWidget>
#include <QPixmap>
#include <QBitmap>
#include <QPainter>
#include <QMouseEvent>

class ShapeWidget : public QWidget
{
    Q_OBJECT
public:
    explicit ShapeWidget(QWidget *parent = nullptr);
    ~ShapeWidget();
protected:
    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void paintEvent(QPaintEvent *event);
signals:

public slots:

private:
    QPoint dragPosition;
    QPixmap pix;
};

#endif // SHAPEWIDGET_H
