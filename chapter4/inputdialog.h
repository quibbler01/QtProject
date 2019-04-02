#ifndef INPUTDIALOG_H
#define INPUTDIALOG_H

#include <QDialog>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QGridLayout>
#include <QInputDialog>
#include <QDebug>

class InputDialog:public QDialog
{
public:
    InputDialog(QDialog *parent = nullptr);
private:
    QLabel *NameLabel,*SexLabel,*AgeLabel,*GradeLabel;
    QLabel *Name,*Sex,*Age,*Grade;
    QPushButton *NameInputButton,*SexInputButton,*AgeInputButton,*GradeInputButton;
    QGridLayout *mainLayout;

};

#endif // INPUTDIALOG_H
