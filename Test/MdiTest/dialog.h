#ifndef DIALOG_H
#define DIALOG_H

#include <QMdiSubWindow>

#include <QDialog>
#include <QMouseEvent>
#include <QPoint>
#include <QCursor>
#include <QRect>
#define PADDING 2

namespace Ui {
class Dialog;
}
enum Direction{
    UP = 0,
    DOWN=1,
    LEFT,
    RIGHT,
    LEFTTOP,
    LEFTBOTTOM,
    RIGHTBOTTOM,
    RIGHTTOP,
    NONE
};
class Dialog : public QMdiSubWindow
{
    Q_OBJECT
    
public:
    explicit Dialog(QWidget *parent = 0);
    ~Dialog();
private:
    void region(const QPoint &cursorPoint);
protected:
    void mouseReleaseEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void mousePressEvent(QMouseEvent *event);
private:
    bool isLeftPressDown;
    QPoint dragPosition;
    Direction dir;
    QWidget *parent;
private:
    Ui::Dialog *ui;
};

#endif // DIALOG_H
