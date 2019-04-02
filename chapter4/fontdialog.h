#ifndef FONTDIALOG_H
#define FONTDIALOG_H

#include <QDialog>
#include <QPushButton>
#include <QFont>
#include <QFontDialog>
#include <QLineEdit>
#include <QGridLayout>

class FontDialog:public QDialog
{
public:
    FontDialog(QDialog *parent = nullptr);
private:
    QPushButton *chooseFontButton;
    QLineEdit *choosedFont;
    QGridLayout *mainLayout;
};

#endif // FONTDIALOG_H
