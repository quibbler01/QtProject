#ifndef FINAL_H
#define FINAL_H

#include <QWidget>
#include "dialog.h"
#include "colordialog.h"
#include "fontdialog.h"
#include "inputdialog.h"
#include "messagedialog.h"

class Final : public QWidget
{
    Q_OBJECT
public:
    explicit Final(QWidget *parent = nullptr);
private:
    Dialog *chooseFileDialog;
    ColorDialog *chooseColorDialo;
    FontDialog *fontDialog;
    InputDialog *inputDialog;
    MessageDialog *messageDialog;

    QVBoxLayout *layout;
signals:

public slots:
};

#endif // FINAL_H
