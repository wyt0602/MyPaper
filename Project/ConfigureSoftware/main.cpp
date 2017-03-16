#include "mainwindow.h"
#include "runsystem.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    //RunSystem w;
    MainWindow w;
    w.show();

    return a.exec();
}
