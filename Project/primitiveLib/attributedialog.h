#ifndef ATTRIBUTEDIALOG_H
#define ATTRIBUTEDIALOG_H

#include <QDialog>

namespace Ui {
class AttributeDialog;
}

class AttributeDialog : public QDialog
{
    Q_OBJECT

public:
    explicit AttributeDialog(QWidget *parent = 0);
    ~AttributeDialog();
    QString getName();
    QString getOther();
    QFont getFont();
    int getFontSize();
    QColor getFontColor();

private slots:
    void on_toolButton_clicked();

private:
    Ui::AttributeDialog *ui;
    QColor color;
};

#endif // ATTRIBUTEDIALOG_H
