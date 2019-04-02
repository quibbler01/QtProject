#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QFileDialog>
#include <QPushButton>
#include <QLineEdit>
#include <QGridLayout>

class Dialog:public QDialog
{
public:
    Dialog(QDialog *parent = nullptr);
private:
    QPushButton *chooseFileButton;
    QLineEdit *filePathLineEdit;
    QGridLayout *mainLayout;
};

#endif // DIALOG_H
