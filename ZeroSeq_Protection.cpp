#include "ZeroSeq_Protection.h"

ZeroSeq_Protection::ZeroSeq_Protection(vector<Electric_Voltage> U, vector<Electric_Current> I)
{
	U_m = U;
	I_m = I;
	ActionTime = 0;
	ProtectActionState = 0;
	Which_Protection = 0;
	UZ = Caculate_UZ_IZ(U_m, I_m).first.first;
	IZ = Caculate_UZ_IZ(U_m, I_m).first.second;
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
}

int ZeroSeq_Protection::ZPCoreAlgorithmQuad_��()
{
	auto ZeroTheta = 90-UseSetValue.GetValue(ProtectDevice, "��·����������");
	auto ZeroSetValue = UseSetValue.GetValue(ProtectDevice, "����������");
	auto U_I = Caculate_UZ_IZ(U_m, I_m);
	auto JudgePara = arg(U_I.first.first.ReturnVComplex() / U_I.first.second.ReturnIComplex()) * 180 / M_PI;
	if (JudgePara<-ZeroTheta && JudgePara>(-180 - ZeroTheta) && 3*U_I.first.second.GetIValid() > ZeroSetValue)
		return 1;
	else
		return 0;
}

int ZeroSeq_Protection::ZPCoreAlgorithmQuad_��()
{
	auto ZeroTheta = 90 - UseSetValue.GetValue(ProtectDevice, "��·����������");
	auto ZeroSetValue = UseSetValue.GetValue(ProtectDevice, "����������");
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
		if (ZPCoreAlgorithmQuad_��())
		{
			double time = UseSetValue.GetValue(ProtectDevice, "����������ʱ��");
			FixTimeDelay(time * 1000 + ��_DPFixDelay + FixTimeError(time));
			EndTime = clock();
			ActionTime = (double)(EndTime - StartTime) / (CLOCKS_PER_SEC) * 1000;
			ProtectActionState = ProtectAction_A;
			Which_Protection = LinXuDianLiu_��Action;
		}
		else if (ZPCoreAlgorithmQuad_��())
		{
			double time = UseSetValue.GetValue(ProtectDevice, "����������ʱ��");
			FixTimeDelay(time * 1000 + ��_DPFixDelay + FixTimeError(time));
			EndTime = clock();
			ActionTime = (double)(EndTime - StartTime) / (CLOCKS_PER_SEC) * 1000;
			ProtectActionState = ProtectAction_A;
			Which_Protection = LinXuDianLiu_��Action;
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
		if (ZPCoreAlgorithmQuad_��())
		{
			double time = UseSetValue.GetValue(ProtectDevice, "����������ʱ��");
			FixTimeDelay(time * 1000 + ��_DPFixDelay + FixTimeError(time));
			EndTime = clock();
			ActionTime = (double)(EndTime - StartTime) / (CLOCKS_PER_SEC) * 1000;
			ProtectActionState = ProtectAction_B;
			Which_Protection = LinXuDianLiu_��Action;
		}
		else if (ZPCoreAlgorithmQuad_��())
		{
			double time = UseSetValue.GetValue(ProtectDevice, "����������ʱ��");
			FixTimeDelay(time * 1000 + ��_DPFixDelay + FixTimeError(time));
			EndTime = clock();
			ActionTime = (double)(EndTime - StartTime) / (CLOCKS_PER_SEC) * 1000;
			ProtectActionState = ProtectAction_B;
			Which_Protection = LinXuDianLiu_��Action;
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
		if (ZPCoreAlgorithmQuad_��())
		{
			double time = UseSetValue.GetValue(ProtectDevice, "����������ʱ��");
			FixTimeDelay(time * 1000 + ��_DPFixDelay + FixTimeError(time));
			EndTime = clock();
			ActionTime = (double)(EndTime - StartTime) / (CLOCKS_PER_SEC) * 1000;
			ProtectActionState = ProtectAction_C;
			Which_Protection = LinXuDianLiu_��Action;
		}
		else if (ZPCoreAlgorithmQuad_��())
		{
			double time = UseSetValue.GetValue(ProtectDevice, "����������ʱ��");
			FixTimeDelay(time * 1000 + ��_DPFixDelay + FixTimeError(time));
			EndTime = clock();
			ActionTime = (double)(EndTime - StartTime) / (CLOCKS_PER_SEC) * 1000;
			ProtectActionState = ProtectAction_C;
			Which_Protection = LinXuDianLiu_��Action;
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
		if (ZPCoreAlgorithmQuad_��())
		{
			double time = UseSetValue.GetValue(ProtectDevice, "����������ʱ��");
			FixTimeDelay(time * 1000 + ��_DPFixDelay + FixTimeError(time));
			EndTime = clock();
			ActionTime = (double)(EndTime - StartTime) / (CLOCKS_PER_SEC) * 1000;
			ProtectActionState = ProtectAction_ABN;
			Which_Protection = LinXuDianLiu_��Action;
		}
		else if (ZPCoreAlgorithmQuad_��())
		{
			double time = UseSetValue.GetValue(ProtectDevice, "����������ʱ��");
			FixTimeDelay(time * 1000 + ��_DPFixDelay + FixTimeError(time));
			EndTime = clock();
			ActionTime = (double)(EndTime - StartTime) / (CLOCKS_PER_SEC) * 1000;
			ProtectActionState = ProtectAction_ABN;
			Which_Protection = LinXuDianLiu_��Action;
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
		if (ZPCoreAlgorithmQuad_��())
		{
			double time = UseSetValue.GetValue(ProtectDevice, "����������ʱ��");
			FixTimeDelay(time * 1000 + ��_DPFixDelay + FixTimeError(time));
			EndTime = clock();
			ActionTime = (double)(EndTime - StartTime) / (CLOCKS_PER_SEC) * 1000;
			ProtectActionState = ProtectAction_BCN;
			Which_Protection = LinXuDianLiu_��Action;
		}
		else if (ZPCoreAlgorithmQuad_��())
		{
			double time = UseSetValue.GetValue(ProtectDevice, "����������ʱ��");
			FixTimeDelay(time * 1000 + ��_DPFixDelay + FixTimeError(time));
			EndTime = clock();
			ActionTime = (double)(EndTime - StartTime) / (CLOCKS_PER_SEC) * 1000;
			ProtectActionState = ProtectAction_BCN;
			Which_Protection = LinXuDianLiu_��Action;
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
	    if (ZPCoreAlgorithmQuad_��())
	    {
		    double time = UseSetValue.GetValue(ProtectDevice, "����������ʱ��");
		    FixTimeDelay(time * 1000 + ��_DPFixDelay + FixTimeError(time));
		    EndTime = clock();
			ActionTime = (double)(EndTime - StartTime) / (CLOCKS_PER_SEC) * 1000;
			ProtectActionState = ProtectAction_CAN;
			Which_Protection = LinXuDianLiu_��Action;
		}
		else if (ZPCoreAlgorithmQuad_��())
		{
			double time = UseSetValue.GetValue(ProtectDevice, "����������ʱ��");
			FixTimeDelay(time * 1000 + ��_DPFixDelay + FixTimeError(time));
			EndTime = clock();
			ActionTime = (double)(EndTime - StartTime) / (CLOCKS_PER_SEC) * 1000;
			ProtectActionState = ProtectAction_CAN;
			Which_Protection = LinXuDianLiu_��Action;
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

void ZeroSeq_Protection::SetUI(vector<Electric_Voltage> U, vector<Electric_Current> I)
{

}
