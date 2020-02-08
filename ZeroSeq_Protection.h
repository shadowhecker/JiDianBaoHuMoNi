#pragma once
#include "res.h"
#include <cstdio>
#include <iostream>
#include "Electric_Current.h"
#include "Electric_Voltage.h"
#include "Protection_Lib.h"
#include "Resistance_Impedance.h"
class ZeroSeq_Protection
{
public:
	ZeroSeq_Protection(vector<Electric_Voltage> U, vector<Electric_Current> I);
	ZeroSeq_Protection();
	int ZPCoreAlgorithmQuad_��();//������
	int ZPCoreAlgorithmQuad_��();//������
	void ZeroSeqProtection();//������̵���

	ActionState GetProtectAcionState();
	ActionState GetWhich_Protection();
	double GetActionTime();
	Electric_Voltage GetUZ();
	Electric_Current GetIZ();
	void SetUI(vector<Electric_Voltage> U, vector<Electric_Current> I);
private:
	vector<Electric_Voltage> U_m;//�����迹�̵����ϵĵ�ѹ��
	vector<Electric_Current> I_m;//�����迹�̵��������ĵ�����
	ActionState ProtectActionState;
	ActionState Which_Protection;
	double ActionTime;
	Electric_Voltage UZ;//�����ѹ
	Electric_Current IZ;//�������
public:
	void SetProtectActionState(ActionState stat);
};

