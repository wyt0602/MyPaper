#ifndef FIREPRIMITIVE_H
#define FIREPRIMITIVE_H
#include "primitive.h"

class FirePrimitive : public Primitive
{
    Q_OBJECT
public:
    explicit FirePrimitive(QWidget *parent = 0);
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

#endif // FIREPRIMITIVE_H
