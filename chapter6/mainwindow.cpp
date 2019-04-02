#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QWidget(parent)
{
    paintArea = new PaintArea;
    shapeLabel = new QLabel(tr("形状:"));
    shapeComboBox = new QComboBox;
    shapeComboBox->addItem(tr("Line"),PaintArea::Line);
    shapeComboBox->addItem(tr("Rectangle"),PaintArea::Rectangle);
    shapeComboBox->addItem(tr("RoundRect"),PaintArea::RoundRect);
    shapeComboBox->addItem(tr("Ellipse"),PaintArea::Ellipse);
    shapeComboBox->addItem(tr("Polygon"),PaintArea::Polygon);
    shapeComboBox->addItem(tr("Polyline"),PaintArea::Polyline);
    shapeComboBox->addItem(tr("Points"),PaintArea::Points);
    shapeComboBox->addItem(tr("Arc"),PaintArea::Arc);
    shapeComboBox->addItem(tr("Path"),PaintArea::Path);
    shapeComboBox->addItem(tr("Text"),PaintArea::Text);
    shapeComboBox->addItem(tr("Pixmap"),PaintArea::Pixmap);
    connect(shapeComboBox,SIGNAL(activated(int)),this,SLOT(showShape(int)));

    penColorLabel = new QLabel(tr("画笔颜色:"));
    penColorFrame = new QFrame;
    penColorFrame->setFrameStyle(QFrame::Panel|QFrame::Sunken);
    penColorFrame->setAutoFillBackground(true);
    penColorFrame->setPalette(QPalette(Qt::blue));
    penColorBtn = new QPushButton(tr("更改"));
    connect(penColorBtn,SIGNAL(clicked()),this,SLOT(showPenColor()));
    //connect(penColorFrame,SIGNAL(clicked()),this,SLOT(showPenColor()));

    penWidthLabel = new QLabel(tr("画笔线宽:"));
    penWidthSPinBox = new QSpinBox;
    penWidthSPinBox->setRange(0,20);
    connect(penWidthSPinBox,SIGNAL(valueChanged(int)),this,SLOT(showPenWidth(int)));

    penStyleLabel = new QLabel(tr("画笔风格:"));
    penStyleComboBox = new QComboBox;
    penStyleComboBox->addItem(tr("SolidLine"),static_cast<int>(Qt::SolidLine));
    penStyleComboBox->addItem(tr("DashLine"),static_cast<int>(Qt::DashLine));
    penStyleComboBox->addItem(tr("DotLine"),static_cast<int>(Qt::DotLine));
    penStyleComboBox->addItem(tr("DashDotLine"),static_cast<int>(Qt::DashDotLine));
    penStyleComboBox->addItem(tr("DashDotDotLine"),static_cast<int>(Qt::DashDotDotLine));
    penStyleComboBox->addItem(tr("CustomDashLine"),static_cast<int>(Qt::CustomDashLine));
    penStyleComboBox->addItem(tr("SolidLine"),static_cast<int>(Qt::SolidLine));
    connect(penStyleComboBox,SIGNAL(activated(int)),this,SLOT(showPenStyle(int)));

    penCapLabel = new QLabel(tr("画笔顶帽:"));
    penCapComboxBox = new QComboBox;
    penCapComboxBox->addItem(tr("SquareCap"),Qt::SquareCap);
    penCapComboxBox->addItem(tr("FlatCap"),Qt::FlatCap);
    penCapComboxBox->addItem(tr("RoundCap"),Qt::RoundCap);
    connect(penCapComboxBox,SIGNAL(activated(int)),this,SLOT(showPenCap(int)));

    penJoinLabel = new QLabel(tr("画笔连接点:"));
    penJoinComboBox = new QComboBox;
    penJoinComboBox->addItem(tr("BevelJoin"),Qt::BevelJoin);
    penJoinComboBox->addItem(tr("MiterJoin"),Qt::MiterJoin);
    penJoinComboBox->addItem(tr("RoundJoin"),Qt::RoundJoin);
    connect(penJoinComboBox,SIGNAL(activated(int)),this,SLOT(showPenJoin(int)));

    fillRuleLabel = new QLabel(tr("填充模式:"));
    fillRuleComboBox = new QComboBox;
    fillRuleComboBox->addItem(tr("OddEvenFill"),Qt::OddEvenFill);
    fillRuleComboBox->addItem(tr("WindingFill"),Qt::WindingFill);
    connect(fillRuleComboBox,SIGNAL(activated(int)),this,SLOT(showFillRule()));

    spreadLabel = new QLabel(tr("铺展效果:"));
    spreadComboBox = new QComboBox;
    spreadComboBox->addItem(tr("PadSpread"),QGradient::PadSpread);
    spreadComboBox->addItem(tr("RepeatSpread"),QGradient::RepeatSpread);
    spreadComboBox->addItem(tr("ReflectSpread"),QGradient::ReflectSpread);
    connect(spreadComboBox,SIGNAL(activated(int)),this,SLOT(showSpreadStyle()));

    brushColorLabel = new QLabel(tr("画刷颜色:"));
    brushColorFrame = new QFrame;
    brushColorFrame->setFrameStyle(QFrame::Panel|QFrame::Sunken);
    brushColorFrame->setAutoFillBackground(true);
    brushColorFrame->setPalette(QPalette(Qt::green));
    brushColorBtn = new QPushButton(tr("更改"));
    connect(brushColorBtn,SIGNAL(clicked()),this,SLOT(showBrushColor()));

    brushStyleLabel = new QLabel("画刷风格");
    brushStyleComboBox = new QComboBox;
    brushStyleComboBox->addItem(tr("SolidPattern"),static_cast<int>(Qt::SolidPattern));
    brushStyleComboBox->addItem(tr("Dense1Pattern"),static_cast<int>(Qt::Dense1Pattern));
    brushStyleComboBox->addItem(tr("Dense2Pattern"),static_cast<int>(Qt::Dense2Pattern));
    brushStyleComboBox->addItem(tr("Dense3Pattern"),static_cast<int>(Qt::Dense3Pattern));
    brushStyleComboBox->addItem(tr("Dense4Pattern"),static_cast<int>(Qt::Dense4Pattern));
    brushStyleComboBox->addItem(tr("Dense5Pattern"),static_cast<int>(Qt::Dense5Pattern));
    brushStyleComboBox->addItem(tr("Dense6Pattern"),static_cast<int>(Qt::Dense6Pattern));
    brushStyleComboBox->addItem(tr("Dense7Pattern"),static_cast<int>(Qt::Dense7Pattern));
    brushStyleComboBox->addItem(tr("HorPattern"),static_cast<int>(Qt::HorPattern));
    brushStyleComboBox->addItem(tr("VerPattern"),static_cast<int>(Qt::VerPattern));
    brushStyleComboBox->addItem(tr("CrossPattern"),static_cast<int>(Qt::CrossPattern));
    brushStyleComboBox->addItem(tr("BDiagPattern"),static_cast<int>(Qt::BDiagPattern));
    brushStyleComboBox->addItem(tr("FDiagPattern"),static_cast<int>(Qt::FDiagPattern));
    brushStyleComboBox->addItem(tr("DiagCrossPattern"),static_cast<int>(Qt::DiagCrossPattern));
    brushStyleComboBox->addItem(tr("LinearGradientPattern"),static_cast<int>(Qt::LinearGradientPattern));
    brushStyleComboBox->addItem(tr("ConicalGradientPattern"),static_cast<int>(Qt::ConicalGradientPattern));
    brushStyleComboBox->addItem(tr("RadialGradientPattern"),static_cast<int>(Qt::RadialGradientPattern));
    brushStyleComboBox->addItem(tr("TexturePattern"),static_cast<int>(Qt::TexturePattern));
    connect(brushStyleComboBox,SIGNAL(activated(int)),this,SLOT(showBrush(int)));

    //layout
    rightLayout = new QGridLayout;
    rightLayout->addWidget(shapeLabel,0,0);
    rightLayout->addWidget(shapeComboBox,0,1);
    rightLayout->addWidget(penColorLabel,1,0);
    rightLayout->addWidget(penColorFrame,1,1);
    rightLayout->addWidget(penColorBtn,1,2);
    rightLayout->addWidget(penWidthLabel,2,0);
    rightLayout->addWidget(penWidthSPinBox,2,1);
    rightLayout->addWidget(penStyleLabel,3,0);
    rightLayout->addWidget(penStyleComboBox,3,1);
    rightLayout->addWidget(penCapLabel,4,0);
    rightLayout->addWidget(penCapComboxBox,4,1);
    rightLayout->addWidget(penJoinLabel,5,0);
    rightLayout->addWidget(penJoinComboBox,5,1);
    rightLayout->addWidget(fillRuleLabel,6,0);
    rightLayout->addWidget(fillRuleComboBox,6,1);
    rightLayout->addWidget(spreadLabel,7,0);
    rightLayout->addWidget(spreadComboBox,7,1);
    rightLayout->addWidget(brushStyleLabel,8,0);
    rightLayout->addWidget(brushStyleComboBox,8,1);
    rightLayout->addWidget(brushColorLabel,9,0);
    rightLayout->addWidget(brushColorFrame,9,1);
    rightLayout->addWidget(brushColorBtn,9,2);

    QHBoxLayout *mainLayout = new QHBoxLayout(this);
    mainLayout->addWidget(paintArea);
    mainLayout->addLayout(rightLayout);
    mainLayout->setStretchFactor(paintArea,1);
    mainLayout->setStretchFactor(rightLayout,0);
    this->resize(700,500);
    //this->setWindowFlags(Qt::WindowStaysOnTopHint|Qt::X11BypassWindowManagerHint);
    showShape(shapeComboBox->currentIndex());
}

MainWindow::~MainWindow()
{

}

void MainWindow::showShape(int value)
{
    PaintArea::Shape shape = PaintArea::Shape(shapeComboBox->itemData(value,Qt::UserRole).toInt());
    paintArea->setShape(shape);
}

void MainWindow::showPenWidth(int value)
{
    QColor color = penColorFrame->palette().color(QPalette::Window);
    Qt::PenStyle style = Qt::PenStyle(penStyleComboBox->itemData(penStyleComboBox->currentIndex(),Qt::UserRole).toInt());
    Qt::PenCapStyle cap = Qt::PenCapStyle(penCapComboxBox->itemData(penCapComboxBox->currentIndex(),Qt::UserRole).toInt());
    Qt::PenJoinStyle join = Qt::PenJoinStyle(penJoinComboBox->itemData(penJoinComboBox->currentIndex(),Qt::UserRole).toInt());
    paintArea->setPen(QPen(color,value,style,cap,join));
}

void MainWindow::showPenColor()
{
    QColor color = QColorDialog::getColor(Qt::blue);
    penColorFrame->setPalette(QPalette(color));
    int value = penWidthSPinBox->value();
    Qt::PenStyle style = Qt::PenStyle(penStyleComboBox->itemData(penStyleComboBox->currentIndex(),Qt::UserRole).toInt());
    Qt::PenCapStyle cap = Qt::PenCapStyle(penCapComboxBox->itemData(penCapComboxBox->currentIndex(),Qt::UserRole).toInt());
    Qt::PenJoinStyle join = Qt::PenJoinStyle(penJoinComboBox->itemData(penJoinComboBox->currentIndex(),Qt::UserRole).toInt());
    paintArea->setPen(QPen(color,value,style,cap,join));
}

void MainWindow::showPenStyle(int valueStyle)
{
    QColor color = penColorFrame->palette().color(QPalette::Window);
    int value = penWidthSPinBox->value();
    Qt::PenStyle style = Qt::PenStyle(penStyleComboBox->itemData(valueStyle,Qt::UserRole).toInt());
    Qt::PenCapStyle cap = Qt::PenCapStyle(penCapComboxBox->itemData(penCapComboxBox->currentIndex(),Qt::UserRole).toInt());
    Qt::PenJoinStyle join = Qt::PenJoinStyle(penJoinComboBox->itemData(penJoinComboBox->currentIndex(),Qt::UserRole).toInt());
    paintArea->setPen(QPen(color,value,style,cap,join));
}

void MainWindow::showPenCap(int valueCap)
{
    QColor color = penColorFrame->palette().color(QPalette::Window);
    int value = penWidthSPinBox->value();
    Qt::PenStyle style = Qt::PenStyle(penStyleComboBox->itemData(penStyleComboBox->currentIndex(),Qt::UserRole).toInt());
    Qt::PenCapStyle cap = Qt::PenCapStyle(penCapComboxBox->itemData(valueCap,Qt::UserRole).toInt());
    Qt::PenJoinStyle join = Qt::PenJoinStyle(penJoinComboBox->itemData(penJoinComboBox->currentIndex(),Qt::UserRole).toInt());
    paintArea->setPen(QPen(color,value,style,cap,join));
}

void MainWindow::showPenJoin(int valueJoin)
{
    QColor color = penColorFrame->palette().color(QPalette::Window);
    int value = penWidthSPinBox->value();
    Qt::PenStyle style = Qt::PenStyle(penStyleComboBox->itemData(penStyleComboBox->currentIndex(),Qt::UserRole).toInt());
    Qt::PenCapStyle cap = Qt::PenCapStyle(penCapComboxBox->itemData(penCapComboxBox->currentIndex(),Qt::UserRole).toInt());
    Qt::PenJoinStyle join = Qt::PenJoinStyle(penJoinComboBox->itemData(valueJoin,Qt::UserRole).toInt());
    paintArea->setPen(QPen(color,value,style,cap,join));
}

void MainWindow::showSpreadStyle()
{
    this->spread = QGradient::Spread(spreadComboBox->itemData(spreadComboBox->currentIndex(),Qt::UserRole).toInt());
}

void MainWindow::showFillRule()
{
    Qt::FillRule rule = Qt::FillRule(fillRuleComboBox->itemData(fillRuleComboBox->currentIndex(),Qt::UserRole).toInt());
    paintArea->setFillRule(rule);
}

void MainWindow::showBrushColor()
{
    QColor color = QColorDialog::getColor(Qt::blue);
    qDebug()<<color;
    brushColorFrame->setPalette(QPalette(color));
    showBrush(brushStyleComboBox->currentIndex());
}

void MainWindow::showBrush(int value)
{
    QColor color = brushColorFrame->palette().color(QPalette::Window);
    Qt::BrushStyle style = Qt::BrushStyle(brushStyleComboBox->itemData(value,Qt::UserRole).toInt());
    if(style==Qt::LinearGradientPattern){
        QLinearGradient linearGradient(0,0,400,400);
        linearGradient.setColorAt(0.0,Qt::white);
        linearGradient.setColorAt(0.2,color);
        linearGradient.setColorAt(1.0,Qt::black);
        linearGradient.setSpread(spread);
        paintArea->setBrush(linearGradient);
    }else if(style==Qt::RadialGradientPattern){
        QRadialGradient radialGradient(200,200,150,150,100);
        radialGradient.setColorAt(0.0,Qt::white);
        radialGradient.setColorAt(0.2,color);
        radialGradient.setColorAt(1.0,Qt::black);
        radialGradient.setSpread(spread);
        paintArea->setBrush(radialGradient);
    }else if(style==Qt::ConicalGradientPattern){
        QConicalGradient conicalGradient(200,200,30);
        conicalGradient.setColorAt(0.0,Qt::white);
        conicalGradient.setColorAt(0.2,color);
        conicalGradient.setCenter(1.0,Qt::black);
    }else if(style==Qt::TexturePattern){
        paintArea->setBrush(QBrush(QPixmap(":/img/butterfly.png")));
        qDebug()<<"Qt::TexturePattern";
    }else{
        paintArea->setBrush(QBrush(color,style));
    }

}
