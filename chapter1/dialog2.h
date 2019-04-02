#ifndef DIALOG2_H
#define DIALOG2_H
#include <QDialog>
#include <QLabel>
#include <QPushButton>
#include <QLineEdit>
#include <QGridLayout>
const static double PI = 3.1416;
class Dialog2 : public QDialog
{
    Q_OBJECT
public:
    Dialog2(QWidget*parent=nullptr);
    ~Dialog2();
private:
    QLabel *rangeLabel,*bLabel;
    QLineEdit *rangeLineEdit;
    QPushButton *calcButton;

private slots:
    void showArea();
};

#endif // DIALOG2_H
