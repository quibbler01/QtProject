#include "switchlanguage.h"

SwitchLanguage::SwitchLanguage(QWidget *parent) : QWidget(parent)
{
    createScreent();
}

SwitchLanguage::~SwitchLanguage()
{

}

void SwitchLanguage::createScreent()
{
    selectLanguange = new QComboBox;
    selectLanguange->addItem("English","en");
    selectLanguange->addItem(tr("Chinese"),"zh");
    selectLanguange->addItem(tr("Latin"),"la");
    label = new QLabel;
    refreshLabel();
    QVBoxLayout *layout = new QVBoxLayout;
    layout->addWidget(selectLanguange,1);
    layout->addWidget(label,5);

    this->setLayout(layout);
    connect(selectLanguange,SIGNAL(currentIndexChanged(int)),this,SLOT(changeLanguage(int)));
    changeLanguage(selectLanguange->currentIndex());
}

void SwitchLanguage::changeTr(const QString langCode)
{
    static QTranslator *translator;
    if(translator!=nullptr){
        qApp->removeTranslator(translator);
        delete translator;
        translator = nullptr;
    }
    translator = new QTranslator;
    QString qmFileName = "lang_"+langCode;
    if(translator->load("C:\\Users\\Administrator\\Documents\\Qt\\chapter14\\"+qmFileName+".qm")){
        qApp->installTranslator(translator);
    }else{
        qDebug()<<"open translator failed";
    }
}

void SwitchLanguage::refreshLabel()
{
    label->setText(tr("TXT_HELLO_WORLD","Hello World"));
}

void SwitchLanguage::changeLanguage(int index)
{
    QString langCode = selectLanguange->itemData(index).toString();
    qDebug()<<langCode;
    changeTr(langCode);
    refreshLabel();
}
