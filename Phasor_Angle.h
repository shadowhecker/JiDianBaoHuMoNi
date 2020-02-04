#pragma once
#include"res.h"
#include"Static_Lib.h"
using namespace std;
using namespace chrono;

class Phasor_Angle
{
public:
	Phasor_Angle();
	Phasor_Angle(ANGLE InitalAngle);
private:
	ANGLE AngularFrequency;
	system_clock::time_point StartTime= software_start_time;//创建电流线程时设定初始时间,该初始时间不可更改
	system_clock::time_point NowTime;//电流线程再创建一个子线程动态变化时间
	ANGLE EpochAngle;//电流的初相角；
	complex<double> PhasorAngleComplex;//本向量的复数形式；
public:
	// 将一般角度转换为常使用的角度
	 static double GetAngle(double InputData);
	 void RefreshAngle();
	 // //返回角度数值
	 ANGLE ReturnAngleData();
	 // //获取向量的初相交
	 ANGLE GetEpochAngle();
	 ANGLE GetEpochAngle()const;
	 friend ANGLE CalculatePhaseDiff(Phasor_Angle& Input_1,Phasor_Angle& Input_2);//计算两个向量的相位差
	 void SubAngle(ANGLE Input);//向量减去一个角度,向后滞后，其实就是初相角减去一个角度
	 void AddAngle(ANGLE Input);//向量加上一个角度，向前旋转
	 Phasor_Angle& operator=(const Phasor_Angle& Input);//向量的赋值运算符													
	 static void AngleToComplex(complex<double>& Data, ANGLE Input);// 角度转换成复数形式的向量
	 static ANGLE ComplexToAngle(const complex<double>& Data);//复数转角度
	 complex<double> ReturnComplex() const;//返回向量的复数形式
	 void SetEpochAngle(ANGLE Input);//更改向量的初相角 
};

