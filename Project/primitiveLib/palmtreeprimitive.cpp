#include "palmtreeprimitive.h"

PalmTreePrimitive::PalmTreePrimitive(QWidget *parent) :
    Primitive(parent)
{
    resize(100, 100);
    this->setWindowFlags(Qt::FramelessWindowHint);
    primitive_type = Other;
    svg_render = new QSvgRenderer(QString(":/svg/images/svg/palmTree.svg"));
}

QListWidgetItem *PalmTreePrimitive::getListWidgetItem()
{
    QListWidgetItem *item = new QListWidgetItem;
    item->setIcon(QIcon(":/png/images/png/palmTree.png"));
    item->setText("棕榈树");
    return item;
}

void PalmTreePrimitive::adjustPosition(QPoint p)
{
    move(p);
}

Primitive *PalmTreePrimitive::clone(QWidget *parent)
{
    return new PalmTreePrimitive(parent);
}

void PalmTreePrimitive::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    svg_render->render(&painter);
}

void PalmTreePrimitive::mouseDoubleClickEvent(QMouseEvent *event)
{
    Primitive::mouseDoubleClickEvent(event);
    object_name.append("_PalmTreePrimitive");
}
