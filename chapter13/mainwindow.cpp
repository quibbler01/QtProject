#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "editdialog.h"
extern int uniqueCarID;
extern int uniqueFactoryID;

//MainWindow::MainWindow(QWidget *parent) :
//    QMainWindow(parent),
//    ui(new Ui::MainWindow)
//{
//    //ui->setupUi(this);
//    QGroupBox *factory = createFactoryGroupBox();
//    QGroupBox *cars = createCarGroupBox();
//    QGroupBox *details = createDetailsGroupBox();
//    //
//    QGridLayout *layout = new QGridLayout;
//    layout->addWidget(factory,0,0);
//    layout->addWidget(cars,1,0);
//    layout->addWidget(details,0,1,2,1);
//    layout->setColumnStretch(1,1);
//    layout->setColumnMinimumWidth(0,500);
//    QWidget *widget = new QWidget;
//    widget->setLayout(layout);
//    this->setCentralWidget(widget);
//    createMenuBar();
//    this->resize(850,400);
//    this->setWindowTitle(tr("主从视图"));
//}

MainWindow::MainWindow(const QString &factoryTable, const QString &carTable, QFile *carDetailes, QWidget *parent):QMainWindow (parent)
{
    file =  carDetailes;
    readCarData();
    carModel = new QSqlRelationalTableModel(this);
    carModel->setTable(carTable);
    carModel->setRelation(2,QSqlRelation(factoryTable,"id","manufactory"));
    carModel->select();
    factoryModel = new QSqlTableModel(this);
    factoryModel->setTable(factoryTable);
    factoryModel->select();
    //
    QGroupBox *factory = createFactoryGroupBox();
    QGroupBox *cars = createCarGroupBox();
    QGroupBox *details = createDetailsGroupBox();
    //
    uniqueCarID = carModel->rowCount();
    uniqueFactoryID = factoryModel->rowCount();
    //
    QGridLayout *layout = new QGridLayout;
    layout->addWidget(factory,0,0);
    layout->addWidget(cars,1,0);
    layout->addWidget(details,0,1,2,1);
    layout->setColumnStretch(1,1);
    layout->setColumnMinimumWidth(0,500);
    QWidget *widget = new QWidget;
    widget->setLayout(layout);
    this->setCentralWidget(widget);
    createMenuBar();
    this->resize(850,400);
    this->setWindowTitle(tr("主从视图"));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::addCar()
{
    EditDialog *dialog = new EditDialog(carModel,factoryModel,carData,file,this);
    int accepted = dialog->exec();
    if(accepted==1){
        int lastRow = carModel->rowCount()-1;
        carView->selectRow(lastRow);
        carView->scrollToBottom();
        showCarDetails(carModel->index(lastRow,0));
    }
}

void MainWindow::changeFactory(QModelIndex index)
{
    QSqlRecord record = factoryModel->record(index.row());
    QString factoryID = record.value("id").toString();
    carModel->setFilter("id = '" + factoryID+"'");
    showFactoryProfile(index);
}

void MainWindow::delCar()
{
    QModelIndexList selection = carView->selectionModel()->selectedRows(0);
    if(!selection.empty()){
        QModelIndex idIndex = selection.at(0);
        int id = idIndex.data().toInt();
        QString name = idIndex.sibling(idIndex.row(),1).data().toString();
        QString factory = idIndex.sibling(idIndex.row(),2).data().toString();
        QMessageBox::StandardButton button;
        button = QMessageBox::question(this,tr("删除汽车记录"),QString(tr("确认删除由%1生产的%2吗？").arg(factory).arg(name)),QMessageBox::Yes|QMessageBox::No);
        if(button==QMessageBox::Yes){
            removeCarFromFile(id);
            removeCarFromDatabase(idIndex);
            decreaseCarCount(indexOfFactory(factory));
        }else{
            QMessageBox::information(this,tr("删除汽车记录"),tr("请选择要删除的记录"));
        }

    }

}

void MainWindow::showCarDetails(QModelIndex index)
{
    QSqlRecord record = carModel->record(index.row());
    QString factory = record.value("manufactory").toString();
    QString name = record.value("name").toString();
    QString year = record.value("year").toString();
    QString carID = record.value("carid").toString();
    showFactoryProfile(indexOfFactory(factory));
    titleLabel->setText(tr("品牌：%1（%2）").arg(name).arg(year));
    titleLabel->show();
    QDomNodeList cars = carData.elementsByTagName("car");
    for(int i = 0;i<cars.count();++i){
        QDomNode car = cars.item(i);
        if(car.toElement().attribute("id")==carID){
            getAttribList(car.toElement());
            break;
        }
    }
    if(attributeList->count()==0){
        attributeList->show();
    }

}

void MainWindow::showFactoryProfile(QModelIndex index)
{
    QSqlRecord record = factoryModel->record(index.row());
    QString name =  record.value("manufactory").toString();
    int count = carModel->rowCount();
    profileLabel->setText(tr("汽车制造商:%1产品数量:%2").arg(name).arg(count));
    profileLabel->show();
    titleLabel->hide();
    attributeList->hide();
}

void MainWindow::decreaseCarCount(QModelIndex index)
{
    int row = index.row();
    int count = carModel->rowCount();
    if(count==0){
        factoryModel->removeRow(row);
    }
}

void MainWindow::getAttribList(QDomNode car)
{
    attributeList->clear();
    QDomNodeList attribs = car.childNodes();
    QDomNode node;
    QString attribtNumber;
    for(int j = 0;j<attribs.count();++j){
        node = attribs.item(j);
        attribtNumber = node.toElement().attribute("number");
        QListWidgetItem *item = new QListWidgetItem(attributeList);
        QString showText(attribtNumber+":"+node.toElement().text());
        item->setText(tr("%1").arg(showText));
    }

}

QModelIndex MainWindow::indexOfFactory(const QString &factory)
{
    for(int i  = 0;i<factoryModel->rowCount();++i){
        QSqlRecord record = factoryModel->record(i);
        if(record.value("manufactory")==factory){
            return factoryModel->index(i,1);
        }
    }
    return QModelIndex();
}

void MainWindow::readCarData()
{
    if(!file->open(QIODevice::ReadOnly)){
        return;
    }
    if(!carData.setContent(file)){
        file->close();
        return;
    }
    file->close();
}

void MainWindow::removeCarFromDatabase(QModelIndex index)
{
    carModel->removeRow(index.row());
}

void MainWindow::removeCarFromFile(int id)
{
    QDomNodeList cars = carData.elementsByTagName("car");
    for(int i = 0;i<cars.count();++i){
        QDomNode node = cars.item(i);
        if(node.toElement().attribute("id").toInt()==id){
            carData.elementsByTagName("archive").item(0).removeChild(node);
            break;
        }
    }

}

QGroupBox *MainWindow::createCarGroupBox()
{
    QGroupBox *box = new QGroupBox(tr("汽车"));
    carView = new QTableView;
    carView->setEditTriggers(QAbstractItemView::NoEditTriggers);
    carView->setSortingEnabled(true);
    carView->setSelectionBehavior(QAbstractItemView::SelectRows);
    carView->setSelectionMode(QAbstractItemView::SingleSelection);
    carView->setShowGrid(false);
    carView->verticalHeader()->hide();
    carView->setAlternatingRowColors(true);
    carView->setModel(carModel);
    connect(carView,SIGNAL(clicked(QModelIndex)),this,SLOT(showCarDetails(QModelIndex)));
    connect(carView,SIGNAL(activated(QModelIndex)),this,SLOT(showCarDetails(QModelIndex)));
    QVBoxLayout *layout=  new QVBoxLayout;
    layout->addWidget(carView,0,0);
    box->setLayout(layout);
    return box;
}

QGroupBox *MainWindow::createFactoryGroupBox()
{
    factoryView = new QTableView;
    factoryView->setEditTriggers(QAbstractItemView::NoEditTriggers);
    factoryView->setSortingEnabled(true);
    factoryView->setSelectionMode(QAbstractItemView::SingleSelection);
    factoryView->setShowGrid(false);
    factoryView->setAlternatingRowColors(true);
    factoryView->setModel(factoryModel);
    connect(factoryView,SIGNAL(clicked(QModelIndex)),this,SLOT(changeFactory(QModelIndex)));
    QGroupBox *box = new QGroupBox(tr("汽车制造商"));
    QGridLayout *layout = new QGridLayout;
    layout->addWidget(factoryView,0,0);
    box->setLayout(layout);
    return box;
}

QGroupBox *MainWindow::createDetailsGroupBox()
{
    QGroupBox *box = new QGroupBox(tr("详细"));
    profileLabel = new QLabel(tr(""));
    profileLabel->setWordWrap(true);
    profileLabel->setAlignment(Qt::AlignBottom);
    titleLabel = new QLabel(tr(""));
    titleLabel->setWordWrap(true);
    titleLabel->setAlignment(Qt::AlignBottom);
    attributeList = new QListWidget;
    QGridLayout *layout = new QGridLayout;
    layout->addWidget(profileLabel,0,0,1,2);
    layout->addWidget(titleLabel,1,0,1,2);
    layout->addWidget(attributeList,2,0,1,2);
    layout->setRowStretch(2,1);
    box->setLayout(layout);
    return box;
}

void MainWindow::createMenuBar()
{
    QAction *addAction = new QAction(tr("添加"),this);
    QAction *deleteAction = new QAction(tr("删除"),this);
    QAction *quitAction = new QAction(tr("退出"),this);
    addAction->setShortcut(tr("Ctrl+A"));
    deleteAction->setShortcut(tr("Ctrl+D"));
    quitAction->setShortcut(tr("Ctrl+Q"));
    QMenu *menu = menuBar()->addMenu(tr("操作菜单"));
    menu->addAction(addAction);
    menu->addAction(deleteAction);
    menu->addSeparator();
    menu->addAction(quitAction);
    connect(addAction,SIGNAL(triggered(bool)),this,SLOT(addCar()));
    connect(deleteAction,SIGNAL(triggered(bool)),this,SLOT(delCar()));
    connect(quitAction,SIGNAL(triggered(bool)),this,SLOT(close()));
}
