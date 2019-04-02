#ifndef SVGMAINWINDOW_H
#define SVGMAINWINDOW_H

#include <QMainWindow>
#include "svgwindown.h"

class SvgMainWindow : public QMainWindow
{
    Q_OBJECT
public:
    explicit SvgMainWindow(QWidget *parent = nullptr);
    ~SvgMainWindow();
    void createMenu();
signals:

public slots:
    void slotOpenFile();
private:
    SvgWindown *svgWindow;
};

#endif // SVGMAINWINDOW_H
