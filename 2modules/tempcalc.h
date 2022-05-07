#ifndef TEMPCALC_H
#define TEMPCALC_H

#include <QDialog>
#include "Table.h"
#include "funcs.h"

extern Table table;

extern float RFuel;
extern float RAir;
extern float a;
extern float L0;

namespace Ui {
class TempCalc;
}

class TempCalc : public QDialog
{
    Q_OBJECT

public:
    explicit TempCalc(QWidget *parent = nullptr);
    ~TempCalc();

private slots:
    void on_pb_calcAir_clicked();

    void on_pb_calcFuel_clicked();

    void on_pb_calcMix_clicked();

private:
    Ui::TempCalc *ui;
};

#endif // TEMPCALC_H
