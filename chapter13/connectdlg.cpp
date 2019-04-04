#include "connectdlg.h"
#include "ui_connectdlg.h"

ConnectDlg::ConnectDlg(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ConnectDlg)
{
    ui->setupUi(this);
    QStringList drivers = QSqlDatabase::drivers();
    ui->comboDriver->addItems(drivers);
    connect(ui->comboDriver,SIGNAL(currentIndexChanged(const QString &)),this,SLOT(driverChanged(const QString&)));
    ui->statusLabel->setText(tr("准备连接数据库！"));
    //qDebug()<<ui->comboDriver->currentData(ui->comboDriver->currentIndex()).toString();
    driverChanged(ui->comboDriver->currentText());
}

ConnectDlg::~ConnectDlg()
{
    delete ui;
}

QString ConnectDlg::driverName() const
{
    return ui->comboDriver->currentText();
}

QString ConnectDlg::databaseName() const
{
    return ui->editDatabase->text();
}

QString ConnectDlg::userName() const
{
    return ui->editUsername->text();
}

QString ConnectDlg::password() const
{
    return ui->editPassword->text();
}

QString ConnectDlg::hostName() const
{
    return ui->editHostname->text();
}

int ConnectDlg::port() const
{
    return ui->editSpinBox->value();
}

QSqlError ConnectDlg::addConnection(const QString &driver, const QString &dbName, const QString &host, const QString &user, const QString &password, int port)
{
    QSqlError err;
    QSqlDatabase db = QSqlDatabase::addDatabase(driver);
    db.setDatabaseName(dbName);
    db.setHostName(host);
    db.setPort(port);
    if(!db.open(userName(),password)){
        err = db.lastError();
    }
    return err;
}

void ConnectDlg::createDB()
{
    QSqlQuery query;
    //create Factory table
    query.exec("create table factory (id int primary key,"
               "manufactory varchar(40),"
               "address varchar(40))");
    query.exec(QObject::tr("insert into factory values(1,'一汽大众','长春')"));
    query.exec(QObject::tr("insert into factory values(2,'二汽神龙','武汉')"));
    query.exec(QObject::tr("insert into factory values(3,'上海大众','上海')"));
    //create Car table
    query.exec("create table cars(carid int primary key,"
               "name varchar(50),factoryid int,year int,foreign key(factoryid) references factory)");
    query.exec(QObject::tr("insert into cars values(1,'奥迪A6',1,2005)"));
    query.exec(QObject::tr("insert into cars values(2,'捷达',1,1993)"));
    query.exec(QObject::tr("insert into cars values(3,'宝来',1,2000)"));
    query.exec(QObject::tr("insert into cars values(4,'毕加索',2,1999)"));
    query.exec(QObject::tr("insert into cars values(5,'富康',2,2004)"));
    query.exec(QObject::tr("insert into cars values(6,'标志307',2,2001)"));
    query.exec(QObject::tr("insert into cars values(7,'桑塔纳',3,1995)"));
    query.exec(QObject::tr("insert into cars values(8,'帕萨特',3,2000)"));
}

void ConnectDlg::addSqliteConnection()
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("databasefileForSQLite.db");
    if(!db.open()){
        ui->statusLabel->setText(db.lastError().text());
        return;
    }
    ui->statusLabel->setText(tr("创建SQLite本地数据库成功!"));
}

void ConnectDlg::on_okButton_clicked()
{
    if(ui->comboDriver->currentText().isEmpty()){
        ui->statusLabel->setText(tr("请选择一个数据库驱动!"));
        ui->comboDriver->setFocus();
    }else if(ui->comboDriver->currentText()=="QSQLITE"){
        addSqliteConnection();
        createDB();
        accept();
    }else{
        QSqlError err = addConnection(driverName(),databaseName(),hostName(),userName(),password(),port());
        if(err.type()!=QSqlError::NoError){
            ui->statusLabel->setText(err.text());
        }else{
            ui->statusLabel->setText(tr("连接数据库成功!"));
        }
        accept();
    }
}

void ConnectDlg::on_cancleButton_clicked()
{
    this->close();
}

void ConnectDlg::driverChanged(const QString &driverType)
{
    if(driverType=="QSQLITE"){
        ui->editDatabase->setEnabled(false);
        ui->editHostname->setEnabled(false);
        ui->editUsername->setEnabled(false);
        ui->editPassword->setEnabled(false);
        ui->editHostname->setEnabled(false);
        ui->editSpinBox->setEnabled(false);
    }else{
        ui->editDatabase->setEnabled(true);
        ui->editHostname->setEnabled(true);
        ui->editUsername->setEnabled(true);
        ui->editPassword->setEnabled(true);
        ui->editHostname->setEnabled(true);
        ui->editSpinBox->setEnabled(true);
    }
}
