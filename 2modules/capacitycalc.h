#ifndef CAPACITYCALC_H
#define CAPACITYCALC_H

#include <QDialog>
#include "tempcalc.h"
#include "endcalc.h"
#include "duringcalc.h"

namespace Ui {
class CapacityCalc;
}

class CapacityCalc : public QDialog
{
    Q_OBJECT

public:
    explicit CapacityCalc(QWidget *parent = nullptr);
    ~CapacityCalc();

private slots:
    void on_temp_button_clicked();

    void on_end_button_clicked();

    void on_during_button_clicked();

private:
    Ui::CapacityCalc *ui;
};

#endif // CAPACITYCALC_H
