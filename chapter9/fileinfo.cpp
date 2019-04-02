#include "fileinfo.h"

FileInfo::FileInfo(QWidget *parent) : QDialog(parent)
{
    fileNameLabel = new QLabel(tr("文件名:"));
    fileNameLineEdit = new QLineEdit;
    fileBtn = new QPushButton(tr("选择文件"));
    sizeLabel = new QLabel(tr("文件大小:"));
    sizeLineEdit = new QLineEdit;
    createTimeLabel = new QLabel(tr("创建时间:"));
    createLineEdit = new QLineEdit;
    lastModifyTimeLabel = new QLabel(tr("最后修改时间:"));
    lastModifyTimeLineEdit = new QLineEdit;
    lastVisitTimeLabel = new QLabel(tr("最后访问时间:"));
    lasVistiTimeLineEdit = new QLineEdit;
    propertyLabel = new QLabel(tr("属性:"));
    isDirCheckBox = new QCheckBox(tr("目录"));
    isFileCheckBox = new QCheckBox(tr("文件"));
    isSymbolLinkCheckBox = new QCheckBox(tr("链接"));
    isHiddenCheckBox = new QCheckBox(tr("隐藏"));
    isReadableCheckBox = new QCheckBox(tr("读"));
    isWriteableCheckBox = new QCheckBox(tr("写"));
    isExecutableCheckBox =  new QCheckBox(tr("执行"));
    getBtn = new QPushButton(tr("获取文件信息"));

    QGridLayout *gridLayout = new QGridLayout;
    gridLayout->addWidget(fileNameLabel,0,0);
    gridLayout->addWidget(fileNameLineEdit,0,1);
    gridLayout->addWidget(fileBtn,0,2);

    gridLayout->addWidget(sizeLabel,1,0);
    gridLayout->addWidget(sizeLineEdit,1,1,1,2);
    gridLayout->addWidget(createTimeLabel,2,0);
    gridLayout->addWidget(createLineEdit,2,1,1,2);
    gridLayout->addWidget(lastModifyTimeLabel,3,0);
    gridLayout->addWidget(lastModifyTimeLineEdit,3,1,1,2);
    gridLayout->addWidget(lastVisitTimeLabel,4,0);
    gridLayout->addWidget(lasVistiTimeLineEdit,4,1,1,2);
    QHBoxLayout *layout2 = new QHBoxLayout;
    layout2->addWidget(propertyLabel);
    layout2->addStretch();
    QHBoxLayout *layout3 = new QHBoxLayout;
    layout3->addWidget(isDirCheckBox);
    layout3->addWidget(isFileCheckBox);
    layout3->addWidget(isSymbolLinkCheckBox);
    layout3->addWidget(isHiddenCheckBox);
    layout3->addWidget(isReadableCheckBox);
    layout3->addWidget(isWriteableCheckBox);
    layout3->addWidget(isExecutableCheckBox);
    QHBoxLayout *layout4 = new QHBoxLayout;
    layout4->addWidget(getBtn);
    QVBoxLayout *mainLayout = new QVBoxLayout(this);

    mainLayout->addLayout(gridLayout);
    mainLayout->addLayout(layout2);
    mainLayout->addLayout(layout3);
    mainLayout->addLayout(layout4);

    connect(fileBtn,SIGNAL(clicked()),this,SLOT(slotFile()));
    connect(getBtn,SIGNAL(clicked()),this,SLOT(slotGet()));




}

FileInfo::~FileInfo()
{

}

void FileInfo::slotFile()
{
    QString fileName = QFileDialog::getOpenFileName(this,tr("打开文件"),"/","files(*)");
    this->fileNameLineEdit->setText(fileName);
    //reset
    sizeLineEdit->setText("");
    createLineEdit->setText("");
    lastModifyTimeLineEdit->setText("");
    lasVistiTimeLineEdit->setText("");
    isDirCheckBox->setCheckState(Qt::Unchecked);
    isFileCheckBox->setCheckState(Qt::Unchecked);
    isSymbolLinkCheckBox->setCheckState(Qt::Unchecked);
    isHiddenCheckBox->setCheckState(Qt::Unchecked);
    isReadableCheckBox->setCheckState(Qt::Unchecked);
    isWriteableCheckBox->setCheckState(Qt::Unchecked);
    isExecutableCheckBox->setCheckState(Qt::Unchecked);
}

void FileInfo::slotGet()
{
    QString file = fileNameLineEdit->text();
    QFileInfo info(file);
    qint64 size = info.size();
    QDateTime created = info.created();
    QDateTime lastMidify = info.lastModified();
    QDateTime lastVisited = info.lastRead();
    bool isDir = info.isDir();
    bool isFile = info.isFile();
    bool isSymbol = info.isSymLink();
    bool isHidden = info.isHidden();
    bool isReadable = info.isReadable();
    bool isWriteable = info.isWritable();
    bool isExecute = info.isExecutable();
    //
    sizeLineEdit->setText(QString::number(size));
    createLineEdit->setText(created.toString());
    lastModifyTimeLineEdit->setText(lastMidify.toString());
    lasVistiTimeLineEdit->setText(lastVisited.toString());

    isDirCheckBox->setCheckState(isDir?Qt::Checked:Qt::Unchecked);
    isFileCheckBox->setCheckState(isFile?Qt::Checked:Qt::Unchecked);
    isSymbolLinkCheckBox->setCheckState(isSymbol?Qt::Checked:Qt::Unchecked);
    isHiddenCheckBox->setCheckState(isHidden?Qt::Checked:Qt::Unchecked);
    isReadableCheckBox->setCheckState(isReadable?Qt::Checked:Qt::Unchecked);
    isWriteableCheckBox->setCheckState(isWriteable?Qt::Checked:Qt::Unchecked);
    isExecutableCheckBox->setCheckState(isExecute?Qt::Checked:Qt::Unchecked);
}
