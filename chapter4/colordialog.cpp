#include "colordialog.h"

ColorDialog::ColorDialog(QDialog *parent):QDialog(parent)
{
    chooseColorButton = new QPushButton(tr("选择颜色"));
    showColorFrame = new QFrame;
    showColorFrame->setFrameShape(QFrame::Box);
    showColorFrame->setAutoFillBackground(true);
    mainLayout = new QGridLayout(this);
    mainLayout->addWidget(chooseColorButton,0,0);
    mainLayout->addWidget(showColorFrame,0,1);
    mainLayout->setColumnStretch(0,1);
    mainLayout->setColumnStretch(1,3);
    connect(chooseColorButton,&QPushButton::clicked,[=](){
        QColor c = QColorDialog::getColor();
        showColorFrame->setPalette(QPalette(c));
    });
}

void ColorDialog::show()
{

}
