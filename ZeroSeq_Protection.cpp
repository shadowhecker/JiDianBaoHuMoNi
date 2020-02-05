#include "ZeroSeq_Protection.h"

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
	if (JudgePara<-ZeroTheta && JudgePara>-180 - ZeroTheta && 3*U_I.first.second.GetIValid() > ZeroSetValue)
		return 1;
	else
		return 0;
}

void ZeroSeq_Protection::ZeroSeqProtection()
{
	auto U_I = Caculate_UZ_IZ(U_m, I_m);
	UZ = U_I.first.first;
	IZ = U_I.first.second;
	if (U_I.second == SingleEarth_Fault_A)
	{
		if (ZPCoreAlgorithmQuad_Ⅱ())
		{
			double time = UseSetValue.GetValue(ProtectDevice, "零序过流Ⅱ段时间");
			FixTimeDelay(time * 1000 + Ⅰ_DPFixDelay + FixTimeError(time));
			EndTime = clock();
			ActionTime = (double)(EndTime - StartTime) / (CLOCKS_PER_SEC) * 1000;
			ProtectActionState = ProtectAction_A;
			Which_Protection = LinXuDianLiu_ⅡAction;
		}
		else if (ZPCoreAlgorithmQuad_Ⅲ())
		{
			double time = UseSetValue.GetValue(ProtectDevice, "零序过流Ⅲ段时间");
			FixTimeDelay(time * 1000 + Ⅰ_DPFixDelay + FixTimeError(time));
			EndTime = clock();
			ActionTime = (double)(EndTime - StartTime) / (CLOCKS_PER_SEC) * 1000;
			ProtectActionState = ProtectAction_A;
			Which_Protection = LinXuDianLiu_ⅢAction;
		}
		else
		{
			ActionTime = 0;
			ProtectActionState = ProtectNoAction;
			Which_Protection = ProtectNoAction;
		}
	}
	else if (U_I.second == SingleEarth_Fault_B)
	{
		if (ZPCoreAlgorithmQuad_Ⅱ())
		{
			double time = UseSetValue.GetValue(ProtectDevice, "零序过流Ⅱ段时间");
			FixTimeDelay(time * 1000 + Ⅰ_DPFixDelay + FixTimeError(time));
			EndTime = clock();
			ActionTime = (double)(EndTime - StartTime) / (CLOCKS_PER_SEC) * 1000;
			ProtectActionState = ProtectAction_B;
			Which_Protection = LinXuDianLiu_ⅡAction;
		}
		else if (ZPCoreAlgorithmQuad_Ⅲ())
		{
			double time = UseSetValue.GetValue(ProtectDevice, "零序过流Ⅲ段时间");
			FixTimeDelay(time * 1000 + Ⅰ_DPFixDelay + FixTimeError(time));
			EndTime = clock();
			ActionTime = (double)(EndTime - StartTime) / (CLOCKS_PER_SEC) * 1000;
			ProtectActionState = ProtectAction_B;
			Which_Protection = LinXuDianLiu_ⅢAction;
		}
		else
		{
			ActionTime = 0;
			ProtectActionState = ProtectNoAction;
			Which_Protection = ProtectNoAction;
		}
	}
	else if (U_I.second == SingleEarth_Fault_C)
	{
		if (ZPCoreAlgorithmQuad_Ⅱ())
		{
			double time = UseSetValue.GetValue(ProtectDevice, "零序过流Ⅱ段时间");
			FixTimeDelay(time * 1000 + Ⅰ_DPFixDelay + FixTimeError(time));
			EndTime = clock();
			ActionTime = (double)(EndTime - StartTime) / (CLOCKS_PER_SEC) * 1000;
			ProtectActionState = ProtectAction_C;
			Which_Protection = LinXuDianLiu_ⅡAction;
		}
		else if (ZPCoreAlgorithmQuad_Ⅲ())
		{
			double time = UseSetValue.GetValue(ProtectDevice, "零序过流Ⅲ段时间");
			FixTimeDelay(time * 1000 + Ⅰ_DPFixDelay + FixTimeError(time));
			EndTime = clock();
			ActionTime = (double)(EndTime - StartTime) / (CLOCKS_PER_SEC) * 1000;
			ProtectActionState = ProtectAction_C;
			Which_Protection = LinXuDianLiu_ⅢAction;
		}
		else
		{
			ActionTime = 0;
			ProtectActionState = ProtectNoAction;
			Which_Protection = ProtectNoAction;
		}
	}
	else if (U_I.second == InterPhaseGround_Fault_AB)
	{
		if (ZPCoreAlgorithmQuad_Ⅱ())
		{
			double time = UseSetValue.GetValue(ProtectDevice, "零序过流Ⅱ段时间");
			FixTimeDelay(time * 1000 + Ⅰ_DPFixDelay + FixTimeError(time));
			EndTime = clock();
			ActionTime = (double)(EndTime - StartTime) / (CLOCKS_PER_SEC) * 1000;
			ProtectActionState = ProtectAction_ABN;
			Which_Protection = LinXuDianLiu_ⅡAction;
		}
		else if (ZPCoreAlgorithmQuad_Ⅲ())
		{
			double time = UseSetValue.GetValue(ProtectDevice, "零序过流Ⅲ段时间");
			FixTimeDelay(time * 1000 + Ⅰ_DPFixDelay + FixTimeError(time));
			EndTime = clock();
			ActionTime = (double)(EndTime - StartTime) / (CLOCKS_PER_SEC) * 1000;
			ProtectActionState = ProtectAction_ABN;
			Which_Protection = LinXuDianLiu_ⅢAction;
		}
		else
		{
			ActionTime = 0;
			ProtectActionState = ProtectNoAction;
			Which_Protection = ProtectNoAction;
		}
	}
	else if (U_I.second == InterPhaseGround_Fault_BC)
	{
		if (ZPCoreAlgorithmQuad_Ⅱ())
		{
			double time = UseSetValue.GetValue(ProtectDevice, "零序过流Ⅱ段时间");
			FixTimeDelay(time * 1000 + Ⅰ_DPFixDelay + FixTimeError(time));
			EndTime = clock();
			ActionTime = (double)(EndTime - StartTime) / (CLOCKS_PER_SEC) * 1000;
			ProtectActionState = ProtectAction_BCN;
			Which_Protection = LinXuDianLiu_ⅡAction;
		}
		else if (ZPCoreAlgorithmQuad_Ⅲ())
		{
			double time = UseSetValue.GetValue(ProtectDevice, "零序过流Ⅲ段时间");
			FixTimeDelay(time * 1000 + Ⅰ_DPFixDelay + FixTimeError(time));
			EndTime = clock();
			ActionTime = (double)(EndTime - StartTime) / (CLOCKS_PER_SEC) * 1000;
			ProtectActionState = ProtectAction_BCN;
			Which_Protection = LinXuDianLiu_ⅢAction;
		}
		else
		{
			ActionTime = 0;
			ProtectActionState = ProtectNoAction;
			Which_Protection = ProtectNoAction;
		}
	}
	else if (U_I.second == InterPhaseGround_Fault_CA)
	{
	    if (ZPCoreAlgorithmQuad_Ⅱ())
	    {
		    double time = UseSetValue.GetValue(ProtectDevice, "零序过流Ⅱ段时间");
		    FixTimeDelay(time * 1000 + Ⅰ_DPFixDelay + FixTimeError(time));
		    EndTime = clock();
			ActionTime = (double)(EndTime - StartTime) / (CLOCKS_PER_SEC) * 1000;
			ProtectActionState = ProtectAction_CAN;
			Which_Protection = LinXuDianLiu_ⅡAction;
		}
		else if (ZPCoreAlgorithmQuad_Ⅲ())
		{
			double time = UseSetValue.GetValue(ProtectDevice, "零序过流Ⅲ段时间");
			FixTimeDelay(time * 1000 + Ⅰ_DPFixDelay + FixTimeError(time));
			EndTime = clock();
			ActionTime = (double)(EndTime - StartTime) / (CLOCKS_PER_SEC) * 1000;
			ProtectActionState = ProtectAction_CAN;
			Which_Protection = LinXuDianLiu_ⅢAction;
		}
		else
		{
			ActionTime = 0;
			ProtectActionState = ProtectNoAction;
			Which_Protection = ProtectNoAction;
		}
	}
	else
	{
	  ActionTime = 0;
	  ProtectActionState = ProtectNoAction;
	  Which_Protection = ProtectNoAction;
	}
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
