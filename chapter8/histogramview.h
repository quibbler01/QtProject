#ifndef HISTOGRAMVIEW_H
#define HISTOGRAMVIEW_H

#include <QObject>
#include <QAbstractItemView>
#include <QItemSelectionModel>
#include <QRegion>
#include <QMouseEvent>
#include <QRect>

class HistogramView : public QAbstractItemView
{
    Q_OBJECT
public:
    explicit HistogramView(QWidget *parent = nullptr);
    QRect visualRect(const QModelIndex &index) const;
    QModelIndex indexAt(const QPoint &point) const;

    void setSelectionModel(QItemSelectionModel *selectionMModel);
    QRegion itemRegion(QModelIndex index);
    void paintEvent(QPaintEvent *);
    void mousePressEvent(QMouseEvent *event);

protected slots:
    void selectionChanged(const QItemSelection &selected, const QItemSelection &deselected);
    void dataChanged(const QModelIndex &topLeft,const QModelIndex &bottomRight, const QVector<int> &roles = QVector<int>());

protected:
    QModelIndex moveCursor(QAbstractItemView::CursorAction cursorAction,Qt::KeyboardModifiers modifiers);
    int horizontalOffset() const;
    int verticalOffset() const;
    bool isIndexHidden(const QModelIndex &index) const;
    void setSelection(const QRect &rect,QItemSelectionModel::SelectionFlags flags);
    QRegion visualRegionForSelection(const QItemSelection &selection) const;
    void scrollTo(const QModelIndex &index, ScrollHint hint = EnsureVisible);
private:
    QItemSelectionModel *selection;
    QList<QRegion> MRegionList;
    QList<QRegion> FRegionList;
    QList<QRegion> SRegionList;

signals:

public slots:
};

#endif // HISTOGRAMVIEW_H
