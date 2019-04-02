#ifndef CONTACT_H
#define CONTACT_H

#include <QWidget>
#include <QLabel>
#include <QLineEdit>
#include <QCheckBox>
#include <QGridLayout>

class Contact : public QWidget
{
    Q_OBJECT
public:
    explicit Contact(QWidget *parent = nullptr);
    ~Contact();
signals:

public slots:

private:
    QLabel *EmailLabel;
    QLineEdit *EmailLineEdit;
    QLabel *AddressLabel;
    QLineEdit *AddressLineEdit;
    QLabel *ZooCode;
    QLineEdit *ZooCodeLineEdit;

    QLabel *MobileLabel;
    QLineEdit *MobileLineEdit;
    QCheckBox *CheckMessageCheckBox;

    QLabel *OfficeTellLabel;
    QLineEdit *OfficeTellLineEdit;

    QGridLayout *MainLayout;
};

#endif // CONTACT_H
