#include "linechartprimitive.h"

LineChartPrimitive::LineChartPrimitive(QWidget *parent) :
    Primitive(parent), x_range(0), x_count(0), y_range(0),
    y_count(0)
{
    resize(200, 200);
    this->setWindowFlags(Qt::FramelessWindowHint);
    primitive_type = BasicShape;
}

QListWidgetItem *LineChartPrimitive::getListWidgetItem()
{
    QListWidgetItem *item = new QListWidgetItem;
    item->setIcon(QIcon(":/png/images/png/lineChart.png"));
    item->setText("折线图");
    return item;
}

void LineChartPrimitive::adjustPosition(QPoint p)
{
    move(p);
}

Primitive *LineChartPrimitive::clone(QWidget *parent)
{
    return new LineChartPrimitive(parent);
}

void LineChartPrimitive::setParameter(int x_range, int x_count, int y_range, int y_count)
{
    this->x_range = x_range;
    this->x_count = x_count - 1;
    this->y_range = y_range;
    this->y_count = y_count;
}

void LineChartPrimitive::setTitle(QString &title)
{
    this->title = title;
}

void LineChartPrimitive::setData(QList<float> &data)
{
    this->data = data;
}

void LineChartPrimitive::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing, true);
    QFontMetrics metrics = painter.fontMetrics();
    int text_height = metrics.ascent() + metrics.descent();

    int left_width = metrics.width(tr("   ")) + 5;
    int right_width = metrics.width(tr("  "));
    int width = this->size().width() - left_width - right_width;
    int height = this->size().height() - 3 * text_height;

    painter.translate(left_width, 1.75 * text_height + height);

    float x_delta = (float)width / x_count;
    float y_delta = (float)height / y_count;

    //绘制横坐标
    painter.drawLine(0, 0, width, 0);
    for (int i = 0; i <= x_count; ++i)
    {
        QString info = tr("%1").arg(i + 1);
        int string_width = metrics.width(info);
        painter.drawLine(x_delta * i, 0, x_delta * i, 4);
        int info_x = x_delta * (i) - string_width / 2;
        painter.drawText(info_x, text_height, info);
    }

    //绘制纵坐标
    painter.drawLine(0, 0, 0, -height);
    painter.drawText(-metrics.width(title),-(y_delta * y_count + text_height / 2 + metrics.descent()), title);
    for (int i = 0; i <= y_count; ++i)
    {
        painter.drawLine(-4, -i * y_delta, 0, -i * y_delta);
        QString value = QString("%1").arg(i * y_range / y_count);
        int string_width = metrics.width(value);
        painter.drawText(-string_width - 4, -(y_delta * i + text_height / 2 - metrics.ascent()), value);
    }

    //绘制折线
    if (data.isEmpty())
        return;

    QPoint last_point, current_point;
    last_point = QPoint(0, -data.at(0)/(float)y_range * height);
    for (int i = 1; i < data.size(); ++i)
    {
        int data_act = data.at(i);
        int h = data_act / (float)y_range * height;
        current_point = QPoint(x_delta * i, -h);
        //绘制红点
        painter.setPen(Qt::red);
        painter.setBrush(Qt::red);
        painter.drawRect(last_point.x()-2, last_point.y()-2, 4, 4);
        //绘制线
        painter.setPen(Qt::black);
        painter.drawLine(last_point, current_point);
        last_point = current_point;
    }
    //绘制最后一个点
    painter.setPen(Qt::red);
    painter.setBrush(Qt::red);
    painter.drawRect(last_point.x()-2, last_point.y()-2, 4, 4);
}

void LineChartPrimitive::mouseDoubleClickEvent(QMouseEvent *event)
{
    Primitive::mouseDoubleClickEvent(event);
    object_name.append("_LineChartPrimitive");
}
