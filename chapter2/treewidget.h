#ifndef TREEWIDGET_H
#define TREEWIDGET_H

#include <QWidget>
#include <QTreeWidgetItem>

class TreeWidget : public QWidget
{
    Q_OBJECT
public:
    explicit TreeWidget(QWidget *parent = nullptr);
    //void init();
    //void updateParentItem(QTreeWidgetItem *item);
public slots:
    //void treeItemChanged(QTreeWidgetItem*item,int colum);

signals:

public slots:
};

#endif // TREEWIDGET_H
