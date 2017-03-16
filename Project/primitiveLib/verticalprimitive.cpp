#include "verticalprimitive.h"

VerticalPrimitive::VerticalPrimitive(QWidget *parent) :
    Primitive(parent)
{
    resize(100, 100);
    this->setWindowFlags(Qt::FramelessWindowHint);
    primitive_type = Pipe;
    svg_render = new QSvgRenderer(QString(":/svg/images/svg/verticalPipe.svg"));
}

QListWidgetItem *VerticalPrimitive::getListWidgetItem()
{
    QListWidgetItem *item = new QListWidgetItem;
    item->setIcon(QIcon(":/png/images/png/verticalPipe.png"));
    item->setText("竖直管道");
    return item;
}

void VerticalPrimitive::adjustPosition(QPoint p)
{
    move(p);
}

Primitive *VerticalPrimitive::clone(QWidget *parent)
{
    return new VerticalPrimitive(parent);
}

void VerticalPrimitive::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    svg_render->render(&painter);
}

void VerticalPrimitive::mouseDoubleClickEvent(QMouseEvent *event)
{
    Primitive::mouseDoubleClickEvent(event);
    object_name.append("_VerticalPrimitive");
}
