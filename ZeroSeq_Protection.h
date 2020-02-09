#pragma once
#include "res.h"
#include <cstdio>
#include <iostream>
#include "Electric_Current.h"
#include "Electric_Voltage.h"
#include "Protection_Lib.h"
#include "Resistance_Impedance.h"
#include "Resource.h"
class ZeroSeq_Protection
{
public:
	ZeroSeq_Protection(vector<Electric_Voltage> U, vector<Electric_Current> I);
	ZeroSeq_Protection();
	int ZPCoreAlgorithmQuad_Ⅱ();//零序Ⅱ段
	int ZPCoreAlgorithmQuad_Ⅲ();//零序Ⅲ段
	void ZeroSeqProtection();//零序方向继电器

	ActionState GetProtectAcionState();
	ActionState GetWhich_Protection();
	double GetActionTime();
	Electric_Voltage GetUZ();
	Electric_Current GetIZ();
	vector<Electric_Voltage> GetU_m();
	vector<Electric_Current> GetI_m();
	void SetActionTime(double time);
	void SetWhich_Protection(int Pro);
	void SetUI(vector<Electric_Voltage> U, vector<Electric_Current> I);
	int GetFault();
private:
	vector<Electric_Voltage> U_m;
	vector<Electric_Current> I_m;
	ActionState ProtectActionState;
	ActionState Which_Protection;
	double ActionTime;
	Electric_Voltage UZ;//零序电压
	Electric_Current IZ;//零序电流
	int Fault;//故障判别标志位
public:
	void SetProtectActionState(ActionState stat);
};

