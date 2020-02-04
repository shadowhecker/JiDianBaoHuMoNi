#pragma once
#include"Phasor_Angle.h"//���������Ƕ���
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
	AMPERE I_Valid;//��������Чֵ
	Phasor_Angle Theta;//����������
	complex<double> I_Complex;//�����ĸ�����ʽ
public:
	void Display_Electric_Current(int IsDynamics);
	void Display_Electric_Current_complex();//�Ը�������ʽ��ʾ������
	AMPERE GetIValid();//���ص�����ֵ
	AMPERE GetIValid() const;
	ANGLE GetTheta() ;//����ת������·��ص����Ƕȣ��Ƕ���ʱ��һֱ�ڱ�
	ANGLE GetInitialTheta();//�������Ⱦ�ֹ�����·��ص����Ƕ�
	ANGLE GetInitialTheta()const;
	complex<double> ReturnIComplex() const;//��õ����ĸ�����ʽ
	AMPERE Getinstantvalue();//��ȡ��������Чֵ
	friend ANGLE CalCurrentPhasorDiff(const Electric_Current& Input_1, const Electric_Current& Input_2);//����������������λ��
	void SubAngle(ANGLE Input);//���������ͺ�
	void AddAngle(ANGLE Input);//������ǰ��ת
	void RefreshIComplex();//���ڽǶȱ仯��Ҫ����������ʽ
	Phasor_Angle ReturnTheta() const;//���ص���������
	Electric_Current& operator=(const Electric_Current& Input);//��ֵ�����
	Electric_Current operator+(const Electric_Current& Input);//�����������
	friend Electric_Current operator+(const Electric_Current& Input1, const Electric_Current& Input2);
	Electric_Current operator-(const Electric_Current& Input);//�����������
	Electric_Current& operator=(const complex<double>& Input);
	Electric_Voltage operator*(const Resistance_Impedance& Input);//���ѹ
	Electric_Current& operator*(double Value);//������ֵ����һ������
	Electric_Current& operator/(double Value);//������ֵ����һ������
	
};




