#include "Electric_Current.h"

void Electric_Current::Display_Electric_Current(int IsDynamics)
{
	// TODO: 在此处添加实现代码.
	if (IsDynamics == DYNAMICS)
		cout << this->GetIValid() << " " << this->GetTheta() << endl;
	else
		cout << this->GetIValid() << " " << this->GetInitialTheta() << endl;
}

void Electric_Current::Display_Electric_Current_complex()
{
	cout << I_Valid * cos(GetDataFromAngle(Theta.GetEpochAngle())) << "+" << I_Valid * sin(GetDataFromAngle(Theta.GetEpochAngle())) << "j" << endl;
}


AMPERE Electric_Current::GetIValid()
{
	// TODO: 在此处添加实现代码.
	return I_Valid;
}

AMPERE Electric_Current::GetIValid() const
{
	return I_Valid;
}


ANGLE Electric_Current::GetTheta()
{
	// TODO: 在此处添加实现代码.
	return Theta.ReturnAngleData();
}

ANGLE Electric_Current::GetInitialTheta()
{
	// TODO: 在此处添加实现代码.
	return Theta.GetEpochAngle();
}

ANGLE Electric_Current::GetInitialTheta() const
{
	return Theta.GetEpochAngle();;
}

complex<double> Electric_Current::ReturnIComplex() const
{
	return I_Complex;
}


// //获取电流的有效值
AMPERE Electric_Current::Getinstantvalue()
{
	// TODO: 在此处添加实现代码.
	return I_Valid * sqrt(2);
}

void Electric_Current::SubAngle(ANGLE Input)
{
	Theta.SubAngle(Input);
	RefreshIComplex();
}

void Electric_Current::AddAngle(ANGLE Input)
{
	Theta.AddAngle(Input);
	RefreshIComplex();
}

void Electric_Current::RefreshIComplex()
{
	I_Complex.real(I_Valid * Theta.ReturnComplex().real());
	I_Complex.imag(I_Valid * Theta.ReturnComplex().imag());
	FiltComplex(I_Complex);
}

Phasor_Angle Electric_Current::ReturnTheta() const
{
	return Theta;
}

Electric_Current& Electric_Current::operator=(const Electric_Current& Input)
{
	// TODO: 在此处插入 return 语句
	I_Valid = Input.GetIValid();
	Theta = Input.ReturnTheta();
	I_Complex = Input.ReturnIComplex();
	return *this;
}

Electric_Current Electric_Current::operator+(const Electric_Current& Input)
{
	I_Complex += Input.ReturnIComplex();
	FiltComplex(I_Complex);
	I_Valid = abs(I_Complex);
	Theta.SetEpochAngle(GetAngleFromData(arg(I_Complex)));
	return *this;
}

Electric_Current Electric_Current::operator-(const Electric_Current& Input)
{
	I_Complex -= Input.ReturnIComplex();
	FiltComplex(I_Complex);
	I_Valid = abs(I_Complex);
	Theta.SetEpochAngle(GetAngleFromData(arg(I_Complex)));
	return *this;
}

Electric_Current& Electric_Current::operator=(const complex<double>& Input)
{
	// TODO: 在此处插入 return 语句
	I_Valid = abs(Input);
	Theta.SetEpochAngle(arg(Input) * 180 / M_PI);
	I_Complex = Input;
	return *this;
}

Electric_Voltage Electric_Current::operator*(const Resistance_Impedance& Input)
{
	return I_Complex*Input.ReturnZComplex();
}

Electric_Current& Electric_Current::operator*(double Value)
{
	// TODO: 在此处插入 return 语句
	I_Complex *= Value;
	FiltComplex(I_Complex);
	I_Valid = abs(I_Complex);
	Theta.SetEpochAngle(GetAngleFromData(arg(I_Complex)));
	return *this;
}

Electric_Current& Electric_Current::operator/(double Value)
{
	I_Complex /= Value;
	FiltComplex(I_Complex);
	I_Valid = abs(I_Complex);
	Theta.SetEpochAngle(GetAngleFromData(arg(I_Complex)));
	return *this;
}

ANGLE CalCurrentPhasorDiff(const Electric_Current& Input_1, const Electric_Current& Input_2)
{
	return Input_1.GetInitialTheta()-Input_2.GetInitialTheta();
}

Electric_Current operator+(const Electric_Current& Input1, const Electric_Current& Input2)
{
	auto temp_complex=Input1.I_Complex +Input2.I_Complex;
	return Electric_Current(temp_complex);
}
