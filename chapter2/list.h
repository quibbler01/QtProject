#ifndef LIST_H
#define LIST_H
#include <QList>
#include<QDebug>
#include <QMap>
#include <QColor>

void test(){
    QString stra;
    int length = stra.capacity();
    for(int i = 0;i<10000;++i){
        stra.append('a');
        if(stra.capacity()!=length){
            qDebug()<<length;
            length = stra.capacity();
        }
    }
    qDebug()<<length;
    QString str = "Welcome to you! ";
    QByteArray ba = str.toLocal8Bit();
    ba.append("Hello world!");
    qDebug()<<ba.data();
    qDebug()<<ba;

}
void testMathic(){
    double a = -19.3,b = 9.7;
    double c = qAbs(a);
    double max = qMax(b,c);
    int bn = qRound(b);
    int cn = qRound(c);

    qDebug()<<"a = "<<a;
    qDebug()<<"b = "<<b;
    qDebug()<<"c =qAbs(a) "<<c;
    qDebug()<<"qMax(b,c) = "<<max;
    qDebug()<<"bn = qRound(b) = "<<bn;
    qDebug()<<"cn = qRound(c) = "<<cn;
    qSwap(bn,cn);
    qDebug()<<"qSwap(bn,cn):"<<"bn = "<<bn<<",cn = "<<cn;
}

void testVariant(){
    QVariant v(709);
    qDebug()<<v.toInt();

    QVariant w("How are you?");
    qDebug()<<w.toString();

    QMap<QString,QVariant> map;
    map["int"] = 709;
    map["double"] = 12.123;
    map["string"] = "How are you!";
    map["color"] = QColor(12,12,32);

    qDebug()<<map["int"]<<map["int"].toInt();
    qDebug()<<map["double"]<<map["double"].toDouble();
    qDebug()<<map["string"]<<map["string"].toString();
    qDebug()<<map["color"]<<map["color"].value<QColor>();

    QStringList sl;
    sl<<"A"<<"B"<<"C"<<"D";
    QVariant slv(sl);
    if(slv.type()==QVariant::StringList){
        QStringList list = slv.toStringList();
        for(int i = 0;i<list.size();++i){
            qDebug()<< list[i]<<" ";
        }
    }
}

void testMap(){
    QMap<QString,QString> map;
    map.insert("beijing","111");
    map.insert("shanghai","012");
    map.insert("nanjing","025");

    QMap<QString,QString>::const_iterator iMap;
    for(iMap = map.begin();iMap!=map.end();++iMap){
        qDebug()<<" "<<iMap.key()<<" "<<iMap.value();
    }

    QMap<QString,QString>::iterator ciMap;
    ciMap = map.find("beijing");
    if(ciMap!=map.end()){
        ciMap.value()="010";
    }

    for(iMap = map.begin();iMap!=map.end();++iMap){
        qDebug()<<" "<<iMap.key()<<" "<<iMap.value();
    }
}

void testList(){
    QList<int> list;
    list<<1<<2<<3<<4;
    QList<int>::const_iterator i;

    for(i = list.begin();i!=list.end();++i){
        qDebug()<<*i;
    }

    QList<int>::iterator j;
    for(j = list.begin();j!=list.end();++j){
        *j *=10;
    }

    for(j = list.begin();j!=list.end();++j){
        qDebug()<<*j<<" ";
    }
}
#endif // LIST_H
