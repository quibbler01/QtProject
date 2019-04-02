#ifndef LAYOUTWINDOW_H
#define LAYOUTWINDOW_H

#include <QDialog>
#include <QPushButton>
#include <QLabel>
#include <QLineEdit>
#include <QComboBox>
#include <QGridLayout>
#include <QTextEdit>
#include <QtDebug>
#include <QFileDialog>
#include <QDebug>


class LayoutWindow : public QDialog
{
    Q_OBJECT
public:
    explicit LayoutWindow(QDialog *parent = nullptr);

signals:

public slots:

private:
    QLabel *UserNameLabel;
    QLabel *NameLabel;
    QLabel *SexLabel;
    QLabel *DepartmentLabel;
    QLabel *AgeLabel;
    QLabel *OtherLabel;

    QLineEdit *UserNameLineEdit;
    QLineEdit *NameLineEdit;
    QComboBox *SexComboBox;

    QTextEdit *DepartmentTextEdit;
    QLineEdit *AgeLineEdit;
    QGridLayout *LeftLayout;

    QLabel *HeadLabel;
    QLabel *HeadIconLael;
    QPushButton *UpdateHeadButton;
    QHBoxLayout * TopRightLayout;
    QLabel *IntroductionLabel;
    QTextEdit *IntroductionTextEdit;
    QVBoxLayout *RightLayout;

    QPushButton *OkButton;
    QPushButton *CancelButton;
    QHBoxLayout *ButtonLayout;

};

#endif // LAYOUTWINDOW_H
