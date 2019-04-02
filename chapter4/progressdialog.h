#ifndef PROGRESSDIALOG_H
#define PROGRESSDIALOG_H

#include <QDialog>
#include <QProgressBar>
#include <QLabel>
#include <QLineEdit>
#include <QComboBox>
#include <QPushButton>
#include <QGridLayout>
#include <QProgressDialog>

class ProgressDialog:public QDialog
{
public:
    ProgressDialog(QDialog *parent = nullptr);
private:
    QLabel *FileNum;
    QLineEdit *FileNumberLineEdit;
    QLabel *ProgressType;
    QComboBox *chooseProgressType;
    QProgressBar *progressBar;
    QPushButton *startButton;
    QGridLayout *mainLayout;

};

#endif // PROGRESSDIALOG_H
