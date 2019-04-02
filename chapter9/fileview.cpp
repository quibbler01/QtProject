#include "fileview.h"

FileView::FileView(QWidget *parent,Qt::WindowFlags f) : QDialog(parent,f)
{
    this->setWindowTitle(tr("File View"));
    fileLineEdit  = new QLineEdit(tr("/"));
    fileListWidget = new QListWidget;
    mainLayout = new QVBoxLayout(this);
    mainLayout->addWidget(fileLineEdit);
    mainLayout->addWidget(fileListWidget);
    connect(fileLineEdit,SIGNAL(returnPressed()),this,SLOT(slotShow()));
    connect(fileListWidget,SIGNAL(itemDoubleClicked(QListWidgetItem*)),this,SLOT(slotDirShow(QListWidgetItem*)));
    QString root = "/";
    QDir rootDir(root);
    QStringList string;
    string<<"*";
    QFileInfoList list = rootDir.entryInfoList(string);
    showFileInfoList(list);
}

FileView::~FileView()
{

}

void FileView::showFileInfoList(QFileInfoList list)
{
    fileListWidget->clear();
    for(int i = 0;i<list.count();++i){
        QFileInfo tmpFileInfo = list.at(i);
        if(tmpFileInfo.isDir()){
            QIcon icon(":/icon/inode_directory_256px_541987_easyicon.net.png");
            QString fileName = tmpFileInfo.fileName();
            QListWidgetItem *tmp = new QListWidgetItem(icon,fileName);
            fileListWidget->addItem(tmp);
        }else if(tmpFileInfo.isFile()){
            QIcon icon(":/icon/files_and_folders_518.0176px_1232399_easyicon.net.png");
            QString fileName = tmpFileInfo.fileName();
            QListWidgetItem *tmp = new QListWidgetItem(icon,fileName);
            fileListWidget->addItem(tmp);
        }
    }
}

void FileView::slotShow(QDir dir)
{
    QStringList string;
    string <<"*";
    QFileInfoList list = dir.entryInfoList(string,QDir::AllEntries,QDir::DirsFirst);
    showFileInfoList(list);
}

void FileView::slotShow()
{
    QString str = fileLineEdit->text();
    QDir dir(str);
    slotShow(dir);
}

void FileView::slotDirShow(QListWidgetItem *item)
{
    QString str = item->text();
    QDir dir;
    dir.setPath(fileLineEdit->text());
    dir.cd(str);
    fileLineEdit->setText(dir.absolutePath());
    slotShow(dir);
}
