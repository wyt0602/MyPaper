#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    //ui->setupUi(this);
    this->resize(800, 800);
    //setCentralWidget(ui->mdiArea);
    //qDebug() << mapToGlobal(ui->mdiArea->pos());
//    QMdiSubWindow *child1 = new Primitive(ui->mdiArea);
//    QMdiSubWindow *child2 = new Primitive(ui->mdiArea);
//    ui->mdiArea->addSubWindow(child1);
//    ui->mdiArea->addSubWindow(child2);
//    ui->mdiArea->resize(800, 800);
//    ui->mdiArea->hide();
    main_widget = new Canvos(this);
    main_widget->resize(900, 900);
    Primitive *child1 = new Primitive(main_widget);
    Primitive *child2 = new Primitive(main_widget);
    Primitive *child3 = new Primitive(main_widget);
    Primitive *child4 = new Primitive(main_widget);
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

void MainWindow::mouseDoubleClickEvent(QMouseEvent *)
{
    main_widget->show();
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
