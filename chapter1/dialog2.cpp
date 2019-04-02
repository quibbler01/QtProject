#include "dialog2.h"


Dialog2::Dialog2(QWidget*parent):QDialog (parent)
{
    //使用setBuddy()设置伙伴关系的时候不需要再设置setText();否则会使"&Key"快捷键失效
    QLineEdit *nameEdit  = new QLineEdit(this);
    QLabel    *nameLabel = new QLabel("&Name:", this);
    nameLabel->setBuddy(nameEdit);

    rangeLineEdit = new QLineEdit(this);
    rangeLabel = new QLabel("&Range:",this);
    //rangeLabel->setText(tr("请输入圆的半径:"));
    rangeLabel->setBuddy(rangeLineEdit);

    bLabel = new QLabel(this);
    calcButton = new QPushButton(this);
    calcButton->setText(tr("计算对应圆的面积"));

    QGridLayout *mainLayout = new QGridLayout(this);
    mainLayout->addWidget(rangeLabel,0,0);
    mainLayout->addWidget(rangeLineEdit,0,1);
    mainLayout->addWidget(bLabel,1,0);
    mainLayout->addWidget(calcButton,1,1);

    mainLayout->addWidget(nameLabel,2,0);
    mainLayout->addWidget(nameEdit,2,1);
    this->setLayout(mainLayout);

    connect(calcButton,SIGNAL(clicked()),this,SLOT(showArea()));
    connect(rangeLineEdit,SIGNAL(textChanged(QString)),this,SLOT(showArea()));
}

Dialog2::~Dialog2()
{

}

void Dialog2::showArea()
{
    QString tempStr;
    QString valueStr = rangeLineEdit->text();
    int valueInt = valueStr.toInt(new bool);
    double area  =valueInt*valueInt*PI;
    bLabel->setText(tempStr.setNum(area));
}
