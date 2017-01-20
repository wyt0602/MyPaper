#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->resize(800, 800);
    setCentralWidget(ui->mdiArea);
    //qDebug() << mapToGlobal(ui->mdiArea->pos());
    QMdiSubWindow *child1 = new Primitive(ui->mdiArea);
    QMdiSubWindow *child2 = new Primitive(ui->mdiArea);
    ui->mdiArea->addSubWindow(child1);
    ui->mdiArea->addSubWindow(child2);
    //ui->mdiArea->addSubWindow(my_widget);
    //setCentralWidget(my_widget);
    //my_widget->show();
}

MainWindow::~MainWindow()
{
    delete ui;
}
