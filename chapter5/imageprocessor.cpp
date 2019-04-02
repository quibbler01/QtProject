#include "imageprocessor.h"
#include "ui_imageprocessor.h"

ImageProcessor::ImageProcessor(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::ImageProcessor)
{
    //ui->setupUi(this);
    this->setWindowTitle(tr("Easy World"));
    showWidget = new ShowWidget(this);
    this->setCentralWidget(showWidget);
    fontLabel = new QLabel(tr("字体"));
    fontComboBox =  new QFontComboBox;
    fontComboBox->setFontFilters(QFontComboBox::ScalableFonts);
    fontLabel2 = new QLabel(tr("字号"));
    sizeComBox = new QComboBox;
    QFontDatabase db;
    foreach(int size,db.standardSizes()){
        sizeComBox->addItem(QString::number(size));
    }
    boldBtn = new QToolButton;
    boldBtn->setIcon(QIcon(":/bold.png"));
    boldBtn->setCheckable(true);
    italicBtn = new QToolButton;
    italicBtn->setIcon(QIcon(":/italic.png"));
    italicBtn->setCheckable(true);
    underLineBtn = new QToolButton;
    underLineBtn->setIcon(QIcon(":/underline_502px_1145627_easyicon.net.png"));
    underLineBtn->setCheckable(true);
    colorBtn = new QToolButton;
    colorBtn->setIcon(QIcon(":/color_palette_1876px_1202956_easyicon.net.png"));
    colorBtn->setCheckable(true);

    //
    createActions();
    createMenus();
    createToolBars();
    if(img.load(":/img/butterfly.png")){
        showWidget->imageLabel->setPixmap(QPixmap::fromImage(img));
    }
    //final add font to mainwindow,and connect signal and slots
    fontToolBar = this->addToolBar(tr("字体"));
    fontToolBar->addWidget(fontLabel);
    fontToolBar->addWidget(fontComboBox);
    fontToolBar->addWidget(fontLabel2);
    fontToolBar->addWidget(sizeComBox);
    fontToolBar->addSeparator();
    fontToolBar->addWidget(boldBtn);
    fontToolBar->addWidget(italicBtn);
    fontToolBar->addWidget(underLineBtn);
    fontToolBar->addSeparator();
    fontToolBar->addWidget(colorBtn);
    connect(fontComboBox,SIGNAL(activated(QString)),this,SLOT(showFontComboBox(QString)));
    connect(sizeComBox,SIGNAL(activated(QString)),this,SLOT(showSizeComSpinBox(QString)));
    connect(boldBtn,SIGNAL(clicked()),this,SLOT(showBoldBtn()));
    connect(italicBtn,SIGNAL(clicked()),this,SLOT(showItalicBtn()));
    connect(underLineBtn,SIGNAL(clicked()),this,SLOT(showUnderLineBtn()));
    connect(colorBtn,SIGNAL(clicked()),this,SLOT(showColorBtn()));
    connect(showWidget->textEdit,SIGNAL(currentCharFormatChanged(const QTextCharFormat &format)),
            this,SLOT(showCurrentFormatChanged(const QTextCharFormat&)));
    //currentCharFormatChanged(const QTextCharFormat &format)
    connect(showWidget->textEdit,SIGNAL(currentCharFormatChanged(QTextCharFormat&)),this,SLOT(showCurrentFormatChanged(QTextCharFormat&)));
}

ImageProcessor::~ImageProcessor()
{
    delete ui;
}

void ImageProcessor::createActions()
{
    //open file
    openFileAction = new QAction(QIcon(":/open_file.png"),tr("打开"),this);
    openFileAction->setShortcut(tr("Ctrl+O"));
    openFileAction->setStatusTip(tr("打开一个文件"));
    connect(openFileAction,SIGNAL(triggered()),this,SLOT(OpenFile()));
    //new file
    NewFileAction = new QAction(QIcon(":/file_create_149px_1222865_easyicon.net.png"),tr("新建"),this);
    NewFileAction->setShortcut(tr("Ctrl+N"));
    NewFileAction->setStatusTip(tr("新建一个文件"));
    connect(NewFileAction,SIGNAL(triggered()),this,SLOT(ShowNewFile()));
    //exit
    exitAction = new QAction(QIcon(":/exit_783px_1226698_easyicon.net.png"),tr("退出"),this);
    exitAction->setShortcut(tr("Ctrl+Q"));
    exitAction->setStatusTip(tr("退出程序"));
    connect(exitAction,SIGNAL(triggered()),this,SLOT(close()));
    //copy
    copyAction = new QAction(QIcon(":/copy_148px_1223049_easyicon.net.png"),tr("复制"),this);
    copyAction->setShortcut(tr("Ctrl+C"));
    copyAction->setStatusTip(tr("复制"));
    connect(copyAction,SIGNAL(triggered()),showWidget->textEdit,SLOT(copy()));
    //cut
    cutAction = new QAction(QIcon(":/cut_coupon_148px_1222587_easyicon.net.png"),tr("剪切"),this);
    cutAction->setShortcut(tr("Ctrl+X"));
    cutAction->setStatusTip(tr("剪切"));
    connect(cutAction,SIGNAL(triggered()),showWidget->textEdit,SLOT(cut()));
    //past
    pasteAction = new QAction(QIcon(":/paste_667px_1158069_easyicon.net.png"),tr("粘贴"),this);
    pasteAction->setShortcut(tr("Ctrl+V"));
    pasteAction->setStatusTip(tr("粘贴文件"));
    connect(pasteAction,SIGNAL(triggered()),showWidget->textEdit,SLOT(paste()));
    //about
    aboutAction = new QAction(QIcon(":/talking_about_love_512px_1079060_easyicon.net.png"),tr("关于"),this);
    //aboutAction->setShortcut(tr("Ctrl+A"));
    aboutAction->setStatusTip(tr("关于"));
    //connect(aboutAction,SIGNAL(triggered()),this,SLOT(QApplication::aboutQt()));
    connect(aboutAction,&QAction::triggered,[&](){
        QMessageBox::aboutQt(this);
    });
    //print text
    PrintTextAction = new QAction(QIcon(":/print_702px_1196212_easyicon.net.png"),tr("打印"),this);
    PrintTextAction->setShortcut(tr("Ctrl+P"));
    PrintTextAction->setStatusTip(tr("打印文件"));
    connect(PrintTextAction,SIGNAL(triggered()),this,SLOT(showPrintText()));
    //print image
    PrintImageAction = new QAction(QIcon(":/print_277px_1211067_easyicon.net.png"),tr("打印图像"),this);
    PrintImageAction->setStatusTip(tr("打印左侧图像"));
    connect(PrintImageAction,SIGNAL(triggered()),this,SLOT(showPrintImage()));
    //zoomIn
    zoomInActoin = new QAction(QIcon(":/zoom_in_625px_1231412_easyicon.net.png"),tr("放大"),this);
    zoomInActoin->setStatusTip(tr("放大图像"));
    connect(zoomInActoin,SIGNAL(triggered()),this,SLOT(showZoomIn()));
    //zoomOut
    zoomOutAction = new QAction(QIcon(":/zoom_out_625px_1231417_easyicon.net.png"),tr("缩小"),this);
    zoomOutAction->setStatusTip(tr("缩小图像"));
    connect(zoomOutAction,SIGNAL(triggered()),this,SLOT(showZoomOut()));
    //rotate 90
    rotate90Action = new QAction(QIcon(":/90.png"),tr("旋转90°"),this);
    rotate90Action->setStatusTip(tr("旋转90°"));
    connect(rotate90Action,SIGNAL(triggered()),this,SLOT(showRotate90()));
    //rotate 180
    rotate180Action = new QAction(QIcon(":/180.png"),tr("旋转180°"),this);
    rotate180Action->setStatusTip(tr("旋转180°"));
    connect(rotate180Action,SIGNAL(triggered()),this,SLOT(showRotate180()));
    //rotate 270
    rotate270Action = new QAction(QIcon(":/270.png"),tr("旋转270°"),this);
    rotate270Action->setStatusTip(tr("旋转270°"));
    connect(rotate270Action,SIGNAL(triggered()),this,SLOT(showRotate270()));
    //mirror vertical
    mirrorVerticalAction = new QAction(QIcon(":/Split_Horizontal_222px_1190982_easyicon.net.png"),tr("垂直镜像"),this);
    mirrorVerticalAction->setStatusTip(tr("垂直镜像"));
    connect(mirrorVerticalAction,SIGNAL(triggered()),this,SLOT(showVerticalMirror()));
    //mirror horizontal
    mirrorHorizontalAction = new QAction(QIcon(":/arrows_expand_horizontal_265px_1182500_easyicon.net.png"),tr("水平镜像"),this);
    mirrorHorizontalAction->setStatusTip(tr("水平镜像"));
    connect(mirrorHorizontalAction,SIGNAL(triggered()),this,SLOT(showHorizontalMirror()));
    //undo
    undoAction = new QAction(QIcon(":/undo.png"),tr("撤销"),this);
    undoAction->setShortcut(tr("Ctrl+Z"));
    undoAction->setStatusTip(tr("撤销编辑"));
    connect(undoAction,SIGNAL(triggered()),showWidget->textEdit,SLOT(undo()));
    //redo
    redoAction = new QAction(QIcon(":/redo.png"),tr("重做"),this);
    redoAction->setShortcut(tr("Ctrl+Y"));
    redoAction->setStatusTip(tr("重做"));
    connect(redoAction,SIGNAL(triggered()),showWidget->textEdit,SLOT(redo()));
}
/*
 * this->menuBar()->addMenu(tr("menu"))
 * */
void ImageProcessor::createMenus()
{
    //file menu
    fileMenu = this->menuBar()->addMenu(tr("文件"));
    fileMenu->addAction(openFileAction);
    fileMenu->addAction(NewFileAction);
    fileMenu->addAction(PrintTextAction);
    fileMenu->addAction(PrintImageAction);
    fileMenu->addSeparator();
    fileMenu->addAction(exitAction);
    //edit menu
    zoomMenu = this->menuBar()->addMenu(tr("编辑"));
    zoomMenu->addAction(undoAction);
    zoomMenu->addAction(redoAction);
    zoomMenu->addSeparator();
    zoomMenu->addAction(copyAction);
    zoomMenu->addAction(cutAction);
    zoomMenu->addAction(pasteAction);

    zoomMenu->addSeparator();
    zoomMenu->addAction(zoomInActoin);
    zoomMenu->addAction(zoomOutAction);
    //rotate menu
    rotateMenu = this->menuBar()->addMenu(tr("旋转"));
    rotateMenu->addAction(rotate90Action);
    rotateMenu->addAction(rotate180Action);
    rotateMenu->addAction(rotate270Action);
    //mirror menu
    mirrorMenu = this->menuBar()->addMenu(tr("镜像"));
    mirrorMenu->addAction(mirrorHorizontalAction);
    mirrorMenu->addAction(mirrorVerticalAction);
    //about menu
    QMenu *aboutMenu = this->menuBar()->addMenu(tr("关于"));
    aboutMenu->addAction(aboutAction);
}

void ImageProcessor::createToolBars()
{
    //file tool
    fileTool = this->addToolBar(tr("文件"));
    fileTool->addAction(openFileAction);
    fileTool->addAction(NewFileAction);
    fileTool->addAction(PrintTextAction);
    fileTool->addAction(PrintImageAction);
    //edit tool bar
    zoomTool = this->addToolBar(tr("编辑"));
    zoomTool->addAction(undoAction);
    zoomTool->addAction(redoAction);
    zoomTool->addAction(copyAction);
    zoomTool->addAction(cutAction);
    zoomTool->addAction(pasteAction);
    zoomTool->addSeparator();
    zoomTool->addAction(zoomInActoin);
    zoomTool->addAction(zoomOutAction);
    //rotate bar
    rotateTool = this->addToolBar(tr("旋转"));
    rotateTool->addAction(rotate90Action);
    rotateTool->addAction(rotate180Action);
    rotateTool->addAction(rotate270Action);

}

void ImageProcessor::loadFile(QString fileName)
{
    printf("file name is %s",fileName.data());
    QFile file(fileName);
    if(file.open(QIODevice::ReadOnly|QIODevice::Text)){
        QTextStream textStream(&file);
        while(!textStream.atEnd()){
            showWidget->textEdit->append(textStream.readLine());
            printf("read line\n");
        }
    }
    printf("end\n");
}

void ImageProcessor::mergeFormat(QTextCharFormat fmt)
{
    QTextCursor cursor = showWidget->textEdit->textCursor();
    if(!cursor.hasSelection()){
        cursor.select(QTextCursor::WordUnderCursor);
    }
    cursor.mergeBlockCharFormat(fmt);
    showWidget->textEdit->mergeCurrentCharFormat(fmt);
}
/*
 * 新建新文件，新开一个窗口
 */
void ImageProcessor::ShowNewFile()
{
    ImageProcessor *imageProcessor = new ImageProcessor;
    imageProcessor->show();
}
/*
 * 打开一个文件
 */
void ImageProcessor::OpenFile()
{
    QString fileName = QFileDialog::getOpenFileName(this,tr("打开文件"),"/");
    if(!fileName.isEmpty()){
        if(showWidget->textEdit->document()->isEmpty()){
            loadFile(fileName);
        }else{
            ImageProcessor *newWindow = new ImageProcessor;
            newWindow->show();
            newWindow->loadFile(fileName);
        }
    }
}

void ImageProcessor::showPrintText()
{
    QPrinter printer;
    QPrintDialog printDialog(&printer,this);
    if(printDialog.exec()){
        QTextDocument *doc = showWidget->textEdit->document();
        doc->print(&printer);
    }
}

void ImageProcessor::showPrintImage()
{
    QPrinter printer;
    QPrintDialog printDialog(&printer,this);
    if(printDialog.exec()){
        QPainter painter(&printer);
        QRect rect = painter.viewport();
        QSize size = img.size();
        size.scale(rect.size(),Qt::KeepAspectRatio);
        painter.setViewport(rect.x(),rect.y(),size.width(),size.height());
        painter.setWindow(img.rect());
        painter.drawImage(0,0,img);
    }
}

void ImageProcessor::showZoomIn()
{
    if(!img.isNull()){
        QMatrix matrix;
        matrix.scale(2,2);
        img = img.transformed(matrix);
        showWidget->imageLabel->setPixmap(QPixmap::fromImage(img));
    }
}

void ImageProcessor::showZoomOut()
{
    if(!img.isNull()){
        QMatrix matrix;
        matrix.scale(0.5,0.5);
        img = img.transformed(matrix);
        showWidget->imageLabel->setPixmap(QPixmap::fromImage(img));
    }
}

void ImageProcessor::showRotate90()
{
    if(!img.isNull()){
        QMatrix matrix;
        matrix.rotate(90);
        img = img.transformed(matrix);
        showWidget->imageLabel->setPixmap(QPixmap::fromImage(img));
    }
}

void ImageProcessor::showRotate180()
{
    if(!img.isNull()){
        QMatrix matrix;
        matrix.rotate(180);
        img = img.transformed(matrix);
        showWidget->imageLabel->setPixmap(QPixmap::fromImage(img));
    }
}

void ImageProcessor::showRotate270()
{
    if(!img.isNull()){
        QMatrix matrix;
        matrix.rotate(270);
        img = img.transformed(matrix);
        showWidget->imageLabel->setPixmap(QPixmap::fromImage(img));
    }
}

void ImageProcessor::showHorizontalMirror()
{
    if(img.isNull()){
        return;
    }else{
        img = img.mirrored(true,false);
        showWidget->imageLabel->setPixmap(QPixmap::fromImage(img));
    }
}

void ImageProcessor::showVerticalMirror()
{
    if(!img.isNull()){
        img = img.mirrored(false,true);
        showWidget->imageLabel->setPixmap(QPixmap::fromImage(img));

    }
}

void ImageProcessor::showFontComboBox(QString comboStr)
{
    QTextCharFormat fmt;
    fmt.setFontFamily(comboStr);
    mergeFormat(fmt);
}

void ImageProcessor::showSizeComSpinBox(QString spinVal)
{
    QTextCharFormat fmt;
    fmt.setFontPointSize(spinVal.toFloat());
    showWidget->textEdit->mergeCurrentCharFormat(fmt);
}

void ImageProcessor::showBoldBtn()
{
    QTextCharFormat fmt;
    fmt.setFontWeight(boldBtn->isChecked()?QFont::Bold:QFont::Normal);
    showWidget->textEdit->mergeCurrentCharFormat(fmt);
}

void ImageProcessor::showItalicBtn()
{
    QTextCharFormat fmt;
    fmt.setFontItalic(italicBtn->isChecked());
    showWidget->textEdit->mergeCurrentCharFormat(fmt);
}

void ImageProcessor::showUnderLineBtn()
{
    QTextCharFormat fmt;
    fmt.setFontUnderline(underLineBtn->isChecked());
    showWidget->textEdit->mergeCurrentCharFormat(fmt);
}

void ImageProcessor::showColorBtn()
{
    QColor color = QColorDialog::getColor(Qt::red,this);
    if(color.isValid()){
        QTextCharFormat fmt;
        fmt.setForeground(color);
        showWidget->textEdit->mergeCurrentCharFormat(fmt);
    }
}

void ImageProcessor::showCurrentFormatChanged(const QTextCharFormat &fmt)
{
    fontComboBox->setCurrentIndex(fontComboBox->findText(fmt.fontFamily()));
    sizeComBox->setCurrentIndex(sizeComBox->findText(QString::number(fmt.fontPointSize())));
    boldBtn->setChecked(fmt.font().bold());
    italicBtn->setChecked(fmt.font().italic());
    underLineBtn->setChecked(fmt.font().underline());
}
