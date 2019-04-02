#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QtDebug>

const static double PI = 3.1416;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    bool ok;
    QString tempStr;
    QString valueStr = ui->lineEdit->text();
    int valueInt = valueStr.toInt(&ok);
    double area = valueInt*valueInt*PI;
    ui->label_3->setText(tempStr.setNum(area));
}

void MainWindow::on_lineEdit_textChanged(const QString &arg1)
{
    bool ok;
    QString tempStr;
    QString valueStr = ui->lineEdit->text();
    int valueInt = valueStr.toInt(&ok);
    double area = valueInt*valueInt*PI;
    ui->label_3->setText(tempStr.setNum(area));
    qDebug()<<arg1;
}
