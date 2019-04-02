#include "fontdialog.h"

FontDialog::FontDialog(QDialog *parent):QDialog (parent)
{
    chooseFontButton = new QPushButton(tr("选择字体"));
    choosedFont = new QLineEdit(tr("Welcome,欢迎"));
    choosedFont->setReadOnly(true);

    mainLayout = new QGridLayout(this);
    mainLayout->addWidget(chooseFontButton,0,0);
    mainLayout->addWidget(choosedFont,0,1);
    mainLayout->setColumnStretch(0,1);
    mainLayout->setColumnStretch(1,3);

    connect(chooseFontButton,&QPushButton::clicked,[=](){
       QFont font = QFontDialog::getFont(nullptr);
       choosedFont->setFont(font);
    });


}
