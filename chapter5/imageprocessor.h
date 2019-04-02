#ifndef IMAGEPROCESSOR_H
#define IMAGEPROCESSOR_H

#include <QMainWindow>
#include <QImage>
#include <QLabel>
#include <QLineEdit>
#include <QMenu>
#include <QMenuBar>
#include <QAction>
#include <QComboBox>
#include <QSpinBox>
#include <QToolBar>
#include <QFontComboBox>
#include <QToolButton>
#include <QTextCharFormat>
#include <QAction>
#include <QMessageBox>
#include <QFileDialog>
#include <QFile>
#include <QTextStream>
#include <QPrinter>
#include <QPrintDialog>
#include <QPainter>
#include <QColor>
#include <QColorDialog>

#include <QTextCharFormat>
#include <QTextBlockFormat>
#include <QTextListFormat>
#include <QTextFrameFormat>
#include <QTextTableFormat>
#include <QTextBlock>
#include <QTextList>
#include <QTextTable>
#include <QTextFrame>

#include "showwidget.h"

namespace Ui {
class ImageProcessor;
}

class ImageProcessor : public QMainWindow
{
    Q_OBJECT

public:
    explicit ImageProcessor(QWidget *parent = nullptr);
    ~ImageProcessor();
    void createActions();
    void createMenus();
    void createToolBars();
    void loadFile(QString fileName);
    void mergeFormat(QTextCharFormat);

protected slots:
    void ShowNewFile();
    void OpenFile();
    void showPrintText();
    void showPrintImage();
    void showZoomIn();
    void showZoomOut();
    void showRotate90();
    void showRotate180();
    void showRotate270();
    void showHorizontalMirror();
    void showVerticalMirror();
    void showFontComboBox(QString comboStr);
    void showSizeComSpinBox(QString spinVal);
    void showBoldBtn();
    void showItalicBtn();
    void showUnderLineBtn();
    void showColorBtn();
    void showCurrentFormatChanged(const QTextCharFormat &fmt);


private:
    Ui::ImageProcessor *ui;
    QMenu *fileMenu;
    QMenu *zoomMenu;
    QMenu *rotateMenu;
    QMenu *mirrorMenu;
    QImage img;
    QString fileName;
    ShowWidget *showWidget;
    //File option
    QAction *openFileAction;
    QAction *NewFileAction;
    QAction *PrintTextAction;
    QAction *PrintImageAction;
    QAction *exitAction;
    //Edit option
    QAction *copyAction;
    QAction *cutAction;
    QAction *pasteAction;
    QAction *aboutAction;
    QAction *zoomInActoin;
    QAction *zoomOutAction;
    //Rotate option
    QAction *rotate90Action;
    QAction *rotate180Action;
    QAction *rotate270Action;
    QAction *mirrorVerticalAction;
    QAction *mirrorHorizontalAction;
    QAction *undoAction;
    QAction *redoAction;
    //Tool Bar
    QToolBar *fileTool;
    QToolBar *zoomTool;
    QToolBar *rotateTool;
    QToolBar *mirrorTool;
    QToolBar *doToolBar;
    //font Bar
    QLabel *fontLabel;
    QFontComboBox *fontComboBox;
    QLabel *fontLabel2;
    QComboBox *sizeComBox;
    QToolButton *boldBtn;
    QToolButton *italicBtn;
    QToolButton *underLineBtn;
    QToolButton *colorBtn;
    QToolBar *fontToolBar;




};


#endif // IMAGEPROCESSOR_H
