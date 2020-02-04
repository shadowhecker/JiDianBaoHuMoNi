#pragma once
#include<iostream>
#include<complex>
#include<cmath>
#include"res.h"

using namespace std;
class Resistance_Impedance
{
private:
	complex<double> Z;
public:
	Resistance_Impedance() :Z(0) {}
	Resistance_Impedance(complex<double> Input) :Z(Input) {}
	Resistance_Impedance(double data1, double data2) :Z(data1* cos(data2 / 180 * M_PI), data1* sin(data2 / 180 * M_PI)) {}
	complex<double> ReturnZComplex();
	complex<double> ReturnZComplex()const;
	double ReturnZValid()const;//�����迹�ķ�ֵ
	double ReturnZValid();
	double ReturnR()const;//�����迹�еĵ���ֵ
	double ReturnR();
	double ReturnX()const;//�����迹�еĵ翹ֵ
	double ReturnX();
	Resistance_Impedance& operator=(const complex<double> Data);
	Resistance_Impedance operator-(const Resistance_Impedance& Input);
	Resistance_Impedance operator/(const Resistance_Impedance& Input);
	void Display_Resistance_Impedance();//�Ը�����ʽչ���迹
	void Display_Resistance_Impedance_Angle();//�ԽǶ���ʽչ���迹
};

