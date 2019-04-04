#include "mainwindow.h"
#include <QApplication>
#include <QTranslator>
#include "switchlanguage.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QTranslator *translator =  new QTranslator;
    translator->load("C:\\Users\\Administrator\\Documents\\Qt\\chapter14\\TestHello.qm");
    a.installTranslator(translator);

    SwitchLanguage w;
    w.show();

    return a.exec();
}
