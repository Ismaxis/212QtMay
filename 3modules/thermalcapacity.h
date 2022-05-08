#ifndef THERMALCAPACITY_H
#define THERMALCAPACITY_H

#include <QDialog>
#include "storage.h"

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

private:
    Ui::ThermalCapacity *ui;
};

#endif // THERMALCAPACITY_H
