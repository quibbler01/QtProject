#ifndef DIALOG_H
#define DIALOG_H

#include <QWidget>
#include <QDialog>
#include <QLabel>
#include <QPushButton>
#include <QHBoxLayout>

class TimeServer;

class Dialog : public QWidget
{
    Q_OBJECT
public:
    explicit Dialog(QWidget *parent = nullptr);
    ~Dialog();

signals:

public slots:
    void slotShow();
private:
    QLabel *label1;
    QLabel *label2;
    QPushButton *quitBtn;

    TimeServer *timeServer;
    int count;
};

#endif // DIALOG_H
