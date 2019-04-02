#ifndef STACKWINDOW_H
#define STACKWINDOW_H

#include <QDialog>
#include <QListWidget>
#include <QStackedWidget>
#include <QLabel>


class StackWindow : public QDialog
{
    Q_OBJECT

public:
    StackWindow(QDialog *parent = 0);
    ~StackWindow();
private:
    QListWidget *list;
    QStackedWidget *stack;
    QLabel *label1;
    QLabel *label2;
    QLabel *label3;
};

#endif // STACKWINDOW_H
