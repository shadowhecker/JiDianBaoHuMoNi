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

ActionState ZeroSeq_Protection::ZeroSeqProtection()
{
	auto U_I = Caculate_UZ_IZ(U_m, I_m);
	if (U_I.second == SingleEarth_Fault_A)
	{
		if (ZPCoreAlgorithmQuad_Ⅱ())
		{
			double time = UseSetValue.GetValue(ProtectDevice, "零序过流Ⅱ段时间");
			FixTimeDelay(time * 1000 + Ⅰ_DPFixDelay + FixTimeError(time));
			EndTime = clock();
			cout << "零序Ⅱ段动作" << (double)(EndTime - StartTime) / (CLOCKS_PER_SEC) * 1000 << "ms" << endl;
			return ProtectAction_A;
		}
		else if (ZPCoreAlgorithmQuad_Ⅲ())
		{
			double time = UseSetValue.GetValue(ProtectDevice, "零序过流Ⅲ段时间");
			FixTimeDelay(time * 1000 + Ⅰ_DPFixDelay + FixTimeError(time));
			EndTime = clock();
			cout << "零序Ⅲ段动作" << (double)(EndTime - StartTime) / (CLOCKS_PER_SEC) * 1000 << "ms" << endl;
			return ProtectAction_A;
		}
		else
			return ProtectNoAction;
	}
	else if (U_I.second == SingleEarth_Fault_B)
	{
		if (ZPCoreAlgorithmQuad_Ⅱ())
		{
			double time = UseSetValue.GetValue(ProtectDevice, "零序过流Ⅱ段时间");
			FixTimeDelay(time * 1000 + Ⅰ_DPFixDelay + FixTimeError(time));
			EndTime = clock();
			cout << "零序Ⅱ段动作" << (double)(EndTime - StartTime) / (CLOCKS_PER_SEC) * 1000 << "ms" << endl;
			return ProtectAction_B;
		}
		else if (ZPCoreAlgorithmQuad_Ⅲ())
		{
			double time = UseSetValue.GetValue(ProtectDevice, "零序过流Ⅲ段时间");
			FixTimeDelay(time * 1000 + Ⅰ_DPFixDelay + FixTimeError(time));
			EndTime = clock();
			cout << "零序Ⅲ段动作" << (double)(EndTime - StartTime) / (CLOCKS_PER_SEC) * 1000 << "ms" << endl;
			return ProtectAction_B;
		}
		else
			return ProtectNoAction;
	}
	else if (U_I.second == SingleEarth_Fault_C)
	{
		if (ZPCoreAlgorithmQuad_Ⅱ())
		{
			double time = UseSetValue.GetValue(ProtectDevice, "零序过流Ⅱ段时间");
			FixTimeDelay(time * 1000 + Ⅰ_DPFixDelay + FixTimeError(time));
			EndTime = clock();
			cout << "零序Ⅱ段动作" << (double)(EndTime - StartTime) / (CLOCKS_PER_SEC) * 1000 << "ms" << endl;
			return ProtectAction_C;
		}
		else if (ZPCoreAlgorithmQuad_Ⅲ())
		{
			double time = UseSetValue.GetValue(ProtectDevice, "零序过流Ⅲ段时间");
			FixTimeDelay(time * 1000 + Ⅰ_DPFixDelay + FixTimeError(time));
			EndTime = clock();
			cout << "零序Ⅲ段动作" << (double)(EndTime - StartTime) / (CLOCKS_PER_SEC) * 1000 << "ms" << endl;
			return ProtectAction_C;
		}
		else
			return ProtectNoAction;
	}
	else if (U_I.second == InterPhaseGround_Fault_AB)
	{
		if (ZPCoreAlgorithmQuad_Ⅱ())
		{
			double time = UseSetValue.GetValue(ProtectDevice, "零序过流Ⅱ段时间");
			FixTimeDelay(time * 1000 + Ⅰ_DPFixDelay + FixTimeError(time));
			EndTime = clock();
			cout << "零序Ⅱ段动作" << (double)(EndTime - StartTime) / (CLOCKS_PER_SEC) * 1000 << "ms" << endl;
			return ProtectAction_ABN;
		}
		else if (ZPCoreAlgorithmQuad_Ⅲ())
		{
			double time = UseSetValue.GetValue(ProtectDevice, "零序过流Ⅲ段时间");
			FixTimeDelay(time * 1000 + Ⅰ_DPFixDelay + FixTimeError(time));
			EndTime = clock();
			cout << "零序Ⅲ段动作" << (double)(EndTime - StartTime) / (CLOCKS_PER_SEC) * 1000 << "ms" << endl;
			return ProtectAction_ABN;
		}
		else
			return ProtectNoAction;
	}
	else if (U_I.second == InterPhaseGround_Fault_BC)
	{
		if (ZPCoreAlgorithmQuad_Ⅱ())
		{
			double time = UseSetValue.GetValue(ProtectDevice, "零序过流Ⅱ段时间");
			FixTimeDelay(time * 1000 + Ⅰ_DPFixDelay + FixTimeError(time));
			EndTime = clock();
			cout << "零序Ⅱ段动作" << (double)(EndTime - StartTime) / (CLOCKS_PER_SEC) * 1000 << "ms" << endl;
			return ProtectAction_BCN;
		}
		else if (ZPCoreAlgorithmQuad_Ⅲ())
		{
			double time = UseSetValue.GetValue(ProtectDevice, "零序过流Ⅲ段时间");
			FixTimeDelay(time * 1000 + Ⅰ_DPFixDelay + FixTimeError(time));
			EndTime = clock();
			cout << "零序Ⅲ段动作" << (double)(EndTime - StartTime) / (CLOCKS_PER_SEC) * 1000 << "ms" << endl;
			return ProtectAction_BCN;
		}
		else
			return ProtectNoAction;
	}
	else if (U_I.second == InterPhaseGround_Fault_CA)
	{
	    if (ZPCoreAlgorithmQuad_Ⅱ())
	    {
		    double time = UseSetValue.GetValue(ProtectDevice, "零序过流Ⅱ段时间");
		    FixTimeDelay(time * 1000 + Ⅰ_DPFixDelay + FixTimeError(time));
		    EndTime = clock();
		    cout << "零序Ⅱ段动作" << (double)(EndTime - StartTime) / (CLOCKS_PER_SEC) * 1000 << "ms" << endl;
		    return ProtectAction_CAN;
		}
		else if (ZPCoreAlgorithmQuad_Ⅲ())
		{
			double time = UseSetValue.GetValue(ProtectDevice, "零序过流Ⅲ段时间");
			FixTimeDelay(time * 1000 + Ⅰ_DPFixDelay + FixTimeError(time));
			EndTime = clock();
			cout << "零序Ⅲ段动作" << (double)(EndTime - StartTime) / (CLOCKS_PER_SEC) * 1000 << "ms" << endl;
			return ProtectAction_CAN;
		}
		else
			return ProtectNoAction;
	}
	else
	   return ProtectNoAction;
}
