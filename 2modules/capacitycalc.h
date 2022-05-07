#ifndef CAPACITYCALC_H
#define CAPACITYCALC_H

#include <QDialog>

namespace Ui {
class CapacityCalc;
}

class CapacityCalc : public QDialog
{
    Q_OBJECT

public:
    explicit CapacityCalc(QWidget *parent = nullptr);
    ~CapacityCalc();

private:
    Ui::CapacityCalc *ui;
};

#endif // CAPACITYCALC_H
