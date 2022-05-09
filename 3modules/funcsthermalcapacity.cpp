#include "funcsthermalcapacity.h"


FuncsThermalCapacity::FuncsThermalCapacity()
{

}

float FuncsThermalCapacity::FuelVolume(std::vector<float> Q, std::vector<float> C) {
    float fuelVolumeAll = 0;

    for (int i = 0; i < Q.size(); i++) {
        fuelVolumeAll += Q[i] * C[i];
    }
    return fuelVolumeAll;
}
float FuncsThermalCapacity::FuelWeight(std::vector<float> Q, std::vector<float> C, std::vector<float> M, std::vector<float> n, std::vector<float> P, std::vector<float> fuel_type) {
    float fuelWeightAll = 0, mAll = 0,
        Qi, mi, Ci;

    for (int i = 0; i < Q.size(); i++) {
        if (fuel_type[i] == 0.0f) {
            mAll += M[i] * C[i];
        }
    }

    for (int i = 0; i < Q.size(); i++) {
        //Если топливо газообразное

        if (fuel_type[i] == 0.0f) {
            mi = M[i] * n[i];
            Qi = Q[i] / mi;
            Ci = C[i] * (M[i] / mAll);

            fuelWeightAll += Qi * Ci;
        }
        //Если топливо жидкое
        if (fuel_type[i] == 1.0f) {
            Qi = Q[i] / P[i];//Перевод из дж/м^3 в Дж/кг
            fuelWeightAll += + Qi * C[i];

        }
    }
    return fuelWeightAll;
}
float FuncsThermalCapacity::FuelRatio(std::vector<float> M, std::vector<float> K, std::vector<float> C) {
    float A = 0;
    for (int i = 0; i < M.size(); i++) {
        A = K[i] * C[i];
    }
    return (2 * A * 16 + 2 * 3.76 * A * 14) / M[0];
}
