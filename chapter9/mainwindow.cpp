#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QtDebug>
#include <QFile>
#include <QDataStream>
#include <QDate>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    //ui->setupUi(this);
    fileFun();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::fileFun()
{
    QFile file("C:\\Users\\61444\\Documents\\qtProject\\Qt\\chapter9\\in.txt");
    file.open(QIODevice::WriteOnly|QIODevice::Truncate);
    QDataStream out(&file);
    out << QString(tr("刘俊"));
    out << QDate::fromString("1996/03/25","yyyy/MM/dd");
    out << (qint32)21;
    file.close();

    file.setFileName("C:\\Users\\61444\\Documents\\qtProject\\Qt\\chapter9\\in.txt");
    if(!file.open(QIODevice::ReadOnly)){
        qDebug()<<"error!";
        return ;
    }
    QDataStream in(&file);
    QString name;
    QDate birthday;
    qint32 age;
    in >> name >> birthday >> age;
    qDebug()<<name<<birthday<<age;
    file.close();


}
