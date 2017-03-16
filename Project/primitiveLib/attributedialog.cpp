#include "attributedialog.h"
#include "ui_attributedialog.h"
#include <QColorDialog>

AttributeDialog::AttributeDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AttributeDialog), color(Qt::black)
{
    ui->setupUi(this);
}

AttributeDialog::~AttributeDialog()
{
    delete ui;
}

QString AttributeDialog::getName()
{
    return ui->name->text();
}

QString AttributeDialog::getOther()
{
    return ui->other->text();
}

QFont AttributeDialog::getFont()
{
    return ui->font->currentFont();
}

int AttributeDialog::getFontSize()
{
    return ui->font_size->text().toInt();
}

QColor AttributeDialog::getFontColor()
{
    return color;
}

void AttributeDialog::on_toolButton_clicked()
{
    color = QColorDialog::getColor(Qt::white, this);
}
