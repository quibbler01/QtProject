#include "geometry.h"

Geometry::Geometry(QWidget *parent):QDialog(parent)
{
    this->setWindowTitle(tr("Geometry"));
    xLabel = new QLabel(tr("x():"));
    xValueLabel = new QLabel;
    yLabel = new QLabel(tr("y():"));
    yValueLabel = new QLabel;
    FrmLabel = new QLabel(tr("Frame:"));
    FrmValueLabel = new QLabel();
    posLabel = new QLabel(tr("Position:"));
    posValueLabel =  new QLabel;
    geoLabel = new QLabel(tr("Geometry:"));
    geoValueLabel = new QLabel;
    widthLabel = new QLabel(tr("width:"));
    widthValueLabel = new QLabel;
    heightLabel = new QLabel(tr("height:"));
    heightValueLabel = new QLabel;
    rectLabel = new QLabel(tr("rect():"));
    rectValueLabel = new QLabel;
    sizeLabel = new QLabel(tr("size():"));
    sizeValueLabel = new QLabel;
    mainLayout = new QGridLayout(this);
    mainLayout->addWidget(xLabel,0,0);
    mainLayout->addWidget(xValueLabel,0,1);
    mainLayout->addWidget(yLabel,1,0);
    mainLayout->addWidget(yValueLabel,1,1);
    mainLayout->addWidget(FrmLabel,2,0);
    mainLayout->addWidget(FrmValueLabel,2,1);
    mainLayout->addWidget(posLabel,3,0);
    mainLayout->addWidget(posValueLabel,3,1);
    mainLayout->addWidget(geoLabel,4,0);
    mainLayout->addWidget(geoValueLabel,4,1);
    mainLayout->addWidget(widthLabel,5,0);
    mainLayout->addWidget(widthValueLabel,5,1);
    mainLayout->addWidget(heightLabel,6,0);
    mainLayout->addWidget(heightValueLabel,6,1);
    mainLayout->addWidget(rectLabel,7,0);
    mainLayout->addWidget(rectValueLabel,7,1);
    mainLayout->addWidget(sizeLabel,8,0);
    mainLayout->addWidget(sizeValueLabel,8,1);
    updateLabel();
    this->resize(500,400);
}

Geometry::~Geometry()
{

}

void Geometry::updateLabel()
{
    QString xStr;
    xValueLabel->setText(xStr.setNum(this->x()));
    QString yStr;
    yValueLabel->setText(yStr.setNum(this->y()));
    QString frameStr;
    QString tmpStr1,tmpStr2,tmpStr3,tmpStr4;
    frameStr = tmpStr1.setNum(this->frameGeometry().x())+","+tmpStr2.setNum(this->frameGeometry().y())
            +","+tmpStr3.setNum(this->frameGeometry().width())+","+tmpStr4.setNum(this->frameGeometry().height());
    FrmValueLabel->setText(frameStr);
    QString positionStr,tmpPosition1,tmpPosition2;
    tmpPosition1.setNum(this->pos().x());
    tmpPosition2.setNum(this->pos().y());
    positionStr = tmpPosition1+","+tmpPosition2;
    posValueLabel->setText(positionStr);
    QString geoStr,tmpGeo1,tmpGeo2,tmpGeo3,tmpGeo4;
    geoStr = tmpGeo1.setNum(this->geometry().x())+","+tmpGeo2.setNum(this->geometry().y())+","+tmpGeo3.setNum(this->geometry().width())
            +","+tmpGeo4.setNum(this->geometry().height());
    geoValueLabel->setText(geoStr);
    QString widthStr,heightStr;
    widthValueLabel->setText(widthStr.setNum(this->width()));
    heightValueLabel->setText(heightStr.setNum(this->height()));
    QString rectStr,rect1,rect2,rect3,rect4;
    rectStr = rect1.setNum(this->rect().x())+","+rect2.setNum(this->rect().y())+","+rect3.setNum(this->rect().width())
            +","+rect4.setNum(this->rect().height());
    rectValueLabel->setText(rectStr);
    QString sizeStr,size1,size2;
    sizeStr = size1.setNum(this->size().width())+","+size2.setNum(this->size().height());
    sizeValueLabel->setText(sizeStr);
}

void Geometry::moveEvent(QMoveEvent *)
{
    updateLabel();
}

void Geometry::resizeEvent(QResizeEvent *)
{
    updateLabel();
}
