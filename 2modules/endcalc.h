#ifndef ENDCALC_H
#define ENDCALC_H

#include <QDialog>
#include "funcs.h"

#include "Table.h"
#include "storage.h"

extern Storage globalStorage;
extern Table table;

extern float RAir;
extern float RFuel;

namespace Ui {
class EndCalc;
}

class EndCalc : public QDialog
{
    Q_OBJECT

public:
    explicit EndCalc(QWidget *parent = nullptr);
    ~EndCalc();

private slots:
    void on_pb_calcAir_clicked();

    void on_radioButton_degree_clicked();

    void on_radioButton_work_clicked();

    void on_pb_calcFuel_clicked();

    void on_pb_calcMix_clicked();

private:
    Ui::EndCalc *ui;
};

#endif // ENDCALC_H
