#include "capacitycalc.h"
#include "ui_capacitycalc.h"

CapacityCalc::CapacityCalc(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CapacityCalc)
{
    ui->setupUi(this);

    QPixmap pix;
    QDir dir("../212QtMay");
    QString s = dir.absoluteFilePath("icon.png");
    if(pix.load(s))
    {
        ui->icon->setPixmap(pix.scaled(ui->icon->size(),Qt::KeepAspectRatio));
    }
}

CapacityCalc::~CapacityCalc()
{
    delete ui;
}

void CapacityCalc::on_temp_button_clicked()
{
    TempCalc calcWin;
    calcWin.setWindowFlags(Qt::FramelessWindowHint);
    int result = calcWin.exec();
}

void CapacityCalc::on_end_button_clicked()
{
    EndCalc calcWin(this);
    calcWin.exec();
}

void CapacityCalc::on_during_button_clicked()
{
    DuringCalc calcWin;
    calcWin.setWindowFlags(Qt::FramelessWindowHint);
    int result = calcWin.exec();
}
