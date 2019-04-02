#include "svgmainwindow.h"

SvgMainWindow::SvgMainWindow(QWidget *parent) : QMainWindow(parent)
{
    this->setWindowTitle(tr("Svg Viewer"));
    createMenu();
    svgWindow = new SvgWindown;
    this->setCentralWidget(svgWindow);
}

SvgMainWindow::~SvgMainWindow()
{

}

void SvgMainWindow::createMenu()
{
    QMenu *fileMenu = menuBar()->addMenu(tr("文件"));
    QAction *openFileAction = new QAction(tr("打开"),this);
    connect(openFileAction,SIGNAL(triggered()),this,SLOT(slotOpenFile()));
    fileMenu->addAction(openFileAction);
}

void SvgMainWindow::slotOpenFile()
{
    QString name = QFileDialog::getOpenFileName(this,tr("打开Svg"),"/","Svg files(*.svg)");
    svgWindow->setFile(name);
}
