#include "ZeroSeq_Protection.h"
#include <afxwin.h>

HANDLE g_event = CreateEvent(NULL, TRUE, FALSE, NULL);
ZeroSeq_Protection::ZeroSeq_Protection(vector<Electric_Voltage> U, vector<Electric_Current> I)
{
	U_m = U;
	I_m = I;
	ActionTime = 0;
	ProtectActionState = 0;
	Which_Protection = 0;
	UZ = Caculate_UZ_IZ(U_m, I_m).first.first;
	IZ = Caculate_UZ_IZ(U_m, I_m).first.second;
	Fault = Caculate_UZ_IZ(U_m, I_m).second;
}

ZeroSeq_Protection::ZeroSeq_Protection()
{
	U_m = { Electric_Voltage(0, 0), Electric_Voltage(0, 0), Electric_Voltage(0, 0) };
	I_m = { Electric_Current(0, 0), Electric_Current(0, 0), Electric_Current(0, 0) };
	ActionTime = 0;
	ProtectActionState = 0;
	Which_Protection = 0;
	UZ = Caculate_UZ_IZ(U_m, I_m).first.first;
	IZ = Caculate_UZ_IZ(U_m, I_m).first.second;
	Fault = Caculate_UZ_IZ(U_m, I_m).second;
}

int ZeroSeq_Protection::ZPCoreAlgorithmQuad_Ⅱ()
{
	auto ZeroTheta = 90-UseSetValue.GetValue(ProtectDevice, "线路零序灵敏角");
	auto ZeroSetValue = UseSetValue.GetValue(ProtectDevice, "零序过流Ⅱ段");
	auto U_I = Caculate_UZ_IZ(U_m, I_m);
	auto JudgePara = arg(U_I.first.first.ReturnVComplex() / U_I.first.second.ReturnIComplex()) * 180 / M_PI;
	if (JudgePara<-ZeroTheta && JudgePara>(-180 - ZeroTheta) && 3*U_I.first.second.GetIValid() > ZeroSetValue)
		return 1;
	else
		return 0;
}

int ZeroSeq_Protection::ZPCoreAlgorithmQuad_Ⅲ()
{
	auto ZeroTheta = 90 - UseSetValue.GetValue(ProtectDevice, "线路零序灵敏角");
	auto ZeroSetValue = UseSetValue.GetValue(ProtectDevice, "零序过流Ⅲ段");
	auto U_I = Caculate_UZ_IZ(U_m, I_m);
	auto JudgePara = arg(U_I.first.first.ReturnVComplex() / U_I.first.second.ReturnIComplex()) * 180 / M_PI;
	if (JudgePara<-ZeroTheta && JudgePara>-180 - ZeroTheta && (3*U_I.first.second.GetIValid()) > ZeroSetValue)
		return 1;
	else
		return 0;
}

void ZeroSeq_Protection::ZeroSeqProtection()
{
	double timeⅡ = UseSetValue.GetValue(ProtectDevice, "零序过流Ⅱ段时间");
	double timeⅢ = UseSetValue.GetValue(ProtectDevice, "零序过流Ⅲ段时间");
	SetTimer(AfxGetMainWnd()->GetSafeHwnd(),TIME_DEVICE_ZP_ALG_2, timeⅡ * 1000+ Ⅰ_DPFixDelay, NULL);
	SetTimer(AfxGetMainWnd()->GetSafeHwnd(),TIME_DEVICE_ZP_ALG_3, timeⅢ * 1000+ Ⅰ_DPFixDelay, NULL);
}

ActionState ZeroSeq_Protection::GetProtectAcionState()
{
	return ProtectActionState;
}

ActionState ZeroSeq_Protection::GetWhich_Protection()
{
	return Which_Protection;
}

double ZeroSeq_Protection::GetActionTime()
{
	return ActionTime;
}

Electric_Voltage ZeroSeq_Protection::GetUZ()
{
	return UZ;
}

Electric_Current ZeroSeq_Protection::GetIZ()
{
	return IZ;
}

vector<Electric_Voltage> ZeroSeq_Protection::GetU_m()
{
	return U_m;
}

vector<Electric_Current> ZeroSeq_Protection::GetI_m()
{
	return I_m;
}

void ZeroSeq_Protection::SetActionTime(double time)
{
	ActionTime = time;
}

void ZeroSeq_Protection::SetWhich_Protection(int Pro)
{
	Which_Protection = Pro;
}

void ZeroSeq_Protection::SetUI(vector<Electric_Voltage> U, vector<Electric_Current> I)
{
	U_m = U;
	I_m = I;
	UZ = Caculate_UZ_IZ(U_m, I_m).first.first;
	IZ = Caculate_UZ_IZ(U_m, I_m).first.second;
	Fault = Caculate_UZ_IZ(U_m, I_m).second;
}

int ZeroSeq_Protection::GetFault()
{
	return 0;
}

void ZeroSeq_Protection::SetProtectActionState(ActionState stat)
{
	ProtectActionState = stat;
	// TODO: 在此处添加实现代码.
}
