#pragma once
#include "res.h"
#include <cstdio>
#include <iostream>
#include "Electric_Current.h"
#include "Electric_Voltage.h"
#include "Protection_Lib.h"
#include "Resistance_Impedance.h"
#include "CurrentDiff_Protection.h"
#include "Distance_Protection.h"
#include "Operation_Case.h"
#include "ZeroSeq_Protection.h"
class TGW931//线路保护装置
{
public:
	TGW931(vector<Electric_Voltage>U, vector<Electric_Current> I) :U_m(U), I_m(I), BK(), DP(U, I), ZP(U, I), CP(U, I, 1, BK.IsBKON()) {}
	TGW931();
	void UpdateProtectBKState();
	void InitializeUI(vector<Electric_Voltage>U, vector<Electric_Current> I);
	void UpdateProtectUI();
public:
	CurrentDiff_Protection CP;
	Distance_Protection DP;
	ZeroSeq_Protection ZP;
	Operation_Case BK;
	vector<Electric_Voltage> U_m;
	vector<Electric_Current> I_m;
};

