﻿#ifndef DATEDELEGATE_H
#define DATEDELEGATE_H

#include <QObject>
#include <QItemDelegate>

class DateDelegate : public QItemDelegate
{
    Q_OBJECT
public:
    explicit DateDelegate(QObject *parent = nullptr);
    QWidget *createEditor(QWidget *parent,const QStyleOptionViewItem &option,const QModelIndex &index) const;
    void setEditorData(QWidget *editor,const QModelIndex &index) const;
    void setModelData(QWidget *eidtor,QAbstractItemModel *model,const QModelIndex &index) const;
    void updateEditorGeometry(QWidget *editor,const QStyleOptionViewItem &option,const QModelIndex &index) const;

signals:

public slots:
};

#endif // DATEDELEGATE_H
