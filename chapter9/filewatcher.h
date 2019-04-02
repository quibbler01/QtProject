#ifndef FILEWATCHER_H
#define FILEWATCHER_H

#include <QWidget>
#include <QLabel>
#include <QFileSystemWatcher>

class FileWatcher : public QWidget
{
    Q_OBJECT
public:
    explicit FileWatcher(QWidget *parent = nullptr);
    ~FileWatcher();
signals:

public slots:
    void directoryChanged(QString path);
private:
    QLabel *pathLabel;
    QFileSystemWatcher fsWatcher;
};

#endif // FILEWATCHER_H
