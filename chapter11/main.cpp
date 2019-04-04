#include "mainwindow.h"
#include "keyevent.h"
#include "eventfilter.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

//    KeyEvent w;
//    w.show();

    EventFilter e;
    e.show();

    return a.exec();
}
