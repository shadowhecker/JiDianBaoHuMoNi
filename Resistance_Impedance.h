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
	double ReturnZValid()const;//返回阻抗的幅值
	double ReturnZValid();
	double ReturnR()const;//返回阻抗中的电阻值
	double ReturnR();
	double ReturnX()const;//返回阻抗中的电抗值
	double ReturnX();
	Resistance_Impedance& operator=(const complex<double> Data);
	Resistance_Impedance operator-(const Resistance_Impedance& Input);
	Resistance_Impedance operator/(const Resistance_Impedance& Input);
	void Display_Resistance_Impedance();//以复数形式展现阻抗
	void Display_Resistance_Impedance_Angle();//以角度形式展现阻抗
};

