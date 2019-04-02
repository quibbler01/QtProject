#include "chapter4.h"
#include <QApplication>
#include <QPixmap>
#include <QSplashScreen>

#include "final.h"
#include "drawer.h"
#include "progressdialog.h"
#include "extensiondlg.h"
#include "shapewidget.h"
#include "splashscreen.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

//    Chapter4 w;
//    w.show();

//    Dialog d;
//    d.show();

//    Final f;
//    f.show();

//    Drawer d;
//    d.show();

    QPixmap pixmap(":/img/frame/splash.png");
    QSplashScreen splash(pixmap);
    splash.show();
    a.processEvents();

    SplashScreen s;
    s.show();

    splash.finish(&s);

    return a.exec();
}
