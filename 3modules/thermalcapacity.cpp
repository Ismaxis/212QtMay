#include "thermalcapacity.h"
#include "ui_ThermalCapacity.h"
#include "funcsthermalcapacity.h"
#include "storage.h"

ThermalCapacity::ThermalCapacity(QWidget *parent):
    QDialog(parent),
    ui(new Ui::ThermalCapacity)
{
    ui->setupUi(this);
}


//QnpV, Qnpm, L0;

ThermalCapacity::~ThermalCapacity()
{
    delete ui;
}

void ThermalCapacity::on_CalcL0_clicked()
{
    Sheet excelTable;
    std::vector<float> Q, C, M, m, P, K, n, L, fuelType;
    excelTable.setPath("test.csv");
    const std::vector<std::vector<float>> measurements = excelTable.readAsFloat();
    float L0;
    FuncsThermalCapacity ThermalCapacity;

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

    L0 = ThermalCapacity.FuelRatio(M, K, C);
    globalStorage.set_L0(L0);

    ui->PrintL0->setNum(L0);
}


