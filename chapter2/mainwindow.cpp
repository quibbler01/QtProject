#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QTimer>
#include <QTime>
#include <QDebug>
#include <QPushButton>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QTimer *timer = new QTimer();
    timer->start(2000);
    connect(timer,&QTimer::timeout,[=](){
        QTime *time = new QTime();
        time->start();
        this->ui->timeEdit->setTime(*time);
        qDebug()<<"Time out";
    });
    //QPushButton *button = new QPushButton("Push this",this);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    this->ui->button->move(400,200);
}
