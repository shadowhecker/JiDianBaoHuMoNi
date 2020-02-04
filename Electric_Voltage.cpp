#include "Electric_Voltage.h"

void Electric_Voltage::Display_Electric_Voltage(int IsDynamics)
{
	// TODO: 在此处添加实现代码.
	if (IsDynamics == DYNAMICS)
		cout << this->GetVValid() << " " << this->GetTheta() << endl;
	else
		cout << this->GetVValid() << " " << this->GetInitialTheta() << endl;
}

void Electric_Voltage::Display_Electric_Voltage_complex()
{
	cout << V_Valid * cos(GetDataFromAngle(Theta.GetEpochAngle())) << "+" << V_Valid * sin(GetDataFromAngle(Theta.GetEpochAngle())) << "j" << endl;
}


VOLTAGE Electric_Voltage::GetVValid()
{
	// TODO: 在此处添加实现代码.
	return V_Valid;
}

VOLTAGE Electric_Voltage::GetVValid() const
{
	return V_Valid;
}


ANGLE Electric_Voltage::GetTheta()
{
	// TODO: 在此处添加实现代码.
	return Theta.ReturnAngleData();
}

ANGLE Electric_Voltage::GetInitialTheta()
{
	// TODO: 在此处添加实现代码.
	return Theta.GetEpochAngle();
}

ANGLE Electric_Voltage::GetInitialTheta() const
{
	return Theta.GetEpochAngle();;
}

complex<double> Electric_Voltage::ReturnVComplex() const
{
	return V_Complex;
}


// //获取电流的有效值
VOLTAGE Electric_Voltage::Getinstantvalue()
{
	// TODO: 在此处添加实现代码.
	return V_Valid / sqrt(2);
}

void Electric_Voltage::SubAngle(ANGLE Input)
{
	Theta.SubAngle(Input);
	RefreshVComplex();
}

void Electric_Voltage::AddAngle(ANGLE Input)
{
	Theta.AddAngle(Input);
	RefreshVComplex();
}

void Electric_Voltage::RefreshVComplex()
{
	V_Complex.real(V_Valid * Theta.ReturnComplex().real());
	V_Complex.imag(V_Valid * Theta.ReturnComplex().imag());
	FiltComplex(V_Complex);
}

Phasor_Angle Electric_Voltage::ReturnTheta() const
{
	return Theta;
}

Electric_Voltage& Electric_Voltage::operator=(const Electric_Voltage& Input)
{
	// TODO: 在此处插入 return 
	V_Valid = Input.GetVValid();
	Theta = Input.ReturnTheta();
	V_Complex = Input.ReturnVComplex();
	return *this;
}

Electric_Voltage Electric_Voltage::operator+(const Electric_Voltage& Input)
{
	V_Complex += Input.ReturnVComplex();
	FiltComplex(V_Complex);
	V_Valid = abs(V_Complex);
	Theta.SetEpochAngle(GetAngleFromData(arg(V_Complex)));
	return *this;
}

Electric_Voltage Electric_Voltage::operator-(const Electric_Voltage& Input)
{
	V_Complex -= Input.ReturnVComplex();
	FiltComplex(V_Complex);
	V_Valid = abs(V_Complex);
	Theta.SetEpochAngle(GetAngleFromData(arg(V_Complex)));
	return *this;
}

ANGLE CalCurrentPhasorDiff(const Electric_Voltage& Input_1, const Electric_Voltage& Input_2)
{
	return Input_1.GetInitialTheta() - Input_2.GetInitialTheta();
}

Electric_Voltage operator+(const Electric_Voltage& Input1, const Electric_Voltage& Input2)
{
	auto temp_complex = Input1.V_Complex + Input2.V_Complex;
	FiltComplex(temp_complex);
	return Electric_Voltage(temp_complex);
}

Resistance_Impedance Electric_Voltage::operator/(const Electric_Current& Input)
{
	return V_Complex / Input.ReturnIComplex();
}

Electric_Current Electric_Voltage::operator/(const Resistance_Impedance& Input)
{
	return V_Complex / Input.ReturnZComplex();
}

Electric_Voltage& Electric_Voltage::operator*(double Value)
{
	V_Complex *= Value;
	FiltComplex(V_Complex);
	V_Valid = abs(V_Complex);
	Theta.SetEpochAngle(GetAngleFromData(arg(V_Complex)));
	return *this;
}

Electric_Voltage& Electric_Voltage::operator/(double Value)
{
	V_Complex /= Value;
	FiltComplex(V_Complex);
	V_Valid = abs(V_Complex);
	Theta.SetEpochAngle(GetAngleFromData(arg(V_Complex)));
	return *this;
}
