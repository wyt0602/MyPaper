#include "teeprimitive.h"

TeePrimitive::TeePrimitive(QWidget *parent) :
    Primitive(parent)
{
    resize(100, 100);
    this->setWindowFlags(Qt::FramelessWindowHint);
    primitive_type = Pipe;
    svg_render = new QSvgRenderer(QString(":/svg/images/svg/tee.svg"));
}

QListWidgetItem *TeePrimitive::getListWidgetItem()
{
    QListWidgetItem *item = new QListWidgetItem;
    item->setIcon(QIcon(":/png/images/png/tee.png"));
    item->setText("三通管道");
    return item;
}

void TeePrimitive::adjustPosition(QPoint p)
{
    move(p);
}

Primitive *TeePrimitive::clone(QWidget *parent)
{
    return new TeePrimitive(parent);
}

void TeePrimitive::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    svg_render->render(&painter);
}

void TeePrimitive::mouseDoubleClickEvent(QMouseEvent *event)
{
    Primitive::mouseDoubleClickEvent(event);
    object_name.append("_TeePrimitive");

}
