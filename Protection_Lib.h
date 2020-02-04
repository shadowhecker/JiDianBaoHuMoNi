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

//�ԳƷ���������
template <typename T>
T GetZeroSeq(const T& Data_A, const T& Data_B, const T& Data_C)//����������
{
	return  (Data_A + Data_B + Data_C) / 3;
}

template <typename T>
T GetNegativeSeq(T Data_A, T Data_B, T Data_C,char Phasor)//��⸺�����
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
T GetPositiveSeq(T Data_A, T Data_B, T Data_C,char Phasor)//����������
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
//�ú����������������ͻ����ѡ��ԭ��

int JudgeFaultStyle_ZerotoANegtive(vector<Electric_Voltage>V_m, vector<Electric_Current> I_m, double Z_InterPhase);
//�ú����������������A�ฺ������Ƚ�ѡ��ԭ��,ͬʱ����������迹�Ķ�ֵ�Ƚ���������ӵع��Ϻ������·�ӵع��ϣ��޷��б�����������·���ϣ���Ϊ����û���������

pair<Resistance_Impedance, double> CaculateZ_m(vector<Electric_Voltage>U, vector<Electric_Current> I);

pair<pair<Electric_Voltage, Electric_Current>,double > Caculate_UZ_IZ(vector<Electric_Voltage>U_m, vector<Electric_Current> I_m);//���������ѹ���������

int CurrentBrustStart(vector<Electric_Current> I_m);//����ͻ����������

char ChoosePhase(vector<double> Input);//��������ѡ���������

pair<pair<double, double>, pair<int, char> > Caculate_CurrentDiff(vector<Electric_Voltage> U_m, vector<Electric_Current> I_m, vector<Electric_Voltage> U_n, vector<Electric_Current> I_n);//����������ز�����ƶ�������������

int WeekFeedBack(int IsStart, int RAS, pair<pair<double, double>, pair<int, char> > I_Cacu, vector<Electric_Voltage> U_m, vector<Electric_Current> I_m);//���������ж�

int RemoteCallStart(int IsStart, int RAS, pair<pair<double, double>, pair<int, char> > I_Cacu, vector<Electric_Voltage> U_m, vector<Electric_Current> I_m);//Զ���ٻ������ж�

int CurrentDiffAlgor(double I_D, double I_B);//��㷨

void InputVoltage(vector<Electric_Voltage>& U_m);

void InputCurrent(vector<Electric_Current>& I_m);