#include "dockwindow.h"
#include <QTextEdit>
#include <QDockWidget>

DockWindow::DockWindow(QMainWindow *parent) : QMainWindow(parent)
{
    this->setWindowTitle("DockWindows");
    QTextEdit *te = new QTextEdit(this);
    te->setText("Main Window");
    te->setAlignment(Qt::AlignCenter);
    this->setCentralWidget(te);
    //
    QDockWidget *dock = new QDockWidget("DockWindow1",this);
    dock->setFeatures(QDockWidget::DockWidgetMovable);
    dock->setAllowedAreas(Qt::LeftDockWidgetArea|Qt::RightDockWidgetArea);

    QTextEdit *te1 = new QTextEdit();
    te1->setText("Window1,The dock widget can be moved between docks by the user");

    dock->setWidget(te1);
    addDockWidget(Qt::RightDockWidgetArea,dock);


    QDockWidget *dock2 = new QDockWidget("DockWindow2",this);
    dock2->setFeatures(QDockWidget::DockWidgetMovable|QDockWidget::DockWidgetClosable|QDockWidget::DockWidgetFloatable);
    QTextEdit *te2 = new QTextEdit();
    te2->setText("Window2,The dock widget can be detached from the mainwindow,and floated as an independent window,and can be closed");
    dock2->setWidget(te2);
    addDockWidget(Qt::RightDockWidgetArea,dock2);

    QDockWidget* dock3 = new QDockWidget("DockWindow3",this);
    dock3->setFeatures(QDockWidget::AllDockWidgetFeatures);
    QTextEdit *te3 = new QTextEdit();
    te3->setText("Window3,The dock widget can be closed.moved,and floated");
    dock3->setWidget(te3);

    this->addDockWidget(Qt::RightDockWidgetArea,dock3);
}
