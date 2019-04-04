#include "keyevent.h"

KeyEvent::KeyEvent(QWidget *parent) : QMainWindow(parent)
{
    this->setWindowTitle(tr("键盘事件"));
    this->setAutoFillBackground(true);
    QPalette palette = this->palette();
    palette.setColor(QPalette::Window,Qt::white);
    this->setPalette(palette);
    this->setMinimumSize(512,256);
    this->setMaximumSize(512,256);
    width = this->size().width();
    height = this->size().height();
    pix = new QPixmap(width,height);
    pix->fill(Qt::white);
    image.load((":/img/feminine_Butterfly_218.34962406015px_1163158_easyicon.net.png"));
    startX = 100;
    startY = 100;
    setp = 20;
    drawPix();
    resize(512,256);
}

KeyEvent::~KeyEvent()
{

}

void KeyEvent::drawPix()
{
    pix->fill(Qt::white);
    QPainter *painter = new QPainter;
    QPen pen(Qt::DotLine);
    for(int i = setp;i<width;i+=setp){
        painter->begin(pix);
        painter->setPen(pen);
        painter->drawLine(QPoint(i,0),QPoint(i,height));
        painter->end();
    }
    for(int j = setp;j<height;j+=setp){
        painter->begin(pix);
        painter->setPen(pen);
        painter->drawLine(QPoint(0,j),QPoint(width,j));
        painter->end();
    }
    painter->begin(pix);
    painter->drawImage(QPoint(startX,startY),image);
    painter->end();
}

void KeyEvent::keyPressEvent(QKeyEvent *e)
{
    if(e->modifiers()==Qt::ControlModifier){
        if(e->key()==Qt::Key_Left){
            startX = (startX-1<0)?startX:startX-1;
        }
        else if(e->key()==Qt::Key_Right){
            startX = (startX+1+image.width()>width)?startX:startX+1;
        }
        else if(e->key()==Qt::Key_Up){
            startY = (startY-1<0)?startY:startY-1;
        }
        else if(e->key()==Qt::Key_Down){
            startY = (startY+1+image.height()>height)?startY:startY+1;
        }
    }else{
        startX = startX - startX%20;
        startY = startY - startY%20;
        if(e->key()==Qt::Key_Left){
            startX = (startX-setp<0)?startX:startX-setp;
        }
        else if(e->key()==Qt::Key_Right){
            startX  =(startX+setp+image.width()>width)?startX:startX+setp;
        }
        else if(e->key()==Qt::Key_Up){
            startY = (startY-setp<0)?startY:startY-setp;
        }
        else if(e->key()==Qt::Key_Down){
            startY = (startY+setp+image.height()>height)?startY:startY+setp;
        }
    }
    drawPix();
    update();
}

void KeyEvent::paintEvent(QPaintEvent *e)
{
    QPainter painter;
    painter.begin(this);
    painter.drawPixmap(QPoint(0,0),*pix);
    painter.end();
}
