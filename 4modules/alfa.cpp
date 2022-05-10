#include "alfa.h"

float alfa(float TAirBegin, float TAirEnd, float TFuelEnd, float K, float h, float L0, float Qnpm){
    int pmiOrPms = 2;
    TableData dataAirBegin = table.getData(TAirBegin , 0, pmiOrPms);
    TableData dataAirEnd = table.getData(TAirEnd , 0, pmiOrPms);
    TableData dataFuelEnd = table.getData(TFuelEnd , 1, pmiOrPms);
    float CpmiAirBegin = CAvgpmi(dataAirBegin.tLow, dataAirBegin.tHigh, dataAirBegin.cLow, dataAirBegin.cHigh);
    float CpmiAirEnd= CAvgpmi(dataAirEnd.tLow, dataAirEnd.tHigh, dataAirEnd.cLow, dataAirEnd.cHigh);
    float CpmiFuelEnd= CAvgpmi(dataFuelEnd.tLow, dataFuelEnd.tHigh, dataFuelEnd.cLow, dataFuelEnd.cHigh);
    return (Qnpm * K - (1 + L0) * CpmiFuelEnd * TFuelEnd + L0 * CpmiAirEnd * TAirEnd + h) / (L0 * (CpmiAirEnd * TAirEnd - CpmiAirBegin * TAirBegin));
}

