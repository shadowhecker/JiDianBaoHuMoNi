#include "Phasor_Angle.h"

Phasor_Angle::Phasor_Angle()
{
	NowTime = system_clock::now();//初始化时初始时间和starttime时间一致
	auto diff = NowTime - StartTime;
	AngularFrequency = ANGULARFREQUENCY * duration<double, milli>(diff).count() / 1000 ;
	EpochAngle = 0;
	AngleToComplex(PhasorAngleComplex, EpochAngle);
}
Phasor_Angle::Phasor_Angle(ANGLE InitalAngle)
{
	NowTime = StartTime;//初始化时初始时间和starttime时间一致
	auto diff = NowTime - StartTime;
	AngularFrequency = ANGULARFREQUENCY * duration<double, milli>(diff).count()/1000 + GetDataFromAngle(InitalAngle);
	AngularFrequency = GetAngle(AngularFrequency);
	EpochAngle = InitalAngle;
	AngleToComplex(PhasorAngleComplex, EpochAngle);
}

// 将一般角度转换为常使用的角度
double Phasor_Angle::GetAngle(double InputData)//将数值转换为经常使用的角度（-360~360之间）
{
	// TODO: 在此处添加实现代码.
	double Temp = InputData / (M_PI) * 180;//计算得出目前的角度
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




// 每一次提取角度时都会根据时间更新一次现有角度
void Phasor_Angle::RefreshAngle()
{
	// TODO: 在此处添加实现代码.
	NowTime = system_clock::now();//初始化时初始时间和starttime时间一致
	auto diff = NowTime - StartTime;
	double i = duration<double, milli>(diff).count()/1000000;
	AngularFrequency = ANGULARFREQUENCY * duration<double, milli>(diff).count() / 1000 + GetDataFromAngle(EpochAngle);
	AngularFrequency = GetAngle(AngularFrequency);
}


// //返回角度数值
ANGLE Phasor_Angle::ReturnAngleData()
{
	// TODO: 在此处添加实现代码.
	RefreshAngle();
	return AngularFrequency;
}


// //获取向量的初相角
ANGLE Phasor_Angle::GetEpochAngle()
{
	// TODO: 在此处添加实现代码.
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
	// TODO: 在此处插入 return 语句
	EpochAngle = Input.EpochAngle;
	PhasorAngleComplex = Input.ReturnComplex();
	RefreshAngle();
	return *this;
}


ANGLE CalculatePhaseDiff(Phasor_Angle& Input_1, Phasor_Angle& Input_2)//计算出相角差
{
	return Input_1.ReturnAngleData() - Input_2.ReturnAngleData();
}

// 角度转换成复数形式的向量
void Phasor_Angle::AngleToComplex(complex<double>& Data, ANGLE Input)
{
	// TODO: 在此处添加实现代码
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
