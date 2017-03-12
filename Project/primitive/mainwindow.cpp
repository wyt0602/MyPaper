#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QLibrary>
#include <QListWidget>
#include <QListWidgetItem>
#include <QDialog>
#include <QLineEdit>
#include <QMapIterator>

#include "primitive.h"
#include "projectlistwidget.h"

typedef Primitive* (*func) (QWidget*);
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->resize(1200, 1200);
    ProjectListWidget *list = ui->listWidget;
    Canvos *canvos = ui->canvos_widget;
    canvos->resize(1000, 1000);
    Primitive *test = new Primitive(canvos);
    canvos->loadPrimitive();
    QMap<int, Primitive*> &primitive_set = canvos->getPrimitiveSet();
    list->setIconSize(QSize(50,50));
    //setCentralWidget(ui->mdiArea);
    //qDebug() << mapToGlobal(ui->mdiArea->pos());
//    QMdiSubWindow *child1 = new Primitive(ui->mdiArea);
//    QMdiSubWindow *child2 = new Primitive(ui->mdiArea);
//    ui->mdiArea->addSubWindow(child1);
//    ui->mdiArea->addSubWindow(child2);
//    ui->mdiArea->resize(800, 800);
//    ui->mdiArea->hide();
//    main_widget = new Canvos(this);
//    main_widget->setStyleSheet("border:1px solid rgb(0, 0, 0);background-color:rgb(22,23,214)");
//    main_widget->loadPrimitive();
//    QMap<int, Primitive*> &primitive_set = main_widget->getPrimitiveSet();
//    main_widget->resize(900, 900);
//    //QVector<func> primitives;
//    ProjectListWidget *list = new ProjectListWidget(ui->list_widget);
//    list->setIconSize(QSize(50, 50));
    //QLibrary lib("D:/primitiveLib.dll");
    //func f = (func)lib.resolve("getTankPrimitive");

//    func f1 = (func)lib.resolve("getFirePrimitive");
//    func f2 = (func)lib.resolve("getHorizontalPipePrimitive");
//    func f3 = (func)lib.resolve("getTeePrimitive");
//    func f4 = (func)lib.resolve("getVerticalPrimitive");
//    primitives.push_back((func)lib.resolve("getTankPrimitive"));
//    primitives.push_back((func)lib.resolve("getHorizontalPipePrimitive"));
//    primitives.push_back((func)lib.resolve("getFirePrimitive"));
//    primitives.push_back((func)lib.resolve("getTeePrimitive"));
//    primitives.push_back((func)lib.resolve("getVerticalPrimitive"));
//    primitives.push_back((func)lib.resolve("getCurvePrimitive"));
//    primitives.push_back((func)lib.resolve("getBuildingPrimitive"));
//    primitives.push_back((func)lib.resolve("getElevatedTankPrimitive"));
//    primitives.push_back((func)lib.resolve("getPalmTreePrimitive"));

    QMapIterator<int, Primitive*> it(primitive_set);
    while (it.hasNext())
    {
        it.next();
        QListWidgetItem *item = it.value()->getListWidgetItem();
        item->setWhatsThis(QString("%1").arg(it.key()));
        item->setSizeHint(QSize(70, 70));
        list->addItem(item);
    }
//    for(auto f : primitives)
//    {
//        Primitive *child = f(main_widget);
//        //child->adjustPosition(QPoint(70, 200));
//        QListWidgetItem *item = child->getListWidgetItem();
//        item->setSizeHint(QSize(70, 70));
//        list->addItem(item);
//    }


//    Primitive *child = f(main_widget);
//    Primitive *child1 = f1(main_widget);
//    Primitive *child2 = f2(main_widget);
//    Primitive *child3 = f3(main_widget);
//    Primitive *child4 = f(main_widget);

//    QListWidgetItem *item = child->getListWidgetItem();
//    QListWidgetItem *item1 = child1->getListWidgetItem();
//    QListWidgetItem *item2 = child2->getListWidgetItem();
//    QListWidgetItem *item3 = child3->getListWidgetItem();
//    QListWidgetItem *item4 = child4->getListWidgetItem();

//    item->setSizeHint(QSize(70,70));
//    item1->setSizeHint(QSize(70,70));
//    item2->setSizeHint(QSize(70,70));
//    item3->setSizeHint(QSize(70,70));

    //item->setTextAlignment(Qt::AlignVCenter | Qt::AlignLeft);
    //item1->setTextAlignment(Qt::AlignCenter);
    //item2->setTextAlignment(Qt::AlignCenter);


    //list->setViewMode(QListView::ListMode);
//    list->addItem(item);
//    list->addItem(item1);
//    list->addItem(item2);
//    list->addItem(item3);

    //setCentralWidget(list);
    //Primitive *child1 = new Primitive(main_widget);
    //Primitive *child2 = new Primitive(main_widget);
    //Primitive *child3 = new Primitive(main_widget);
    //Primitive *child4 = new Primitive(main_widget);
    //main_widget->hide();
    //ui->mdiArea->hide();
    //qDebug() << ui->widget->height();
    //main_widget->show();
    //child1->show();
    //child2->show();
    //ui->mdiArea->show();
    //ui->mdiArea->addSubWindow(my_widget);
    //setCentralWidget(my_widget);
    //my_widget->show();
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::mousePressEvent(QMouseEvent *event)
{
    if (main_widget->hasFocus())
    {
        QObjectList children = main_widget->children();

        for (auto child : children)
        {
            Primitive *p = (Primitive *)child;
            p->setStyleSheet("border:0px dotted rgb(0, 0, 0);background-color:rgba(0,0,0,0)");
        }
    }
}

void MainWindow::on_pushButton_clicked()
{
    qDebug() << "double";
    ui->canvos_widget->loadPrimitive();
    QMap<int, Primitive*> &primitive_set = ui->canvos_widget->getPrimitiveSet();
    for(auto item : primitive_set)
        item->show();
}
