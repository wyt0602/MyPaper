#include "textprimitive.h"
#include <QFont>
#include <QDebug>

TextPrimitive::TextPrimitive(QWidget *parent) :
    Primitive(parent)
{
    resize(100, 100);
    this->setWindowFlags(Qt::FramelessWindowHint);
    primitive_type = Other;
}

QListWidgetItem *TextPrimitive::getListWidgetItem()
{
    QListWidgetItem *item = new QListWidgetItem;
    item->setIcon(QIcon(":/png/images/png/text.png"));
    item->setText("文本框");
    return item;
}

void TextPrimitive::adjustPosition(QPoint p)
{
    move(p);
}

Primitive *TextPrimitive::clone(QWidget *parent)
{
    return new TextPrimitive(parent);
}

void TextPrimitive::serialized(QDataStream &out)
{
    position = this->pos();
    h = this->height();
    w = this->width();
    out << object_name << position << h << w;
    out << object_other << font << font_color << font_size;
}

void TextPrimitive::deserialized(QDataStream &in)
{
    in >> position;
    in >> h;
    in >> w;
    in >> object_other >> font >> font_color >> font_size;
    move(position);
    resize(w, h);
}

void TextPrimitive::paintEvent(QPaintEvent *event)
{
    QRect rect = this->rect();
    QPainter painter(this);
    painter.setPen(font_color);
    font.setBold(true);
    font.setPointSize(font_size);
    painter.setFont(font);
    painter.drawText(rect, Qt::AlignCenter, object_other);
}

void TextPrimitive::mouseDoubleClickEvent(QMouseEvent *event)
{
    Primitive::mouseDoubleClickEvent(event);
    object_name.append("_TextPrimitive");
}
