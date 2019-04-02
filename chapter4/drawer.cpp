#include "drawer.h"

Drawer::Drawer(QWidget *parent,Qt::WindowFlags f):QToolBox(parent,f)
{
    this->setWindowTitle(tr("QQ"));

    toolButton1_1 = new QToolButton;
    toolButton1_1->setText(tr("张三"));
    toolButton1_1->setIcon(QPixmap(":/img/1.png"));
    toolButton1_1->setIconSize(QPixmap(":/img/1.png").size());
    toolButton1_1->setAutoRaise(true);
    toolButton1_1->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);

    toolButton1_2 = new QToolButton;
    toolButton1_2->setText(tr("王五"));
    toolButton1_2->setIcon(QPixmap(":/img/2.png"));
    toolButton1_2->setIconSize(QPixmap(":/img/2.png").size());
    toolButton1_2->setAutoRaise(true);
    toolButton1_2->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);

    toolButton1_3 = new QToolButton;
    toolButton1_3->setText(tr("赵四"));
    toolButton1_3->setIcon(QPixmap(":/img/3.png"));
    toolButton1_3->setIconSize(QPixmap(":/img/3.png").size());
    toolButton1_3->setAutoRaise(true);
    toolButton1_3->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);

    toolButton1_4 = new QToolButton;
    toolButton1_4->setText(tr("万二"));
    toolButton1_4->setIcon(QPixmap(":/img/4.png"));
    toolButton1_4->setIconSize(QPixmap(":/img/4.png").size());
    toolButton1_4->setAutoRaise(true);
    toolButton1_4->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);

    toolButton2_5 = new QToolButton;
    toolButton2_5->setText(tr("孙子"));
    toolButton2_5->setIcon(QPixmap(":/img/5.png"));
    toolButton2_5->setIconSize(QPixmap(":/img/5.png").size());
    toolButton2_5->setAutoRaise(true);
    toolButton2_5->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);

    toolButton2_6 = new QToolButton;
    toolButton2_6->setText(tr("孔子"));
    toolButton2_6->setIcon(QPixmap(":/img/6.png"));
    toolButton2_6->setIconSize(QPixmap(":/img/6.png").size());
    toolButton2_6->setAutoRaise(true);
    toolButton2_6->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);

    toolButton2_7 = new QToolButton;
    toolButton2_7->setText(tr("老子"));
    toolButton2_7->setIcon(QPixmap(":/img/7.png"));
    toolButton2_7->setIconSize(QPixmap(":/img/7.png").size());
    toolButton2_7->setAutoRaise(true);
    toolButton2_7->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);

    toolButton2_8 = new QToolButton;
    toolButton2_8->setText(tr("墨子"));
    toolButton2_8->setIcon(QPixmap(":/img/8.png"));
    toolButton2_8->setIconSize(QPixmap(":/img/8.png").size());
    toolButton2_8->setAutoRaise(true);
    toolButton2_8->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);

    toolButton2_9 = new QToolButton;
    toolButton2_9->setText(tr("荀子"));
    toolButton2_9->setIcon(QPixmap(":/img/9.png"));
    toolButton2_9->setIconSize(QPixmap(":/img/9.png").size());
    toolButton2_9->setAutoRaise(true);
    toolButton2_9->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);

    QGroupBox *groupBox1 = new QGroupBox;
    QVBoxLayout *layout1 = new QVBoxLayout(groupBox1);
    layout1->setMargin(10);
    layout1->setAlignment(Qt::AlignHCenter);
    //add all too button to graoup box
    layout1->addWidget(toolButton1_1);
    layout1->addWidget(toolButton1_2);
    layout1->addWidget(toolButton1_3);
    layout1->addWidget(toolButton1_4);
    layout1->addStretch();//插入占位符

    QGroupBox *groupBox2 = new QGroupBox;
    QVBoxLayout *layout2 = new QVBoxLayout(groupBox2);
    layout2->setMargin(10);
    layout2->setAlignment(Qt::AlignHCenter);
    layout2->addWidget(toolButton2_5);
    layout2->addWidget(toolButton2_6);
    layout2->addWidget(toolButton2_7);
    layout2->addWidget(toolButton2_8);
    layout2->addWidget(toolButton2_9);
    /**************************Add Layout to ToolBox************************************/
    this->addItem((QWidget*)groupBox1,tr("好友"));
    this->addItem((QWidget*)groupBox2,tr("朋友"));

}
