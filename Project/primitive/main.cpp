#include "mainwindow.h"
#include <QApplication>
#include "primitive.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
//    Primitive my_widget;
//    my_widget.show();
    MainWindow w;
    w.show();

    return a.exec();
}
