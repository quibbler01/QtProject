#ifndef FINAL_H
#define FINAL_H

#include <QWidget>
#include <QSplitter>
#include <QTextCodec>
#include <QListWidget>
#include "content.h"

class Final : public QWidget
{
    Q_OBJECT
public:
    explicit Final(QWidget *parent = nullptr);

private:
    QSplitter *splitterMain;
    QListWidget * list;
    Content *content;

signals:

public slots:
};

#endif // FINAL_H
