#ifndef SPLASHSCREEN_H
#define SPLASHSCREEN_H

#include <QMainWindow>
#include <QTextEdit>
#include <windows.h>

class SplashScreen : public QMainWindow
{
    Q_OBJECT
public:
    explicit SplashScreen(QWidget *parent = nullptr);

signals:

public slots:
};

#endif // SPLASHSCREEN_H
