#include "mainwindow.h"
#include "fileview.h"
#include "fileinfo.h"
#include "filewatcher.h"
#include <QApplication>
#include <QFile>
#include <QDebug>
#include <QDir>

extern qint64 du(const QString &path);

int main(int argc, char *argv[])
{
   QApplication a(argc, argv);
   // MainWindow w;
   // w.show();

//    QFile file("C:\\Users\\61444\\Documents\\qtProject\\Qt\\chapter9\\date.txt");
//    if(file.open(QFile::ReadOnly)){
//        char buffer[2048];
//        qint64 lineLen = file.readLine(buffer,sizeof (buffer));
//        while(lineLen!=-1){
//            qDebug()<<buffer;
//            lineLen = file.readLine(buffer,sizeof (buffer));
//        }
//        file.close();
//    }

//    QStringList args = a.arguments();
//    QString path;
//    if(args.count()>1){
//        path=args[1];
//    }else{
//        path = QDir::currentPath();
//    }
//    qDebug()<<path<<endl;
//    du(path);

   FileWatcher f;
   f.show();

    return a.exec();/*0;*/
}
