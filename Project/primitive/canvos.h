#ifndef CANVOS_H
#define CANVOS_H

#include <QWidget>

class Canvos : public QWidget
{
    Q_OBJECT
public:
    explicit Canvos(QWidget *parent = 0);

protected:
    void mousePressEvent(QMouseEvent *event);

signals:

public slots:

};

#endif // CANVOS_H
