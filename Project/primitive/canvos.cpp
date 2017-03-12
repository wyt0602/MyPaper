#include "canvos.h"
#include <QFile>
#include <QTextStream>
#include <QDebug>
#include <QMimeData>

typedef Primitive* (*GetPrimitiveFunc) (QWidget*);

Canvos::Canvos(QWidget *parent) :
    QWidget(parent)
{
    init();
    setAcceptDrops(true);
}

void Canvos::init()
{
    lib = new QLibrary("D:/primitiveLib.dll");
}

void Canvos::loadPrimitive()
{
    //QLibrary lib("D:/primitiveLib.dll");
    QFile file("D:/primitiveCfg.txt");
    int id = 1;
    if (file.open(QFile::ReadOnly))
    {
        QByteArray line;
        while (!file.atEnd()){
            line = file.readLine();
            line.remove(line.size() - 2, 2);
            GetPrimitiveFunc func = (GetPrimitiveFunc)lib->resolve(line.data());
            primitives[id] = func(0);
            ++id;
        }
        file.close();
    }
}

QMap<int, Primitive *> &Canvos::getPrimitiveSet()
{
    return primitives;
}

void Canvos::mousePressEvent(QMouseEvent *event)
{
    QObjectList children = this->children();

    for (auto child : children)
    {
        Primitive *p = (Primitive *)child;
        p->setStyleSheet("border:0px dotted rgb(0, 0, 0);background-color:rgba(255,255,255,0)");
    }
}

void Canvos::dragEnterEvent(QDragEnterEvent *event)
{

    event->setDropAction(Qt::MoveAction);
    event->accept();

}

void Canvos::dragMoveEvent(QDragMoveEvent *event)
{

    event->setDropAction(Qt::MoveAction);
    event->accept();
}

void Canvos::dropEvent(QDropEvent *event)
{
    Primitive *f = primitives[event->mimeData()->text().toInt()]->clone(this);
    if (f == NULL)
    {
        qDebug() << "clone error";
        return;
    }
    f->adjustPosition(event->pos());
    f->show();
    event->setDropAction(Qt::MoveAction);
    event->accept();
}
