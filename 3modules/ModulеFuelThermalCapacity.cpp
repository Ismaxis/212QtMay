#include <iostream>
#include <vector>
#include "Sheet.h"
using namespace std;

//Т.к. перевод из СС не требудется, то функция считает как для газообразного, так и для жидкого
float FuelVolume(vector<float> Q, vector<float> C) {
	float fuelVolumeAll = 0;

	for (int i = 0; i < Q.size(); i++) {
		fuelVolumeAll += Q[i] * C[i];
	}
	return fuelVolumeAll;
}

//В функции учитывается вид топлива (газообразное топливо - 0, жидкое топливо - 1)
float FuelWeight(vector<float> Q, vector<float> C, vector<float> M, vector<float> n, vector<float> P, vector<float> fuel_type) {
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

//Значение не зависит от вида топлива, значит функция 1 для всех видов
float FuelRatio(vector<float> M, vector<float> K, vector<float> C) {
	float A = 0;
	for (int i = 0; i < M.size(); i++) {
		A = K[i] * C[i];
	}
	return (2 * A * 16 + 2 * 3.76 * A * 14) / M[0];
}

int main()
{
	setlocale(LC_ALL, "rus");

	Sheet excelTable;
	vector<float> Q, C, M, m, P, K, n, L, fuelType;


	excelTable.setPath("test.csv");

	const vector<vector<float>> measurements = excelTable.readAsFloat();

	for (const auto& measurement : measurements)
	{
		Q.push_back(measurement[0]);
		C.push_back(measurement[1]);
		M.push_back(measurement[2]);
		m.push_back(measurement[3]);
		P.push_back(measurement[4]);
		K.push_back(measurement[5]);
		n.push_back(measurement[6]);
		L.push_back(measurement[7]);
		fuelType.push_back(measurement[8]);
	}

	cout << "Объемная теплотворность топлива = " << FuelVolume(Q, C) << endl;
	cout << "Массовая теплотворность топлива = " << FuelWeight(Q, C, M, n, P, fuelType) << endl;

	cout << "Стереохимическое отношение = " << FuelRatio(M, K, C) << endl;

	return 0;
}
/*
Входные данные:
Таблица с данными. Таблица состоит из строк со значениями 
и разделенны запятыми.
в порядке: Q(дж/м^3), C(по объему), M, m, P, K, n, L, 
fuel_type(газообразное топливо - 0, жидкое топливо - 1)
Пример того как должна выглядеть таблица:
1,2,3,4,5,6,7,8,1
1,2,3,4,5,6,7,8,1
1,2,3,4,5,6,7,8,0

Выходные данные:
Функции fuel_volume, fuel_weight и fuel_ratio считают итоговую 
объемную теплотворность, массовую теплотворность и стереохимическое отношение соответственно
и выводят значение типа float.
*/