#ifndef CONTENT_H
#define CONTENT_H

#include <QWidget>
#include <QStackedWidget>
#include <QPushButton>
#include "baseinfo.h"
#include "contact.h"
#include "detail.h"


class Content : public QWidget
{
    Q_OBJECT
public:
    explicit Content(QWidget *parent = nullptr);
    ~Content();
    QStackedWidget *stack;
private:
    QPushButton *AmendBtn;
    QPushButton *CloseBtn;
    BaseInfo *baseInfo;
    Detail *detail;
    Contact *contact;

signals:

public slots:

};

#endif // CONTENT_H
