#include <QDir>
#include "thermalcapacity.h"
#include "ui_ThermalCapacity.h"


ThermalCapacity::ThermalCapacity(QWidget *parent):
    QDialog(parent),
    ui(new Ui::ThermalCapacity)
{
    ui->setupUi(this);

    Sheet excelTable;
    QDir dir("../212QtMay/tables");
    excelTable.setPath((dir.absoluteFilePath("test.csv").toStdString()));
    auto measurements = excelTable.readAsFloat();
    for (const auto& measurement : measurements)
        {
            Q.push_back(measurement[0]);
            C.push_back(measurement[1]);
            M.push_back(measurement[2]);
            m.push_back(measurement[3]);
            P.push_back(measurement[4]);
            K.push_back(measurement[5]);
            n.push_back(measurement[6]);
            L.push_back(measurement[7]);
            fuelType.push_back(measurement[8]);
        }
}

ThermalCapacity::~ThermalCapacity()
{
    delete ui;
}

void ThermalCapacity::on_CalcL0_clicked()
{
    L0 = ThermalCapacityFunc.FuelRatio(M, K, C);
    globalStorage.set_L0(L0);
    ui->PrintL0->setNum(L0);
}



void ThermalCapacity::on_CalcQnpV_2_clicked()
{
    QnpV = ThermalCapacityFunc.FuelVolume(Q, C);
    globalStorage.set_QnpV(QnpV);
    ui->PrintQnpV->setNum(QnpV);
}


void ThermalCapacity::on_CalcQnpm_clicked()
{
    Qnpm = ThermalCapacityFunc.FuelWeight(Q, C, M, n, P, fuelType);
    globalStorage.set_Qnpm(Qnpm);
    ui->PrintQnpm->setNum(Qnpm);
}

