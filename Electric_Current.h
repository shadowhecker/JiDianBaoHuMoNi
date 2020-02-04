#pragma once
#include"Phasor_Angle.h"//包含向量角度类
#include"res.h"
#include"Electric_Voltage.h"
#include"Resistance_Impedance.h"
#include"Static_Lib.h"
using namespace std;

class Electric_Voltage;
class Electric_Current
{
public:
	Electric_Current() :Theta(0) { I_Valid = 0; I_Complex = I_Valid * Theta.ReturnComplex(); }
	Electric_Current(AMPERE I_Input, double Angle_Input) :Theta(Angle_Input) 
	{
		I_Valid = I_Input; I_Complex = I_Valid * Theta.ReturnComplex();
	}
	Electric_Current(complex<double> CurrentComplexData) :I_Valid(abs(CurrentComplexData)), Theta(arg(CurrentComplexData) * 180 / M_PI), I_Complex(CurrentComplexData) {}
private:
	AMPERE I_Valid;//电流的有效值
	Phasor_Angle Theta;//电流的向量
	complex<double> I_Complex;//电流的复数形式
public:
	void Display_Electric_Current(int IsDynamics);
	void Display_Electric_Current_complex();//以复数的形式显示电流量
	AMPERE GetIValid();//返回电流幅值
	AMPERE GetIValid() const;
	ANGLE GetTheta() ;//在旋转的情况下返回电流角度，角度随时间一直在变
	ANGLE GetInitialTheta();//在相对零度静止条件下返回电流角度
	ANGLE GetInitialTheta()const;
	complex<double> ReturnIComplex() const;//获得电流的复数形式
	AMPERE Getinstantvalue();//获取电流的有效值
	friend ANGLE CalCurrentPhasorDiff(const Electric_Current& Input_1, const Electric_Current& Input_2);//计算两个电流的相位差
	void SubAngle(ANGLE Input);//电流向量滞后
	void AddAngle(ANGLE Input);//电流向前旋转
	void RefreshIComplex();//由于角度变化需要更新向量形式
	Phasor_Angle ReturnTheta() const;//返回电流的向量
	Electric_Current& operator=(const Electric_Current& Input);//赋值运算符
	Electric_Current operator+(const Electric_Current& Input);//电流向量相加
	friend Electric_Current operator+(const Electric_Current& Input1, const Electric_Current& Input2);
	Electric_Current operator-(const Electric_Current& Input);//电流向量相减
	Electric_Current& operator=(const complex<double>& Input);
	Electric_Voltage operator*(const Resistance_Impedance& Input);//求电压
	Electric_Current& operator*(double Value);//电流幅值乘以一个倍数
	Electric_Current& operator/(double Value);//电流幅值除以一个倍数
	
};




