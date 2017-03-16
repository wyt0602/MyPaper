#ifndef CURVEPRIMITIVE_H
#define CURVEPRIMITIVE_H
#include "primitive.h"

class CurvePrimitive : public Primitive
{
    Q_OBJECT
public:
    explicit CurvePrimitive(QWidget *parent = 0);
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

#endif // CURVEPRIMITIVE_H
