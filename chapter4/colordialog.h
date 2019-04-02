#ifndef COLORDIALOG_H
#define COLORDIALOG_H

#include <QDialog>
#include <QPushButton>
#include <QFrame>
#include <QColorDialog>
#include <QGridLayout>

class ColorDialog : public QDialog
{
public:
    ColorDialog(QDialog *parent = nullptr);
private:
    QPushButton *chooseColorButton;
    QFrame *showColorFrame;
    QGridLayout *mainLayout;
public slots:
    void show();
};

#endif // COLORDIALOG_H
