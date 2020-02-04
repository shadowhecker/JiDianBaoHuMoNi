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
	VOLTAGE V_Valid;//��ѹ����Чֵ
	Phasor_Angle Theta;//��ѹ������
	complex<double> V_Complex;//��ѹ�ĸ�����ʽ
public:
	void Display_Electric_Voltage(int IsDynamics);
	void Display_Electric_Voltage_complex();//�Ը�������ʽ��ʾ��ѹ��
	VOLTAGE GetVValid();//���ص�ѹ��ֵ
	VOLTAGE GetVValid() const;
	ANGLE GetTheta();//����ת������·��ص�ѹ�Ƕȣ��Ƕ���ʱ��һֱ�ڱ�
	ANGLE GetInitialTheta();//�������Ⱦ�ֹ�����·��ص�ѹ�Ƕ�
	ANGLE GetInitialTheta()const;
	complex<double> ReturnVComplex() const;//��õ�ѹ�ĸ�����ʽ
	VOLTAGE Getinstantvalue();//��ȡ��ѹ����Чֵ
	friend ANGLE CalCurrentPhasorDiff(const Electric_Voltage& Input_1, const Electric_Voltage& Input_2);//����������ѹ����λ��
	void SubAngle(ANGLE Input);//��ѹ�����ͺ�
	void AddAngle(ANGLE Input);//��ѹ��ǰ��ת
	void RefreshVComplex();//���ڽǶȱ仯��Ҫ����������ʽ
	Phasor_Angle ReturnTheta() const;//���ص�ѹ������
	Electric_Voltage& operator=(const Electric_Voltage& Input);//��ֵ�����
	Electric_Voltage operator+(const Electric_Voltage& Input);//��ѹ�������
	friend Electric_Voltage operator+(const Electric_Voltage& Input1, const Electric_Voltage& Input2);
	Electric_Voltage operator-(const Electric_Voltage& Input);//��ѹ�������
	Resistance_Impedance operator/(const Electric_Current& Input);//���迹
	Electric_Current operator/(const Resistance_Impedance& Input);//�����
	Electric_Voltage& operator*(double Value);//���Է�ֵ����
	Electric_Voltage& operator/(double Value);//��ֵ����һ������
};


