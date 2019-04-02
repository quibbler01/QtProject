#include "dialog.h"

Dialog::Dialog(QDialog *parent):QDialog (parent)
{
    chooseFileButton = new QPushButton(tr("选择文件"));
    filePathLineEdit = new QLineEdit;
    filePathLineEdit->setReadOnly(true);
    mainLayout = new QGridLayout(this);
    mainLayout->addWidget(chooseFileButton,0,0);
    mainLayout->addWidget(filePathLineEdit,0,1);
    mainLayout->setColumnStretch(0,1);
    mainLayout->setColumnStretch(1,3);

    connect(chooseFileButton,&QPushButton::clicked,[&]{
        QString path = QFileDialog::getOpenFileName(this,"选择文件","/","C++(*.cpp *.c *.h);;C(*.c);;Head(*.h)");
        filePathLineEdit->setText(path);
    });
}
