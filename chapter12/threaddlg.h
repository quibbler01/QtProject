#ifndef THREADDLG_H
#define THREADDLG_H

#include <QWidget>
#include <QPushButton>
#include <QHBoxLayout>
#include "workthread.h"

#define MAXSIZE 1 /**线程池设置为1或者5，观察程序运行输出结果顺序**/

class ThreadDlg : public QWidget
{
    Q_OBJECT
public:
    explicit ThreadDlg(QWidget *parent = nullptr);
    ~ThreadDlg();

signals:

public slots:
    void slotStartThread();
    void slotStopThread();
    void slotQuit();

private:
    QPushButton *startBtn;
    QPushButton *stopBtn;
    QPushButton *quitBtn;
    QHBoxLayout *mainLayout;

    WorkThread *workThreads[MAXSIZE];

};

#endif // THREADDLG_H
