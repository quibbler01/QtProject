#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    //ui->setupUi(this);
    this->setWindowTitle(tr("鼠标事件"));
    statusLabel = new QLabel;
    statusLabel->setText(tr("当前位置:"));
    statusLabel->setFixedWidth(100);
    mousePosLabel = new QLabel;
    mousePosLabel->setText(tr(""));
    mousePosLabel->setFixedWidth(100);
    statusBar()->addPermanentWidget(statusLabel);
    statusBar()->addPermanentWidget(mousePosLabel);
    this->setMouseTracking(true);
    resize(400,200);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::mousePressEvent(QMouseEvent *e)
{
    QString str = "("+QString::number(e->x())+","+QString::number(e->y())+")";
    if(e->button()==Qt::LeftButton){
        statusBar()->showMessage(tr("左键:")+str);
    }else if(e->button()==Qt::RightButton){
        statusBar()->showMessage(tr("右键:")+str);
    }else if(e->button()==Qt::MidButton){
        statusBar()->showMessage(tr("中键:")+str);
    }
}

void MainWindow::mouseMoveEvent(QMouseEvent *e)
{
    mousePosLabel->setText("("+QString::number(e->x())+","+QString::number(e->y())+")");
}

void MainWindow::mouseReleaseEvent(QMouseEvent *e)
{
    QString str = "("+QString::number(e->x())+","+QString::number(e->y())+")";
    statusBar()->showMessage(tr("释放:")+str);
}

void MainWindow::mouseDoubleClickEvent(QMouseEvent *e)
{

}
