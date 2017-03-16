#ifndef PALMTREEPRIMITIVE_H
#define PALMTREEPRIMITIVE_H
#include "primitive.h"

class PalmTreePrimitive : public Primitive
{
    Q_OBJECT
public:
    explicit PalmTreePrimitive(QWidget *parent = 0);
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

#endif // PALMTREEPRIMITIVE_H
