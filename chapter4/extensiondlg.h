#ifndef EXTENSIONDLG_H
#define EXTENSIONDLG_H

#include <QDialog>
#include <QVBoxLayout>
#include <QPushButton>
#include <QLabel>
#include <QLineEdit>
#include <QComboBox>
#include <QDialogButtonBox>
#include <QHBoxLayout>

class ExtensionDlg : public QDialog
{
    Q_OBJECT
public:
    ExtensionDlg(QWidget *parent = nullptr);
    ~ExtensionDlg();

private slots:
    void showDetailInfo();
private :
    void createBaseInfo();
    void createDetailInfo();
    QWidget *baseWidget;
    QWidget *detailWidget;

};

#endif // EXTENSIONDLG_H
