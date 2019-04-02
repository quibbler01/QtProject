#ifndef DRAWER_H
#define DRAWER_H

#include <QToolBox>
#include <QToolButton>
#include <QGroupBox>
#include <QVBoxLayout>

class Drawer : public QToolBox
{
public:
    Drawer(QWidget *parent = nullptr,Qt::WindowFlags f = nullptr);

private:
    QToolButton *toolButton1_1;
    QToolButton *toolButton1_2;
    QToolButton *toolButton1_3;
    QToolButton *toolButton1_4;
    QToolButton *toolButton2_5;
    QToolButton *toolButton2_6;
    QToolButton *toolButton2_7;
    QToolButton *toolButton2_8;
    QToolButton *toolButton2_9;


};

#endif // DRAWER_H
