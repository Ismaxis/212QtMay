#include "tempcalc.h"
#include "ui_tempcalc.h"

TempCalc::TempCalc(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::TempCalc)
{
    ui->setupUi(this);

    if(!globalStorage.isEmpty_a())
    {
        local_a = globalStorage.get_a();
        ui->paste_a_lineEdit->setPlaceholderText(QString::number(local_a));
    }
    else
    {
        ui->paste_a_lineEdit->setPlaceholderText("Enter alfa");
        local_a = -1.0f;
    }

    if(!globalStorage.isEmpty_L0())
    {
        local_L0 = globalStorage.get_L0();
        ui->paste_L0_lineEdit->setPlaceholderText(QString::number(local_L0));
    }
    else
    {
        ui->paste_L0_lineEdit->setPlaceholderText("Enter L0");
        local_L0 = -1.0f;
    }
}

TempCalc::~TempCalc()
{
    delete ui;
}

void TempCalc::on_pb_calcAir_clicked()
{
    float temp = ui->le_air->text().toFloat();

    int pmiOrPms = 2; // pmi default
    if(ui->radioButton_pms->isChecked())
    {
        pmiOrPms = 3;
    }

    TableData data = table.getData(temp , 0, pmiOrPms);

    float CpAir = Cp(temp, data.cLow, data.cHigh, data.tLow, data.tHigh);
    ui->output_air->setText(QString::number(CpAir));
    ui->le_capAir->setText(QString::number(CpAir));
}

void TempCalc::on_pb_calcFuel_clicked()
{
    float temp = ui->le_fuel->text().toFloat();

    int pmiOrPms = 2; // pmi default
    if(ui->radioButton_pms->isChecked())
    {
        pmiOrPms = 3;
    }

    TableData data = table.getData(temp , 1, pmiOrPms);

    float CpFuel = Cp(temp, data.cLow, data.cHigh, data.tLow, data.tHigh);
    ui->output_fuel->setText(QString::number(CpFuel));
    ui->le_capFuel->setText(QString::number(CpFuel));
}

void TempCalc::on_pb_calcMix_clicked()
{
    float CpAir = ui->le_capAir->text().toFloat();
    float CpFuel = ui->le_capFuel->text().toFloat();

    float CpMix = Cpmix(local_a, local_L0, CpAir, CpFuel);

    ui->output_mix->setText(QString::number(CpMix));
}

void TempCalc::on_pastePushButton_clicked()
{
    if(ui->paste_a_lineEdit->text().isEmpty())
    {
        if(globalStorage.get_a() != -1.0f)
        {
            local_a = globalStorage.get_a();
        }
        else
        {
            QMessageBox::warning(this, "Error", "Enter value for alfa");
            return;
        }
    }
    else
    {
        local_a = ui->paste_a_lineEdit->text().toFloat();
    }
    ui->le_a->setText(QString::number(local_a));

    if(ui->paste_L0_lineEdit->text().isEmpty())
    {
        if(globalStorage.get_L0() != -1.0f)
        {
            local_L0 = globalStorage.get_L0();
        }
        else
        {
            QMessageBox::warning(this, "Error", "Enter value for L0");
            return;
        }
    }
    else
    {
        local_L0 = ui->paste_L0_lineEdit->text().toFloat();
    }
    ui->le_L0->setText(QString::number(local_L0));
}
