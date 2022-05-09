#include "mainwindow.h"
#include "3modules/thermalcapacity.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pb_2_clicked()
{
    CapacityCalc calcWin;
    int result = calcWin.exec();
}


void MainWindow::on_pb_3_clicked()
{
    ThermalCapacity calcCnp;
    calcCnp.setModal(true);
    int resoult = calcCnp.exec();
}

