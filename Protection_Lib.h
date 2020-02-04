#pragma once
#include"res.h"
#include"Electric_Current.h"
#include"Electric_Voltage.h"
#include"Resistance_Impedance.h"
#include"SettingValue.h"
#include"CurrentDiff_Protection.h"
#include<fstream>
#include<sstream>
#include<iostream>
using namespace std;

//对称分量法函数
template <typename T>
T GetZeroSeq(const T& Data_A, const T& Data_B, const T& Data_C)//求解零序分量
{
	return  (Data_A + Data_B + Data_C) / 3;
}

template <typename T>
T GetNegativeSeq(T Data_A, T Data_B, T Data_C,char Phasor)//求解负序分量
{
	if (Phasor == 'A')
	{
		Data_B.AddAngle(240);
		Data_C.AddAngle(120);
		auto i = Data_A + Data_B + Data_C;
		return i / 3;
	}
	else if (Phasor == 'B')
	{
		Data_C.AddAngle(240);
		Data_A.AddAngle(120);
		auto i = Data_A + Data_B + Data_C;
		return i / 3;
	}
	else if (Phasor == 'C')
	{
		Data_A.AddAngle(240);
		Data_B.AddAngle(120);
		auto i = Data_A + Data_B + Data_C;
		return i / 3;
	}
	else
		cout << "Error wrong phasor char" << endl;
}

template <typename T>
T GetPositiveSeq(T Data_A, T Data_B, T Data_C,char Phasor)//求解正序分量
{
	if (Phasor == 'A')
	{
		Data_B.AddAngle(120);
		Data_C.AddAngle(240);
		auto i = Data_A + Data_B + Data_C;
		return i / 3;
	}
	else if (Phasor == 'B')
	{
		Data_C.AddAngle(120);
		Data_A.AddAngle(240);
		auto i = Data_A + Data_B + Data_C;
		return i / 3;
	}
	else if (Phasor == 'C')
	{
		Data_A.AddAngle(120);
		Data_B.AddAngle(240);
		auto i = Data_A + Data_B + Data_C;
		return i / 3;
	}
	else
		cout << "Error wrong phasor char" << endl;
}

int JudgeFaultStyle_PhaseDiff(vector<Electric_Current> I_m);
//该函数采用两相电流差突变量选相原理

int JudgeFaultStyle_ZerotoANegtive(vector<Electric_Voltage>V_m, vector<Electric_Current> I_m, double Z_InterPhase);
//该函数采用零序电流与A相负序电流比较选相原理,同时还需与相间阻抗的定值比较来区别单相接地故障和两相短路接地故障，无法判别相间与三相短路故障，因为它们没有零序电流

pair<Resistance_Impedance, double> CaculateZ_m(vector<Electric_Voltage>U, vector<Electric_Current> I);

pair<pair<Electric_Voltage, Electric_Current>,double > Caculate_UZ_IZ(vector<Electric_Voltage>U_m, vector<Electric_Current> I_m);//计算零序电压和零序电流

int CurrentBrustStart(vector<Electric_Current> I_m);//电流突变量差启动

char ChoosePhase(vector<double> Input);//辅助函数选差流最大相

pair<pair<double, double>, pair<int, char> > Caculate_CurrentDiff(vector<Electric_Voltage> U_m, vector<Electric_Current> I_m, vector<Electric_Voltage> U_n, vector<Electric_Current> I_n);//计算差流返回差动量、制动量及故障类型

int WeekFeedBack(int IsStart, int RAS, pair<pair<double, double>, pair<int, char> > I_Cacu, vector<Electric_Voltage> U_m, vector<Electric_Current> I_m);//弱馈启动判断

int RemoteCallStart(int IsStart, int RAS, pair<pair<double, double>, pair<int, char> > I_Cacu, vector<Electric_Voltage> U_m, vector<Electric_Current> I_m);//远方召唤启动判断

int CurrentDiffAlgor(double I_D, double I_B);//差动算法

void InputVoltage(vector<Electric_Voltage>& U_m);

void InputCurrent(vector<Electric_Current>& I_m);