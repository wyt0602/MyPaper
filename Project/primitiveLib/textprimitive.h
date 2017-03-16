#ifndef TEXTPRIMITIVE_H
#define TEXTPRIMITIVE_H
#include "primitive.h"

class TextPrimitive : public Primitive
{
    Q_OBJECT
public:
    explicit TextPrimitive(QWidget *parent = 0);
    QListWidgetItem* getListWidgetItem();
    void adjustPosition(QPoint p);
    Primitive* clone(QWidget *parent);
    void serialized(QDataStream &out);
    void deserialized(QDataStream &in);

protected:
    void paintEvent(QPaintEvent *event);
    void mouseDoubleClickEvent(QMouseEvent *event);

signals:

public slots:

};

#endif // TEXTPRIMITIVE_H
