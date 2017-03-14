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


private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::MainWindow *ui;
    Canvos *main_widget;
    Primitive *my_widget;
    Canvos *canvos;
    QString filename;
};

#endif // MAINWINDOW_H
