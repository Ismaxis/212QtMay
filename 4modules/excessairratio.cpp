#include "excessairratio.h"
#include "ui_excessairratio.h"

extern Storage globalStorage;
extern Table table;

ExcessAirRatio::ExcessAirRatio(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ExcessAirRatio)
{
    ui->setupUi(this);

    QPixmap pix;
    QDir dir("../212QtMay");
    QString s = dir.absoluteFilePath("icon.png");
    if(pix.load(s))
    {
        ui->windowIcon->setPixmap(pix.scaled(ui->windowIcon->size(),Qt::KeepAspectRatio));
    }
    ui->L0LineEdit->setText(QString::number(globalStorage.get_L0()));
    ui->QnpmLineEdit->setText(QString::number(globalStorage.get_Q().Qnpm));
    if (ui->QnpmLineEdit->text() == "-1")
        ui->QnpmLineEdit->setText("nan");
}

ExcessAirRatio::~ExcessAirRatio()
{
    delete ui;
}


void ExcessAirRatio::on_exitpb_clicked()
{
    close();
}

void ExcessAirRatio::on_pb_calc_clicked()
{
    float TAirBegin = ui->lineEditAirBeginTemp->text().toFloat();
    float TAirEnd = ui->lineEditAirEndTemp->text().toFloat();
    float TFuelEnd = ui->lineEditFuelEndTemp->text().toFloat();
    float K = ui->KLineEdit->text().toFloat();
    float h = ui->HtopLineEdit->text().toFloat();
    float L0 = ui->L0LineEdit->text().toFloat();
    float Qnpm = ui->QnpmLineEdit->text().toFloat();
    if (ui->QnpmLineEdit->text() != "nan"){
        float A = alfa(TAirBegin, TAirEnd, TFuelEnd, K, h, L0, Qnpm);
        ui->alfaLabel->setText(QString::number(A));
        globalStorage.set_a(A);
    }
    else
        ui->alfaLabel->setText("nan");
}
