#ifndef VERTICALPRIMITIVE_H
#define VERTICALPRIMITIVE_H
#include "primitive.h"

class VerticalPrimitive : public Primitive
{
    Q_OBJECT
public:
    explicit VerticalPrimitive(QWidget *parent = 0);
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

#endif // VERTICALPRIMITIVE_H
