#include "Distance_Protection.h"
Distance_Protection::Distance_Protection(vector<Electric_Voltage> U, vector<Electric_Current> I)
{
	U_m = U;
	I_m = I;
	Z_m = CaculateZ_m(U, I);
	ProtectActionState = ProtectNoAction;
	Which_Protection = ProtectNoAction;
	ActionTime = 0;
	Fault = FaultToProtection[Z_m.second];
}

Distance_Protection::Distance_Protection()
{
	U_m = { Electric_Voltage(0, 0), Electric_Voltage(0, 0), Electric_Voltage(0, 0) };
	I_m = { Electric_Current(0, 0), Electric_Current(0, 0), Electric_Current(0, 0) };
	Z_m = CaculateZ_m(U_m, I_m);
	ProtectActionState = ProtectNoAction;
	Which_Protection = ProtectNoAction;
	ActionTime = 0;
	Fault = FaultToProtection[Z_m.second];
}

int Distance_Protection::DPCoreAlgorithmOne_Ⅰ(double FaultStyle)
{
	double JudgePara_Ⅰ;
	Resistance_Impedance Z_set_Ⅰ;
	if (FaultStyle == SingleEarth_Fault_A || FaultStyle == SingleEarth_Fault_B || FaultStyle == SingleEarth_Fault_C
		|| FaultStyle == InterPhaseGround_Fault_AB || FaultStyle == InterPhaseGround_Fault_BC || FaultStyle == InterPhaseGround_Fault_CA)
	{
		Z_set_Ⅰ = Resistance_Impedance(UseSetValue.GetValue(ProtectDevice, "接地距离Ⅰ段"), UseSetValue.GetValue(ProtectDevice, "线路正序灵敏角"));
	}
	else
	{
		Z_set_Ⅰ = Resistance_Impedance(UseSetValue.GetValue(ProtectDevice, "相间距离Ⅰ段"), UseSetValue.GetValue(ProtectDevice, "线路正序灵敏角"));
	}
	JudgePara_Ⅰ = arg((Z_m.first.ReturnZComplex() - Z_set_Ⅰ.ReturnZComplex()) / Z_m.first.ReturnZComplex()) * 180 / M_PI;
	if ((JudgePara_Ⅰ > 90 && JudgePara_Ⅰ <= 180.001)|| (JudgePara_Ⅰ < -90 && JudgePara_Ⅰ >= -180.001))
		return 1;
	else
		return 0;
}

int Distance_Protection::DPCoreAlgorithmOne_Ⅱ(double FaultStyle)
{
	double JudgePara_Ⅱ;
	Resistance_Impedance Z_set_Ⅱ;
	if (FaultStyle == SingleEarth_Fault_A || FaultStyle == SingleEarth_Fault_B || FaultStyle == SingleEarth_Fault_C
		|| FaultStyle == InterPhaseGround_Fault_AB || FaultStyle == InterPhaseGround_Fault_BC || FaultStyle == InterPhaseGround_Fault_CA)
	{
		Z_set_Ⅱ = Resistance_Impedance(UseSetValue.GetValue(ProtectDevice, "接地距离Ⅱ段"), UseSetValue.GetValue(ProtectDevice, "线路正序灵敏角"));
	}
	else
	{
		Z_set_Ⅱ = Resistance_Impedance(UseSetValue.GetValue(ProtectDevice, "相间距离Ⅱ段"), UseSetValue.GetValue(ProtectDevice, "线路正序灵敏角"));
	}
	JudgePara_Ⅱ = arg((Z_m.first.ReturnZComplex() - Z_set_Ⅱ.ReturnZComplex()) / Z_m.first.ReturnZComplex()) * 180 / M_PI;
	if ((JudgePara_Ⅱ > 90 && JudgePara_Ⅱ <= 180.001) || (JudgePara_Ⅱ < -90 && JudgePara_Ⅱ >= -180.001))
		return 1;
	else
		return 0;
}

int Distance_Protection::DPCoreAlgorithmOne_Ⅲ(double FaultStyle)
{
	double JudgePara_Ⅲ;
	Resistance_Impedance Z_set_Ⅲ;
	if (FaultStyle == SingleEarth_Fault_A || FaultStyle == SingleEarth_Fault_B || FaultStyle == SingleEarth_Fault_C
		|| FaultStyle == InterPhaseGround_Fault_AB || FaultStyle == InterPhaseGround_Fault_BC || FaultStyle == InterPhaseGround_Fault_CA)
	{
		Z_set_Ⅲ = Resistance_Impedance(UseSetValue.GetValue(ProtectDevice, "接地距离Ⅲ段"), UseSetValue.GetValue(ProtectDevice, "线路正序灵敏角"));
	}
	else
	{
		Z_set_Ⅲ = Resistance_Impedance(UseSetValue.GetValue(ProtectDevice, "相间距离Ⅲ段"), UseSetValue.GetValue(ProtectDevice, "线路正序灵敏角"));
	}
	JudgePara_Ⅲ = arg((Z_m.first.ReturnZComplex() - Z_set_Ⅲ.ReturnZComplex()) / Z_m.first.ReturnZComplex()) * 180 / M_PI;
	if ((JudgePara_Ⅲ > 90 && JudgePara_Ⅲ <= 180.001) || (JudgePara_Ⅲ < -90 && JudgePara_Ⅲ >= -180.001))
		return 1;
	else
		return 0;
	return 0;
}

void Distance_Protection::DistanceProtection()
{
	double timeⅡ;
	double timeⅢ;
	double timeⅠ;//继电器动作固有延时
	if (Z_m.second == SingleEarth_Fault_A || Z_m.second == SingleEarth_Fault_B || Z_m.second == SingleEarth_Fault_C)
	{
		timeⅠ = Ⅰ_DPFixDelay;
		timeⅡ = UseSetValue.GetValue(ProtectDevice, "接地距离Ⅱ段时间");
		timeⅢ = UseSetValue.GetValue(ProtectDevice, "接地距离Ⅲ段时间");
	}
	else
	{
		timeⅡ = UseSetValue.GetValue(ProtectDevice, "相间距离Ⅱ段时间");
		timeⅢ = UseSetValue.GetValue(ProtectDevice, "相间距离Ⅲ段时间");
	}
	SetTimer(AfxGetMainWnd()->GetSafeHwnd(), TIME_DEVICE_DP_ALG_1, Ⅰ_DPFixDelay, NULL);
	SetTimer(AfxGetMainWnd()->GetSafeHwnd(), TIME_DEVICE_DP_ALG_2, timeⅡ * 1000 + Ⅰ_DPFixDelay, NULL);
	SetTimer(AfxGetMainWnd()->GetSafeHwnd(), TIME_DEVICE_DP_ALG_3, timeⅢ * 1000 + Ⅰ_DPFixDelay, NULL);
}

int Distance_Protection::DPCoreAlgorithmQuad_Ⅰ(double FaultStyle)
{
	double JudgePara1_Ⅰ,JudgePara2_Ⅰ,JudgePara3_Ⅰ;
	Resistance_Impedance Z_set_Ⅰ;
	if (FaultStyle == SingleEarth_Fault_A || FaultStyle == SingleEarth_Fault_B || FaultStyle == SingleEarth_Fault_C
		|| FaultStyle == InterPhaseGround_Fault_AB || FaultStyle == InterPhaseGround_Fault_BC || FaultStyle == InterPhaseGround_Fault_CA)
	{
		Z_set_Ⅰ = Resistance_Impedance(UseSetValue.GetValue(ProtectDevice, "接地距离Ⅰ段"), UseSetValue.GetValue(ProtectDevice, "线路正序灵敏角"));
		SetWhich_Protection(JieDiJuLi_ⅠAction);
	}
	if(FaultStyle==InterPhase_Fault_AB|| FaultStyle == InterPhase_Fault_BC|| FaultStyle == InterPhase_Fault_CA|| FaultStyle == ThreePhase_Fault)
	{
		Z_set_Ⅰ = Resistance_Impedance(UseSetValue.GetValue(ProtectDevice, "相间距离Ⅰ段"), UseSetValue.GetValue(ProtectDevice, "线路正序灵敏角"));
		SetWhich_Protection(XiangJianJuLi_ⅠAction);
	}
	JudgePara1_Ⅰ = arg(Z_m.first.ReturnZComplex()) * 180 / M_PI;
	if (JudgePara1_Ⅰ >= -15 && JudgePara1_Ⅰ <= 105&&Z_set_Ⅰ.ReturnZValid()!=0)
	{
		if (JudgePara1_Ⅰ > 0 && JudgePara1_Ⅰ < 90)
		{
			JudgePara2_Ⅰ = arg((Z_m.first.ReturnZComplex() - Z_set_Ⅰ.ReturnZComplex()) / Z_m.first.ReturnZComplex().real()) * 180 / M_PI;
			JudgePara3_Ⅰ = arg((Z_m.first.ReturnZComplex() - Z_set_Ⅰ.ReturnZComplex().real()) / Z_m.first.ReturnZComplex().imag()) * 180 / M_PI;
			if ((JudgePara2_Ⅰ <= -7 && JudgePara3_Ⅰ >= -173) && (JudgePara3_Ⅰ >= 30 && JudgePara3_Ⅰ <= 210))
				return 1;
			else
			{
				SetWhich_Protection(ProtectNoAction);
				return 0;
			}
		}
		else if (JudgePara1_Ⅰ >= -15 && JudgePara1_Ⅰ <= 0)
		{
			if (Z_m.first.ReturnZComplex().real() < 8*Z_set_Ⅰ.ReturnZComplex().real())
				return 1;
			else
			{
				SetWhich_Protection(ProtectNoAction);
				return 0;
			}
		}
		else
		{
			if (Z_m.first.ReturnZComplex().imag() < Z_set_Ⅰ.ReturnZComplex().imag())
				return 1;
			else
			{
				SetWhich_Protection(ProtectNoAction);
				return 0;
			}
		}
	}
	else
	{
		SetWhich_Protection(ProtectNoAction);
		return 0;
	}
}

int Distance_Protection::DPCoreAlgorithmQuad_Ⅱ(double FaultStyle)
{
	double JudgePara1_Ⅰ, JudgePara2_Ⅰ, JudgePara3_Ⅰ;
	Resistance_Impedance Z_set_Ⅰ;
	if (FaultStyle == SingleEarth_Fault_A || FaultStyle == SingleEarth_Fault_B || FaultStyle == SingleEarth_Fault_C
		|| FaultStyle == InterPhaseGround_Fault_AB || FaultStyle == InterPhaseGround_Fault_BC || FaultStyle == InterPhaseGround_Fault_CA || FaultStyle == ThreePhase_Fault)
	{
		Z_set_Ⅰ = Resistance_Impedance(UseSetValue.GetValue(ProtectDevice, "接地距离Ⅱ段"), UseSetValue.GetValue(ProtectDevice, "线路正序灵敏角"));
		SetWhich_Protection(JieDiJuLi_ⅡAction);
	}
	if (FaultStyle == InterPhase_Fault_AB || FaultStyle == InterPhase_Fault_BC || FaultStyle == InterPhase_Fault_CA)
	{
		Z_set_Ⅰ = Resistance_Impedance(UseSetValue.GetValue(ProtectDevice, "相间距离Ⅱ段"), UseSetValue.GetValue(ProtectDevice, "线路正序灵敏角"));
		SetWhich_Protection(XiangJianJuLi_ⅡAction);
	}
	JudgePara1_Ⅰ = arg(Z_m.first.ReturnZComplex()) * 180 / M_PI;
	if (JudgePara1_Ⅰ >= -15 && JudgePara1_Ⅰ <= 105 && Z_set_Ⅰ.ReturnZValid() != 0)
	{
		if (JudgePara1_Ⅰ > 0 && JudgePara1_Ⅰ < 90)
		{
			JudgePara2_Ⅰ = arg((Z_m.first.ReturnZComplex() - Z_set_Ⅰ.ReturnZComplex()) / Z_m.first.ReturnZComplex().real()) * 180 / M_PI;
			JudgePara3_Ⅰ = arg((Z_m.first.ReturnZComplex() - Z_set_Ⅰ.ReturnZComplex().real()) / Z_m.first.ReturnZComplex().imag()) * 180 / M_PI;
			if ((JudgePara2_Ⅰ <= -7 && JudgePara3_Ⅰ >= -173) && (JudgePara3_Ⅰ >= 30 && JudgePara3_Ⅰ <= 210))
				return 1;
			else
			{
				SetWhich_Protection(ProtectNoAction);
				return 0;
			}
		}
		else if (JudgePara1_Ⅰ >= -15 && JudgePara1_Ⅰ <= 0)
		{
			if (Z_m.first.ReturnZComplex().real() < 8*Z_set_Ⅰ.ReturnZComplex().real())
				return 1;
			else
			{
				SetWhich_Protection(ProtectNoAction);
				return 0;
			}
		}
		else
		{
			if (Z_m.first.ReturnZComplex().imag() < Z_set_Ⅰ.ReturnZComplex().imag())
				return 1;
			else
			{
				SetWhich_Protection(ProtectNoAction);
				return 0;
			}
		}
	}
	else
	{
		SetWhich_Protection(ProtectNoAction);
		return 0;
	}
}

int Distance_Protection::DPCoreAlgorithmQuad_Ⅲ(double FaultStyle)
{
	double JudgePara1_Ⅰ, JudgePara2_Ⅰ, JudgePara3_Ⅰ;
	Resistance_Impedance Z_set_Ⅰ;
	if (FaultStyle == SingleEarth_Fault_A || FaultStyle == SingleEarth_Fault_B || FaultStyle == SingleEarth_Fault_C
		|| FaultStyle == InterPhaseGround_Fault_AB || FaultStyle == InterPhaseGround_Fault_BC || FaultStyle == InterPhaseGround_Fault_CA)
	{
		Z_set_Ⅰ = Resistance_Impedance(UseSetValue.GetValue(ProtectDevice, "接地距离Ⅲ段"), UseSetValue.GetValue(ProtectDevice, "线路正序灵敏角"));
		SetWhich_Protection(JieDiJuLi_ⅢAction);
	}
	if (FaultStyle == InterPhase_Fault_AB || FaultStyle == InterPhase_Fault_BC || FaultStyle == InterPhase_Fault_CA || FaultStyle == ThreePhase_Fault)
	{
		Z_set_Ⅰ = Resistance_Impedance(UseSetValue.GetValue(ProtectDevice, "相间距离Ⅲ段"), UseSetValue.GetValue(ProtectDevice, "线路正序灵敏角"));
		SetWhich_Protection(XiangJianJuLi_ⅢAction);
	}
	JudgePara1_Ⅰ = arg(Z_m.first.ReturnZComplex()) * 180 / M_PI;
	if (JudgePara1_Ⅰ >= -15 && JudgePara1_Ⅰ <= 105 && Z_set_Ⅰ.ReturnZValid() != 0)
	{
		if (JudgePara1_Ⅰ > 0 && JudgePara1_Ⅰ < 90)
		{
			JudgePara2_Ⅰ = arg((Z_m.first.ReturnZComplex() - Z_set_Ⅰ.ReturnZComplex()) / Z_m.first.ReturnZComplex().real()) * 180 / M_PI;
			JudgePara3_Ⅰ = arg((Z_m.first.ReturnZComplex() - Z_set_Ⅰ.ReturnZComplex().real()) / Z_m.first.ReturnZComplex().imag()) * 180 / M_PI;
			if ((JudgePara2_Ⅰ <= -7 && JudgePara3_Ⅰ >= -173) && (JudgePara3_Ⅰ >= 30 && JudgePara3_Ⅰ <= 210))
				return 1;
			else
			{
				SetWhich_Protection(ProtectNoAction);
				return 0;
			}
		}
		else if (JudgePara1_Ⅰ >= -15 && JudgePara1_Ⅰ <= 0)
		{
			if (Z_m.first.ReturnZComplex().real() < 8*Z_set_Ⅰ.ReturnZComplex().real())
				return 1;
			else
			{
				SetWhich_Protection(ProtectNoAction);
				return 0;
			}
		}
		else
		{
			if (Z_m.first.ReturnZComplex().imag() < Z_set_Ⅰ.ReturnZComplex().imag())
				return 1;
			else
			{
				SetWhich_Protection(ProtectNoAction);
				return 0;
			}
		}
	}
	else
	{
		SetWhich_Protection(ProtectNoAction);
		return 0;
	}
}

ActionState Distance_Protection::GetProtectAcionState()
{
	return ProtectActionState;
}

ActionState Distance_Protection::GetWhich_Protection()
{
	return Which_Protection;
}

double Distance_Protection::GetActionTime()
{
	return ActionTime;
}

pair<Resistance_Impedance, double> Distance_Protection::GetZ_m()
{
	return Z_m;
}

void Distance_Protection::SetUI(vector<Electric_Voltage> U, vector<Electric_Current> I)
{
	U_m = U;
	I_m = I;
	Z_m = CaculateZ_m(U, I);
	Fault = FaultToProtection[Z_m.second];
}

void Distance_Protection::SetProtectActionState(ActionState stat)
{
	ProtectActionState = stat;
}

vector<Electric_Voltage> Distance_Protection::GetU_m()
{
	return U_m;
}

vector<Electric_Current> Distance_Protection::GetI_m()
{
	return I_m;
}

void Distance_Protection::SetActionTime(double time)
{
	ActionTime = time;
}

void Distance_Protection::SetWhich_Protection(int Pro)
{
	Which_Protection = Pro;
}

int Distance_Protection::GetFault()
{
	return Fault;
}
