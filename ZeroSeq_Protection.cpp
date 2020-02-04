#include "ZeroSeq_Protection.h"

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

ActionState ZeroSeq_Protection::ZeroSeqProtection()
{
	auto U_I = Caculate_UZ_IZ(U_m, I_m);
	if (U_I.second == SingleEarth_Fault_A)
	{
		if (ZPCoreAlgorithmQuad_��())
		{
			double time = UseSetValue.GetValue(ProtectDevice, "����������ʱ��");
			FixTimeDelay(time * 1000 + ��_DPFixDelay + FixTimeError(time));
			EndTime = clock();
			cout << "�����ζ���" << (double)(EndTime - StartTime) / (CLOCKS_PER_SEC) * 1000 << "ms" << endl;
			return ProtectAction_A;
		}
		else if (ZPCoreAlgorithmQuad_��())
		{
			double time = UseSetValue.GetValue(ProtectDevice, "����������ʱ��");
			FixTimeDelay(time * 1000 + ��_DPFixDelay + FixTimeError(time));
			EndTime = clock();
			cout << "�����ζ���" << (double)(EndTime - StartTime) / (CLOCKS_PER_SEC) * 1000 << "ms" << endl;
			return ProtectAction_A;
		}
		else
			return ProtectNoAction;
	}
	else if (U_I.second == SingleEarth_Fault_B)
	{
		if (ZPCoreAlgorithmQuad_��())
		{
			double time = UseSetValue.GetValue(ProtectDevice, "����������ʱ��");
			FixTimeDelay(time * 1000 + ��_DPFixDelay + FixTimeError(time));
			EndTime = clock();
			cout << "�����ζ���" << (double)(EndTime - StartTime) / (CLOCKS_PER_SEC) * 1000 << "ms" << endl;
			return ProtectAction_B;
		}
		else if (ZPCoreAlgorithmQuad_��())
		{
			double time = UseSetValue.GetValue(ProtectDevice, "����������ʱ��");
			FixTimeDelay(time * 1000 + ��_DPFixDelay + FixTimeError(time));
			EndTime = clock();
			cout << "�����ζ���" << (double)(EndTime - StartTime) / (CLOCKS_PER_SEC) * 1000 << "ms" << endl;
			return ProtectAction_B;
		}
		else
			return ProtectNoAction;
	}
	else if (U_I.second == SingleEarth_Fault_C)
	{
		if (ZPCoreAlgorithmQuad_��())
		{
			double time = UseSetValue.GetValue(ProtectDevice, "����������ʱ��");
			FixTimeDelay(time * 1000 + ��_DPFixDelay + FixTimeError(time));
			EndTime = clock();
			cout << "�����ζ���" << (double)(EndTime - StartTime) / (CLOCKS_PER_SEC) * 1000 << "ms" << endl;
			return ProtectAction_C;
		}
		else if (ZPCoreAlgorithmQuad_��())
		{
			double time = UseSetValue.GetValue(ProtectDevice, "����������ʱ��");
			FixTimeDelay(time * 1000 + ��_DPFixDelay + FixTimeError(time));
			EndTime = clock();
			cout << "�����ζ���" << (double)(EndTime - StartTime) / (CLOCKS_PER_SEC) * 1000 << "ms" << endl;
			return ProtectAction_C;
		}
		else
			return ProtectNoAction;
	}
	else if (U_I.second == InterPhaseGround_Fault_AB)
	{
		if (ZPCoreAlgorithmQuad_��())
		{
			double time = UseSetValue.GetValue(ProtectDevice, "����������ʱ��");
			FixTimeDelay(time * 1000 + ��_DPFixDelay + FixTimeError(time));
			EndTime = clock();
			cout << "�����ζ���" << (double)(EndTime - StartTime) / (CLOCKS_PER_SEC) * 1000 << "ms" << endl;
			return ProtectAction_ABN;
		}
		else if (ZPCoreAlgorithmQuad_��())
		{
			double time = UseSetValue.GetValue(ProtectDevice, "����������ʱ��");
			FixTimeDelay(time * 1000 + ��_DPFixDelay + FixTimeError(time));
			EndTime = clock();
			cout << "�����ζ���" << (double)(EndTime - StartTime) / (CLOCKS_PER_SEC) * 1000 << "ms" << endl;
			return ProtectAction_ABN;
		}
		else
			return ProtectNoAction;
	}
	else if (U_I.second == InterPhaseGround_Fault_BC)
	{
		if (ZPCoreAlgorithmQuad_��())
		{
			double time = UseSetValue.GetValue(ProtectDevice, "����������ʱ��");
			FixTimeDelay(time * 1000 + ��_DPFixDelay + FixTimeError(time));
			EndTime = clock();
			cout << "�����ζ���" << (double)(EndTime - StartTime) / (CLOCKS_PER_SEC) * 1000 << "ms" << endl;
			return ProtectAction_BCN;
		}
		else if (ZPCoreAlgorithmQuad_��())
		{
			double time = UseSetValue.GetValue(ProtectDevice, "����������ʱ��");
			FixTimeDelay(time * 1000 + ��_DPFixDelay + FixTimeError(time));
			EndTime = clock();
			cout << "�����ζ���" << (double)(EndTime - StartTime) / (CLOCKS_PER_SEC) * 1000 << "ms" << endl;
			return ProtectAction_BCN;
		}
		else
			return ProtectNoAction;
	}
	else if (U_I.second == InterPhaseGround_Fault_CA)
	{
	    if (ZPCoreAlgorithmQuad_��())
	    {
		    double time = UseSetValue.GetValue(ProtectDevice, "����������ʱ��");
		    FixTimeDelay(time * 1000 + ��_DPFixDelay + FixTimeError(time));
		    EndTime = clock();
		    cout << "�����ζ���" << (double)(EndTime - StartTime) / (CLOCKS_PER_SEC) * 1000 << "ms" << endl;
		    return ProtectAction_CAN;
		}
		else if (ZPCoreAlgorithmQuad_��())
		{
			double time = UseSetValue.GetValue(ProtectDevice, "����������ʱ��");
			FixTimeDelay(time * 1000 + ��_DPFixDelay + FixTimeError(time));
			EndTime = clock();
			cout << "�����ζ���" << (double)(EndTime - StartTime) / (CLOCKS_PER_SEC) * 1000 << "ms" << endl;
			return ProtectAction_CAN;
		}
		else
			return ProtectNoAction;
	}
	else
	   return ProtectNoAction;
}
