#include "capacitycalc.h"
#include "ui_capacitycalc.h"

CapacityCalc::CapacityCalc(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CapacityCalc)
{
    ui->setupUi(this);
}

CapacityCalc::~CapacityCalc()
{
    delete ui;
}
