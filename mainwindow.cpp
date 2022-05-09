#include "mainwindow.h"
#include "3modules/thermalcapacity.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QPixmap pix;
    if(pix.load(QString::asprintf("D:/C++/Qt/212QtMay/icon.png")))
    {
        ui->icon->setPixmap(pix.scaled(ui->icon->size(),Qt::KeepAspectRatio));
    }
    if(pix.load(QString::asprintf("D:/C++/Qt/212QtMay/logo.png")))
    {
        ui->logo->setPixmap(pix.scaled(ui->logo->size(),Qt::KeepAspectRatio));
    }

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pb_2_clicked()
{
    CapacityCalc calcWin;
    calcWin.setWindowFlags(Qt::FramelessWindowHint);
    this->hide();
    int result = calcWin.exec();
    this->show();
}


void MainWindow::on_pb_3_clicked()
{
    ThermalCapacity calcCnp;
    calcCnp.setModal(true);
    int resoult = calcCnp.exec();
}

