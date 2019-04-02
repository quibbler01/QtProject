#include "windowwithspliter.h"

WindowWithSpliter::WindowWithSpliter(QWidget *parent) : QWidget(parent)
{
    this->resize(600,400);
    this->setFont(QFont("ZYSong18030",12));
    QSplitter *splitterMain = new QSplitter(Qt::Horizontal,this);
    QTextEdit *textLeft = new QTextEdit(QObject::tr("Left Widget"),splitterMain);
    textLeft->setAlignment(Qt::AlignCenter);

    QSplitter *splitterRight = new QSplitter(Qt::Vertical,splitterMain);
    splitterRight->setOpaqueResize(false);
    QTextEdit *textUp = new QTextEdit(QObject::tr("Top Widget"),splitterRight);
    textUp->setAlignment(Qt::AlignCenter);

    QTextEdit *textBottom = new QTextEdit(QObject::tr(("Bottom Widget")),splitterRight);
    textBottom->setAlignment(Qt::AlignCenter);
    splitterMain->setStretchFactor(1,1);
    splitterMain->setWindowTitle(QObject::tr("Splitter"));
    //splitterMain->show();


}
