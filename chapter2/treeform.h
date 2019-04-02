#ifndef TREEFORM_H
#define TREEFORM_H

#include <QWidget>
#include <QTreeWidgetItem>


namespace Ui {
class TreeForm;
}

class TreeForm : public QWidget
{
    Q_OBJECT

public:
    explicit TreeForm(QWidget *parent = nullptr);
    ~TreeForm();
    void init();
    void updateParentItem(QTreeWidgetItem *item);

public slots:
    void treeItemChanged(QTreeWidgetItem*item,int colum);


private:
    Ui::TreeForm *ui;
};

#endif // TREEFORM_H
