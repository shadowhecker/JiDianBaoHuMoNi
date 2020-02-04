#pragma once
#include"Electric_Current.h"
#include"Resistance_Impedance.h"
#include "res.h"
#include"Static_Lib.h"
using namespace std;

class Electric_Current;
class Electric_Voltage
{
public:
	Electric_Voltage() :Theta(0) { V_Valid = 0; V_Complex = V_Valid * Theta.ReturnComplex(); }
	Electric_Voltage(VOLTAGE V_Input, double Angle_Input) :Theta(Angle_Input)
	{
		V_Valid = V_Input; V_Complex = V_Valid * Theta.ReturnComplex();
	}
	Electric_Voltage(complex<double> CurrentComplexData) :V_Valid(abs(CurrentComplexData)), Theta(arg(CurrentComplexData) * 180 / M_PI), V_Complex(CurrentComplexData) {}
private:
	VOLTAGE V_Valid;//电压的有效值
	Phasor_Angle Theta;//电压的向量
	complex<double> V_Complex;//电压的复数形式
public:
	void Display_Electric_Voltage(int IsDynamics);
	void Display_Electric_Voltage_complex();//以复数的形式显示电压量
	VOLTAGE GetVValid();//返回电压幅值
	VOLTAGE GetVValid() const;
	ANGLE GetTheta();//在旋转的情况下返回电压角度，角度随时间一直在变
	ANGLE GetInitialTheta();//在相对零度静止条件下返回电压角度
	ANGLE GetInitialTheta()const;
	complex<double> ReturnVComplex() const;//获得电压的复数形式
	VOLTAGE Getinstantvalue();//获取电压的有效值
	friend ANGLE CalCurrentPhasorDiff(const Electric_Voltage& Input_1, const Electric_Voltage& Input_2);//计算两个电压的相位差
	void SubAngle(ANGLE Input);//电压向量滞后
	void AddAngle(ANGLE Input);//电压向前旋转
	void RefreshVComplex();//由于角度变化需要更新向量形式
	Phasor_Angle ReturnTheta() const;//返回电压的向量
	Electric_Voltage& operator=(const Electric_Voltage& Input);//赋值运算符
	Electric_Voltage operator+(const Electric_Voltage& Input);//电压向量相加
	friend Electric_Voltage operator+(const Electric_Voltage& Input1, const Electric_Voltage& Input2);
	Electric_Voltage operator-(const Electric_Voltage& Input);//电压向量相减
	Resistance_Impedance operator/(const Electric_Current& Input);//求阻抗
	Electric_Current operator/(const Resistance_Impedance& Input);//求电流
	Electric_Voltage& operator*(double Value);//乘以幅值倍数
	Electric_Voltage& operator/(double Value);//幅值除以一个倍数
};


