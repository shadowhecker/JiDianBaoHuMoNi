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
	int ReceiveActionSingle = 0;
	int SendActionSingle = 0;
	int IsStart = 0;
}

ActionState CurrentDiff_Protection::CurrentDiffProtectionLoop()
{
	I_DB = Caculate_CurrentDiff(U_OnSide, I_OnSide, U_OnSide, I_OnSide);
	SelfSideStart();
	if (IsStart == 1 && BreakerStat == 1 && ReceiveActionSingle == 1)
	{
		if (CurrentDiffAlgor(I_DB.first.first, I_DB.first.second))
		{
			return FaultToProtection[I_DB.second.first];
		}
		else
			return ProtectNoAction;
	}
	else
		return ProtectNoAction;
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
	if (CP_m.ProtectStart())
	{
		cout << "本侧保护启动" << endl;
	}
	CP_m.SendActionSingle();
	if (CP_n.ProtectStart())
	{
		cout << "对侧保护启动" << endl;
	}
	CP_n.SendActionSingle();
	SyncCPStat(CP_m, CP_n);
	if (CP_m.OtherProtectStart())
	{
		cout << "本侧保护弱馈启动" << endl;
	}
	if (CP_n.OtherProtectStart())
	{
		cout << "对侧保护弱馈启动" << endl;
	}
	SyncCPStat(CP_m, CP_n);
}

vector<ActionState> CurrentDiffProtection(CurrentDiff_Protection& CP_m, CurrentDiff_Protection& CP_n)
{
	AllSideStart(CP_m, CP_n);
	int ACS_m, ACS_n;
	vector<int> result;
	if (CP_m.IsStart == 1 && CP_m.BreakerStat == 1 && CP_m.ReceiveActionSingle == 1)
	{
		if (CurrentDiffAlgor(CP_m.I_DB.first.first, CP_m.I_DB.first.first))
		{
			ACS_m = FaultToProtection[CP_m.I_DB.second.first];
		}
		else
			ACS_m = ProtectNoAction;
	}
	else
		ACS_m=ProtectNoAction;
	if (CP_n.IsStart == 1 && CP_n.BreakerStat == 1 && CP_n.ReceiveActionSingle == 1)
	{
		if (CurrentDiffAlgor(CP_n.I_DB.first.first, CP_n.I_DB.first.first))
		{
			ACS_n = FaultToProtection[CP_n.I_DB.second.first];
		}
		else
			ACS_n = ProtectNoAction;
	}
	else
		ACS_n == ProtectNoAction;
	result.push_back(ACS_m);
	result.push_back(ACS_n);
	return result;
}
