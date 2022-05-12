#include "endcalc.h"
#include "ui_endcalc.h"

#include <QMessageBox>

EndCalc::EndCalc(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::EndCalc)
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

    ui->le_workAir->hide();
    ui->le_workFuel->hide();

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

EndCalc::~EndCalc()
{
    delete ui;
}


void EndCalc::on_pb_calcAir_clicked()
{
    if(ui->le_tempAir->text().isEmpty() || ui->le_degreeAir->text().isEmpty() || ui->le_workAir->text().isEmpty() && ui->radioButton_work->isChecked()|| ui->le_effAir->text().isEmpty() && ui->radioButton_degree->isChecked())
    {
        QMessageBox::warning(this, "Ошибка", "Введите данные");
        return;
    }

    float temp = ui->le_tempAir->text().toFloat();
    float degree = ui->le_degreeAir->text().toFloat();
    float work = ui->le_workAir->text().toFloat();
    float eff = ui->le_effAir->text().toFloat();

    if(eff > 1.0f || eff == 0.0f || temp < -100.f || degree < 0.0f || work < 0.0f)
    {
        QMessageBox::warning(this, "Ошибка", "Неверный данные");
        return;
    }

    TableData data = table.getData(temp, 0); // pmi always

    float Cstart = Cp(temp, data.cLow, data.cHigh, data.tLow, data.tHigh);

    float Tend = 0;
    if(ui->radioButton_degree->isChecked())
    {
        Tend = TendCompDegree(temp, degree, RAir, Cstart, eff);
    }
    else if(ui->radioButton_work->isChecked())
    {
        Tend = TendCompWork(temp, work, Cstart, eff);
    }

    if(Tend == -1.0f)
    {
        QMessageBox::warning(this, "Ошибка", "Неверный данные\nНе получилось вычислить");
        return;
    }

    ui->output_air->setText(QString::number(Tend));
    ui->le_capAir->setText(QString::number(Tend));
}

void EndCalc::on_pb_calcFuel_clicked()
{
    if(ui->le_tempFuel->text().isEmpty() || ui->le_degreeFuel->text().isEmpty() || ui->le_workFuel->text().isEmpty() && ui->radioButton_work->isChecked()|| ui->le_effFuel->text().isEmpty() && ui->radioButton_degree->isChecked())
    {
        QMessageBox::warning(this, "Ошибка", "Введите данные");
        return;
    }

    float temp = ui->le_tempFuel->text().toFloat();
    float degree = ui->le_degreeFuel->text().toFloat();
    float work = ui->le_workFuel->text().toFloat();
    float eff = ui->le_effFuel->text().toFloat();

    if(eff > 1.0f || eff == 0.0f || temp < -100.f || degree < 0.0f || work < 0.0f)
    {
        QMessageBox::warning(this, "Ошибка", "Неверный данные");
        return;
    }

    TableData data = table.getData(temp, 1); // pmi always

    float Cstart = Cp(temp, data.cLow, data.cHigh, data.tLow, data.tHigh);

    float Tend = 0;
    if(ui->radioButton_degree->isChecked())
    {
        Tend = TendExpDegree(temp, degree, RFuel, Cstart, eff);
    }
    else if(ui->radioButton_work->isChecked())
    {
        Tend = TendExpWork(temp, work, Cstart, eff);
    }

    if(Tend == -1.0f)
    {
        QMessageBox::warning(this, "Ошибка", "Неверный данные\nНе получилось вычислить");
        return;
    }

    ui->output_fuel->setText(QString::number(Tend));
    ui->le_capFuel->setText(QString::number(Tend));
}

void EndCalc::on_radioButton_degree_clicked()
{
    ui->le_degreeAir->show();
    ui->le_degreeFuel->show();
    ui->le_workAir->hide();
    ui->le_workFuel->hide();
}


void EndCalc::on_radioButton_work_clicked()
{
    ui->le_degreeAir->hide();
    ui->le_degreeFuel->hide();
    ui->le_workAir->show();
    ui->le_workFuel->show();
}

void EndCalc::on_pb_calcMix_clicked()
{
    if(local_a == -1)
    {
        QMessageBox::warning(this, "Ошибка", "Введите значение для alfa");
        return;
    }
    if(local_L0 == -1)
    {
        QMessageBox::warning(this, "Ошибка", "Введите значение для L0");
        return;
    }

    float CpAir = ui->le_capAir->text().toFloat();
    float CpFuel = ui->le_capFuel->text().toFloat();

    if(CpAir == 0.0f || CpFuel == 0.0f)
    {
        QMessageBox::warning(this, "Ошибка", "Введите теплоёмкости не посчитаны");
        return;
    }

    float CpMix = Cpmix(local_a, local_L0, CpAir, CpFuel); // a and L0 must takes from other module or FROM USER
    ui->output_mix->setText(QString::number(CpMix));
}


void EndCalc::on_pastePushButton_clicked()
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

