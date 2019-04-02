#ifndef MODELVIEW_H
#define MODELVIEW_H

#include <QWidget>
#include <QTableView>
#include <QtSql/QSqlTableModel>


class ModelView : public QWidget
{
    Q_OBJECT
public:
    explicit ModelView(QWidget *parent = nullptr);

signals:

public slots:
};

#endif // MODELVIEW_H
