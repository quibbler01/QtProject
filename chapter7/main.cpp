#include "mainwindow.h"
#include "butterfly.h"
#include "itemmotion.h"
#include <QApplication>
#include <QGraphicsScene>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

//    QGraphicsScene *scene = new QGraphicsScene;
//    scene->setSceneRect(QRectF(-200,-200,400,400));
//    ButterFly *butterFly = new ButterFly;
//    butterFly->setPos(-100,0);
//    scene->addItem(butterFly);
//    QGraphicsView *view = new QGraphicsView;
//    view->setScene(scene);
//    view->resize(400,400);
//    view->show();

    ItemMotion w;
    w.show();

    return a.exec();
}
