#ifndef TEEPRIMITIVE_H
#define TEEPRIMITIVE_H
#include "primitive.h"

class TeePrimitive : public Primitive
{
    Q_OBJECT
public:
    explicit TeePrimitive(QWidget *parent = 0);
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

#endif // TEEPRIMITIVE_H
