#ifndef BUILDINGPRIMITIVE_H
#define BUILDINGPRIMITIVE_H
#include "primitive.h"

class BuildingPrimitive : public Primitive
{
    Q_OBJECT
public:
    explicit BuildingPrimitive(QWidget *parent = 0);
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

#endif // BUILDINGPRIMITIVE_H
