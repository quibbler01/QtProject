#include "mainwindow.h"
#include "dialog2.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
//    MainWindow w;
//    w.show();
    Dialog2 d;
    d.show();


    return a.exec();
}
