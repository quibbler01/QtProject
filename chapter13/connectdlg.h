#ifndef CONNECTDLG_H
#define CONNECTDLG_H

#include <QDialog>
#include <QSqlError>
#include <QSql>
#include <QSqlDriver>
#include <QSqlDatabase>
#include <QMessageBox>
#include <QDebug>
#include <QSqlQuery>

namespace Ui {
class ConnectDlg;
}

class ConnectDlg : public QDialog
{
    Q_OBJECT

public:
    explicit ConnectDlg(QWidget *parent = nullptr);
    ~ConnectDlg();
    QString driverName() const;
    QString databaseName() const;
    QString userName() const;
    QString password() const;
    QString hostName() const;
    int port() const;
    QSqlError addConnection(const QString &driver,const QString &dbName,const QString &host,const QString &user,
                            const QString &password,int port = -1);
    void createDB();
    void addSqliteConnection();


private slots:
    void on_okButton_clicked();
    void on_cancleButton_clicked();
    void driverChanged(const QString &dirverType);

private:
    Ui::ConnectDlg *ui;
};

#endif // CONNECTDLG_H
