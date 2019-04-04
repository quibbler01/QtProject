#ifndef KEYEVENT_H
#define KEYEVENT_H

#include <QMainWindow>
#include <QKeyEvent>
#include <QPainter>
#include <QPaintEvent>

class KeyEvent : public QMainWindow
{
    Q_OBJECT
public:
    explicit KeyEvent(QWidget *parent = nullptr);
    ~KeyEvent();
    void drawPix();
    void keyPressEvent(QKeyEvent *e);
    void paintEvent(QPaintEvent *e);

private:
    QPixmap *pix;
    QImage image;
    int startX;
    int startY;

    int width;
    int height;
    int setp;

signals:

public slots:

};

#endif // KEYEVENT_H
