#ifndef THERMALCAPACITY_H
#define THERMALCAPACITY_H

#include <QDialog>
#include "storage.h"
#include "../Sheet.h"
#include "funcsthermalcapacity.h"

extern Storage globalStorage;

namespace Ui {
class ThermalCapacity;
}

class ThermalCapacity : public QDialog
{
    Q_OBJECT

public:
    explicit ThermalCapacity(QWidget *parent = nullptr);
    ~ThermalCapacity();

private slots:
    void on_CalcL0_clicked();

    void on_CalcQnpV_2_clicked();

    void on_CalcQnpm_clicked();

private:
    Ui::ThermalCapacity *ui;
    std::vector<float> Q, C, M, m, P, K, n, L, fuelType;
    float QnpV, Qnpm, L0;
    FuncsThermalCapacity ThermalCapacityFunc;
};

#endif // THERMALCAPACITY_H
