#ifndef EVENTFILTER_H
#define EVENTFILTER_H

#include <QDialog>
#include <QLabel>
#include <QImage>
#include <QEvent>
#include <QHBoxLayout>
#include <QMouseEvent>

class EventFilter : public QDialog
{
    Q_OBJECT
public:
    explicit EventFilter(QWidget *parent = nullptr);
    ~EventFilter();

signals:

public slots:
    bool eventFilter(QObject*,QEvent*);

private:
    QLabel *label1;
    QLabel *label2;
    QLabel *label3;
    QLabel *stateLabel;
    QImage image1;
    QImage image2;
    QImage image3;
};

#endif // EVENTFILTER_H
