#ifndef DIGICLOCK_H
#define DIGICLOCK_H

#include <QLCDNumber>
#include <QTimer>
#include <QTime>
#include <QMouseEvent>
#include <QDebug>
#include <QPushButton>
#include <QGridLayout>

class DigicLock : public QLCDNumber
{
    Q_OBJECT

public:
    DigicLock(QWidget *parent = nullptr);
    ~DigicLock();

    void mousePressEvent(QMouseEvent *);
    void mouseMoveEvent(QMouseEvent *);
    void keyPressEvent(QKeyEvent *event);
public slots:
    void showTime();

private :
    QPoint dragPosition;
    bool showColon;
    QPushButton *changeBackGround;
    bool flag;
};

#endif // DIGICLOCK_H
