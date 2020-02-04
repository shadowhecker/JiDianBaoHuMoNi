#include "Resistance_Impedance.h"

complex<double> Resistance_Impedance::ReturnZComplex()
{
	return Z;
}

complex<double> Resistance_Impedance::ReturnZComplex() const
{
	return Z;
}

double Resistance_Impedance::ReturnZValid() const
{
	return abs(Z);
}

double Resistance_Impedance::ReturnZValid()
{
	return abs(Z);
}

double Resistance_Impedance::ReturnR() const
{
	return Z.real();
}

double Resistance_Impedance::ReturnR()
{
	return Z.real();
}

double Resistance_Impedance::ReturnX() const
{
	return Z.imag();
}

double Resistance_Impedance::ReturnX()
{
	return Z.imag();
}

Resistance_Impedance& Resistance_Impedance::operator=(const complex<double> Data)
{
	Z = Data;
	return *this;
}

Resistance_Impedance Resistance_Impedance::operator-(const Resistance_Impedance& Input)
{
	return Z - Input.ReturnZComplex();
}

Resistance_Impedance Resistance_Impedance::operator/(const Resistance_Impedance& Input)
{
	return Z / Input.ReturnZComplex();
}

void Resistance_Impedance::Display_Resistance_Impedance()
{
	cout << Z.real() << "+" << Z.imag() << "j" << endl;
}

void Resistance_Impedance::Display_Resistance_Impedance_Angle()
{
	cout << abs(Z) << " " << arg(Z) * 180 / M_PI << endl;
}

