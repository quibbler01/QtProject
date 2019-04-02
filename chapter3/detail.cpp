#include "detail.h"

Detail::Detail(QWidget *parent):QWidget (parent)
{
    NationAddressLabel = new QLabel(tr("国家/地区："));
    ChooseNationAddress = new QComboBox;
    ChooseNationAddress->addItem(tr("中国"));
    ChooseNationAddress->addItem(tr("蒙古"));
    ChooseNationAddress->addItem(tr("朝鲜"));
    ChooseNationAddress->addItem(tr("韩国"));
    ChooseNationAddress->addItem(tr("日本"));
    ChooseNationAddress->addItem(tr("菲律宾"));
    ChooseNationAddress->addItem(tr("菲律宾"));
    ChooseNationAddress->addItem(tr("越南"));
    ChooseNationAddress->addItem(tr("老挝"));
    ChooseNationAddress->addItem(tr("柬埔寨"));
    ChooseNationAddress->addItem(tr("缅甸"));
    ChooseNationAddress->addItem(tr("泰国"));
    ChooseNationAddress->addItem(tr("马来西亚"));
    ChooseNationAddress->addItem(tr("文莱"));
    ChooseNationAddress->addItem(tr("新加坡"));
    ChooseNationAddress->addItem(tr("印度尼西亚"));
    ChooseNationAddress->addItem(tr("东帝汶"));

    ProvienceLabel = new QLabel(tr("省份："));
    ProvienceComboBox = new QComboBox;
    ProvienceComboBox->addItem(tr("安徽"));
    ProvienceComboBox->addItem(tr("上海"));
    ProvienceComboBox->addItem(tr("江苏"));
    ProvienceComboBox->addItem(tr("浙江"));
    ProvienceComboBox->addItem(tr("北京"));
    ProvienceComboBox->addItem(tr("天津"));
    ProvienceComboBox->addItem(tr("广东"));
    ProvienceComboBox->addItem(tr("河北"));
    ProvienceComboBox->addItem(tr("河南"));
    ProvienceComboBox->addItem(tr("山东"));
    ProvienceComboBox->addItem(tr("湖北"));
    ProvienceComboBox->addItem(tr("湖南"));
    ProvienceComboBox->addItem(tr("江西"));
    ProvienceComboBox->addItem(tr("福建"));
    ProvienceComboBox->addItem(tr("四川"));
    ProvienceComboBox->addItem(tr("重庆"));
    ProvienceComboBox->addItem(tr("广西"));
    ProvienceComboBox->addItem(tr("山西"));
    ProvienceComboBox->addItem(tr("辽宁"));
    ProvienceComboBox->addItem(tr("吉林"));
    ProvienceComboBox->addItem(tr("黑龙江"));
    ProvienceComboBox->addItem(tr("贵州"));
    ProvienceComboBox->addItem(tr("陕西"));
    ProvienceComboBox->addItem(tr("云南"));

    CityLabel = new QLabel(tr("城市："));
    CityLineEdit = new QLineEdit;

    PersonalDetailLabel = new QLabel(tr("个人说明："));
    PersonalDetailTextEdit = new QTextEdit();

    MainLayout = new QGridLayout(this);
    MainLayout->addWidget(NationAddressLabel,0,0);
    MainLayout->addWidget(ChooseNationAddress,0,1);
    MainLayout->addWidget(ProvienceLabel,1,0);
    MainLayout->addWidget(ProvienceComboBox,1,1);
    MainLayout->addWidget(CityLabel,2,0);
    MainLayout->addWidget(CityLineEdit,2,1);
    MainLayout->addWidget(PersonalDetailLabel,3,0);
    MainLayout->addWidget(PersonalDetailTextEdit,3,1);
}
