#ifndef TEMPCALC_H
#define TEMPCALC_H

#include <QDialog>
#include "funcs.h"
#include "Table.h"
#include "storage.h"

extern Storage globalStorage;
extern Table table;

extern float RFuel;
extern float RAir;

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
