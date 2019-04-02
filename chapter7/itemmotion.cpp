#include "itemmotion.h"

ItemMotion::ItemMotion(QWidget *parent) : QWidget(parent)
{
    angle = 0;
    scaleValue = 5;
    shearValuel = 5;
    translateValue = 50;
    QGraphicsScene *scene = new QGraphicsScene;
    scene->setSceneRect(-200,-200,400,400);

    QPixmap *pixmap = new QPixmap(":/img/star_783px_1221876_easyicon.net.png");
    pixItem = new PixItem(pixmap);
    scene->addItem(pixItem);
    pixItem->setPos(0,0);

    view  = new QGraphicsView;
    view->setScene(scene);
    view->setMinimumSize(400,400);
    ctrlFrame = new QFrame;
    createControlFrame();
    //
    QHBoxLayout *mainLayout = new QHBoxLayout;
    mainLayout->setMargin(10);
    mainLayout->setSpacing(20);
    mainLayout->addWidget(view);
    mainLayout->addWidget(ctrlFrame);
    this->setLayout(mainLayout);
    this->setWindowTitle(tr("Graphics Item Transformation"));
}

ItemMotion::~ItemMotion()
{

}

void ItemMotion::createControlFrame()
{
    QSlider *rotateSlider = new QSlider;
    rotateSlider->setOrientation(Qt::Horizontal);
    rotateSlider->setRange(0,360);
    QHBoxLayout *rotateLayout = new QHBoxLayout;
    rotateLayout->addWidget(rotateSlider);
    QGroupBox *rotateGroup = new QGroupBox(tr("rotate"));
    rotateGroup->setLayout(rotateLayout);

    QSlider *scaleSlider = new QSlider;
    scaleSlider->setOrientation(Qt::Horizontal);
    scaleSlider->setRange(0,2*scaleValue);
    QHBoxLayout *scaleLayout = new QHBoxLayout;
    scaleLayout->addWidget(scaleSlider);
    QGroupBox *scaleGroup = new QGroupBox(tr("Scale"));
    scaleGroup->setLayout(scaleLayout);

    QSlider *shearSlider = new QSlider;
    shearSlider->setOrientation(Qt::Horizontal);
    shearSlider->setRange(0,2*shearValuel);
    QHBoxLayout *shearLayout = new QHBoxLayout;
    shearLayout->addWidget(shearSlider);
    QGroupBox *shearGroup = new QGroupBox(tr("shear"));
    shearGroup->setLayout(shearLayout);

    QSlider *transSlider = new QSlider;
    transSlider->setOrientation(Qt::Horizontal);
    transSlider->setRange(0,2*translateValue);
    QHBoxLayout *transLayout = new QHBoxLayout;
    transLayout->addWidget(transSlider);
    QGroupBox *transGroup = new QGroupBox(tr("transfer"));
    transGroup->setLayout(transLayout);

    QVBoxLayout *frameLayout = new QVBoxLayout;
    frameLayout->setMargin(10);
    frameLayout->setSpacing(20);
    frameLayout->addWidget(rotateGroup);
    frameLayout->addWidget(scaleGroup);
    frameLayout->addWidget(shearGroup);
    frameLayout->addWidget(transGroup);
    ctrlFrame->setLayout(frameLayout);

    //connect
    connect(rotateSlider,SIGNAL(valueChanged(int)),this,SLOT(slotRotate(int)));
    connect(scaleSlider,SIGNAL(valueChanged(int)),this,SLOT(slotScale(int)));
    connect(shearSlider,SIGNAL(valueChanged(int)),this,SLOT(slotShear(int)));
    connect(transSlider,SIGNAL(valueChanged(int)),this,SLOT(slotTranslate(int)));
}

void ItemMotion::slotRotate(int value)
{
    view->rotate(value-angle);
    angle = value;
}

void ItemMotion::slotScale(int value)
{
    qreal s;
    if(value>scaleValue){
        s = pow(1.1,(value-scaleValue));
    }else{
        s = pow(1/1.1,(scaleValue-value));
    }
    view->scale(s,s);
    scaleValue=value;
}

void ItemMotion::slotShear(int value)
{
    view->shear((value-shearValuel)/10.0,0.0);
    shearValuel=value;
}

void ItemMotion::slotTranslate(int value)
{
    qDebug()<<"Translate";
    view->translate(value-translateValue,value-translateValue);
    translateValue=value;
}
