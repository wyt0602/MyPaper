#include "fireprimitive.h"

FirePrimitive::FirePrimitive(QWidget *parent) :
    Primitive(parent)
{
    resize(100, 100);
    this->setWindowFlags(Qt::FramelessWindowHint);
    primitive_type = Other;
    svg_render = new QSvgRenderer(QString(":/svg/images/svg/fire.svg"));
}

QListWidgetItem *FirePrimitive::getListWidgetItem()
{
    QListWidgetItem *item = new QListWidgetItem;
    item->setIcon(QIcon(":/png/images/png/fire.png"));
    item->setText("火焰");
    return item;
}

void FirePrimitive::adjustPosition(QPoint p)
{
    move(p);
}

Primitive *FirePrimitive::clone(QWidget *parent)
{
    return new FirePrimitive(parent);
}

void FirePrimitive::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    svg_render->render(&painter);
}

void FirePrimitive::mouseDoubleClickEvent(QMouseEvent *event)
{
    Primitive::mouseDoubleClickEvent(event);
    object_name.append("_FirePrimitive");
}
