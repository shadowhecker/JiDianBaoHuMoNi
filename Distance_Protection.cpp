#include "Distance_Protection.h"

Distance_Protection::Distance_Protection(vector<Electric_Voltage> U, vector<Electric_Current> I)
{
	U_m = U;
	I_m = I;
	Z_m = CaculateZ_m(U, I);
}

int Distance_Protection::DPCoreAlgorithmOne_��(double FaultStyle)
{
	double JudgePara_��;
	Resistance_Impedance Z_set_��;
	if (FaultStyle == SingleEarth_Fault_A || FaultStyle == SingleEarth_Fault_B || FaultStyle == SingleEarth_Fault_C
		|| FaultStyle == InterPhaseGround_Fault_AB || FaultStyle == InterPhaseGround_Fault_BC || FaultStyle == InterPhaseGround_Fault_CA)
	{
		Z_set_�� = Resistance_Impedance(UseSetValue.GetValue(ProtectDevice, "�ӵؾ�����"), UseSetValue.GetValue(ProtectDevice, "��·����������"));
	}
	else
	{
		Z_set_�� = Resistance_Impedance(UseSetValue.GetValue(ProtectDevice, "��������"), UseSetValue.GetValue(ProtectDevice, "��·����������"));
	}
	JudgePara_�� = arg((Z_m.first.ReturnZComplex() - Z_set_��.ReturnZComplex()) / Z_m.first.ReturnZComplex()) * 180 / M_PI;
	if ((JudgePara_�� > 90 && JudgePara_�� <= 180.001)|| (JudgePara_�� < -90 && JudgePara_�� >= -180.001))
		return 1;
	else
		return 0;
}

int Distance_Protection::DPCoreAlgorithmOne_��(double FaultStyle)
{
	double JudgePara_��;
	Resistance_Impedance Z_set_��;
	if (FaultStyle == SingleEarth_Fault_A || FaultStyle == SingleEarth_Fault_B || FaultStyle == SingleEarth_Fault_C
		|| FaultStyle == InterPhaseGround_Fault_AB || FaultStyle == InterPhaseGround_Fault_BC || FaultStyle == InterPhaseGround_Fault_CA)
	{
		Z_set_�� = Resistance_Impedance(UseSetValue.GetValue(ProtectDevice, "�ӵؾ�����"), UseSetValue.GetValue(ProtectDevice, "��·����������"));
	}
	else
	{
		Z_set_�� = Resistance_Impedance(UseSetValue.GetValue(ProtectDevice, "��������"), UseSetValue.GetValue(ProtectDevice, "��·����������"));
	}
	JudgePara_�� = arg((Z_m.first.ReturnZComplex() - Z_set_��.ReturnZComplex()) / Z_m.first.ReturnZComplex()) * 180 / M_PI;
	if ((JudgePara_�� > 90 && JudgePara_�� <= 180.001) || (JudgePara_�� < -90 && JudgePara_�� >= -180.001))
		return 1;
	else
		return 0;
}

int Distance_Protection::DPCoreAlgorithmOne_��(double FaultStyle)
{
	double JudgePara_��;
	Resistance_Impedance Z_set_��;
	if (FaultStyle == SingleEarth_Fault_A || FaultStyle == SingleEarth_Fault_B || FaultStyle == SingleEarth_Fault_C
		|| FaultStyle == InterPhaseGround_Fault_AB || FaultStyle == InterPhaseGround_Fault_BC || FaultStyle == InterPhaseGround_Fault_CA)
	{
		Z_set_�� = Resistance_Impedance(UseSetValue.GetValue(ProtectDevice, "�ӵؾ�����"), UseSetValue.GetValue(ProtectDevice, "��·����������"));
	}
	else
	{
		Z_set_�� = Resistance_Impedance(UseSetValue.GetValue(ProtectDevice, "��������"), UseSetValue.GetValue(ProtectDevice, "��·����������"));
	}
	JudgePara_�� = arg((Z_m.first.ReturnZComplex() - Z_set_��.ReturnZComplex()) / Z_m.first.ReturnZComplex()) * 180 / M_PI;
	if ((JudgePara_�� > 90 && JudgePara_�� <= 180.001) || (JudgePara_�� < -90 && JudgePara_�� >= -180.001))
		return 1;
	else
		return 0;
	return 0;
}

ActionState Distance_Protection::DistanceProtection()
{
	if (Z_m.second == SingleEarth_Fault_A)
	{
		if (DPCoreAlgorithmQuad_��(Z_m.second))
		{
			FixTimeDelay(��_DPFixDelay + FixTimeError(��_DPFixDelay));
			EndTime = clock();
			cout << "�ӵؾ����ζ���" << (double)(EndTime - StartTime) / (CLOCKS_PER_SEC) * 1000 << "ms" << endl;
			cout << "����R=" << Z_m.first.ReturnR() << "    " << "�翹Z=" << Z_m.first.ReturnX() << endl;
			return ProtectAction_A;
		}
		else if (DPCoreAlgorithmQuad_��(Z_m.second))
		{
			double time = UseSetValue.GetValue(ProtectDevice, "�ӵؾ�����ʱ��");
			FixTimeDelay(time * 1000 + ��_DPFixDelay+ FixTimeError(time));
			EndTime = clock();
			cout << "�ӵؾ����ζ���" << (double)(EndTime - StartTime) / (CLOCKS_PER_SEC) * 1000 << "ms" << endl;
			cout << "����R=" << Z_m.first.ReturnR() << "    " << "�翹Z=" << Z_m.first.ReturnX() << endl;
			return ProtectAction_A;
		}
		else if (DPCoreAlgorithmQuad_��(Z_m.second))
		{
			double time = UseSetValue.GetValue(ProtectDevice, "�ӵؾ�����ʱ��");
			FixTimeDelay(time * 1000 + ��_DPFixDelay + FixTimeError(time));
			EndTime = clock();
			cout << "�ӵؾ����ζ���" << (double)(EndTime - StartTime) / (CLOCKS_PER_SEC) * 1000 << "ms" << endl;
			cout << "����R=" << Z_m.first.ReturnR() << "    " << "�翹Z=" << Z_m.first.ReturnX() << endl;
			return ProtectAction_A;
		}
		else
			return ProtectNoAction;
	}
	else if (Z_m.second == SingleEarth_Fault_B)
	{
		if (DPCoreAlgorithmQuad_��(Z_m.second))
		{
			FixTimeDelay(��_DPFixDelay + FixTimeError(��_DPFixDelay));
			EndTime = clock();
			cout << "�ӵؾ����ζ���" << (double)(EndTime - StartTime) / (CLOCKS_PER_SEC) * 1000 << "ms" << endl;
			cout << "����R=" << Z_m.first.ReturnR() << "    " << "�翹Z=" << Z_m.first.ReturnX() << endl;
			return ProtectAction_B;
		}
		else if (DPCoreAlgorithmQuad_��(Z_m.second))
		{
			double time = UseSetValue.GetValue(ProtectDevice, "�ӵؾ�����ʱ��");
			FixTimeDelay(time * 1000 + ��_DPFixDelay + FixTimeError(time));
			EndTime = clock();
			cout << "�ӵؾ����ζ���" << (double)(EndTime - StartTime) / (CLOCKS_PER_SEC) * 1000 << "ms" << endl;
			cout << "����R=" << Z_m.first.ReturnR() << "    " << "�翹Z=" << Z_m.first.ReturnX() << endl;
			return ProtectAction_B;
		}
		else if (DPCoreAlgorithmQuad_��(Z_m.second))
		{
			double time = UseSetValue.GetValue(ProtectDevice, "�ӵؾ�����ʱ��");
			FixTimeDelay(time * 1000 + ��_DPFixDelay + FixTimeError(time));
			EndTime = clock();
			cout << "�ӵؾ����ζ���" << (double)(EndTime - StartTime) / (CLOCKS_PER_SEC) * 1000 << "ms" << endl;
			cout << "����R=" << Z_m.first.ReturnR() << "    " << "�翹Z=" << Z_m.first.ReturnX() << endl;
			return ProtectAction_B;
		}
		else
			return ProtectNoAction;
	}
	else if (Z_m.second == SingleEarth_Fault_C)
	{
		if (DPCoreAlgorithmQuad_��(Z_m.second))
		{
			FixTimeDelay(30);
			EndTime = clock();
			cout << "�ӵؾ����ζ���" << (double)(EndTime - StartTime) / (CLOCKS_PER_SEC) * 1000 << "ms" << endl;
			cout << "����R=" << Z_m.first.ReturnR() << "    " << "�翹Z=" << Z_m.first.ReturnX() << endl;
			return ProtectAction_C;
		}
		else if (DPCoreAlgorithmQuad_��(Z_m.second))
		{
			double time = UseSetValue.GetValue(ProtectDevice, "�ӵؾ�����ʱ��");
			FixTimeDelay(time * 1000 + ��_DPFixDelay + FixTimeError(time));
			EndTime = clock();
			cout << "�ӵؾ����ζ���" << (double)(EndTime - StartTime) / (CLOCKS_PER_SEC) * 1000 << "ms" << endl;
			cout << "����R=" << Z_m.first.ReturnR() << "    " << "�翹Z=" << Z_m.first.ReturnX() << endl;
			return ProtectAction_C;
		}
		else if (DPCoreAlgorithmQuad_��(Z_m.second))
		{
			double time = UseSetValue.GetValue(ProtectDevice, "�ӵؾ�����ʱ��");
			FixTimeDelay(time * 1000 + ��_DPFixDelay + FixTimeError(time));
			EndTime = clock();
			cout << "�ӵؾ����ζ���" << (double)(EndTime - StartTime) / (CLOCKS_PER_SEC) * 1000 << "ms" << endl;
			cout << "����R=" << Z_m.first.ReturnR() << "    " << "�翹Z=" << Z_m.first.ReturnX() << endl;
			return ProtectAction_C;
		}
		else
			return ProtectNoAction;
	}
	else if (Z_m.second == InterPhase_Fault_AB)
	{
		if (DPCoreAlgorithmQuad_��(Z_m.second))
		{
			FixTimeDelay(30);
			EndTime = clock();
			cout << "�������ζ���" << (double)(EndTime - StartTime) / (CLOCKS_PER_SEC) * 1000 << "ms" << endl;
			cout << "����R=" << Z_m.first.ReturnR() << "    " << "�翹Z=" << Z_m.first.ReturnX() << endl;
			return ProtectAction_AB;
		}
		else if (DPCoreAlgorithmQuad_��(Z_m.second))
		{
			double time = UseSetValue.GetValue(ProtectDevice, "��������ʱ��");
			FixTimeDelay(time * 1000 + ��_DPFixDelay + FixTimeError(time));
			EndTime = clock();
			cout << "�������ζ���" << (double)(EndTime - StartTime) / (CLOCKS_PER_SEC) * 1000 << "ms" << endl;
			cout << "����R=" << Z_m.first.ReturnR() << "    " << "�翹Z=" << Z_m.first.ReturnX() << endl;
			return ProtectAction_AB;
		}
		else if (DPCoreAlgorithmQuad_��(Z_m.second))
		{
			double time = UseSetValue.GetValue(ProtectDevice, "��������ʱ��");
			FixTimeDelay(time * 1000 + ��_DPFixDelay + FixTimeError(time));
			EndTime = clock();
			cout << "�������ζ���" << (double)(EndTime - StartTime) / (CLOCKS_PER_SEC) * 1000 << "ms" << endl;
			cout << "����R=" << Z_m.first.ReturnR() << "    " << "�翹Z=" << Z_m.first.ReturnX() << endl;
			return ProtectAction_AB;
		}
		else
			return ProtectNoAction;
	}
	else if (Z_m.second == InterPhase_Fault_BC)
	{
		if (DPCoreAlgorithmQuad_��(Z_m.second))
		{
			FixTimeDelay(30);
			EndTime = clock();
			cout << "�������ζ���" <<(double)(EndTime-StartTime)/(CLOCKS_PER_SEC)*1000<<"ms"<< endl;
			cout << "����R=" << Z_m.first.ReturnR() << "    " << "�翹Z=" << Z_m.first.ReturnX() << endl;
			return ProtectAction_BC;
		}
		else if (DPCoreAlgorithmQuad_��(Z_m.second))
		{
			double time = UseSetValue.GetValue(ProtectDevice, "��������ʱ��");
			FixTimeDelay(time * 1000 + ��_DPFixDelay + FixTimeError(time));
			EndTime = clock();
			cout << "�������ζ���" << (double)(EndTime - StartTime) / (CLOCKS_PER_SEC) * 1000 << "ms" << endl;
			cout << "����R=" << Z_m.first.ReturnR() << "    " << "�翹Z=" << Z_m.first.ReturnX() << endl;
			return ProtectAction_BC;
		}
		else if (DPCoreAlgorithmQuad_��(Z_m.second))
		{
			double time = UseSetValue.GetValue(ProtectDevice, "��������ʱ��");
			FixTimeDelay(time * 1000 + ��_DPFixDelay + FixTimeError(time));
			EndTime = clock();
			cout << "�������ζ���" << (double)(EndTime - StartTime) / (CLOCKS_PER_SEC) * 1000 << "ms" << endl;
			cout << "����R=" << Z_m.first.ReturnR() << "    " << "�翹Z=" << Z_m.first.ReturnX() << endl;
			return ProtectAction_BC;
		}
		else
			return ProtectNoAction;
	}
	else if (Z_m.second == InterPhase_Fault_CA)
	{
		if (DPCoreAlgorithmQuad_��(Z_m.second))
		{
			FixTimeDelay(30);
			EndTime = clock();
			cout << "�������ζ���" << (double)(EndTime - StartTime) / (CLOCKS_PER_SEC) * 1000 << "ms" << endl;
			cout << "����R=" << Z_m.first.ReturnR() << "    " << "�翹Z=" << Z_m.first.ReturnX() << endl;
			return ProtectAction_CA;
		}
		else if (DPCoreAlgorithmQuad_��(Z_m.second))
		{
			double time = UseSetValue.GetValue(ProtectDevice, "��������ʱ��");
			FixTimeDelay(time * 1000 + ��_DPFixDelay + FixTimeError(time));
			EndTime = clock();
			cout << "�������ζ���" << (double)(EndTime - StartTime) / (CLOCKS_PER_SEC) * 1000 << "ms" << endl;
			cout << "����R=" << Z_m.first.ReturnR() << "    " << "�翹Z=" << Z_m.first.ReturnX() << endl;
			return ProtectAction_CA;
		}
		else if (DPCoreAlgorithmQuad_��(Z_m.second))
		{
			double time = UseSetValue.GetValue(ProtectDevice, "��������ʱ��");
			FixTimeDelay(time * 1000 + ��_DPFixDelay + FixTimeError(time));
			EndTime = clock();
			cout << "�������ζ���" << (double)(EndTime - StartTime) / (CLOCKS_PER_SEC) * 1000 << "ms" << endl;
			cout << "����R=" << Z_m.first.ReturnR() << "    " << "�翹Z=" << Z_m.first.ReturnX() << endl;
			return ProtectAction_CA;
		}
		else
			return ProtectNoAction;
	}
	else if (Z_m.second == InterPhaseGround_Fault_AB)
	{
		if (DPCoreAlgorithmQuad_��(Z_m.second))
		{
			FixTimeDelay(30);
			EndTime = clock();
			cout << "�������ζ���" << (double)(EndTime - StartTime) / (CLOCKS_PER_SEC) * 1000 << "ms" << endl;
			cout << "����R=" << Z_m.first.ReturnR() << "    " << "�翹Z=" << Z_m.first.ReturnX() << endl;
			return ProtectAction_ABN;
		}
		else if (DPCoreAlgorithmQuad_��(Z_m.second))
		{
			double time = UseSetValue.GetValue(ProtectDevice, "��������ʱ��");
			FixTimeDelay(time * 1000 + ��_DPFixDelay + FixTimeError(time));
			EndTime = clock();
			cout << "�������ζ���" << (double)(EndTime - StartTime) / (CLOCKS_PER_SEC) * 1000 << "ms" << endl;
			cout << "����R=" << Z_m.first.ReturnR() << "    " << "�翹Z=" << Z_m.first.ReturnX() << endl;
			return ProtectAction_ABN;
		}
		else if (DPCoreAlgorithmQuad_��(Z_m.second))
		{
			double time = UseSetValue.GetValue(ProtectDevice, "��������ʱ��");
			FixTimeDelay(time * 1000 + ��_DPFixDelay + FixTimeError(time));
			EndTime = clock();
			cout << "�������ζ���" << (double)(EndTime - StartTime) / (CLOCKS_PER_SEC) * 1000 << "ms" << endl;
			cout << "����R=" << Z_m.first.ReturnR() << "    " << "�翹Z=" << Z_m.first.ReturnX() << endl;
			return ProtectAction_ABN;
		}
		else
			return ProtectNoAction;
	}
	else if (Z_m.second == InterPhaseGround_Fault_BC)
	{
		if (DPCoreAlgorithmQuad_��(Z_m.second))
		{
			FixTimeDelay(30);
			EndTime = clock();
			cout << "�������ζ���" << (double)(EndTime - StartTime) / (CLOCKS_PER_SEC) * 1000 << "ms" << endl;
			cout << "����R=" << Z_m.first.ReturnR() << "    " << "�翹Z=" << Z_m.first.ReturnX() << endl;
			return ProtectAction_BCN;
		}
		else if (DPCoreAlgorithmQuad_��(Z_m.second))
		{
			double time = UseSetValue.GetValue(ProtectDevice, "��������ʱ��");
			FixTimeDelay(time * 1000 + ��_DPFixDelay + FixTimeError(time));
			EndTime = clock();
			cout << "�������ζ���" << (double)(EndTime - StartTime) / (CLOCKS_PER_SEC) * 1000 << "ms" << endl;
			cout << "����R=" << Z_m.first.ReturnR() << "    " << "�翹Z=" << Z_m.first.ReturnX() << endl;
			return ProtectAction_BCN;
		}
		else if (DPCoreAlgorithmQuad_��(Z_m.second))
		{
			double time = UseSetValue.GetValue(ProtectDevice, "��������ʱ��");
			FixTimeDelay(time * 1000 + ��_DPFixDelay + FixTimeError(time));
			EndTime = clock();
			cout << "�������ζ���" << (double)(EndTime - StartTime) / (CLOCKS_PER_SEC) * 1000 << "ms" << endl;
			cout << "����R=" << Z_m.first.ReturnR() << "    " << "�翹Z=" << Z_m.first.ReturnX() << endl;
			return ProtectAction_BCN;
		}
		else
			return ProtectNoAction;
	}
	else if (Z_m.second == InterPhaseGround_Fault_CA)
	{
		if (DPCoreAlgorithmQuad_��(Z_m.second))
		{
			FixTimeDelay(30);
			EndTime = clock();
			cout << "�������ζ���" << (double)(EndTime - StartTime) / (CLOCKS_PER_SEC) * 1000 << "ms" << endl;
			cout << "����R=" << Z_m.first.ReturnR() << "    " << "�翹Z=" << Z_m.first.ReturnX() << endl;
			return ProtectAction_CAN;
		}
		else if (DPCoreAlgorithmQuad_��(Z_m.second))
		{
			double time = UseSetValue.GetValue(ProtectDevice, "��������ʱ��");
			FixTimeDelay(time * 1000 + ��_DPFixDelay + FixTimeError(time));
			EndTime = clock();
			cout << "�������ζ���" << (double)(EndTime - StartTime) / (CLOCKS_PER_SEC) * 1000 << "ms" << endl;
			cout << "����R=" << Z_m.first.ReturnR() << "    " << "�翹Z=" << Z_m.first.ReturnX() << endl;
			return ProtectAction_CAN;
		}
		else if (DPCoreAlgorithmQuad_��(Z_m.second))
		{
			double time = UseSetValue.GetValue(ProtectDevice, "��������ʱ��");
			FixTimeDelay(time * 1000 + ��_DPFixDelay + FixTimeError(time));
			EndTime = clock();
			cout << "�������ζ���" << (double)(EndTime - StartTime) / (CLOCKS_PER_SEC) * 1000 << "ms" << endl;
			cout << "����R=" << Z_m.first.ReturnR() << "    " << "�翹Z=" << Z_m.first.ReturnX() << endl;
			return ProtectAction_CAN;
		}
		else
			return ProtectNoAction;
	}
	else if (Z_m.second == ThreePhase_Fault)
	{
		if (DPCoreAlgorithmQuad_��(Z_m.second))
		{
			FixTimeDelay(30);
			EndTime = clock();
			cout << "�������ζ���" << (double)(EndTime - StartTime) / (CLOCKS_PER_SEC) * 1000 << "ms" << endl;
			cout << "����R=" << Z_m.first.ReturnR() << "    " << "�翹Z=" << Z_m.first.ReturnX() << endl;
			return ProtectAction_ABC;
		}
		else if (DPCoreAlgorithmQuad_��(Z_m.second))
		{
			double time = UseSetValue.GetValue(ProtectDevice, "��������ʱ��");
			FixTimeDelay(time * 1000 + ��_DPFixDelay + FixTimeError(time));
			EndTime = clock();
			cout << "�������ζ���" << (double)(EndTime - StartTime) / (CLOCKS_PER_SEC) * 1000 << "ms" << endl;
			cout << "����R=" << Z_m.first.ReturnR() << "    " << "�翹Z=" << Z_m.first.ReturnX() << endl;
			return ProtectAction_ABC;
		}
		else if (DPCoreAlgorithmQuad_��(Z_m.second))
		{
			double time = UseSetValue.GetValue(ProtectDevice, "��������ʱ��");
			FixTimeDelay(time * 1000 + ��_DPFixDelay + FixTimeError(time));
			EndTime = clock();
			cout << "�������ζ���" << (double)(EndTime - StartTime) / (CLOCKS_PER_SEC) * 1000 << "ms" << endl;
			cout << "����R=" << Z_m.first.ReturnR() << "    " << "�翹Z=" << Z_m.first.ReturnX() << endl;
			return ProtectAction_ABC;
		}
		else
			return ProtectNoAction;
	}
	else
	{
		return ProtectNoAction;
	}
}

int Distance_Protection::DPCoreAlgorithmQuad_��(double FaultStyle)
{
	double JudgePara1_��,JudgePara2_��,JudgePara3_��;
	Resistance_Impedance Z_set_��;
	if (FaultStyle == SingleEarth_Fault_A || FaultStyle == SingleEarth_Fault_B || FaultStyle == SingleEarth_Fault_C
		|| FaultStyle == InterPhaseGround_Fault_AB || FaultStyle == InterPhaseGround_Fault_BC || FaultStyle == InterPhaseGround_Fault_CA)
	{
		Z_set_�� = Resistance_Impedance(UseSetValue.GetValue(ProtectDevice, "�ӵؾ�����"), UseSetValue.GetValue(ProtectDevice, "��·����������"));
	}
	else
	{
		Z_set_�� = Resistance_Impedance(UseSetValue.GetValue(ProtectDevice, "��������"), UseSetValue.GetValue(ProtectDevice, "��·����������"));
	}
	JudgePara1_�� = arg(Z_m.first.ReturnZComplex()) * 180 / M_PI;
	if (JudgePara1_�� >= -15 && JudgePara1_�� <= 105)
	{
		if (JudgePara1_�� >= 0 && JudgePara1_�� <= 90)
		{
			JudgePara2_�� = arg((Z_m.first.ReturnZComplex() - Z_set_��.ReturnZComplex()) / Z_m.first.ReturnZComplex().real()) * 180 / M_PI;
			JudgePara3_�� = arg((Z_m.first.ReturnZComplex() - Z_set_��.ReturnZComplex().real()) / Z_m.first.ReturnZComplex().imag()) * 180 / M_PI;
			if ((JudgePara2_�� <= -7 && JudgePara3_�� >= -173) && (JudgePara3_�� >= 30 && JudgePara3_�� <= 210))
				return 1;
			else
				return 0;
		}
		else if (JudgePara1_�� >= -15 && JudgePara1_�� < 0)
		{
			if (Z_m.first.ReturnZComplex().real() < Z_set_��.ReturnZComplex().real())
				return 1;
			else
				return 0;
		}
		else
		{
			if (Z_m.first.ReturnZComplex().imag() < Z_set_��.ReturnZComplex().imag())
				return 1;
			else
				return 0;
		}
	}
	else
		return 0;
}

int Distance_Protection::DPCoreAlgorithmQuad_��(double FaultStyle)
{
	double JudgePara1_��, JudgePara2_��, JudgePara3_��;
	Resistance_Impedance Z_set_��;
	if (FaultStyle == SingleEarth_Fault_A || FaultStyle == SingleEarth_Fault_B || FaultStyle == SingleEarth_Fault_C
		|| FaultStyle == InterPhaseGround_Fault_AB || FaultStyle == InterPhaseGround_Fault_BC || FaultStyle == InterPhaseGround_Fault_CA)
	{
		Z_set_�� = Resistance_Impedance(UseSetValue.GetValue(ProtectDevice, "�ӵؾ�����"), UseSetValue.GetValue(ProtectDevice, "��·����������"));
	}
	else
	{
		Z_set_�� = Resistance_Impedance(UseSetValue.GetValue(ProtectDevice, "��������"), UseSetValue.GetValue(ProtectDevice, "��·����������"));
	}
	JudgePara1_�� = arg(Z_m.first.ReturnZComplex()) * 180 / M_PI;
	if (JudgePara1_�� >= -15 && JudgePara1_�� <= 105)
	{
		if (JudgePara1_�� >= 0 && JudgePara1_�� <= 90)
		{
			JudgePara2_�� = arg((Z_m.first.ReturnZComplex() - Z_set_��.ReturnZComplex()) / Z_m.first.ReturnZComplex().real()) * 180 / M_PI;
			JudgePara3_�� = arg((Z_m.first.ReturnZComplex() - Z_set_��.ReturnZComplex().real()) / Z_m.first.ReturnZComplex().imag()) * 180 / M_PI;
			if ((JudgePara2_�� <= -7 && JudgePara3_�� >= -173) && (JudgePara3_�� >= 30 && JudgePara3_�� <= 210))
				return 1;
			else
				return 0;
		}
		else if (JudgePara1_�� >= -15 && JudgePara1_�� < 0)
		{
			if (Z_m.first.ReturnZComplex().real() < Z_set_��.ReturnZComplex().real())
				return 1;
			else
				return 0;
		}
		else
		{
			if (Z_m.first.ReturnZComplex().imag() < Z_set_��.ReturnZComplex().imag())
				return 1;
			else
				return 0;
		}
	}
	else
		return 0;
}

int Distance_Protection::DPCoreAlgorithmQuad_��(double FaultStyle)
{
	double JudgePara1_��, JudgePara2_��, JudgePara3_��;
	Resistance_Impedance Z_set_��;
	if (FaultStyle == SingleEarth_Fault_A || FaultStyle == SingleEarth_Fault_B || FaultStyle == SingleEarth_Fault_C
		|| FaultStyle == InterPhaseGround_Fault_AB || FaultStyle == InterPhaseGround_Fault_BC || FaultStyle == InterPhaseGround_Fault_CA)
	{
		Z_set_�� = Resistance_Impedance(UseSetValue.GetValue(ProtectDevice, "�ӵؾ�����"), UseSetValue.GetValue(ProtectDevice, "��·����������"));
	}
	else
	{
		Z_set_�� = Resistance_Impedance(UseSetValue.GetValue(ProtectDevice, "��������"), UseSetValue.GetValue(ProtectDevice, "��·����������"));
	}
	JudgePara1_�� = arg(Z_m.first.ReturnZComplex()) * 180 / M_PI;
	if (JudgePara1_�� >= -15 && JudgePara1_�� <= 105)
	{
		if (JudgePara1_�� >= 0 && JudgePara1_�� <= 90)
		{
			JudgePara2_�� = arg((Z_m.first.ReturnZComplex() - Z_set_��.ReturnZComplex()) / Z_m.first.ReturnZComplex().real()) * 180 / M_PI;
			JudgePara3_�� = arg((Z_m.first.ReturnZComplex() - Z_set_��.ReturnZComplex().real()) / Z_m.first.ReturnZComplex().imag()) * 180 / M_PI;
			if ((JudgePara2_�� <= -7 && JudgePara3_�� >= -173) && (JudgePara3_�� >= 30 && JudgePara3_�� <= 210))
				return 1;
			else
				return 0;
		}
		else if (JudgePara1_�� >= -15 && JudgePara1_�� < 0)
		{
			if (Z_m.first.ReturnZComplex().real() < Z_set_��.ReturnZComplex().real())
				return 1;
			else
				return 0;
		}
		else
		{
			if (Z_m.first.ReturnZComplex().imag() < Z_set_��.ReturnZComplex().imag())
				return 1;
			else
				return 0;
		}
	}
	else
		return 0;
}
