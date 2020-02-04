#include "Phasor_Angle.h"

Phasor_Angle::Phasor_Angle()
{
	NowTime = system_clock::now();//��ʼ��ʱ��ʼʱ���starttimeʱ��һ��
	auto diff = NowTime - StartTime;
	AngularFrequency = ANGULARFREQUENCY * duration<double, milli>(diff).count() / 1000 ;
	EpochAngle = 0;
	AngleToComplex(PhasorAngleComplex, EpochAngle);
}
Phasor_Angle::Phasor_Angle(ANGLE InitalAngle)
{
	NowTime = StartTime;//��ʼ��ʱ��ʼʱ���starttimeʱ��һ��
	auto diff = NowTime - StartTime;
	AngularFrequency = ANGULARFREQUENCY * duration<double, milli>(diff).count()/1000 + GetDataFromAngle(InitalAngle);
	AngularFrequency = GetAngle(AngularFrequency);
	EpochAngle = InitalAngle;
	AngleToComplex(PhasorAngleComplex, EpochAngle);
}

// ��һ��Ƕ�ת��Ϊ��ʹ�õĽǶ�
double Phasor_Angle::GetAngle(double InputData)//����ֵת��Ϊ����ʹ�õĽǶȣ�-360~360֮�䣩
{
	// TODO: �ڴ˴����ʵ�ִ���.
	double Temp = InputData / (M_PI) * 180;//����ó�Ŀǰ�ĽǶ�
	if (Temp<360&&Temp>-360)
		return Temp;
	else if (Temp >=360)
	{
		for (; Temp >= 360; Temp = Temp - 360)
		{
		}
		return Temp;
	}
	else
	{
		for (; Temp <= -360; Temp = Temp + 360)
		{
		}
		return Temp;
	}
}




// ÿһ����ȡ�Ƕ�ʱ�������ʱ�����һ�����нǶ�
void Phasor_Angle::RefreshAngle()
{
	// TODO: �ڴ˴����ʵ�ִ���.
	NowTime = system_clock::now();//��ʼ��ʱ��ʼʱ���starttimeʱ��һ��
	auto diff = NowTime - StartTime;
	double i = duration<double, milli>(diff).count()/1000000;
	AngularFrequency = ANGULARFREQUENCY * duration<double, milli>(diff).count() / 1000 + GetDataFromAngle(EpochAngle);
	AngularFrequency = GetAngle(AngularFrequency);
}


// //���ؽǶ���ֵ
ANGLE Phasor_Angle::ReturnAngleData()
{
	// TODO: �ڴ˴����ʵ�ִ���.
	RefreshAngle();
	return AngularFrequency;
}


// //��ȡ�����ĳ����
ANGLE Phasor_Angle::GetEpochAngle()
{
	// TODO: �ڴ˴����ʵ�ִ���.
	return EpochAngle;
}

ANGLE Phasor_Angle::GetEpochAngle() const
{
	return EpochAngle;
}

void Phasor_Angle::SubAngle(ANGLE Input)
{
	EpochAngle -= Input;
	AngleToComplex(PhasorAngleComplex, EpochAngle);
}

void Phasor_Angle::AddAngle(ANGLE Input)
{
	EpochAngle += Input;
	AngleToComplex(PhasorAngleComplex, EpochAngle);
}

Phasor_Angle& Phasor_Angle::operator=(const Phasor_Angle& Input)
{
	// TODO: �ڴ˴����� return ���
	EpochAngle = Input.EpochAngle;
	PhasorAngleComplex = Input.ReturnComplex();
	RefreshAngle();
	return *this;
}


ANGLE CalculatePhaseDiff(Phasor_Angle& Input_1, Phasor_Angle& Input_2)//�������ǲ�
{
	return Input_1.ReturnAngleData() - Input_2.ReturnAngleData();
}

// �Ƕ�ת���ɸ�����ʽ������
void Phasor_Angle::AngleToComplex(complex<double>& Data, ANGLE Input)
{
	// TODO: �ڴ˴����ʵ�ִ���
	complex<double> temp(cos(GetDataFromAngle(Input)), sin(GetDataFromAngle(Input)));
	Data = temp;
}

ANGLE Phasor_Angle::ComplexToAngle(const complex<double>& Data)
{
	return arg(Data);
}

complex<double> Phasor_Angle::ReturnComplex() const
{
	return PhasorAngleComplex;
}

void Phasor_Angle::SetEpochAngle(ANGLE Input)
{
	EpochAngle = Input;
	RefreshAngle();
	AngleToComplex(PhasorAngleComplex, EpochAngle);
}
