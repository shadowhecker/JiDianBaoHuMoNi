#pragma once
#include"res.h"
#include"Phasor_Angle.h"

using namespace std;
double GetDataFromAngle(double InputData);
double GetAngleFromData(double InputData);//输入一个角度获得数值(例如该数值用为PI/2，而不是90)
void FiltComplex(complex<double>& Data);//由于double的精度太高导致计算过程中复数会出现非常小的值，所以用此函数归零
