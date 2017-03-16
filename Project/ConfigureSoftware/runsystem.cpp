#include "runsystem.h"
#include "ui_runsystem.h"
#include <QDebug>

RunSystem::RunSystem(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::RunSystem),
    filename("D:/data.dat")
{
    ui->setupUi(this);
    ui->tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->tableWidget_2->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    qDebug() << ui->widget->height() << ui->widget->width();
    canvos = new Canvos(ui->widget);
    canvos->resize(1280, 720);
    canvos->loadPrimitiveFromFile(filename);
}

RunSystem::~RunSystem()
{
    delete ui;
}
