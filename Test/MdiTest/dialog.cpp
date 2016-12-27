#include "dialog.h"
#include <QDebug>

Dialog::Dialog(QWidget *parent) :
    QMdiSubWindow(parent),parent(parent)
{
    isLeftPressDown = false;
    this->dir = NONE;
    this->setMinimumHeight(100);
    this->setMinimumWidth(100);
    this->setMaximumHeight(200);
    this->setMaximumWidth(200);
    this->setWindowFlags(Qt::FramelessWindowHint|Qt::WindowSystemMenuHint );
    this->setMouseTracking(true);
}

Dialog::~Dialog()
{
}
void Dialog::mouseReleaseEvent(QMouseEvent *event)
{
    if(event->button() == Qt::LeftButton) {
        isLeftPressDown = false;
        if(dir != NONE) {
            this->releaseMouse();
            this->setCursor(QCursor(Qt::ArrowCursor));
        }
    }
}

void Dialog::mousePressEvent(QMouseEvent *event)
{
    switch(event->button()) {
    case Qt::LeftButton:
        isLeftPressDown = true;
        if(dir != NONE) {
            this->mouseGrabber();
        } else {
            dragPosition = event->globalPos() - this->geometry().topLeft();
        }
        break;
    case Qt::RightButton:
        this->close();
        break;
    default:
        QMdiSubWindow::mousePressEvent(event);
    }

}

void Dialog::mouseMoveEvent(QMouseEvent *event)
{
    QPoint gloPoint = event->globalPos();
    QRect rect = this->rect();
    //QPoint tl = rect.topLeft();
    //QPoint rb = rect.bottomRight();
    //qDebug() << rect;
    QPoint tl = mapToGlobal(rect.topLeft());
    QPoint rb = mapToGlobal(rect.bottomRight());

    qDebug() << "topLeft:" << tl << ";bottomRight:" << rb;
    qDebug() << "globalPoint: " << gloPoint;

    if(!isLeftPressDown) {
        this->region(event->globalPos());
    } else {

        if(dir != NONE) {
            QPoint rMove(mapToParent(this->rect().topLeft()));
            int width = this->width();
            int height = this->height();

            qDebug() << "rMove: " << rMove;
            qDebug() << "width: " << width;
            qDebug() << "height: " << height;

            switch(dir) {
            case LEFT:
                if(rb.x() - gloPoint.x() <= this->minimumWidth())
                    rMove.setX(rMove.x());
                else
                {
                    width = width - (gloPoint.x() - rMove.x());
                    rMove.setX(gloPoint.x());
                }
                break;
            case RIGHT:
                width = gloPoint.x() - tl.x();
                break;
            case UP:
                if(rb.y() - gloPoint.y() <= this->minimumHeight())
                    rMove.setY(rMove.y());
                else
                {
                    rMove.setY(gloPoint.y());
                }
                break;
            case DOWN:
                height = gloPoint.y() - tl.y();
                break;
            case LEFTTOP:
                if(rb.x() - gloPoint.x() <= this->minimumWidth())
                    rMove.setX(tl.x());
                else
                    rMove.setX(gloPoint.x());
                if(rb.y() - gloPoint.y() <= this->minimumHeight())
                    rMove.setY(tl.y());
                else
                    rMove.setY(gloPoint.y());
                break;
            case RIGHTTOP:
                rMove.setY(gloPoint.y());
                break;
            case LEFTBOTTOM:
                rMove.setX(gloPoint.x());
                break;
            case RIGHTBOTTOM:
                break;
            default:

                break;
            }

            qDebug() << "move now: " << width << " " << height;
            this->setGeometry(rMove.x(), rMove.y(), width, height);
        } else {
            move(event->globalPos() - dragPosition);
            event->accept();
        }
    }
    //QMdiSubWindow::mouseMoveEvent(event);
}

void Dialog::region(const QPoint &cursorGlobalPoint)
{
    QRect rect = this->rect();
    QPoint tl = mapToGlobal(rect.topLeft());
    QPoint rb = mapToGlobal(rect.bottomRight());
    int x = cursorGlobalPoint.x();
    int y = cursorGlobalPoint.y();

    if(tl.x() + PADDING >= x && tl.x() <= x && tl.y() + PADDING >= y && tl.y() <= y) {
        // 左上角
        dir = LEFTTOP;
        this->setCursor(QCursor(Qt::SizeFDiagCursor));
    } else if(x >= rb.x() - PADDING && x <= rb.x() && y >= rb.y() - PADDING && y <= rb.y()) {
        // 右下角
        dir = RIGHTBOTTOM;
        this->setCursor(QCursor(Qt::SizeFDiagCursor));
    } else if(x <= tl.x() + PADDING && x >= tl.x() && y >= rb.y() - PADDING && y <= rb.y()) {
        //左下角
        dir = LEFTBOTTOM;
        this->setCursor(QCursor(Qt::SizeBDiagCursor));
    } else if(x <= rb.x() && x >= rb.x() - PADDING && y >= tl.y() && y <= tl.y() + PADDING) {
        // 右上角
        dir = RIGHTTOP;
        this->setCursor(QCursor(Qt::SizeBDiagCursor));
    } else if(x <= tl.x() + PADDING && x >= tl.x()) {
        // 左边
        dir = LEFT;
        this->setCursor(QCursor(Qt::SizeHorCursor));
    } else if( x <= rb.x() && x >= rb.x() - PADDING) {
        // 右边
        qDebug() << "right";
        dir = RIGHT;
        this->setCursor(QCursor(Qt::SizeHorCursor));
    }else if(y >= tl.y() && y <= tl.y() + PADDING){
        // 上边
        qDebug() << "up";
        dir = UP;
        this->setCursor(QCursor(Qt::SizeVerCursor));
    } else if(y <= rb.y() && y >= rb.y() - PADDING) {
        // 下边
        dir = DOWN;
        this->setCursor(QCursor(Qt::SizeVerCursor));
    }else {
        // 默认
        dir = NONE;
        this->setCursor(QCursor(Qt::ArrowCursor));
    }
}
