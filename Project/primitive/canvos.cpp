#include "canvos.h"
#include "primitive.h"

Canvos::Canvos(QWidget *parent) :
    QWidget(parent)
{
}

void Canvos::mousePressEvent(QMouseEvent *event)
{
    QObjectList children = this->children();

    for (auto child : children)
    {
        Primitive *p = (Primitive *)child;
        p->setStyleSheet("border:0px dotted rgb(0, 0, 0);background-color:rgba(0,0,0,0)");
    }

    QWidget::mousePressEvent(event);
}
