#ifndef DOCKWINDOW_H
#define DOCKWINDOW_H

#include <QMainWindow>

class DockWindow : public QMainWindow
{
    Q_OBJECT
public:
    explicit DockWindow(QMainWindow *parent = nullptr);

signals:

public slots:
};

#endif // DOCKWINDOW_H
