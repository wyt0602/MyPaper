#ifndef HORIZONTAPIPEPRIMITIVE_H
#define HORIZONTAPIPEPRIMITIVE_H
#include "primitive.h"

class HorizontalPipePrimitive : public Primitive
{
    Q_OBJECT
public:
    explicit HorizontalPipePrimitive(QWidget *parent = 0);
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

#endif // HORIZONTAPIPEPRIMITIVE_H
