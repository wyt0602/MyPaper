#ifndef CANVOS_H
#define CANVOS_H

#include <QWidget>
#include <QLibrary>
#include "primitive.h"
#include "projectlistwidget.h"

class Canvos : public QWidget
{
    Q_OBJECT
public:
    explicit Canvos(QWidget *parent = 0);
    void init();
    void loadPrimitive();
    void savePrimitiveToFile(QString &filename);
    void loadPrimitiveFromFile(QString &filename);
    QMap<int, Primitive*>& getPrimitiveSet();
    QList<Primitive*>& getCurrentPrimitive();
    ProjectListWidget *getListWidget();


protected:
    void mousePressEvent(QMouseEvent *event);
    void dragEnterEvent(QDragEnterEvent *event);
    void dragMoveEvent(QDragMoveEvent *event);
    void dropEvent(QDropEvent *event);

    void setData(Primitive *item);

signals:

public slots:

private:
    QLibrary *lib;
    QMap<int, Primitive*> primitives;
    QList<Primitive*> cur_pri;
    ProjectListWidget *list;

    bool type_flag;
    bool run_env;
};

#endif // CANVOS_H
