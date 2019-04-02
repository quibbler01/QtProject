#include "chapter4.h"
#include "ui_chapter4.h"

Chapter4::Chapter4(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Chapter4)
{
    ui->setupUi(this);
}

Chapter4::~Chapter4()
{
    delete ui;
}
