#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent)
{
    createActions();
    createMenu();
    scene = new QGraphicsScene;
    scene->setSceneRect(-200,-200,400,400);
    initScene();
    QGraphicsView *view = new QGraphicsView;
    view->setScene(scene);
    view->setMinimumSize(400,400);
    view->show();
    setCentralWidget(view);
    resize(550,450);
    setWindowTitle(tr("Graphics Items"));
}

MainWindow::~MainWindow()
{

}

void MainWindow::initScene()
{
    int i;
    for(i=0;i<3;++i){
        slotAddEllipseItem();
    }
    for(i=0;i<3;++i){
        slotAddPolygonItem();
    }
    for(i=0;i<3;++i){
        slotAddTextItem();
    }
    for(i=0;i<3;++i){
        slotAddRectItem();
    }
    for(i=0;i<3;++i){
        slotAddAlphaItem();
    }
}

void MainWindow::createActions()
{
    newAct = new QAction(tr("新建"),this);
    clearAct = new QAction(tr("清除"),this);
    exitAct = new QAction(tr("退出"),this);
    addEllipseAct = new QAction(tr("添加椭圆"),this);
    addPolygonAct = new QAction(tr("添加多边形"),this);
    addTextAct = new QAction(tr("添加文字"),this);
    addRectAct = new QAction(tr("添加矩形"),this);
    addAlphaAct = new QAction(tr("添加图片"),this);
    addFlashAct = new QAction(tr("添加闪图"),this);
    addStarAct = new QAction(tr("添加星星"),this);
    connect(newAct,SIGNAL(triggered()),this,SLOT(slotNew()));
    connect(clearAct,SIGNAL(triggered()),this,SLOT(slotClear()));
    connect(addEllipseAct,SIGNAL(triggered()),this,SLOT(slotAddEllipseItem()));
    connect(addPolygonAct,SIGNAL(triggered()),this,SLOT(slotAddPolygonItem()));
    connect(addTextAct,SIGNAL(triggered()),this,SLOT(slotAddTextItem()));
    connect(addRectAct,SIGNAL(triggered()),this,SLOT(slotAddRectItem()));
    connect(addAlphaAct,SIGNAL(triggered()),this,SLOT(slotAddAlphaItem()));
    connect(addFlashAct,SIGNAL(triggered()),this,SLOT(slotAddFlashItem()));
    connect(addStarAct,SIGNAL(triggered()),this,SLOT(slotAddStarItem()));
}

void MainWindow::createMenu()
{
    QMenu *fileMenu = menuBar()->addMenu(tr("文件"));
    fileMenu->addAction(newAct);
    fileMenu->addAction(clearAct);
    fileMenu->addSeparator();
    fileMenu->addAction(exitAct);

    QMenu *itemsMenu = menuBar()->addMenu(tr("图元"));
    itemsMenu->addAction(addEllipseAct);
    itemsMenu->addAction(addPolygonAct);
    itemsMenu->addAction(addTextAct);
    itemsMenu->addAction(addRectAct);
    itemsMenu->addAction(addAlphaAct);
    itemsMenu->addSeparator();
    itemsMenu->addAction(addFlashAct);
    itemsMenu->addAction(addStarAct);
}

void MainWindow::slotNew()
{
    slotClear();
    initScene();
    MainWindow *newWin = new MainWindow;
    //newWin->initScene();
    newWin->show();
}

void MainWindow::slotClear()
{
    QList<QGraphicsItem*> listItem = scene->items();
    while(!listItem.empty()){
        scene->removeItem(listItem.at(0));
        listItem.removeAt(0);
    }
}

void MainWindow::slotAddEllipseItem()
{
    QGraphicsEllipseItem *item = new QGraphicsEllipseItem(QRectF(0,0,80,60));
    item->setPen(Qt::NoPen);
    item->setBrush(QColor(qrand()%256,qrand()%256,qrand()%256));
    item->setFlag(QGraphicsItem::ItemIsMovable);
    scene->addItem(item);
    item->setPos((qrand()%int(scene->sceneRect().width()))-200,(qrand()%int(scene->sceneRect().height()))-200);
}

void MainWindow::slotAddPolygonItem()
{
    QVector<QPoint> v;
    v<<QPoint(30,15)<<QPoint(0,-30)<<QPoint(30,15)<<QPoint(-30,15)<<QPoint(0,30)<<QPoint(30,15);
    QGraphicsPolygonItem *item = new QGraphicsPolygonItem(QPolygonF(v));
    item->setBrush(QColor(qrand()%256,qrand()%256,qrand()%256));
    item->setFlag(QGraphicsItem::ItemIsMovable);
    scene->addItem(item);
    item->setPos((qrand()%(int)(scene->sceneRect().width()))-200,(qrand()%(int)(scene->sceneRect().height()))-200);
}

void MainWindow::slotAddTextItem()
{
    QFont font("Times",16);
    QGraphicsTextItem *item = new QGraphicsTextItem("Hello Qt");
    item->setFont(font);
    item->setFlag(QGraphicsItem::ItemIsMovable);
    item->setDefaultTextColor(QColor(qrand()%256,qrand()%256,qrand()%256));
    scene->addItem(item);
    item->setPos((qrand()%(int)(scene->sceneRect().width()))-200,(qrand()%(int)(scene->sceneRect().height()))-200);
}

void MainWindow::slotAddRectItem()
{
    QGraphicsRectItem *item = new QGraphicsRectItem;
    QPen pen;
    pen.setWidth(3);
    pen.setColor(QColor(qrand()%256,qrand()%256,qrand()%256));
    item->setPen(pen);
    item->setBrush(QColor(qrand()%256,qrand()%256,qrand()%256));
    item->setFlag(QGraphicsItem::ItemIsMovable);
    scene->addItem(item);
    item->setPos((qrand()%(int)(scene->sceneRect().width()))-200,(qrand()%(int)(scene->sceneRect().height()))-200);
}

void MainWindow::slotAddAlphaItem()
{
    QGraphicsPixmapItem *item = new QGraphicsPixmapItem(QPixmap(":/img/delicacy_Butterfly_386.64480874317px_1163157_easyicon.net.png"));
    item->setFlag(QGraphicsItem::ItemIsMovable);
    scene->addItem(item);
    item->setPos((qrand()%(int)(scene->sceneRect().width()))-200,(qrand()%(int)(scene->sceneRect().height()))-200);
}

void MainWindow::slotAddFlashItem()
{
    FlashItem *item = new FlashItem;
    scene->addItem(item);
    item->setPos((qrand()%(int)(scene->sceneRect().width()))-200,(qrand()%(int)(scene->sceneRect().height()))-200);
}

void MainWindow::slotAddStarItem()
{
    qDebug()<<"star";
    StartItem *item = new StartItem();
    QGraphicsItemAnimation *anim = new QGraphicsItemAnimation;
    anim->setItem(item);
    QTimeLine *timeLine = new QTimeLine(4000);
    timeLine->setCurveShape(QTimeLine::SineCurve);
    timeLine->setLoopCount(0);
    anim->setTimeLine(timeLine);
    int y = (qrand()%400)-200;
    for(int i = 0;i<400;++i){
        anim->setPosAt(i/400.0,QPointF(i-200,y));

    }
    timeLine->start();
    scene->addItem(item);
    //item->setPos((qrand()%(int)(scene->sceneRect().width()))-200,(qrand()%(int)(scene->sceneRect().height()))-200);
}
