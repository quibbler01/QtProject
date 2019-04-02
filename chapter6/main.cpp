#include "mainwindow.h"
#include "geometry.h"
#include "mainwindow.h"
#include "drawwidget.h"
#include "drawsomething.h"
#include "svgmainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
//    QFont font("ZYSong18030",12);
//    a.setFont(font);
    SvgMainWindow w;
    w.show();

    return a.exec();
}
