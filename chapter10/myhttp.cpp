#include "myhttp.h"
#include "ui_myhttp.h"

myHTTP::myHTTP(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::myHTTP)
{
    this->setWindowTitle(tr("http://www.baidu.com"));
    ui->setupUi(this);
    ui->progressBar->hide();
    manager = new QNetworkAccessManager(this);
    connect(manager,SIGNAL(finished(QNetworkReply*)),this,SLOT(replyFinished(QNetworkReply*)));
    //manager->get(QNetworkRequest(QUrl("http://www.baidu.com")));
}

myHTTP::~myHTTP()
{
    delete ui;
}

void myHTTP::startRequest(QUrl url)
{
    reply = manager->get(QNetworkRequest(url));
    connect(reply,SIGNAL(readyRead()),this,SLOT(httpReadyRead()));
    connect(reply,SIGNAL(downloadProgress(qint64,qint64)),this,SLOT(updateDataReadProgress(qint64,qint64)));
    connect(reply,SIGNAL(finished()),this,SLOT(httpFinished()));
}

void myHTTP::replyFinished(QNetworkReply *reply)
{
    QString all = reply->readAll();
    ui->textBrowser->setText(all);
    reply->deleteLater();
}

void myHTTP::httpFinished()
{
    ui->progressBar->hide();
    file->flush();
    file->close();
    reply->deleteLater();
    reply = nullptr;
    delete  file;
    file = nullptr;
}

void myHTTP::httpReadyRead()
{
    if(file)
        file->write(reply->readAll());
}

void myHTTP::updateDataReadProgress(qint64 bytesRead, qint64 totalBytes)
{
    ui->progressBar->setMaximum(totalBytes);
    ui->progressBar->setValue(bytesRead);
}

void myHTTP::on_pushButton_clicked()
{
    url = ui->lineEdit->text();
    QFileInfo info(url.path());
    QString fileName(info.fileName());
    file = new QFile(fileName);
    if(!file->open(QIODevice::WriteOnly)){
        qDebug()<<"File OPen Error";
        delete file;
        file = nullptr;
        return;
    }
    startRequest(url);
    ui->progressBar->setValue(0);
    ui->progressBar->show();
}
