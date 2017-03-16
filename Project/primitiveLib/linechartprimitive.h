#ifndef LINECHARTPRIMITIVE_H
#define LINECHARTPRIMITIVE_H
#include "primitive.h"

class LineChartPrimitive : public Primitive
{
    Q_OBJECT
public:
    explicit LineChartPrimitive(QWidget *parent = 0);
    QListWidgetItem* getListWidgetItem();
    void adjustPosition(QPoint p);
    Primitive* clone(QWidget *parent);
    void setParameter(int x_range, int x_count, int y_range, int y_count);
    void setTitle(QString &title);
    void setData(QList<float> &data);

protected:
    void paintEvent(QPaintEvent *event);
    void mouseDoubleClickEvent(QMouseEvent *event);

signals:

public slots:

private:
    int x_range;
    int x_count;
    int y_range;
    int y_count;
    QString title;
    QList<float> data;

};

#endif // LINECHARTPRIMITIVE_H
