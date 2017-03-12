#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "primitive.h"
#include "canvos.h"

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
    void mousePressEvent(QMouseEvent *event);


private slots:
    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;
    Canvos *main_widget;
    Primitive *my_widget;
};

#endif // MAINWINDOW_H
