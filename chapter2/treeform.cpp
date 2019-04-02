#include "treeform.h"
#include "ui_treeform.h"
#include <QtDebug>

TreeForm::TreeForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::TreeForm)
{
    ui->setupUi(this);
    init();
    connect(ui->treeWidget,SIGNAL(itemChanged(QTreeWidgetItem*,int)),this,SLOT(treeItemChanged(QTreeWidgetItem*,int)));
//    connect(ui->treeWidget,&QTreeWidgetItem::itemChanged,[=](){

//    });
}

TreeForm::~TreeForm()
{
    delete ui;

}

void TreeForm::init()
{
    ui->treeWidget->clear();

    QTreeWidgetItem *group1 = new QTreeWidgetItem(ui->treeWidget);
    group1->setText(0,"group1");
    group1->setFlags(Qt::ItemIsUserCheckable|Qt::ItemIsEnabled|Qt::ItemIsSelectable);
    group1->setCheckState(0,Qt::Unchecked);

    QTreeWidgetItem* subItem1 = new QTreeWidgetItem(group1);
    subItem1->setFlags(Qt::ItemIsUserCheckable|Qt::ItemIsEnabled|Qt::ItemIsSelectable);
    subItem1->setText(0,"subItem1");
    subItem1->setCheckState(0,Qt::Unchecked);

    QTreeWidgetItem *subItem2 = new QTreeWidgetItem(group1);
    subItem2->setFlags(Qt::ItemIsUserCheckable|Qt::ItemIsEnabled|Qt::ItemIsSelectable);
    subItem2->setText(0,"subItem2");
    subItem2->setCheckState(0,Qt::Unchecked);

    QTreeWidgetItem *subItem3 = new QTreeWidgetItem(group1);
    subItem3->setFlags(Qt::ItemIsUserCheckable|Qt::ItemIsEnabled|Qt::ItemIsSelectable);
    subItem3->setText(0,"subItem3");
    subItem3->setCheckState(0,Qt::Unchecked);

    QTreeWidgetItem *subItem4 = new QTreeWidgetItem(group1);
    subItem4->setFlags(Qt::ItemIsUserCheckable|Qt::ItemIsEnabled|Qt::ItemIsSelectable);
    subItem4->setText(0,"subItem4");
    subItem4->setCheckState(0,Qt::Unchecked);


    QTreeWidgetItem *group2 = new QTreeWidgetItem(ui->treeWidget);
    group2->setText(0,"group2");
    group2->setFlags(Qt::ItemIsUserCheckable|Qt::ItemIsEnabled|Qt::ItemIsSelectable);
    group2->setCheckState(0,Qt::Unchecked);

    QTreeWidgetItem* subItem11 = new QTreeWidgetItem(group2);
    subItem11->setFlags(Qt::ItemIsUserCheckable|Qt::ItemIsEnabled|Qt::ItemIsSelectable);
    subItem11->setText(0,"subItem11");
    subItem11->setCheckState(0,Qt::Unchecked);

    QTreeWidgetItem *subItem22 = new QTreeWidgetItem(group2);
    subItem22->setFlags(Qt::ItemIsUserCheckable|Qt::ItemIsEnabled|Qt::ItemIsSelectable);
    subItem22->setText(0,"subItem22");
    subItem22->setCheckState(0,Qt::Unchecked);

    QTreeWidgetItem *subItem33 = new QTreeWidgetItem(group2);
    subItem33->setFlags(Qt::ItemIsUserCheckable|Qt::ItemIsEnabled|Qt::ItemIsSelectable);
    subItem33->setText(0,"subItem33");
    subItem33->setCheckState(0,Qt::Unchecked);

    QTreeWidgetItem *subItem44 = new QTreeWidgetItem(group2);
    subItem44->setFlags(Qt::ItemIsUserCheckable|Qt::ItemIsEnabled|Qt::ItemIsSelectable);
    subItem44->setText(0,"subItem44");
    subItem44->setCheckState(0,Qt::Unchecked);

    QTreeWidgetItem* subItem111 = new QTreeWidgetItem(subItem44);
    subItem111->setFlags(Qt::ItemIsUserCheckable|Qt::ItemIsEnabled|Qt::ItemIsSelectable);
    subItem111->setText(0,"subItem111");
    subItem111->setCheckState(0,Qt::Unchecked);

    QTreeWidgetItem *subItem222 = new QTreeWidgetItem(subItem44);
    subItem222->setFlags(Qt::ItemIsUserCheckable|Qt::ItemIsEnabled|Qt::ItemIsSelectable);
    subItem222->setText(0,"subItem222");
    subItem222->setCheckState(0,Qt::Unchecked);

    QTreeWidgetItem *subItem333 = new QTreeWidgetItem(subItem44);
    subItem333->setFlags(Qt::ItemIsUserCheckable|Qt::ItemIsEnabled|Qt::ItemIsSelectable);
    subItem333->setText(0,"subItem333");
    subItem333->setCheckState(0,Qt::Unchecked);

    QTreeWidgetItem *subItem444 = new QTreeWidgetItem(subItem44);
    subItem444->setFlags(Qt::ItemIsUserCheckable|Qt::ItemIsEnabled|Qt::ItemIsSelectable);
    subItem444->setText(0,"subItem444");
    subItem444->setCheckState(0,Qt::Unchecked);

}

void TreeForm::updateParentItem(QTreeWidgetItem *item)
{
    QTreeWidgetItem *parent = item->parent();
    if(parent==nullptr){
        return;
    }
    int selectedCount = 0;
    int childCount = parent->childCount();

    for(int i =0;i<childCount;++i){
        QTreeWidgetItem*childItem = parent->child(i);
        if(childItem->checkState(0) == Qt::Checked){
            ++selectedCount;
        }

    }
    //qDebug()<<selectedCount;
    if(selectedCount<=0){
        parent->setCheckState(0,Qt::Unchecked);
    }else if(selectedCount>0&&selectedCount<childCount){
        parent->setCheckState(0,Qt::PartiallyChecked);
    }
    else if(selectedCount == childCount){
        parent->setCheckState(0,Qt::Checked);
    }
    updateParentItem(parent);
}

void TreeForm::treeItemChanged(QTreeWidgetItem *item, int colum)
{
    //qDebug()<<item->text(0);
    //QString itemText = item->text(0);
    if(Qt::Checked == item->checkState(0)){
        //QTreeWidgetItem *parent = item->parent();
        int count =  item->childCount();
        if(count>0){
            for(int i = 0;i<count;++i){
                item->child(i)->setCheckState(0,Qt::Checked);
            }
        }else{
            updateParentItem(item);
        }
    }else if(Qt::Unchecked == item->checkState(0)){
        int count = item->childCount();
        if(count>0){
            for(int i =0;i<count;++i){
                item->child(i)->setCheckState(0,Qt::Unchecked);
            }
        }else{
            updateParentItem(item);
        }
    }
}
