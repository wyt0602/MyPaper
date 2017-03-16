#ifndef RUNSYSTEM_H
#define RUNSYSTEM_H

#include <QMainWindow>
#include "canvos.h"

namespace Ui {
class RunSystem;
}

class RunSystem : public QMainWindow
{
    Q_OBJECT

public:
    explicit RunSystem(QWidget *parent = 0);
    ~RunSystem();

private:
    Ui::RunSystem *ui;
    Canvos *canvos;
    QString filename;
};

#endif // RUNSYSTEM_H
