#include "final.h"

Final::Final(QWidget *parent) : QWidget(parent)
{
    chooseFileDialog = new Dialog;
    chooseColorDialo = new ColorDialog;
    fontDialog = new FontDialog;
    inputDialog = new InputDialog;
    messageDialog = new MessageDialog;



    QPushButton *inputButton = new QPushButton(tr("演示输入对话框"));
    connect(inputButton,&QPushButton::clicked,[=](){
       inputDialog->show();
    });

    layout = new QVBoxLayout(this);
    layout->setSpacing(10);
    layout->addWidget(chooseFileDialog);
    layout->addWidget(chooseColorDialo);
    layout->addWidget(fontDialog);
    layout->addWidget(inputButton);
    layout->addWidget(messageDialog);
}
