#include "primitive.h"
#include <QDebug>
#include <QGraphicsColorizeEffect>

Primitive::Primitive(QWidget *parent) :
    QMdiSubWindow(parent), is_left_press_down(false),
    direction(Inner)
{
    this->resize(200, 200);
    this->setWindowFlags(Qt::FramelessWindowHint);

    qDebug() << this->parentWidget()->rect().width();
    qDebug() << this->parentWidget()->width() << this->parentWidget()->height();
    this->setMinimumHeight(50);
    this->setMinimumWidth(50);
    this->setMaximumHeight(500);
    this->setMaximumWidth(500);
    move(QPoint(0, 100));
    this->resize(100, 100);

    //svg_render = new QSvgRenderer(QString("D:/pump.svg"));
    //QGraphicsColorizeEffect *color_effect = new QGraphicsColorizeEffect;
    //color_effect->setColor(Qt::red);
    //this->setGraphicsEffect(color_effect);

    //this->setMouseTracking(true);
}

void Primitive::mousePressEvent(QMouseEvent *event)
{

    setBorderCheckParameter(event);
    setRegionInfo(event);

    switch (event->button()) {
    case Qt::LeftButton:
        this->raise();
        this->setStyleSheet("border:1px dotted rgb(0, 0, 0);background-color:rgba(255,255,255,0)");
        clearBorder();
        is_left_press_down = true;
        if (direction == Inner)
        {
            drag_relative_position = event->globalPos() - this->geometry().topLeft();
            this->setCursor(Qt::SizeAllCursor);
        }
        break;
    default:
        break;
    }
}

void Primitive::mouseReleaseEvent(QMouseEvent *)
{
    is_left_press_down = false;
    this->setCursor(Qt::ArrowCursor);
    this->repaint();
}

void Primitive::mouseMoveEvent(QMouseEvent *event)
{    
    qDebug() << event->pos();
    if (is_left_press_down)
    {
        QPoint mouse_position = event->globalPos();
        borderCheck(event, mouse_position);
        if (direction == Inner)
            move(mouse_position - drag_relative_position);
        else
            adjustShape(mouse_position);
    }
    else if (this->hasFocus())
        setRegionInfo(event);
    else
        this->setCursor(Qt::ArrowCursor);
}

void Primitive::mouseDoubleClickEvent(QMouseEvent *)
{
    this->resize(100, 100);
    //this->close();
}
void Primitive::adjustPosition(QPoint p)
{

}
QString Primitive::getObjectName()
{
    return object_name;
}
void Primitive::paintEvent(QPaintEvent *event)
{
    Primitive *w = this;
    QPainter painter(w);
    QFontMetrics metrics = painter.fontMetrics();
    int textHeight = metrics.ascent() + metrics.descent();

    int leftWidth = metrics.width(tr("9000")) + 5;
    int rightWidth = metrics.width(tr("(日)"));
    int width = w->size().width() - leftWidth - rightWidth;
    int height = w->size().height() - 3 * textHeight;

    // 绘制外框
    painter.drawRect(0, 0, w->size().width() -1, w->size().height() - 1);

    //　移动坐标系
    painter.translate(leftWidth, 1.75 * textHeight + height);
    int totalCount = 9000; // 默认每年收入9000件衣服
    int count = 10;        // 分成10成
    float deltaX = width / 12.0f;         // x坐标上每分的宽度
    float deltaY = (float)height / count; // y坐标上每分的宽度

    // 画横坐标

    painter.drawLine(0, 0, width, 0);

    for (int i = 1; i <= 12; ++i) {
        QString month = tr("%1月").arg(i);
        int stringWidth = metrics.width(month);
        // 绘制坐标刻度
        painter.drawLine(deltaX * i, 0, deltaX * i, 4);
       // 绘制坐标处的月
        int monthX = deltaX * (i - 1) + ((deltaX - stringWidth) / 2);
        painter.drawText(monthX, textHeight, month);
    }
   // 画纵坐标

    painter.drawLine(0, 0, 0, -height);
    painter.drawText(-metrics.width(tr("(件)")),

                     -(deltaY * count + textHeight / 2 + metrics.descent()),

                     tr("(件)"));
    for (int i = 1; i <= count; ++i) {

        QString value = QString("%1").arg(i * totalCount / count);

        int stringWidth = metrics.width(value);
        // 绘制坐标刻度
        painter.drawLine(-4, -i * deltaY, 0, -i * deltaY);
        // 绘制坐标值

        //painter.drawText(-stringWidth - 4, -i * deltaY + stringHeight / 2, value);

        painter.drawText(-stringWidth - 4, -(deltaY * i + textHeight / 2 - metrics.ascent()), value);

    }
    // 绘制每个月收到的服饰

    painter.setBrush(Qt::BDiagPattern);

    QList<int> yearList = {233, 234, 342, 378,453, 567,654,876};
    for (int i = 0; i < yearList.size(); ++i) {

        painter.setPen(Qt::black);

        int fineryCount = yearList.at(i); // 第i + 1个月收到的服饰件数

        int h = fineryCount / (float)totalCount * height;

        painter.drawRect(deltaX * i + 2, 0, deltaX - 4, -h);



        // 绘制收到的服饰件数

        QString fineryString = QString("%1").arg(fineryCount);

        int stringWidth = metrics.width(fineryString);



        if (h > height) {

            h = height;

        }



        painter.setPen(Qt::red);

        //painter.drawText(deltaX * i + (deltaX - stringWidth) / 2, -(h + metrics.descent()), fineryString);

    }
}

PrimitiveType Primitive::getType()
{
    return primitive_type;
}

QListWidgetItem *Primitive::getListWidgetItem()
{

}

void Primitive::serialized(QDataStream &out)
{

}

void Primitive::deserialized(QDataStream &in)
{

}

Primitive *Primitive::clone(QWidget *parent)
{
    qDebug() << "in parent";
}

void Primitive::setRegionInfo(QMouseEvent *event)
{
    QRect cur_primitive = this->rect();
    QPoint cur_tl = mapToGlobal(cur_primitive.topLeft());
    QPoint cur_tr = mapToGlobal(cur_primitive.topRight());
    QPoint cur_bl = mapToGlobal(cur_primitive.bottomLeft());
    QPoint cur_br = mapToGlobal(cur_primitive.bottomRight());


    QPoint mouse_position = event->globalPos();

    //region 0(top left)
    if (mouse_position.x() >= cur_tl.x() &&
            mouse_position.x() <= cur_tl.x() + PADDING &&
            mouse_position.y() >= cur_tl.y() &&
            mouse_position.y() <= cur_tl.y() + PADDING)
    {
        direction = TopLeft;
        this->setCursor(Qt::SizeFDiagCursor);
        return;
    }

    //region 1(top)
    if (mouse_position.x() >= cur_tl.x() + PADDING &&
            mouse_position.x() <= cur_tr.x() - PADDING &&
            mouse_position.y() >= cur_tl.y() &&
            mouse_position.y() <= cur_tl.y() + PADDING)
    {
        direction = Top;
        this->setCursor(Qt::SizeVerCursor);
        return;
    }

    //region 2(top right)
    if (mouse_position.x() >= cur_tr.x() - PADDING &&
            mouse_position.x() <= cur_tr.x() + PADDING &&
            mouse_position.y() >= cur_tr.y() - PADDING &&
            mouse_position.y() <= cur_tr.y() + PADDING)
    {
        direction = TopRight;
        this->setCursor(Qt::SizeBDiagCursor);
        return;
    }

    //region 3(left)
    if (mouse_position.x() >= cur_tl.x() &&
            mouse_position.x() <= cur_tl.x() + PADDING &&
            mouse_position.y() >= cur_tl.y() + PADDING &&
            mouse_position.y() <= cur_bl.y() - PADDING)
    {
        direction = Left;
        this->setCursor(Qt::SizeHorCursor);
        return;
    }

    //region 4(right)
    if (mouse_position.x() >= cur_tr.x() - PADDING &&
            mouse_position.x() <= cur_tr.x() &&
            mouse_position.y() >= cur_tr.y() + PADDING &&
            mouse_position.y() <= cur_br.y() - PADDING)
    {
        direction = Right;
        this->setCursor(Qt::SizeHorCursor);
        return;
    }

    //region 5(bottom left)
    if (mouse_position.x() >= cur_bl.x() &&
            mouse_position.x() <= cur_bl.x() + PADDING &&
            mouse_position.y() >= cur_bl.y() - PADDING &&
            mouse_position.y() <= cur_bl.y())
    {
        direction = BottomLeft;
        this->setCursor(Qt::SizeBDiagCursor);
        return;
    }

    //region 6(bottom)
    if (mouse_position.x() >= cur_bl.x() + PADDING &&
            mouse_position.x() <= cur_br.x() - PADDING &&
            mouse_position.y() >= cur_bl.y() - PADDING &&
            mouse_position.y() <= cur_bl.y())
    {
        direction = Bottom;
        this->setCursor(Qt::SizeVerCursor);
        return;
    }

    //region 7(bottom right)
    if (mouse_position.x() >= cur_br.x() - PADDING &&
            mouse_position.x() <= cur_br.x() &&
            mouse_position.y() >= cur_br.y() - PADDING &&
            mouse_position.y() <= cur_br.y())
    {
        direction = BottomRight;
        this->setCursor(Qt::SizeFDiagCursor);
        return;
    }

    direction = Inner;
    this->setCursor(Qt::ArrowCursor);
}

void Primitive::adjustShape(QPoint &mouse_position)
{
    QRect rect = this->rect();
    QPoint tl = mapToGlobal(rect.topLeft());
    QPoint tr = mapToGlobal(rect.topRight());
    QPoint bl = mapToGlobal(rect.bottomLeft());
    QPoint br = mapToGlobal(rect.bottomRight());

    QPoint adjust_tl(mapToParent(rect.topLeft()));

    int height = this->height();
    int width = this->width();

    switch (direction) {
    case Top:
        if(br.y() - mouse_position.y() >= this->minimumHeight() && br.y() - mouse_position.y() <= this->maximumHeight())
        {
            int distance = mouse_position.y() - tl.y();
            adjust_tl.setY(adjust_tl.y() + distance);
            height -= distance;
        }
        break;
    case Bottom:
        height = mouse_position.y() - tl.y();
        break;
    case Left:
        if(br.x() - mouse_position.x() >= this->minimumHeight() && br.x() - mouse_position.x() <= this->maximumHeight())
        {
            int distance = mouse_position.x() - tl.x();
            adjust_tl.setX(adjust_tl.x() + distance);
            width -= distance;
        }
        break;
    case Right:
        width = mouse_position.x() - tl.x();
        break;
    case TopLeft:
        if (br.x() - mouse_position.x() >= this->minimumWidth() &&
                br.y() - mouse_position.y() >= this->minimumHeight() &&
                br.x() - mouse_position.x() <= this->maximumWidth() &&
                br.y() - mouse_position.y() <= this->maximumHeight())
        {
            int distance_x = mouse_position.x() - tl.x();
            int distance_y = mouse_position.y() - tl.y();
            adjust_tl.setX(adjust_tl.x() + distance_x);
            width -= distance_x;
            adjust_tl.setY(adjust_tl.y() + distance_y);
            height -= distance_y;
        }
        break;
    case TopRight:
        if (mouse_position.x() - bl.x() >= this->minimumWidth() &&
                bl.y() - mouse_position.y() >= this->minimumHeight() &&
                mouse_position.x() - bl.x() <= this->maximumWidth() &&
                bl.y() - mouse_position.y() <= this->maximumHeight())
        {
            int distance_y = mouse_position.y() - tl.y();
            width = mouse_position.x() - tl.x();
            adjust_tl.setY(adjust_tl.y() + distance_y);
            height -= distance_y;
        }
        break;
    case BottomLeft:
        if (tr.x() - mouse_position.x() >= this->minimumWidth() &&
                mouse_position.y() - tr.y() >= this->minimumHeight() &&
                tr.x() - mouse_position.x() <= this->maximumWidth() &&
                mouse_position.y() - tr.y() <= this->maximumHeight())
        {
            int distance_x = mouse_position.x() - tl.x();
            adjust_tl.setX(adjust_tl.x() + distance_x);
            width -= distance_x;
            height = mouse_position.y() - tl.y();
        }
        break;
    case BottomRight:
        if (mouse_position.x() - tl.x() >= this->minimumWidth() &&
                mouse_position.y() - tl.y() >= this->minimumHeight() &&
                mouse_position.x() - tl.x() <= this->maximumWidth() &&
                mouse_position.y() - tl.y()  <= this->maximumHeight())
        {
            width = mouse_position.x() - tl.x();
            height = mouse_position.y() - tl.y();
        }
        break;
    default:
        break;
    }
    this->setGeometry(adjust_tl.x(), adjust_tl.y(), width, height);
}

void Primitive::borderCheck(QMouseEvent *event, QPoint &mouse_position)
{
    QPoint parent_tl = mapToGlobal(QPoint(0, 0)) - this->pos();
    QPoint parent_br;
    parent_br.setX(parent_tl.x() + this->parentWidget()->width());
    parent_br.setY(parent_tl.y() + this->parentWidget()->height());

    QPoint global_point = event->globalPos();

    if (direction != Inner)
        top = bottom = left = right = 0;

    if (global_point.x()  < parent_tl.x() + left)
        mouse_position.setX(parent_tl.x() + left);

    if (global_point.x()  > parent_br.x() - right)
        mouse_position.setX(parent_br.x() - right);

    if (global_point.y() < parent_tl.y() + top)
        mouse_position.setY(parent_tl.y() + top);

    if (global_point.y() > parent_br.y() - bottom)
        mouse_position.setY(parent_br.y() - bottom);
}

void Primitive::setBorderCheckParameter(QMouseEvent *event)
{
    QPoint tl = mapToGlobal(this->rect().topLeft());
    QPoint br = mapToGlobal(this->rect().bottomRight());
    top = qAbs(tl.y() - event->globalPos().y());
    bottom = qAbs(br.y() - event->globalPos().y());
    left = qAbs(tl.x() - event->globalPos().x());
    right = qAbs(br.x() - event->globalPos().x());
}

void Primitive::clearBorder()
{
    QObjectList children = this->parentWidget()->children();

    for (auto child : children)
    {
        if (child != this)
        {
            Primitive *p = (Primitive *)child;
            p->setStyleSheet("border:0px dotted rgb(0, 0, 0);background-color:rgba(255,255,255,0)");
        }
    }
}


