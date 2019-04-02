#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QAction>
#include <QMenu>
#include <QMenuBar>
#include <QGraphicsEllipseItem>
#include <QRect>
#include <QVector>
#include <QPoint>
#include <QDebug>
#include <QGraphicsItemAnimation>
#include <QTimeLine>
#include "flashitem.h"
#include <startitem.h>

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void initScene();
    void createActions();
    void createMenu();
 public slots:
    void slotNew();
    void slotClear();
    void slotAddEllipseItem();
    void slotAddPolygonItem();
    void slotAddTextItem();
    void slotAddRectItem();
    void slotAddAlphaItem();

    void slotAddFlashItem();
    void slotAddStarItem();

private:
    QGraphicsScene *scene;
    QAction *newAct;
    QAction *clearAct;
    QAction *exitAct;
    QAction *addEllipseAct;
    QAction *addPolygonAct;
    QAction *addTextAct;
    QAction *addRectAct;
    QAction *addAlphaAct;

    QAction *addFlashAct;
    QAction *addStarAct;
};

#endif // MAINWINDOW_H
