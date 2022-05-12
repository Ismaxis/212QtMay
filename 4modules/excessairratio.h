#ifndef EXCESSAIRRATIO_H
#define EXCESSAIRRATIO_H

#include <QDialog>
#include <QDir>
#include "storage.h"
#include "Table.h"
#include "alfa.h"
#include "2modules/funcs.h"
namespace Ui {
class ExcessAirRatio;
}

class ExcessAirRatio : public QDialog
{
    Q_OBJECT

public:
    explicit ExcessAirRatio(QWidget *parent = nullptr);
    ~ExcessAirRatio();

private slots:
    void on_exitpb_clicked();

    void on_pb_calc_clicked();

private:
    Ui::ExcessAirRatio *ui;
};

#endif // EXCESSAIRRATIO_H
