#include "canvos.h"
#include <QFile>
#include <QTextStream>
#include <QDebug>
#include <QMimeData>

typedef Primitive* (*GetPrimitiveFunc) (QWidget*);

Canvos::Canvos(QWidget *parent) :
    QWidget(parent), type_flag(false), run_env(true),
    list(new ProjectListWidget)
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
    QFile file("D:/primitiveCfg.txt");
    int id = 1;
    if (file.open(QFile::ReadOnly))
    {
        QByteArray line;
        while (!file.atEnd()){
            line = file.readLine();
            line.remove(line.size() - 2, 2);
            GetPrimitiveFunc func = (GetPrimitiveFunc)lib->resolve(line.data());
            if (func == NULL)
            {
                qDebug() << "resolve error!";
                return;
            }
            primitives[id] = func(0);
            ++id;
        }
        file.close();
    }
}

void Canvos::savePrimitiveToFile(QString &filename)
{
    QFile file(filename);
    if (file.open(QIODevice::WriteOnly))
    {
        QDataStream out(&file);
        for (Primitive* item : cur_pri)
            item->serialized(out);
        file.close();
    }
}

void Canvos::loadPrimitiveFromFile(QString &filename)
{
    QFile file(filename);
    QString object_name;
    if (file.open(QIODevice::ReadOnly))
    {
        QDataStream in(&file);
        while (!in.atEnd())
        {
            in >> object_name;
            QString primitive_name = object_name.split("_").at(1);
            qDebug() << primitive_name;
            QByteArray str("get");
            str.append(primitive_name);

            GetPrimitiveFunc func = (GetPrimitiveFunc)lib->resolve(str.data());
            if (func == NULL)
            {
                qDebug() << "resolve error!";
                return;
            }
            Primitive *pri = func(this);
            if (pri->getType() == BasicShape)
                setData(pri);
            pri->deserialized(in);
            cur_pri.push_back(pri);
            pri->show();
        }
        file.close();
    }
}

QMap<int, Primitive *> &Canvos::getPrimitiveSet()
{
    return primitives;
}

QList<Primitive *> &Canvos::getCurrentPrimitive()
{
    return cur_pri;
}

ProjectListWidget *Canvos::getListWidget()
{
    list->setIconSize(QSize(50,50));
    QMapIterator<int, Primitive*> it(primitives);
    while (it.hasNext())
    {
        it.next();
        if (it.value()->getType() == Pipe)
            continue;
        QListWidgetItem *item = it.value()->getListWidgetItem();
        item->setWhatsThis(QString("%1").arg(it.key()));
        item->setSizeHint(QSize(70, 70));
        list->addItem(item);
    }
    return list;
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
    if (f->getType() == BasicShape)
        setData(f);
    cur_pri.push_back(f);
    f->show();
    event->setDropAction(Qt::MoveAction);
    event->accept();
}

void Canvos::setData(Primitive *item)
{
    QList<float> temperature = {81.2,
                                83.0,
                                85.2,
                                80.1,
                                86.1,
                                66.1,
                                80.0,
                                87.1,
                                88.3,
                                82.6};
    QList<float> water = {145.0,
                          142.2,
                          134.3,
                          130.0,
                          150.7,
                          167.0,
                          172.4,
                          175.6,
                          192.3,
                          187.3};

    QString label_t("(℃)");
    QString label_w("(m³)");
    if (type_flag == false)
    {
        item->setParameter(10, 10, 100, 10);
        item->setTitle(label_t);
        if (run_env)
            item->setData(temperature);
        type_flag = true;
    }
    else
    {
        item->setParameter(10, 10, 200, 20);
        item->setTitle(label_w);
        if (run_env)
            item->setData(water);
        type_flag = false;
    }
}
