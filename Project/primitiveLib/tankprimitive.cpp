#include "tankprimitive.h"

TankPrimitive::TankPrimitive(QWidget *parent) :
    Primitive(parent)
{
    resize(100, 100);
    this->setWindowFlags(Qt::FramelessWindowHint);
    primitive_type = Tank;
    svg_render = new QSvgRenderer(QString(":/svg/images/svg/tank.svg"));
}

QListWidgetItem *TankPrimitive::getListWidgetItem()
{
    QListWidgetItem *item = new QListWidgetItem;
    item->setIcon(QIcon(":/png/images/png/tank.png"));
    item->setText("水罐");
    return item;
}

void TankPrimitive::adjustPosition(QPoint p)
{
    move(p);
}

Primitive *TankPrimitive::clone(QWidget *parent)
{
    return new TankPrimitive(parent);
}

void TankPrimitive::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    svg_render->render(&painter);
}

void TankPrimitive::mouseDoubleClickEvent(QMouseEvent *event)
{
    Primitive::mouseDoubleClickEvent(event);
    object_name.append("_TankPrimitive");
}
