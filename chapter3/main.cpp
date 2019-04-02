#include "mainwindow.h"
#include <QApplication>
#include <QSplitter>
#include <QTextCodec>
#include <QListWidget>

#include "windowwithspliter.h"
#include "dockwindow.h"
#include "stackwindow.h"
#include "layoutwindow.h"
#include "final.h"


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QFont font("AR PL KaitiM GB",12);
    a.setFont(font);
//    MainWindow w;
//    w.show();

//    WindowWithSpliter ws;
//    ws.show();

//      DockWindow d;
//      d.show();

//    StackWindow s;
//    s.show();

//    LayoutWindow l;
//    l.show();


//    BaseInfo b;
//    b.show();

//    Contact t;
//    t.show();

//    Detail d;
//    d.show();

//    Content c;
//    c.show();

    Final f;
    f.show();


    return a.exec();

}
