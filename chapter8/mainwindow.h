#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QStandardItemModel>
#include <QTableView>
#include <QMenuBar>
#include <QMenu>
#include <QAction>
#include <QSplitter>
#include <QFile>
#include <QFileDialog>
#include <QTextStream>
#include <QStringList>

#include "histogramview.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void createAction();
    void createMenu();
    void setupModel();
    void setupView();
    void openFile(QString fileName);

protected slots:
    void slotOpenFile();

private:
    QMenu *fileMenu;
    QAction *openAct;
    QStandardItemModel *model;
    QTableView *table;
    QSplitter *splitter;

    HistogramView *histogram;

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
