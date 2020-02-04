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
	system_clock::time_point StartTime= software_start_time;//���������߳�ʱ�趨��ʼʱ��,�ó�ʼʱ�䲻�ɸ���
	system_clock::time_point NowTime;//�����߳��ٴ���һ�����̶߳�̬�仯ʱ��
	ANGLE EpochAngle;//�����ĳ���ǣ�
	complex<double> PhasorAngleComplex;//�������ĸ�����ʽ��
public:
	// ��һ��Ƕ�ת��Ϊ��ʹ�õĽǶ�
	 static double GetAngle(double InputData);
	 void RefreshAngle();
	 // //���ؽǶ���ֵ
	 ANGLE ReturnAngleData();
	 // //��ȡ�����ĳ��ཻ
	 ANGLE GetEpochAngle();
	 ANGLE GetEpochAngle()const;
	 friend ANGLE CalculatePhaseDiff(Phasor_Angle& Input_1,Phasor_Angle& Input_2);//����������������λ��
	 void SubAngle(ANGLE Input);//������ȥһ���Ƕ�,����ͺ���ʵ���ǳ���Ǽ�ȥһ���Ƕ�
	 void AddAngle(ANGLE Input);//��������һ���Ƕȣ���ǰ��ת
	 Phasor_Angle& operator=(const Phasor_Angle& Input);//�����ĸ�ֵ�����													
	 static void AngleToComplex(complex<double>& Data, ANGLE Input);// �Ƕ�ת���ɸ�����ʽ������
	 static ANGLE ComplexToAngle(const complex<double>& Data);//����ת�Ƕ�
	 complex<double> ReturnComplex() const;//���������ĸ�����ʽ
	 void SetEpochAngle(ANGLE Input);//���������ĳ���� 
};

