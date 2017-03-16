#include "curveprimitive.h"

CurvePrimitive::CurvePrimitive(QWidget *parent) :
    Primitive(parent)
{
    resize(100, 100);
    this->setWindowFlags(Qt::FramelessWindowHint);
    primitive_type = Pipe;
    svg_render = new QSvgRenderer(QString(":/svg/images/svg/curve.svg"));
}

QListWidgetItem *CurvePrimitive::getListWidgetItem()
{
    QListWidgetItem *item = new QListWidgetItem;
    item->setIcon(QIcon(":/png/images/png/curve.png"));
    item->setText("两通管道");
    return item;
}

void CurvePrimitive::adjustPosition(QPoint p)
{
    move(p);
}

Primitive *CurvePrimitive::clone(QWidget *parent)
{
    return new CurvePrimitive(parent);
}

void CurvePrimitive::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    svg_render->render(&painter);
}

void CurvePrimitive::mouseDoubleClickEvent(QMouseEvent *event)
{
    Primitive::mouseDoubleClickEvent(event);
    object_name.append("_CurvePrimitive");
}
