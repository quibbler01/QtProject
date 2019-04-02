#include "dialog.h"
#include "ui_dialog.h"

#include <QRegExp>
#include <QPushButton>


Dialog::Dialog(QDialog *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
    QRegExp regExp("[A-Za-z][1-9][0-9]{0,2}");
    ui->lineEdit->setValidator(new QRegExpValidator(regExp));
    connect(ui->okButton,SIGNAL(clicked()),this,SLOT(accept()));
    connect(ui->cancleButton,SIGNAL(clicked()),this,SLOT(reject()));


}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::on_lineEdit_textChanged(const QString &arg1)
{
    Q_UNUSED(arg1);
    ui->okButton->setEnabled(ui->lineEdit->hasAcceptableInput());
}
