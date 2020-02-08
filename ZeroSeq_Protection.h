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
	int ZPCoreAlgorithmQuad_Ⅱ();//零序Ⅱ段
	int ZPCoreAlgorithmQuad_Ⅲ();//零序Ⅲ段
	void ZeroSeqProtection();//零序方向继电器

	ActionState GetProtectAcionState();
	ActionState GetWhich_Protection();
	double GetActionTime();
	Electric_Voltage GetUZ();
	Electric_Current GetIZ();
	void SetUI(vector<Electric_Voltage> U, vector<Electric_Current> I);
private:
	vector<Electric_Voltage> U_m;//距离阻抗继电器上的电压量
	vector<Electric_Current> I_m;//距离阻抗继电器流经的电流量
	ActionState ProtectActionState;
	ActionState Which_Protection;
	double ActionTime;
	Electric_Voltage UZ;//零序电压
	Electric_Current IZ;//零序电流
public:
	void SetProtectActionState(ActionState stat);
};

