#ifndef FUNCSTHERMALCAPACITY_H
#define FUNCSTHERMALCAPACITY_H

#include <QVector>
#include "../Sheet.h"

class FuncsThermalCapacity
{
public:
    FuncsThermalCapacity();

    float FuelVolume(std::vector<float> Q, std::vector<float> C);

    float FuelWeight(std::vector<float> Q, std::vector<float> C, std::vector<float> M, std::vector<float> n, std::vector<float> P);

    float FuelRatio(std::vector<float> M, std::vector<float> K, std::vector<float> C);
};

#endif // FUNCSTHERMALCAPACITY_H
