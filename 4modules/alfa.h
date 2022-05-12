#ifndef ALFA_H
#define ALFA_H
#include "storage.h"
#include "Table.h"
#include "2modules/funcs.h"


extern Storage globalStorage;
extern Table table;


float alfa(float TAirBegin, float TAirEnd, float TFuelEnd, float K, float h, float L0, float Qnpm);

#endif // ALFA_H
