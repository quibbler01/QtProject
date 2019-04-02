#ifndef ITEMMOTION_H
#define ITEMMOTION_H

#include <QWidget>
#include <QLabel>
#include <QPushButton>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QFrame>
#include <QHBoxLayout>
#include <QSlider>
#include <QGroupBox>
#include <QDebug>
#include "pixitem.h"

class ItemMotion : public QWidget
{
    Q_OBJECT
public:
    explicit ItemMotion(QWidget *parent = nullptr);
    ~ItemMotion();
    void createControlFrame();
private:
    int angle;
    qreal scaleValue;
    qreal shearValuel;
    qreal translateValue;
    QGraphicsView *view;
    QFrame *ctrlFrame;

    PixItem *pixItem;

signals:

public slots:
    void slotRotate(int value);
    void slotScale(int value);
    void slotShear(int value);
    void slotTranslate(int value);
};

#endif // ITEMMOTION_H
