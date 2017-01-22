#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "primitive.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

protected:
    void mouseDoubleClickEvent(QMouseEvent *);


private:
    Ui::MainWindow *ui;
    QWidget *main_widget;
    Primitive *my_widget;
};

#endif // MAINWINDOW_H
