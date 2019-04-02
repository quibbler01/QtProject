#include "progressdialog.h"

ProgressDialog::ProgressDialog(QDialog *parent):QDialog (parent)
{
    FileNum = new QLabel(tr("文件数目："));
    FileNumberLineEdit = new QLineEdit;
    ProgressType = new QLabel(tr("显示类型："));
    chooseProgressType = new QComboBox;
    chooseProgressType->addItem(tr("progressBar"));
    chooseProgressType->addItem(tr("progressDialog"));
    progressBar = new QProgressBar;
    startButton = new QPushButton(tr("开始"));
    mainLayout = new QGridLayout(this);
    mainLayout->addWidget(FileNum,0,0);
    mainLayout->addWidget(FileNumberLineEdit,0,1);
    mainLayout->addWidget(ProgressType,1,0);
    mainLayout->addWidget(chooseProgressType,1,1);
    mainLayout->addWidget(progressBar,2,0,1,2);
    mainLayout->addWidget(startButton,3,1,1,1);
    mainLayout->setMargin(15);
    mainLayout->setSpacing(10);
    connect(startButton,&QPushButton::clicked,[&](){
        bool ok;
        int num = FileNumberLineEdit->text().toInt(&ok);
        if(chooseProgressType->currentIndex()==0){
            progressBar->setRange(0,num);
            for(int i = 0;i<num+1;++i){
                progressBar->setValue(i);
            }
        }else if(chooseProgressType->currentIndex()==1){
            QProgressDialog *progressDialog = new QProgressDialog(this);
            QFont font("ZYSong18030",12);
            progressDialog->setFont(font);
            progressDialog->setWindowModality(Qt::WindowModal);
            progressDialog->setMinimumDuration(5);
            progressDialog->setWindowTitle(tr("请稍等..."));
            progressDialog->setCancelButtonText(tr("取消"));
            progressDialog->setRange(0,num);
            for(int i = 0;i<num+1;++i){
                progressDialog->setValue(i);
                if(progressDialog->wasCanceled()){
                    return ;
                }
            }

        }
    });

}
