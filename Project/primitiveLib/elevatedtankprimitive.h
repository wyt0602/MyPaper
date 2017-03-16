#ifndef ELEVATEDTANKPRIMITIVE_H
#define ELEVATEDTANKPRIMITIVE_H
#include "primitive.h"

class ElevatedTankPrimitive : public Primitive
{
    Q_OBJECT
public:
    explicit ElevatedTankPrimitive(QWidget *parent = 0);
    QListWidgetItem* getListWidgetItem();
    void adjustPosition(QPoint p);
    Primitive* clone(QWidget *parent);

protected:
    void paintEvent(QPaintEvent *event);
    void mouseDoubleClickEvent(QMouseEvent *event);

signals:

public slots:

private:
    QSvgRenderer *svg_render;

};

#endif // ELEVATEDTANKPRIMITIVE_H
