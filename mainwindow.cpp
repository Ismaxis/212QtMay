#include "mainwindow.h"
#include "3modules/thermalcapacity.h"
#include "4modules/excessairratio.h"
#include "ui_mainwindow.h"
#include <QDir>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QPixmap pix;
    QDir dir("../212QtMay");
    QString s = dir.absoluteFilePath("icon.png");
    if(pix.load(s))
    {
        ui->icon->setPixmap(pix.scaled(ui->icon->size(),Qt::KeepAspectRatio));
    }
    s = dir.absoluteFilePath("logo.png");
    if(pix.load(s))
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
    calcCnp.setWindowFlags(Qt::FramelessWindowHint);
    this->hide();
    int result = calcCnp.exec();
    this->show();
}


void MainWindow::on_pb_4_clicked()
{
    ExcessAirRatio calcAlfa;
    calcAlfa.setWindowFlags(Qt::FramelessWindowHint);
    this->hide();
    int result = calcAlfa.exec();
    this->show();
}

void MainWindow::mousePressEvent(QMouseEvent* event)
{
    curPos = event->globalPos();
}

void MainWindow::mouseMoveEvent(QMouseEvent* event)
{
    posChange = event->globalPos() - curPos;
    move(x() + posChange.x(), y() + posChange.y());
    curPos = event->globalPos();
}
