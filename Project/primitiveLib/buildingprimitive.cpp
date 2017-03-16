#include "buildingprimitive.h"

BuildingPrimitive::BuildingPrimitive(QWidget *parent) :
    Primitive(parent)
{
    resize(100, 100);
    this->setWindowFlags(Qt::FramelessWindowHint);
    primitive_type = Other;
    svg_render = new QSvgRenderer(QString(":/svg/images/svg/building.svg"));
}

QListWidgetItem *BuildingPrimitive::getListWidgetItem()
{
    QListWidgetItem *item = new QListWidgetItem;
    item->setIcon(QIcon(":/png/images/png/building.png"));
    item->setText("建筑物");
    return item;
}

void BuildingPrimitive::adjustPosition(QPoint p)
{
    move(p);
}

Primitive *BuildingPrimitive::clone(QWidget *parent)
{
    return new BuildingPrimitive(parent);
}

void BuildingPrimitive::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    svg_render->render(&painter);
}

void BuildingPrimitive::mouseDoubleClickEvent(QMouseEvent *event)
{
    Primitive::mouseDoubleClickEvent(event);
    object_name.append("_BuildingPrimitive");
}
