#include "digiclock.h"

DigicLock::DigicLock(QWidget *parent):QLCDNumber(parent)
{
    QPalette p = palette();
    p.setColor(QPalette::Window,Qt::black);
    p.setColor(QPalette::WindowText,Qt::white);
    setPalette(p);
    this->setWindowFlags(Qt::FramelessWindowHint|Qt::WindowStaysOnTopHint);
    this->setWindowOpacity(1);

//    changeBackGround = new QPushButton(tr("Style"),this);
//    changeBackGround->setGeometry(10,10,60,30);
//    changeBackGround->setShortcut(tr("Ctrl+C"));
//    changeBackGround->hide();
//    flag = true;
//    connect(changeBackGround,&QPushButton::clicked,[&](){
//        if(flag){
//            QPalette p = palette();
//            p.setColor(QPalette::Window,Qt::white);
//            p.setColor(QPalette::WindowText,Qt::black);
//            setPalette(p);
//            flag  =false;
//            update();
//        }else{
//            QPalette p = palette();
//            p.setColor(QPalette::Window,Qt::black);
//            p.setColor(QPalette::WindowText,Qt::white);
//            setPalette(p);
//            flag = true;
//            update();
//        }
//    });

    //this->showFullScreen();
    QTimer *timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(showTime()));

    timer->start(1000);
    showTime();
    showColon = true;
}

DigicLock::~DigicLock()
{

}

void DigicLock::mousePressEvent(QMouseEvent *event)
{
    if(event->button()==Qt::LeftButton){
        dragPosition = event->globalPos()-frameGeometry().topLeft();
        event->accept();
    }
    if(event->button()==Qt::RightButton){
        qDebug()<< this->close();

    }
}

void DigicLock::mouseMoveEvent(QMouseEvent *event)
{
    if(event->buttons() && Qt::LeftButton){
        move(event->globalPos()-dragPosition);
        event->accept();
    }
}

void DigicLock::keyPressEvent(QKeyEvent *event)
{
    if(event->key()==Qt::Key_Shift){
        qDebug()<< "Shift Pressed";
        if(flag){
            QPalette p = palette();
            p.setColor(QPalette::Window,Qt::white);
            p.setColor(QPalette::WindowText,Qt::black);
            setPalette(p);
            flag  =false;
            update();
        }else{
            QPalette p = palette();
            p.setColor(QPalette::Window,Qt::black);
            p.setColor(QPalette::WindowText,Qt::white);
            setPalette(p);
            flag = true;
            update();
        }
    }
}

void DigicLock::showTime()
{
    QTime time = QTime::currentTime();
    QString text = time.toString("hh:mm");
    if(showColon){
        text[2] = ':';
        showColon = false;
    }else{
        text[2]  =' ';
        showColon = true;
    }
    display(text);
}
