#include "CurrentDiff_Protection.h"


int CurrentDiff_Protection::ProtectStart()
{
	if (CurrentBrustStart(I_OnSide))
	{
		IsStart = 1;
		return 1;
	}
	else
	{
		IsStart = 0;
		return 0;
	}
}

void CurrentDiff_Protection::SendActionSingle()
{
	auto I_Diff = I_DB;
	if ((IsStart == 1 || BreakerStat == 0) && I_Diff.first.first != 0)
	{
		SendActionSingleStat = 1;
		if (ChannelLoop == 1)
			ReceiveActionSingle = 1;
	}
	else
		SendActionSingleStat = 0;
}

void CurrentDiff_Protection::SelfSideStart()
{
	ProtectStart();
	SendActionSingle();
}

int CurrentDiff_Protection::OtherProtectStart()//弱馈及远方召唤启动
{
	auto I_Diff_Ca = I_DB;
	if (BreakerStat==1&&IsStart==0&&WeekFeedBack(IsStart, ReceiveActionSingle, I_Diff_Ca, U_OnSide, I_OnSide) == 1) //|| RemoteCallStart(IsStart, ReceiveActionSingle, I_Diff_Ca, U_OnSide, I_OnSide) == 1)远方召唤暂且不模拟
	{
		IsStart = 1;
		IsWeedBack = 1;
		SendActionSingle();
		return 1;
	}
	return 0;
}

double CurrentDiff_Protection::GetI_Diff()
{
	return I_DB.first.first;
}

double CurrentDiff_Protection::GetI_B()
{
	return I_DB.first.second;
}

CurrentDiff_Protection::CurrentDiff_Protection(vector<Electric_Voltage> U_m, vector<Electric_Current> I_m, int Loop, int Breaker)
{
	U_OnSide = U_m;
	I_OnSide = I_m;
	U_OffSide = { Electric_Voltage(0, 0), Electric_Voltage(0, 0), Electric_Voltage(0, 0) };
	I_OffSide = { Electric_Current(0, 0), Electric_Current(0, 0), Electric_Current(0, 0) };
	ChannelLoop =Loop;//默认设置装置不自环
	if (ChannelLoop == 1)
	{
		U_OffSide = U_OnSide;
		I_OffSide = I_OnSide;
	}
	BreakerStat = Breaker;
	if (ChannelLoop == 1)
	{
		BreakerStat = 1;
	}
	if (Breaker == 0)
	{
		I_OnSide[0] = 0;
		I_OnSide[1] = 0;
		I_OnSide[2] = 0;
	}
	ReceiveActionSingle = 0;
	SendActionSingleStat = 0;
	IsStart = 0;
	IsWeedBack = 0;
	ProtectActionState = 0;
	ActionTime = 0;
}

CurrentDiff_Protection::CurrentDiff_Protection()
{
	U_OnSide = { Electric_Voltage(0, 0), Electric_Voltage(0, 0), Electric_Voltage(0, 0) };
	I_OnSide = { Electric_Current(0, 0), Electric_Current(0, 0), Electric_Current(0, 0) };
	U_OffSide = { Electric_Voltage(0, 0), Electric_Voltage(0, 0), Electric_Voltage(0, 0) };
	I_OffSide = { Electric_Current(0, 0), Electric_Current(0, 0), Electric_Current(0, 0) };
	int ReceiveActionSingle = 0;
	int SendActionSingle = 0;
	int IsStart = 0;
	int IsWeedBack = 0;
	ReceiveActionSingle = 0;
	SendActionSingleStat = 0;
	IsStart = 0;
	IsWeedBack = 0;
	ProtectActionState = 0;
	ActionTime = 0;
	ChannelLoop = 0;
	BreakerStat = 0;
}

void CurrentDiff_Protection::CurrentDiffProtectionLoop()
{
	I_DB = Caculate_CurrentDiff(U_OnSide, I_OnSide, U_OnSide, I_OnSide);
	SelfSideStart();
	if (IsStart == 1 && BreakerStat == 1 && ReceiveActionSingle == 1)
	{
		if (CurrentDiffAlgor(I_DB.first.first, I_DB.first.second))
		{
			ProtectActionState = FaultToProtection[I_DB.second.first];
			FixTimeDelay(10);
			EndTime = clock();
			ActionTime = (double)(EndTime - StartTime) / (CLOCKS_PER_SEC) * 1000;
		}
		else
		{
			ActionTime = 0;
			ProtectActionState = ProtectNoAction;
		}
	}
	else
	{
		ActionTime = 0;
		ProtectActionState = ProtectNoAction;
	}
}

ActionState CurrentDiff_Protection::GetProtectAcionState()
{
	return ProtectActionState;
}

void CurrentDiff_Protection::SetProtectActionState(ActionState)
{
	ProtectActionState = ProtectAction_ABC;
}

double CurrentDiff_Protection::GetActionTime()
{
	return ActionTime;
}

int CurrentDiff_Protection::GetIsStart()
{
	return IsStart;
}

int CurrentDiff_Protection::GetIsWeedBack()
{
	return IsWeedBack;
}

void CurrentDiff_Protection::SetBKState(int BK)
{
	BreakerStat = BK;
}

void CurrentDiff_Protection::SetUI(vector<Electric_Voltage> U, vector<Electric_Current> I)
{
	U_OnSide = U;
	I_OnSide = I;
	I_DB = Caculate_CurrentDiff(U_OnSide, I_OnSide, U_OffSide, I_OffSide);
}


void SyncCPStat(CurrentDiff_Protection& CP_m, CurrentDiff_Protection& CP_n)
{
	CP_m.I_OffSide = CP_n.I_OnSide;
	CP_n.I_OffSide = CP_m.I_OnSide;
	CP_m.U_OffSide = CP_n.U_OnSide;
	CP_n.U_OffSide = CP_m.U_OnSide;
	if (CP_m.ChannelLoop == 1 || CP_n.ChannelLoop == 1)
	{
		CP_m.ChannelLoop = 1;
		CP_n.ChannelLoop = 1;
	}
	if (CP_m.SendActionSingleStat == 1)
		CP_n.ReceiveActionSingle = 1;
	if (CP_n.SendActionSingleStat == 1)
		CP_m.ReceiveActionSingle = 1;
}

void AllSideStart(CurrentDiff_Protection& CP_m, CurrentDiff_Protection& CP_n)
{
	SyncCPStat(CP_m, CP_n);
	CP_m.I_DB = Caculate_CurrentDiff(CP_m.U_OnSide, CP_m.I_OnSide, CP_n.U_OnSide, CP_n.I_OnSide);
	CP_n.I_DB = Caculate_CurrentDiff(CP_n.U_OnSide, CP_n.I_OnSide, CP_m.U_OnSide, CP_m.I_OnSide);
	CP_m.ProtectStart();
	CP_m.SendActionSingle();
	CP_n.ProtectStart();
	CP_n.SendActionSingle();
	SyncCPStat(CP_m, CP_n);
	CP_m.OtherProtectStart();
	CP_n.OtherProtectStart();
	SyncCPStat(CP_m, CP_n);
}

void CurrentDiffProtection(CurrentDiff_Protection& CP_m, CurrentDiff_Protection& CP_n)
{
	AllSideStart(CP_m, CP_n);
	vector<int> result;
	if (CP_m.IsStart == 1 && CP_m.BreakerStat == 1 && CP_m.ReceiveActionSingle == 1)
	{
		if (CurrentDiffAlgor(CP_m.I_DB.first.first, CP_m.I_DB.first.first))
		{
			CP_m.ProtectActionState = FaultToProtection[CP_m.I_DB.second.first];
			FixTimeDelay(10);
			EndTime = clock();
			CP_m.ActionTime = (double)(EndTime - StartTime) / (CLOCKS_PER_SEC) * 1000;
		}
		else
		{
			CP_m.ActionTime = 0;
			CP_m.ProtectActionState = ProtectNoAction;
		}
	}
	else
	{
		CP_m.ActionTime = 0;
		CP_m.ProtectActionState = ProtectNoAction;
	}
	if (CP_n.IsStart == 1 && CP_n.BreakerStat == 1 && CP_n.ReceiveActionSingle == 1)
	{
		if (CurrentDiffAlgor(CP_n.I_DB.first.first, CP_n.I_DB.first.first))
		{
			CP_n.ProtectActionState = FaultToProtection[CP_n.I_DB.second.first];
			FixTimeDelay(10);
			EndTime = clock();
			CP_n.ActionTime = (double)(EndTime - StartTime) / (CLOCKS_PER_SEC) * 1000;
		}
		else
		{
			CP_n.ActionTime = 0;
			CP_n.ProtectActionState = ProtectNoAction;
		}
	}
	else
	{
		CP_n.ActionTime = 0;
		CP_n.ProtectActionState = ProtectNoAction;
	}
}
