#ifndef EDITDIALOG_H
#define EDITDIALOG_H

#include <QDialog>
#include <QtGui>
#include <QtXml>
#include <QtSql>
#include <QDialogButtonBox>
#include <QMessageBox>
#include "ui_connectdlg.h"

class EditDialog : public QDialog
{
    Q_OBJECT
public:
    //explicit EditDialog(QObject *parent = nullptr);
    EditDialog(QSqlRelationalTableModel *cars,QSqlTableModel *factory,QDomDocument details,QFile *output,QWidget *parent = nullptr);

private:
    int addNewCar(const QString &name,int factoryID);
    int addNewFactory(const QString &factory,const QString &address);
    void addAttribs(int carID,QStringList attribs);
    QDialogButtonBox *createButtons();
    QGroupBox *createInputWidgets();
    int findFactoryID(const QString &factory);
    int generateCarID();
    int generateFactoryID();

    QSqlRelationalTableModel *carModel;
    QSqlTableModel *factoryModel;
    QDomDocument carDetails;
    QFile *outputFile;
    QLineEdit *factoryEditor;
    QLineEdit *addressEditor;
    QLineEdit *carEditor;
    QSpinBox *yearSpinBox;
    QLineEdit *attribEditor;
signals:

public slots:
    void revert();
    void submit();
};

#endif // EDITDIALOG_H
