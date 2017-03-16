#include "elevatedtankprimitive.h"

ElevatedTankPrimitive::ElevatedTankPrimitive(QWidget *parent) :
    Primitive(parent)
{
    resize(100, 100);
    this->setWindowFlags(Qt::FramelessWindowHint);
    primitive_type = Tank;
    svg_render = new QSvgRenderer(QString(":/svg/images/svg/elevatedTank.svg"));
}

QListWidgetItem *ElevatedTankPrimitive::getListWidgetItem()
{
    QListWidgetItem *item = new QListWidgetItem;
    item->setIcon(QIcon(":/png/images/png/elevatedTank.png"));
    item->setText("水塔");
    return item;
}

void ElevatedTankPrimitive::adjustPosition(QPoint p)
{
    move(p);
}

Primitive *ElevatedTankPrimitive::clone(QWidget *parent)
{
    return new ElevatedTankPrimitive(parent);
}

void ElevatedTankPrimitive::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    svg_render->render(&painter);
}

void ElevatedTankPrimitive::mouseDoubleClickEvent(QMouseEvent *event)
{
    Primitive::mouseDoubleClickEvent(event);
    object_name.append("_ElevatedTankPrimitive");
}
