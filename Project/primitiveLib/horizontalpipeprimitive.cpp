#include "horizontalpipeprimitive.h"

HorizontalPipePrimitive::HorizontalPipePrimitive(QWidget *parent) :
    Primitive(parent)
{
    resize(100, 100);
    this->setWindowFlags(Qt::FramelessWindowHint);
    primitive_type = Pipe;
    svg_render = new QSvgRenderer(QString(":/svg/images/svg/horizontaPipe.svg"));
}

QListWidgetItem *HorizontalPipePrimitive::getListWidgetItem()
{
    QListWidgetItem *item = new QListWidgetItem;
    item->setIcon(QIcon(":/png/images/png/horizontaPipe.png"));
    item->setText("水平管道");
    return item;
}

void HorizontalPipePrimitive::adjustPosition(QPoint p)
{
    move(p);
}

Primitive *HorizontalPipePrimitive::clone(QWidget *parent)
{
    return new HorizontalPipePrimitive(parent);
}

void HorizontalPipePrimitive::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    svg_render->render(&painter);
}

void HorizontalPipePrimitive::mouseDoubleClickEvent(QMouseEvent *event)
{
    Primitive::mouseDoubleClickEvent(event);
    object_name.append("_HorizontalPipePrimitive");
}
