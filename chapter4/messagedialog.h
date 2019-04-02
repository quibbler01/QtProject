#ifndef MESSAGEDIALOG_H
#define MESSAGEDIALOG_H

#include <QWidget>
#include <QLabel>
#include <QPushButton>
#include <QGridLayout>
#include <QMessageBox>
#include <QDebug>

class MessageDialog:public QWidget
{
    Q_OBJECT

public:
    MessageDialog(QWidget *parent = nullptr);

private:
    QLabel *label;
    QPushButton *questionBtn;
    QPushButton *informationBtn;
    QPushButton *warningBtn;
    QPushButton *criticalBtn;
    QPushButton *aboutBtn;
    QPushButton *aboutQtBtn;
    QPushButton *customBtn;
    QGridLayout *mainLayout;

private slots:


};

#endif // MESSAGEDIALOG_H
