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

int TGW931::IsBKOffSuccess(ActionState stat)
{
	switch (stat)
	{
	case ProtectAction_A:
		if (!BK.IsBKAON() && I_m[0].GetIValid() == 0)
			return 1;
		else
			return 0;
		break;
	case ProtectAction_B:
		if (!BK.IsBKBON() && I_m[1].GetIValid() == 0)
			return 1;
		else
			return 0;
		break;
	case ProtectAction_C:
		if (!BK.IsBKCON() && I_m[2].GetIValid() == 0)
			return 1;
		else
			return 0;
		break;
	default:
		if (!BK.IsBKON() && I_m[0].GetIValid() == 0 && I_m[1].GetIValid() == 0 &&I_m[2].GetIValid() == 0)
			return 1;
		else
			return 0;
		break;
	}
	return 0;
}

void TGW931::ClearUI()
{
	U_m = { Electric_Voltage(0,0),Electric_Voltage(0,0), Electric_Voltage(0,0) };
	I_m = { Electric_Current(0,0),Electric_Current(0,0),Electric_Current(0,0) };
	DP.SetUI(U_m, I_m);
	ZP.SetUI(U_m, I_m);
	CP.SetUI(U_m, I_m);
}

