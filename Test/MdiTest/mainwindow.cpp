#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QLabel>
#include <QDialog>
#include <QMdiSubWindow>
#include "dialog.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    mdiArea = new QMdiArea(ui->widget);
    mdiArea->setHorizontalScrollBarPolicy(Qt::ScrollBarAsNeeded);
    mdiArea->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);
    //mdiArea->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    //mdiArea->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    mdiArea->setBaseSize(800, 800);
    mdiArea->setSizeAdjustPolicy(QAbstractScrollArea::AdjustIgnored);
    setCentralWidget(mdiArea);
//    QMdiSubWindow *child1 = new QMdiSubWindow;
//    child1->setWidget(new Dialog);
//    child1->setWindowFlags(Qt::CustomizeWindowHint);
//    child1->setWindowOpacity(0.4);
//    mdiArea->addSubWindow(child1);
//    QMdiSubWindow *child2 = new QMdiSubWindow;
//    child2->setWidget(new Dialog);
//    mdiArea->addSubWindow(child2);

    QMdiSubWindow *child1 = new Dialog(mdiArea);
    mdiArea->addSubWindow(child1);
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}
