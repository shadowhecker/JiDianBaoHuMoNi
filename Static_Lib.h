#pragma once
#include"res.h"
#include"Phasor_Angle.h"

using namespace std;
double GetDataFromAngle(double InputData);
double GetAngleFromData(double InputData);//����һ���ǶȻ����ֵ(�������ֵ��ΪPI/2��������90)
void FiltComplex(complex<double>& Data);//����double�ľ���̫�ߵ��¼�������и�������ַǳ�С��ֵ�������ô˺�������
