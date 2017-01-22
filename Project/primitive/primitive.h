#ifndef PRIMITIVE_H
#define PRIMITIVE_H

#include <QMouseEvent>
#include <QPoint>
#include <QRect>
#include <QMdiSubWindow>

#define PADDING 6

class Primitive : public QMdiSubWindow
{
    Q_OBJECT

    typedef enum
    {
        Top = 0,
        Bottom,
        Left,
        Right,
        TopLeft,
        TopRight,
        BottomLeft,
        BottomRight,
        Inner
    }RegionDirection;

public:
    explicit Primitive(QWidget *parent = 0);

protected:
    void mousePressEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *);
    void mouseMoveEvent(QMouseEvent *event);
    void mouseDoubleClickEvent(QMouseEvent *);

    void paintEvent(QPaintEvent *event);

private:
    void setRegionInfo(QMouseEvent *event);
    void adjustShape(QPoint &mouse_position);
    void borderCheck(QMouseEvent *event, QPoint &mouse_position);
    void setBorderCheckParameter(QMouseEvent *event);

signals:

public slots:

private:
    QPoint drag_relative_position;
    bool is_left_press_down;
    RegionDirection direction;
    int top, bottom, left, right;

    QRect parent_info;
    QPoint position;
    int h;
    int w;
};

#endif // PRIMITIVE_H
