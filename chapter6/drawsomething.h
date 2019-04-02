#ifndef DRAWSOMETHING_H
#define DRAWSOMETHING_H

#include <QMainWindow>
#include <QToolBar>
#include <QLabel>
#include <QToolButton>
#include <QSpinBox>
#include <QComboBox>
#include "drawwidget.h"
class DrawSomething : public QMainWindow
{
    Q_OBJECT
public:
    explicit DrawSomething(QWidget *parent = nullptr);
    ~DrawSomething();
    void createToolBar();
signals:

public slots:
    void showStyle();
    void showColor();
private:
    DrawWidget *drawWidget;
    QLabel *styleLabel;
    QComboBox *styleComboBox;
    QLabel *widthLabel;
    QSpinBox *widthSpinBox;
    QToolButton *colorBtn;
    QToolButton *clearBtn;
};

#endif // DRAWSOMETHING_H
