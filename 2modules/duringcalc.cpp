#include "duringcalc.h"
#include "ui_duringcalc.h"

DuringCalc::DuringCalc(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DuringCalc)
{
    ui->setupUi(this);
    //icon
    QPixmap pix;
    QDir dir("../212QtMay");
    QString s = dir.absoluteFilePath("icon.png");
    if(pix.load(s))
    {
        ui->icon->setPixmap(pix.scaled(ui->icon->size(),Qt::KeepAspectRatio));
    }


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

DuringCalc::~DuringCalc()
{
    delete ui;
}

void DuringCalc::on_pb_calcAir_clicked()
{
    float tempStart = ui->le_tempStartAir->text().toFloat();
    float tempEnd = ui->le_tempEndAir->text().toFloat();

    int pmiOrPms = 2; // pmi default
    if(ui->radioButton_pms->isChecked())
    {
        pmiOrPms = 3;
    }

    TableData dataStart = table.getData(tempStart , 0, pmiOrPms);
    TableData dataEnd = table.getData(tempEnd , 0, pmiOrPms);

    float CpAirStart = Cp(tempStart, dataStart.cLow, dataStart.cHigh, dataStart.tLow, dataStart.tHigh);
    float CpAirEnd = Cp(tempStart, dataEnd.cLow, dataEnd.cHigh, dataEnd.tLow, dataEnd.tHigh);

    float CpAirAvg = CAvgpmi(tempStart, tempEnd, CpAirStart, CpAirEnd); // avg capacity of air during process

    ui->output_air->setText(QString::number(CpAirAvg));
    ui->le_capAir->setText(QString::number(CpAirAvg));
}


void DuringCalc::on_pb_calcFuel_clicked()
{
    float tempStart = ui->le_tempStartFuel->text().toFloat();
    float tempEnd = ui->le_tempEndFuel->text().toFloat();

    int pmiOrPms = 2; // pmi default
    if(ui->radioButton_pms->isChecked())
    {
        pmiOrPms = 3;
    }

    TableData dataStart = table.getData(tempStart , 1, pmiOrPms);
    TableData dataEnd = table.getData(tempEnd , 1, pmiOrPms);

    float CpFuelStart = Cp(tempStart, dataStart.cLow, dataStart.cHigh, dataStart.tLow, dataStart.tHigh);
    float CpFuelEnd = Cp(tempStart, dataEnd.cLow, dataEnd.cHigh, dataEnd.tLow, dataEnd.tHigh);

    float CpFuelAvg = CAvgpmi(tempStart, tempEnd, CpFuelStart, CpFuelEnd); // avg capacity of air during process

    ui->output_fuel->setText(QString::number(CpFuelAvg));
    ui->le_capFuel->setText(QString::number(CpFuelAvg));
}


void DuringCalc::on_pb_calcMix_clicked()
{
    if(local_a == -1)
    {
        QMessageBox::warning(this, "Error", "Enter value for alfa");
        return;
    }
    if(local_L0 == -1)
    {
        QMessageBox::warning(this, "Error", "Enter value for L0");
        return;
    }

    float CpAirAvg = ui->le_capAir->text().toFloat();
    float CpFuelAvg = ui->le_capFuel->text().toFloat();

    float CAvgMix = Cpmix(local_a, local_L0, CpAirAvg, CpFuelAvg); // avg capacity of mix during process

    ui->output_mix->setText(QString::number(CAvgMix));
}


void DuringCalc::on_pastePushButton_clicked()
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

