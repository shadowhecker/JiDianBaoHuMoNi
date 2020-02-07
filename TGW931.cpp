#include "TGW931.h"


TGW931::TGW931()
{
	U_m = { Electric_Voltage(0, 0), Electric_Voltage(0, 0), Electric_Voltage(0, 0) };
	I_m = { Electric_Current(0,0),Electric_Current(0,0),Electric_Current(0,0) };
	DP = Distance_Protection(U_m, I_m);
	ZP = ZeroSeq_Protection(U_m, I_m);
	CP = CurrentDiff_Protection(U_m, I_m, 1, BK.IsBKON());
}

void TGW931::UpdateProtectBKState()
{
	CP.SetBKState(BK.IsBKON());
}

void TGW931::InitializeUI(vector<Electric_Voltage> U, vector<Electric_Current> I)
{
	U_m = U;
	I_m = I;
	UpdateProtectUI();
}

void TGW931::UpdateProtectUI()
{
	DP.SetUI(U_m,I_m);
	ZP.SetUI(U_m,I_m);
	CP.SetUI(U_m, I_m);
}
