#ifndef SWITCHLANGUAGE_H
#define SWITCHLANGUAGE_H

#include <QWidget>
#include <QComboBox>
#include <QLabel>
#include <QVBoxLayout>
#include <QTranslator>
#include <QApplication>
#include <QDebug>


class SwitchLanguage : public QWidget
{
    Q_OBJECT
public:
    explicit SwitchLanguage(QWidget *parent = nullptr);
    ~SwitchLanguage();

signals:

private:
    void createScreent();
    void changeTr(const QString langCode);
    void refreshLabel();
    QComboBox *selectLanguange;
    QLabel *label;

public slots:
    void changeLanguage(int index);
};

#endif // SWITCHLANGUAGE_H
