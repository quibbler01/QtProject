#include "splashscreen.h"

SplashScreen::SplashScreen(QWidget *parent) : QMainWindow(parent)
{
    this->setWindowTitle(tr("Splash Example"));
    QTextEdit *edit = new QTextEdit;
    edit->setText("Splash Example");
    this->setCentralWidget(edit);
    this->resize(600,450);
    Sleep(1000);
}
