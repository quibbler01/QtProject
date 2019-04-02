#ifndef DETAIL_H
#define DETAIL_H

#include <QWidget>
#include <QLabel>
#include <QLineEdit>
#include <QTextEdit>
#include<QComboBox>
#include <QGridLayout>

class Detail:public QWidget
{
    Q_OBJECT

public:
    Detail(QWidget *parent = nullptr);
private:
    QLabel *NationAddressLabel;
    QComboBox *ChooseNationAddress;
    QLabel *ProvienceLabel;
    QComboBox *ProvienceComboBox;
    QLabel *CityLabel;
    QLineEdit *CityLineEdit;
    QLabel *PersonalDetailLabel;
    QTextEdit *PersonalDetailTextEdit;
    QGridLayout *MainLayout;
};

#endif // DETAIL_H
