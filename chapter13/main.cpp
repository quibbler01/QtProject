#include "mainwindow.h"
#include "connectdlg.h"
#include <QApplication>
#include <QTextCodec>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QTime>
#include <QSqlError>
#include <QDebug>
#include <QSqlDriver>
#include <QSqlRecord>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

//    MainWindow m;
//    m.show();

    ConnectDlg c;
    if(c.exec()!=QDialog::Accepted){
        return -1;
    }
    //c.show();
    QFile *carDetails = new QFile("attribs.xml");
    MainWindow window("factory","cars",carDetails);
    window.show();


    if(false){
        QTextCodec::setCodecForLocale(QTextCodec::codecForLocale());
        QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
        db.setHostName("easybook-3313b0");
        db.setDatabaseName("qtDB.db");
        db.setUserName("zhouhejun");
        db.setPassword("123456");
        db.open();
        //
        QSqlQuery query;
        bool success =  query.exec("create table automobile"
                                   "(id int primary key,"
                                   "attribute varchar,"
                                   "type varchar,"
                                   "kind varchar,"
                                   "nation int,"
                                   "carnumber int,"
                                   "elevaltor int,"
                                   "distance int,"
                                   "oil int,"
                                   "temperature int)");
        if(success){
            qDebug()<<"数据库表创建成功！";
        }else{
            qDebug()<<"数据库表创建失败！";
        }
        query.exec("select * from automobile");
        QSqlRecord rec = query.record();
        qDebug()<<QObject::tr("automobile表字段数:")<<rec.count();
        //insert
        QTime t;
        t.start();
        query.prepare("insert into automobile values(?,?,?,?,?,?,?,?,?,?)");
        long records = 100;
        for(int i = 0;i<records;++i){
            query.bindValue(0,i);
            query.bindValue(1,"四轮");
            query.bindValue(2,"轿车");
            query.bindValue(3,"富康");
            query.bindValue(4,rand()%100);
            query.bindValue(5,rand()%10000);
            query.bindValue(6,rand()%300);
            query.bindValue(7,rand()%20000);
            query.bindValue(8,rand()%52);
            query.bindValue(9,rand()%100);
            success = query.exec();
            if(!success){
                QSqlError lastError = query.lastError();
                qDebug()<<lastError.driverText()<<QString(QObject::tr("插入数据记录失败"));
            }
        }
        qDebug()<<QObject::tr("插入:%1记录，耗时:%2ms").arg(records).arg(t.elapsed());
        //sort
        t.restart();
        success = query.exec("select *from automobile order by id desc");
        if(success){
            qDebug()<<QObject::tr("排序:%1条记录，耗时:%2ms").arg(records).arg(t.elapsed());
        }else{
            qDebug()<<QObject::tr("排序失败!");
        }
        //update
        t.restart();
        for(int i = 0;i<records;++i){
            query.clear();
            query.prepare(QString("update automobile set attribute=?,type=?,kind=?,nation=?,"
                                  "carnumber=?,elevaltor=?,distance=?,oil=?,temperature=? where id=%1").arg(i));
            query.bindValue(0,"四轮");
            query.bindValue(1,"轿车");
            query.bindValue(2,"富康");
            query.bindValue(3,rand()%100);
            query.bindValue(4,rand()%10000);
            query.bindValue(5,rand()%300);
            query.bindValue(6,rand()%20000);
            query.bindValue(7,rand()%52);
            query.bindValue(8,rand()%100);
            success = query.exec();
            if(!success){
                QSqlError lastError = query.lastError();
                qDebug()<<lastError.driverText()<<QString(QObject::tr("更新失败!"));
            }
        }
        qDebug()<<QObject::tr("更新:%1条记录，耗时:%2ms").arg(records).arg(t.elapsed());
        //delete
        t.restart();
        query.exec("delete from automobile where id = 5");
        qDebug()<<QObject::tr("删除一条记录，耗时%1ms").arg(t.elapsed());
        return 0;
    }
    return a.exec();
}
