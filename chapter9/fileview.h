#ifndef FILEVIEW_H
#define FILEVIEW_H

#include <QObject>
#include <QWidget>
#include <QDialog>
#include <QListWidget>
#include <QVBoxLayout>
#include <QListWidgetItem>
#include <QFile>
#include <QFileInfoList>
#include <QDir>
#include <QLineEdit>

class FileView : public QDialog
{
    Q_OBJECT
public:
    explicit FileView(QWidget *parent = nullptr,Qt::WindowFlags f = 0);
    ~FileView();
    void showFileInfoList(QFileInfoList list);

signals:

public slots:
    void slotShow(QDir dir);
    void slotShow();
    void slotDirShow(QListWidgetItem* item);

private:
    QLineEdit *fileLineEdit;
    QListWidget *fileListWidget;
    QVBoxLayout *mainLayout;
};

#endif // FILEVIEW_H
