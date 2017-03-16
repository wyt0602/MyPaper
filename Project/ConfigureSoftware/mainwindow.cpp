#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    filename("D:/data.dat")
{
    ui->setupUi(this);
    canvos = new Canvos(ui->widget);
    canvos->resize(1280, 720);
    canvos->loadPrimitive();
    list = canvos->getListWidget();
    list->resize(271, 441);
    list->setParent(ui->listWidget);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_export_2_triggered()
{
    canvos->savePrimitiveToFile(filename);
}
