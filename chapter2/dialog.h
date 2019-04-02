#ifndef DIALOG_H
#define DIALOG_H

#include <QWidget>
#include <QDialog>
namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QDialog *parent = nullptr);
    ~Dialog();

private slots:
    void on_lineEdit_textChanged(const QString &arg1);

private:
    Ui::Dialog *ui;
};

#endif // DIALOG_H
