#ifndef MYHTTP_H
#define MYHTTP_H

#include <QMainWindow>
#include <QtNetwork>

class QNetworkReply;
class QNetworkAccessManager;

namespace Ui {
class myHTTP;
}

class myHTTP : public QMainWindow
{
    Q_OBJECT

public:
    explicit myHTTP(QWidget *parent = nullptr);
    ~myHTTP();
    void startRequest(QUrl url);

private:
    Ui::myHTTP *ui;
    QNetworkAccessManager *manager;
    QNetworkReply *reply;
    QUrl url;
    QFile *file;

private slots:
    void replyFinished(QNetworkReply*);
    void httpFinished();
    void httpReadyRead();
    void updateDataReadProgress(qint64,qint64);
    void on_pushButton_clicked();
};

#endif // MYHTTP_H
