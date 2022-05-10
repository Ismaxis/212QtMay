#ifndef EXCESSAIRRATIO_H
#define EXCESSAIRRATIO_H

#include <QDialog>

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

private:
    Ui::ExcessAirRatio *ui;
};

#endif // EXCESSAIRRATIO_H
