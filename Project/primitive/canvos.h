#ifndef CANVOS_H
#define CANVOS_H

#include <QWidget>
#include <QLibrary>
#include "primitive.h"

class Canvos : public QWidget
{
    Q_OBJECT
public:
    explicit Canvos(QWidget *parent = 0);
    void init();
    void loadPrimitive();
    QMap<int, Primitive*>& getPrimitiveSet();


protected:
    void mousePressEvent(QMouseEvent *event);
    void dragEnterEvent(QDragEnterEvent *event);
    void dragMoveEvent(QDragMoveEvent *event);
    void dropEvent(QDropEvent *event);

signals:

public slots:

private:
    QLibrary *lib;
    QMap<int, Primitive*> primitives;
};

#endif // CANVOS_H
