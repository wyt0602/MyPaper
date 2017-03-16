#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "canvos.h"
#include "projectlistwidget.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_export_2_triggered();

private:
    Ui::MainWindow *ui;
    Canvos *canvos;
    ProjectListWidget *list;
    QString filename;
};

#endif // MAINWINDOW_H
