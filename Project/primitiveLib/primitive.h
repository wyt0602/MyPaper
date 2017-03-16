#ifndef PRIMITIVE_H
#define PRIMITIVE_H

#include <QMouseEvent>
#include <QPoint>
#include <QRect>
#include <QMdiSubWindow>
#include <QSvgRenderer>
#include <QPainter>
#include <QListWidgetItem>

#define PADDING 3

typedef enum{
    BasicShape,  //一些基本的图元
    PushButton,  //按钮形状的图元
    Arrow,  //箭头形状的图元
    Pipe,  //各类管状的图元
    Blower,  //鼓风机类的图元
    Boiler,  //锅炉类的图元
    Pump,  //泵形状的图元
    Controller,  //各类控制器形状的图元
    Motor,  //电机形状的图元
    Tank,  //各种罐子形状的图元
    Other,  //未分类的图元
    PrimitiveTypeSize  //图元类型的总数
}PrimitiveType;


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

public:
    virtual PrimitiveType getType();
    virtual QListWidgetItem* getListWidgetItem();
    virtual QString getObjectName();
    virtual void adjustPosition(QPoint p);
    virtual void serialized(QDataStream &out);
    virtual void deserialized(QDataStream &in);
    virtual Primitive* clone(QWidget *parent);

    virtual void setParameter(int x_range, int x_count, int y_range, int y_count);
    virtual void setTitle(QString &title);
    virtual void setData(QList<float> &data);

private:
    void setRegionInfo(QMouseEvent *event);
    void adjustShape(QPoint &mouse_position);
    void borderCheck(QMouseEvent *event, QPoint &mouse_position);
    void setBorderCheckParameter(QMouseEvent *event);
    void clearBorder();

signals:

public slots:

protected:
    QPoint drag_relative_position;
    bool is_left_press_down;
    RegionDirection direction;
    int top, bottom, left, right;

    PrimitiveType primitive_type;
    QString object_name;
    QString object_other;

    QPoint position;
    int h;
    int w;

    QFont font;
    QColor font_color;
    int font_size;
};

#endif // PRIMITIVE_H
