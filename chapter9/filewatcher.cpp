#include "filewatcher.h"
#include <QVBoxLayout>
#include <QDir>
#include <QMessageBox>
#include <QApplication>
#include <QStringList>
#include <QString>

FileWatcher::FileWatcher(QWidget *parent) : QWidget(parent)
{
    QStringList args = qApp->arguments();
    QString path;
    if(args.count()>1){
        path = args[1];
    }else{
        path = QDir::currentPath();
    }
    printf("%s",path.data());
    pathLabel = new QLabel;
    pathLabel->setText(tr("监视的目录:")+path);
    QVBoxLayout *mainLayout = new QVBoxLayout(this);
    mainLayout->addWidget(pathLabel);
    //fsWatcher = QFileSystemWatcher();
    fsWatcher.addPath(path);
    connect(&fsWatcher,SIGNAL(directoryChanged(const QString)),this,SLOT(directoryChanged(QString)));

}

FileWatcher::~FileWatcher()
{

}

void FileWatcher::directoryChanged(QString path)
{
    QMessageBox::information(nullptr,tr("目录")+path+"变化",path);
}
