#include "mainwindow.h"
#include "2modules/Table.h"
#include "storage.h"

#include <QApplication>

Storage globalStorage;
Table table;

float RFuel = 290.1;
float RAir = 287.0;

int main(int argc, char *argv[])
{
    globalStorage.set_a(3.0f); // 3 module work
    globalStorage.set_L0(15.0f);

    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
