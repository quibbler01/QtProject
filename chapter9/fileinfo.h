#ifndef FILEINFO_H
#define FILEINFO_H

#include <QObject>
#include <QDialog>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QCheckBox>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QFileDialog>
#include <QDateTime>

class FileInfo : public QDialog
{
    Q_OBJECT
public:
    explicit FileInfo(QWidget *parent = nullptr);
    ~FileInfo();

private:
    QLabel *fileNameLabel;
    QLineEdit *fileNameLineEdit;
    QPushButton *fileBtn;
    QLabel *sizeLabel;
    QLineEdit *sizeLineEdit;
    QLabel *createTimeLabel;
    QLineEdit *createLineEdit;
    QLabel *lastModifyTimeLabel;
    QLineEdit *lastModifyTimeLineEdit;
    QLabel *lastVisitTimeLabel;
    QLineEdit *lasVistiTimeLineEdit;

    QLabel *propertyLabel;
    QCheckBox *isDirCheckBox;
    QCheckBox *isFileCheckBox;
    QCheckBox *isSymbolLinkCheckBox;
    QCheckBox *isHiddenCheckBox;
    QCheckBox *isReadableCheckBox;
    QCheckBox *isWriteableCheckBox;
    QCheckBox *isExecutableCheckBox;
    QPushButton *getBtn;
signals:

public slots:
    void slotFile();
    void slotGet();
};

#endif // FILEINFO_H
