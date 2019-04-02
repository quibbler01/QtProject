#include "mainwindow.h"
#include <QApplication>
#include <QAbstractItemModel>
#include <QAbstractItemView>
#include <QItemSelectionModel>
#include <QDirModel>
#include <QTreeView>
#include <QListView>
#include <QTableView>
#include <QSplitter>
#include <QObject>
#include "modelex.h"
#include "datedelegate.h"
#include "combodelegate.h"
#include "spindelegate.h"


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

//    QDirModel model;
//    QTreeView *tree = new QTreeView;
//    QTableView *table = new QTableView;
//    QListView *list = new QListView;
//    //共用一个QDirModel
//    tree->setModel(&model);
//    table->setModel(&model);
//    list->setModel(&model);

//    tree->setSelectionMode(QAbstractItemView::MultiSelection);
//    list->setSelectionModel(tree->selectionModel());
//    table->setSelectionModel(tree->selectionModel());

//    QObject::connect(tree,SIGNAL(doubleClicked(QModelIndex)),list,SLOT(setRootIndex(QModelIndex)));
//    QObject::connect(tree,SIGNAL(doubleClicked(QModelIndex)),table,SLOT(setRootIndex(QModelIndex)));

//    QSplitter *splitter = new QSplitter;
//    splitter->addWidget(tree);
//    splitter->addWidget(list);
//    splitter->addWidget(table);

//    splitter->setWindowTitle(QObject::tr("Dir Browser"));
//    splitter->show();

//    ModelEx modelEx;
//    QTableView view;
//    view.setModel(&modelEx);
//    view.setWindowTitle(QObject::tr("modelEx"));
//    view.resize(400,400);
//    view.show();

//    MainWindow mainWindow;
//    mainWindow.show();

    QStandardItemModel model(4,4);
    QTableView tableView;
    tableView.setModel(&model);
    DateDelegate dateDelegate;
    tableView.setItemDelegateForColumn(1,&dateDelegate);
    ComboDelegate com;
    tableView.setItemDelegateForColumn(2,&com);
    SpinDelegate spin;
    tableView.setItemDelegateForColumn(3,&spin);
    model.setHeaderData(0,Qt::Horizontal,QObject::tr("姓名"));
    model.setHeaderData(1,Qt::Horizontal,QObject::tr("生日"));
    model.setHeaderData(2,Qt::Horizontal,QObject::tr("职业"));
    model.setHeaderData(3,Qt::Horizontal,QObject::tr("收入"));

    QFile file(":/data/date.txt");
    if(file.open(QFile::ReadOnly|QFile::Text)){
        QTextStream stream(&file);
        QString line;
        model.removeRows(0,model.rowCount(QModelIndex()),QModelIndex());
        int row = 0;
        do{
            line = stream.readLine();
            if(!line.isEmpty()){
                model.insertRows(row,1,QModelIndex());
                QStringList pieces = line.split(",",QString::SkipEmptyParts);
                model.setData(model.index(row,0,QModelIndex()),pieces.value(0));
                model.setData(model.index(row,1,QModelIndex()),pieces.value(1));
                model.setData(model.index(row,2,QModelIndex()),pieces.value(2));
                model.setData(model.index(row,3,QModelIndex()),pieces.value(3));
                ++row;
            }
        }while(!line.isEmpty());
        file.close();
    }
    tableView.setWindowTitle(QObject::tr("Delegate"));
    tableView.show();

    return a.exec();
}
