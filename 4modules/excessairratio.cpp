#include "excessairratio.h"
#include "ui_excessairratio.h"
#include <QDir>
ExcessAirRatio::ExcessAirRatio(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ExcessAirRatio)
{
    ui->setupUi(this);

    QPixmap pix;
    QDir dir("../212QtMay");
    QString s = dir.absoluteFilePath("icon.png");
    if(pix.load(s))
    {
        ui->windowIcon->setPixmap(pix.scaled(ui->windowIcon->size(),Qt::KeepAspectRatio));
    }
}

ExcessAirRatio::~ExcessAirRatio()
{
    delete ui;
}


void ExcessAirRatio::on_exitpb_clicked()
{
    close();
}
