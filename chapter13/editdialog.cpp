#include "editdialog.h"

//EditDialog::EditDialog(QObject *parent) : QDialog(parent)
//{

//}
//定义全局变量
int uniqueCarID;
int uniqueFactoryID;

EditDialog::EditDialog(QSqlRelationalTableModel *cars, QSqlTableModel *factory, QDomDocument details, QFile *output, QWidget *parent)
{
    carModel = cars;
    factoryModel = factory;
    carDetails = details;
    outputFile = output;
    QGroupBox *inputWidgetBox = createInputWidgets();
    QDialogButtonBox *buttonBox = createButtons();
    QVBoxLayout *layout = new QVBoxLayout;
    layout->addWidget(inputWidgetBox);
    layout->addWidget(buttonBox);
    this->setLayout(layout);
    this->setWindowTitle(tr("添加产品"));
}

int EditDialog::addNewCar(const QString &name, int factoryID)
{
    int id = generateCarID();
    QSqlRecord record;
    QSqlField f1("carid",QVariant::Int);
    QSqlField f2("name",QVariant::String);
    QSqlField f3("factoryid",QVariant::Int);
    QSqlField f4("year",QVariant::Int);
    f1.setValue(QVariant(id));
    f2.setValue(QVariant(name));
    f3.setValue(QVariant(factoryID));
    f4.setValue(QVariant(yearSpinBox->value()));
    record.append(f1);
    record.append(f2);
    record.append(f3);
    record.append(f4);
    carModel->insertRecord(-1,record);
    return id;
}

int EditDialog::addNewFactory(const QString &factory, const QString &address)
{
    QSqlRecord record;
    int id = generateFactoryID();
    QSqlField f1("id",QVariant::Int);
    QSqlField f2("manufactory",QVariant::String);
    QSqlField f3("address",QVariant::String);
    f1.setValue(QVariant(id));
    f2.setValue(QVariant(factory));
    f3.setValue(QVariant(address));
    record.append(f1);
    record.append(f2);
    record.append(f3);
    factoryModel->insertRecord(-1,record);
    return id;
}

void EditDialog::addAttribs(int carID, QStringList attribs)
{
    QDomElement carNode = carDetails.createElement("car");
    carNode.setAttribute("id",carID);
    for(int i = 0;i<attribs.count();++i){
        QString attribNumber = QString::number(i+1);
        if(i<10){
            attribNumber.prepend("0");
        }
        QDomText textNode = carDetails.createTextNode(attribs.at(i));
        QDomElement attribNode = carDetails.createElement("attrib");
        attribNode.setAttribute("number",attribNumber);
        attribNode.appendChild(textNode);
        carNode.appendChild(attribNode);
    }
    QDomNodeList archive = carDetails.elementsByTagName("archive");
    archive.item(0).appendChild(carNode);
    if(!outputFile->open(QIODevice::ReadOnly)){
        return;
    }else{
        QTextStream stream(outputFile);
        archive.item(0).save(stream,4);
        outputFile->close();
    }

}

QDialogButtonBox *EditDialog::createButtons()
{
    QPushButton *closeBtn = new QPushButton(tr("关闭"));
    QPushButton *revertButton = new QPushButton(tr("撤销"));
    QPushButton *submitButton = new QPushButton(tr("提交"));
    closeBtn->setDefault(true);
    connect(closeBtn,SIGNAL(clicked()),this,SLOT(close()));
    connect(revertButton,SIGNAL(clicked()),this,SLOT(rever()));
    connect(submitButton,SIGNAL(clicked()),this,SLOT(submit()));
    QDialogButtonBox *buttonBox = new QDialogButtonBox;
    buttonBox->addButton(submitButton,QDialogButtonBox::ResetRole);
    buttonBox->addButton(revertButton,QDialogButtonBox::ResetRole);
    buttonBox->addButton(closeBtn,QDialogButtonBox::RejectRole);
    return buttonBox;
}

QGroupBox *EditDialog::createInputWidgets()
{
    QGroupBox *box = new QGroupBox(tr("添加产品"));
    QLabel *factoryLabel = new QLabel(tr("制造商"));
    QLabel *addressLabel =   new QLabel(tr("厂址"));
    QLabel *carLabel = new QLabel(tr("品牌"));
    QLabel *yearLabel = new QLabel(tr("上市时间"));
    QLabel *atribLabel = new QLabel(tr("产品属性（由封号;隔开）"));
    factoryEditor = new QLineEdit;
    carEditor = new QLineEdit;
    addressEditor = new QLineEdit;
    yearSpinBox = new QSpinBox;
    yearSpinBox->setMinimum(1900);
    yearSpinBox->setMaximum(QDate::currentDate().year());
    yearSpinBox->setValue(yearSpinBox->maximum());
    yearSpinBox->setReadOnly(false);
    attribEditor = new QLineEdit;
    QGridLayout *layout = new QGridLayout;
    layout->addWidget(factoryLabel,0,0);
    layout->addWidget(factoryEditor,0,1);
    layout->addWidget(addressLabel,1,0);
    layout->addWidget(addressEditor,1,1);
    layout->addWidget(carLabel,2,0);
    layout->addWidget(carEditor,2,1);
    layout->addWidget(yearLabel,3,0);
    layout->addWidget(yearSpinBox,3,1);
    layout->addWidget(atribLabel,4,0,1,2);
    layout->addWidget(attribEditor,5,0,1,2);
    box->setLayout(layout);
    return box;
}

int EditDialog::findFactoryID(const QString &factory)
{
    int row = 0;
    while(row<factoryModel->rowCount()){
        QSqlRecord record = factoryModel->record(row);
        if(record.value("manufactory")==factory){
            return record.value("id").toInt();
        }else{
            ++row;
        }
    }
    return -1;
}

int EditDialog::generateCarID()
{
    uniqueCarID +=1;
    return uniqueCarID;
}

int EditDialog::generateFactoryID()
{
    uniqueFactoryID +=1;
    return uniqueFactoryID;
}

void EditDialog::revert()
{
    factoryEditor->clear();
    addressEditor->clear();
    carEditor->clear();
    yearSpinBox->setValue(QDate::currentDate().year());
    attribEditor->clear();
}

void EditDialog::submit()
{
    QString factory = factoryEditor->text();
    QString address = addressEditor->text();
    QString name =  carEditor->text();
    if(factory.isEmpty()||address.isEmpty()||name.isEmpty()){
        QString message(tr("请输入厂名，厂址和商品名称!"));
        QMessageBox::information(this,tr("添加商品"),message);
    }else{
        int factoryID = findFactoryID(factory);
        if(factoryID == -1){
            factoryID = addNewFactory(factory,address);
        }
        int carID = addNewCar(name,factoryID);
        QStringList attribs;
        attribs = attribEditor->text().split(";",QString::SkipEmptyParts);
        addAttribs(carID,attribs);
    }
    accept();
}
