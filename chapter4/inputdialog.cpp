#include "inputdialog.h"

InputDialog::InputDialog(QDialog *parent):QDialog(parent)
{
    NameLabel = new QLabel(tr("姓名："));
    SexLabel = new QLabel(tr("性别："));
    AgeLabel = new QLabel(tr("年龄："));
    GradeLabel = new QLabel(tr("分数："));

    Name  =new QLabel;
    Sex = new QLabel;
    Age = new QLabel;
    Grade = new QLabel;

    NameInputButton = new QPushButton(tr("输入姓名"));
    SexInputButton = new QPushButton(tr("选择性别"));
    AgeInputButton = new QPushButton(tr("输入年龄"));
    GradeInputButton = new QPushButton(tr("输入分数"));

    mainLayout  = new QGridLayout(this);
    mainLayout->setSpacing(5);
    mainLayout->addWidget(NameLabel,0,0);
    mainLayout->addWidget(Name,0,1);
    mainLayout->addWidget(NameInputButton,0,2);
    mainLayout->addWidget(SexLabel,1,0);
    mainLayout->addWidget(Sex,1,1);
    mainLayout->addWidget(SexInputButton,1,2);
    mainLayout->addWidget(AgeLabel,2,0);
    mainLayout->addWidget(Age,2,1);
    mainLayout->addWidget(AgeInputButton,2,2);
    mainLayout->addWidget(GradeLabel,3,0);
    mainLayout->addWidget(Grade,3,1);
    mainLayout->addWidget(GradeInputButton,3,2);
    mainLayout->setColumnStretch(1,3);

    /********************连接信号和槽，处理按钮点击和输入*******************************/
    connect(NameInputButton,&QPushButton::clicked,[&](){
       bool ok;
       QString name = QInputDialog::getText(this,tr("输入姓名"),tr("输入姓名："),QLineEdit::Normal,Name->text(),&ok);
       if(ok){
           Name->setText(name);
       }
    });

    connect(SexInputButton,&QPushButton::clicked,[&](){
        QStringList items;
        items << tr("男") <<tr("女");
        bool ok;
        QString sex = QInputDialog::getItem(this,tr("标准条目选择对话框"),tr("选择性别"),items,0,false,&ok);
        if(ok && !items.isEmpty()){
            Sex->setText(sex);
        }
    });

    connect(AgeInputButton,&QPushButton::clicked,[&](){
        bool ok;
        int age = QInputDialog::getInt(this,tr("标准输入对话框"),tr("输入年龄"),Age->text().toInt(&ok),0,100,1,&ok);
        if(ok){
            Age->setText(QString("%1").arg(age));
        }else{
            qDebug()<<"输入年龄出错"<<age;
        }
    });

    connect(GradeInputButton,&QPushButton::clicked,[&](){
        bool ok;
        double grade = QInputDialog::getDouble(this,tr("标准double输入对话框"),tr("输入成绩："),Grade->text().toDouble(&ok),0,100,1,&ok);
        if(ok){
            Grade->setText(QString("%1").arg(grade));
        }
    });
}
