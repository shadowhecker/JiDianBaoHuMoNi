#pragma once
#include "res.h"
#include <cstdio>
#include <iostream>
#include "Electric_Current.h"
#include "Electric_Voltage.h"
#include "Protection_Lib.h"
#include "Resistance_Impedance.h"
#include "Resource.h"
class Distance_Protection
{
public:
	Distance_Protection(vector<Electric_Voltage> U, vector<Electric_Current> I);//������Ĭ�Ϲ��캯��
	Distance_Protection();
	int DPCoreAlgorithmOne_��(double FaultStyle);//����̵�����������һ  ���
	int DPCoreAlgorithmOne_��(double FaultStyle);//����̵�����������һ  ���
	int DPCoreAlgorithmOne_��(double FaultStyle);//����̵�����������һ  ���
	void DistanceProtection();//����̵���
	int DPCoreAlgorithmQuad_��(double FaultStyle);//����̵��������ı��ζ������� ���
	int DPCoreAlgorithmQuad_��(double FaultStyle);//����̵��������ı��ζ������� ���
	int DPCoreAlgorithmQuad_��(double FaultStyle);//����̵��������ı��ζ������� ���
	ActionState GetProtectAcionState();
	ActionState GetWhich_Protection();
	double GetActionTime();
	pair<Resistance_Impedance, double> GetZ_m();
	void SetUI(vector<Electric_Voltage> U,vector<Electric_Current> I);
	void SetProtectActionState(ActionState stat);
	vector<Electric_Voltage>GetU_m();
	vector<Electric_Current>GetI_m();
	void SetActionTime(double time);
	void SetWhich_Protection(int Pro);
	int GetFault();
private:
	vector<Electric_Voltage> U_m;//�����迹�̵����ϵĵ�ѹ��
	vector<Electric_Current> I_m;//�����迹�̵��������ĵ�����
	pair<Resistance_Impedance,double> Z_m;//�����迹�̵����Ĳ����迹,���Զ������迹�̵���
	ActionState ProtectActionState;
	ActionState Which_Protection;
	double ActionTime;
	int Fault;
};

