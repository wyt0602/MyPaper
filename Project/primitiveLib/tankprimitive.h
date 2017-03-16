#ifndef TANKPRIMITIVE_H
#define TANKPRIMITIVE_H

#include "primitive.h"

class TankPrimitive : public Primitive
{
    Q_OBJECT
public:
    explicit TankPrimitive(QWidget *parent = 0);
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

#endif // TANKPRIMITIVE_H
