#include "drawsomething.h"

DrawSomething::DrawSomething(QWidget *parent) : QMainWindow(parent)
{
    drawWidget = new DrawWidget;
    setCentralWidget(drawWidget);
    createToolBar();
    this->setMinimumSize(600,400);
    showStyle();
    drawWidget->setWidth(widthSpinBox->value());
    drawWidget->setColor(Qt::black);
}

DrawSomething::~DrawSomething()
{

}

void DrawSomething::createToolBar()
{
    QToolBar *toolBar = this->addToolBar(tr("工具栏"));
    styleLabel = new QLabel(tr("样式:"));
    styleComboBox = new QComboBox;
    styleComboBox->addItem(tr("SolidLine"),static_cast<int>(Qt::SolidLine));
    styleComboBox->addItem(tr("DashLine"),static_cast<int>(Qt::DashLine));
    styleComboBox->addItem(tr("DotLine"),static_cast<int>(Qt::DotLine));
    styleComboBox->addItem(tr("DashDotLine"),static_cast<int>(Qt::DashDotLine));
    styleComboBox->addItem(tr("DashDotDotLine"),static_cast<int>(Qt::DashDotDotLine));
    connect(styleComboBox,SIGNAL(activated(int)),this,SLOT(showStyle()));

    widthLabel = new QLabel(tr("线条宽度:"));
    widthSpinBox = new QSpinBox;
    widthSpinBox->setRange(0,20);
    connect(widthSpinBox,SIGNAL(valueChanged(int)),drawWidget,SLOT(setWidth(int)));

    colorBtn = new QToolButton();
    QPixmap pixmap(20,20);
    pixmap.fill(Qt::black);
    colorBtn->setIcon(QIcon(pixmap));
    connect(colorBtn,SIGNAL(clicked()),this,SLOT(showColor()));

    clearBtn = new QToolButton;
    clearBtn->setText(tr("清除"));
    connect(clearBtn,SIGNAL(clicked()),drawWidget,SLOT(clear()));

    toolBar->addWidget(styleLabel);
    toolBar->addWidget(styleComboBox);
    toolBar->addWidget(widthLabel);
    toolBar->addWidget(widthSpinBox);
    toolBar->addSeparator();
    toolBar->addWidget(colorBtn);
    toolBar->addWidget(clearBtn);
}

void DrawSomething::showStyle()
{
    drawWidget->setStyle(styleComboBox->itemData(styleComboBox->currentIndex(),Qt::UserRole).toInt());
}

void DrawSomething::showColor()
{
    QColor color = QColorDialog::getColor(Qt::blue,this);
    if(color.isValid()){
        drawWidget->setColor(color);
        QPixmap pixmap(20,20);
        pixmap.fill(color);
        colorBtn->setIcon(QIcon(pixmap));
    }

}
