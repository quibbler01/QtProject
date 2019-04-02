#ifndef CHAPTER4_H
#define CHAPTER4_H

#include <QMainWindow>

namespace Ui {
class Chapter4;
}

class Chapter4 : public QMainWindow
{
    Q_OBJECT

public:
    explicit Chapter4(QWidget *parent = nullptr);
    ~Chapter4();

private:
    Ui::Chapter4 *ui;
};

#endif // CHAPTER4_H
