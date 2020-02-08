#include "Protection_Lib.h"

int JudgeFaultStyle_PhaseDiff(vector<Electric_Current> I_m)
{
	double I_AB = abs(I_m[0].ReturnIComplex() - I_m[1].ReturnIComplex());
	double I_BC = abs(I_m[1].ReturnIComplex() - I_m[2].ReturnIComplex());
	double I_CA = abs(I_m[2].ReturnIComplex() - I_m[0].ReturnIComplex());
	if (CompareDouble(I_AB, I_BC) == 1 && CompareDouble(I_CA, I_BC) == 1)
		return SingleEarth_Fault_A;
	else if (CompareDouble(I_AB, I_CA) == 1 && CompareDouble(I_BC, I_CA) == 1)
		return SingleEarth_Fault_B;
	else if (CompareDouble(I_BC, I_AB) == 1 && CompareDouble(I_CA, I_AB) == 1)
		return SingleEarth_Fault_C;
	else if (CompareDouble(I_AB, I_BC) == 1 && CompareDouble(I_AB, I_CA) == 1)
		return InterPhase_Fault_AB;
	else if (CompareDouble(I_BC, I_AB) == 1 && CompareDouble(I_BC, I_CA) == 1)
		return InterPhase_Fault_BC;
	else if (CompareDouble(I_CA, I_AB) == 1 && CompareDouble(I_CA, I_BC) == 1)
		return InterPhase_Fault_CA;
	else if (CompareDouble(I_AB, I_BC) == 0 && CompareDouble(I_CA, I_BC) == 0 && CompareDouble(I_AB, 0) != 0)
		return ThreePhase_Fault;
	else
		return Judge_Fault_ERROR;
}

int JudgeFaultStyle_ZerotoANegtive(vector<Electric_Voltage>V_m, vector<Electric_Current> I_m, double Z_InterPhase)
{
	Electric_Current I_Zero = GetZeroSeq(I_m[0], I_m[1], I_m[2]);
	if (CompareDouble(I_Zero.GetIValid(), 0) == 0)
		return 0;
	Electric_Current I_A_Negtive = GetNegativeSeq(I_m[0], I_m[1], I_m[2], 'A');
	int JudgePhase = arg(I_A_Negtive.ReturnIComplex()/I_Zero.ReturnIComplex() ) * 180 / M_PI;
	if (JudgePhase > 30 && JudgePhase < 90)
		return InterPhaseGround_Fault_AB;
	else if (JudgePhase > 150 && JudgePhase <= 180 || JudgePhase>=-180 && JudgePhase < -150)
		return InterPhaseGround_Fault_CA;
	else if (JudgePhase > -90 && JudgePhase < -30)
		return InterPhaseGround_Fault_BC;
	else if (JudgePhase >-30 && JudgePhase <= 30)
	{
		if((I_m[1]-I_m[2]).GetIValid()==0)
			return SingleEarth_Fault_A;
		else
		{
			Resistance_Impedance Z_m = (V_m[1] - V_m[2]) / (I_m[1] - I_m[2]);//求相间阻抗
			if (Z_m.ReturnZValid() > Z_InterPhase)
				return SingleEarth_Fault_A;
			else
				return InterPhaseGround_Fault_BC;
		}
	}
	else if (JudgePhase > 90 && JudgePhase < 150)
	{
		if((I_m[0] - I_m[1]).GetIValid()==0)
			return SingleEarth_Fault_C;
		else
		{
			Resistance_Impedance Z_m = (V_m[0] - V_m[1]) / (I_m[0] - I_m[1]);//求相间阻抗
			if (Z_m.ReturnZValid() > Z_InterPhase)
				return SingleEarth_Fault_C;
			else
				return InterPhaseGround_Fault_AB;
		}
	}
	else if (JudgePhase > -150 && JudgePhase < -90)
	{
		if((I_m[2] - I_m[0]).GetIValid()==0)
			return SingleEarth_Fault_B;
		else
		{
			Resistance_Impedance Z_m = (V_m[2] - V_m[0]) / (I_m[2] - I_m[0]);//求相间阻抗
			if (Z_m.ReturnZValid() > Z_InterPhase)
				return SingleEarth_Fault_B;
			else
				return InterPhaseGround_Fault_CA;
		}
	}
	else
		return Judge_Fault_ERROR;
}

pair<Resistance_Impedance, double> CaculateZ_m(vector<Electric_Voltage> U, vector<Electric_Current> I)
{
	Resistance_Impedance Z_m;
	double Z_s;
    double K = UseSetValue.GetValue(ProtectDevice, "零序电抗补偿系数");
	auto PhaseDiff_res = JudgeFaultStyle_PhaseDiff(I);
	auto ZeroDiff_res = JudgeFaultStyle_ZerotoANegtive(U, I, UseSetValue.GetValue(ProtectDevice, "接地距离Ⅲ段"));
	if (PhaseDiff_res == SingleEarth_Fault_A)
	{
		if (ZeroDiff_res == InterPhaseGround_Fault_BC)
		{
			Z_m = U[1] / (I[1] * (1+K));//相间故障无需K值
			Z_s = InterPhaseGround_Fault_BC;
			pair<Resistance_Impedance, double> Z = make_pair(Z_m, Z_s);
			return Z;
		}
		else
		{
			Z_m = U[0] / (I[0] * (1 + K));//A相
			Z_s = SingleEarth_Fault_A;
			pair<Resistance_Impedance, double> Z = make_pair(Z_m, Z_s);
			return Z;
		}
	}
	else if (PhaseDiff_res == SingleEarth_Fault_B)
	{
		if (ZeroDiff_res == InterPhaseGround_Fault_CA)
		{
			Z_m = U[2] / (I[2] * (1 + K));//相间故障无需K值
			Z_s = InterPhaseGround_Fault_CA;
			pair<Resistance_Impedance, double> Z = make_pair(Z_m, Z_s);
			return Z;
		}
		else
		{
			Z_m = U[1] / (I[1] * (1 + K));//B相
			Z_s = SingleEarth_Fault_B;
			pair<Resistance_Impedance, double> Z = make_pair(Z_m, Z_s);
			return Z;
		}
		
	}
	else if (PhaseDiff_res == SingleEarth_Fault_C)
	{
		if (ZeroDiff_res == InterPhaseGround_Fault_AB)
		{
			Z_m = U[0] / (I[0] * (1 + K));//相间故障无需K值
			Z_s = InterPhaseGround_Fault_AB;
			pair<Resistance_Impedance, double> Z = make_pair(Z_m, Z_s);
			return Z;
		}
		else
		{
			Z_m = U[2] / (I[2] * (1 + K));//C相
			Z_s = SingleEarth_Fault_C;
			pair<Resistance_Impedance, double> Z = make_pair(Z_m, Z_s);
			return Z;
		}
	}
	else if (PhaseDiff_res == InterPhase_Fault_AB)
	{
		if (ZeroDiff_res == InterPhaseGround_Fault_AB)
		{
			Z_m = U[0] / (I[0] * (1 + K));//相间故障无需K值
			Z_s = InterPhaseGround_Fault_AB;
			pair<Resistance_Impedance, double> Z = make_pair(Z_m, Z_s);
			return Z;
		}
		else
		{
			Z_m = (U[0] - U[1]) / (I[0] - I[1]);//相间故障无需K值
			Z_s = InterPhase_Fault_AB;
			pair<Resistance_Impedance, double> Z = make_pair(Z_m, Z_s);
			return Z;
		}
	}
	else if (PhaseDiff_res == InterPhase_Fault_BC)
	{
		if (ZeroDiff_res == InterPhaseGround_Fault_BC)
		{
			Z_m = U[1] / (I[1] * (1 + K));//相间故障无需K值
			Z_s = InterPhaseGround_Fault_BC;
			pair<Resistance_Impedance, double> Z = make_pair(Z_m, Z_s);
			return Z;
		}
		else
		{
			Z_m = (U[1] - U[2]) / (I[1] - I[2]);//相间故障无需K值
			Z_s = InterPhase_Fault_BC;
			pair<Resistance_Impedance, double> Z = make_pair(Z_m, Z_s);
			return Z;
		}
	}
	else if (PhaseDiff_res == InterPhase_Fault_CA)
	{
		if (ZeroDiff_res == InterPhaseGround_Fault_CA)
		{
			Z_m = U[2] / (I[2] * (1 + K));//相间故障无需K值
			Z_s = InterPhaseGround_Fault_CA;
			pair<Resistance_Impedance, double> Z = make_pair(Z_m, Z_s);
			return Z;
		}
		else
		{
			Z_m = (U[2] - U[0]) / (I[2] - I[0]);//相间故障无需K值
			Z_s = InterPhase_Fault_CA;
			pair<Resistance_Impedance, double> Z = make_pair(Z_m, Z_s);
			return Z;
		}
	}
	else if (PhaseDiff_res == ThreePhase_Fault)
	{
		Z_m =(U[0]-U[1])/(I[0]-I[1]);
		Z_s = ThreePhase_Fault;
		pair<Resistance_Impedance, double> Z = make_pair(Z_m, Z_s);
		return Z;
	}
	else
		return pair<Resistance_Impedance, double>();
}

pair<pair<Electric_Voltage, Electric_Current>, double > Caculate_UZ_IZ(vector<Electric_Voltage>U, vector<Electric_Current> I)
{
	Electric_Voltage U0;
	Electric_Current I0;
	auto ZeroDiff_res = JudgeFaultStyle_ZerotoANegtive(U, I, UseSetValue.GetValue(ProtectDevice, "接地距离Ⅲ段"));//用零序电流与A相正序电压比较法
	auto PhaseDiff_res = JudgeFaultStyle_PhaseDiff(I);
	if (PhaseDiff_res == SingleEarth_Fault_A)
	{
		if (ZeroDiff_res == InterPhaseGround_Fault_BC)
		{
			U0 = GetZeroSeq(U[0], U[1], U[2]);
			I0 = GetZeroSeq(I[0], I[1], I[2]);
			pair<pair<Electric_Voltage, Electric_Current>, double > UI = make_pair(make_pair(U0,I0),InterPhaseGround_Fault_BC);
			return UI;
		}
		else
		{
			U0 = GetZeroSeq(U[0], U[1], U[2]);
			I0 = GetZeroSeq(I[0], I[1], I[2]);
			pair<pair<Electric_Voltage, Electric_Current>, double > UI = make_pair(make_pair(U0, I0), SingleEarth_Fault_A);
			return UI;
		}
	}
	else if (PhaseDiff_res == SingleEarth_Fault_B)
	{
		if (ZeroDiff_res == InterPhaseGround_Fault_CA)
		{
			U0 = GetZeroSeq(U[0], U[1], U[2]);
			I0 = GetZeroSeq(I[0], I[1], I[2]);
			pair<pair<Electric_Voltage, Electric_Current>, double > UI = make_pair(make_pair(U0, I0), InterPhaseGround_Fault_CA);
			return UI;
		}
		else
		{
			U0 = GetZeroSeq(U[0], U[1], U[2]);
			I0 = GetZeroSeq(I[0], I[1], I[2]);
			pair<pair<Electric_Voltage, Electric_Current>, double > UI = make_pair(make_pair(U0, I0), SingleEarth_Fault_B);
			return UI;
		}
	}
	else if (PhaseDiff_res == SingleEarth_Fault_C)
	{
		if (ZeroDiff_res == InterPhaseGround_Fault_AB)
		{
			U0 = GetZeroSeq(U[0], U[1], U[2]);
			I0 = GetZeroSeq(I[0], I[1], I[2]);
			pair<pair<Electric_Voltage, Electric_Current>, double > UI = make_pair(make_pair(U0, I0), InterPhaseGround_Fault_AB);
			return UI;
		}
		else
		{
			U0 = GetZeroSeq(U[0], U[1], U[2]);
			I0 = GetZeroSeq(I[0], I[1], I[2]);
			pair<pair<Electric_Voltage, Electric_Current>, double > UI = make_pair(make_pair(U0, I0), SingleEarth_Fault_C);
			return UI;
		}
	}
	else if (PhaseDiff_res == InterPhase_Fault_AB)
	{
		if (ZeroDiff_res == InterPhaseGround_Fault_AB)
		{
			U0 = GetZeroSeq(U[0], U[1], U[2]);
			I0 = GetZeroSeq(I[0], I[1], I[2]);
			pair<pair<Electric_Voltage, Electric_Current>, double > UI = make_pair(make_pair(U0, I0), InterPhaseGround_Fault_AB);
			return UI;
		}
		else
			return pair<pair<Electric_Voltage, Electric_Current>, double >();
	}
	else if (JudgeFaultStyle_PhaseDiff(I) == InterPhase_Fault_BC)
	{
		if (ZeroDiff_res == InterPhaseGround_Fault_BC)
		{
			U0 = GetZeroSeq(U[0], U[1], U[2]);
			I0 = GetZeroSeq(I[0], I[1], I[2]);
			pair<pair<Electric_Voltage, Electric_Current>, double > UI = make_pair(make_pair(U0, I0), InterPhaseGround_Fault_BC);
			return UI;
		}
		else
			return pair<pair<Electric_Voltage, Electric_Current>, double >();
	}
	else if (JudgeFaultStyle_PhaseDiff(I) == InterPhase_Fault_CA)
	{
		if (ZeroDiff_res == InterPhaseGround_Fault_CA)
		{
			U0 = GetZeroSeq(U[0], U[1], U[2]);
			I0 = GetZeroSeq(I[0], I[1], I[2]);
			pair<pair<Electric_Voltage, Electric_Current>, double > UI = make_pair(make_pair(U0, I0), InterPhaseGround_Fault_CA);
			return UI;
		}
		else
			return pair<pair<Electric_Voltage, Electric_Current>, double >();
	}
	else
		return pair<pair<Electric_Voltage, Electric_Current>, double > ();
}

int CurrentBrustStart(vector<Electric_Current> I_m)
{
	double I_ABm = abs(I_m[0].ReturnIComplex() - I_m[1].ReturnIComplex());
	double I_BCm = abs(I_m[1].ReturnIComplex() - I_m[2].ReturnIComplex());
	double I_CAm = abs(I_m[2].ReturnIComplex() - I_m[0].ReturnIComplex());
	auto JudgePara = UseSetValue.GetValue(ProtectDevice, "变化量启动电流定值");
	if (I_ABm >= JudgePara || I_BCm >= JudgePara || I_CAm >= JudgePara)
		return 1;
	return 0;
}

char ChoosePhase(vector<double> Input)
{
	auto i = max(max(Input[0], Input[1]), Input[2]);
	if (i == Input[0])
		return 'A';
	if (i == Input[1])
		return 'B';
	if (i == Input[2])
		return 'C';
}

pair<pair<double,double>,pair<int,char> > Caculate_CurrentDiff(vector<Electric_Voltage> U_m, vector<Electric_Current> I_m, vector<Electric_Voltage> U_n, vector<Electric_Current> I_n)
{
	double I_A_Diff = abs(I_m[0].ReturnIComplex() + I_n[0].ReturnIComplex());//差动量
	double I_B_Diff = abs(I_m[1].ReturnIComplex() + I_n[1].ReturnIComplex());
	double I_C_Diff = abs(I_m[2].ReturnIComplex() + I_n[2].ReturnIComplex());
	double I_A_ZD = abs(I_m[0].ReturnIComplex() - I_n[0].ReturnIComplex());//制动量
	double I_B_ZD = abs(I_m[1].ReturnIComplex() - I_n[1].ReturnIComplex());//制动量
	double I_C_ZD = abs(I_m[2].ReturnIComplex() - I_n[2].ReturnIComplex());//制动量
	vector<Electric_Current> I_D = {Electric_Current(I_m[0].ReturnIComplex() + I_n[0].ReturnIComplex()),Electric_Current(I_m[1].ReturnIComplex() + I_n[1].ReturnIComplex()), Electric_Current(I_m[2].ReturnIComplex() + I_n[2].ReturnIComplex())};
	vector<double> i = { I_A_Diff ,I_B_Diff ,I_C_Diff };
	auto PhaseDiff_res = JudgeFaultStyle_PhaseDiff(I_D);
	auto ZeroDiff_res = JudgeFaultStyle_ZerotoANegtive(U_m, I_D, UseSetValue.GetValue(ProtectDevice, "接地距离Ⅲ段"));
	if (PhaseDiff_res == SingleEarth_Fault_A)
	{
		if (ZeroDiff_res == InterPhaseGround_Fault_BC)
			return make_pair(make_pair(max(I_B_Diff, I_C_Diff), min(I_B_ZD, I_C_ZD)), make_pair(ZeroDiff_res, ChoosePhase(i)));
		else
			return make_pair(make_pair(I_A_Diff, I_A_ZD), make_pair(PhaseDiff_res, ChoosePhase(i)));
	}
	else if (PhaseDiff_res == SingleEarth_Fault_B)
	{
		if (ZeroDiff_res == InterPhaseGround_Fault_CA)
			return make_pair(make_pair(max(I_A_Diff, I_C_Diff), min(I_A_ZD, I_C_ZD)), make_pair(ZeroDiff_res, ChoosePhase(i)));
		else
			return make_pair(make_pair(I_B_Diff, I_B_ZD), make_pair(PhaseDiff_res, ChoosePhase(i)));

	}
	else if (PhaseDiff_res == SingleEarth_Fault_C)
	{
		if (ZeroDiff_res == InterPhaseGround_Fault_AB)
			return make_pair(make_pair(max(I_A_Diff, I_B_Diff), min(I_A_ZD, I_B_ZD)), make_pair(ZeroDiff_res, ChoosePhase(i)));
		else
			return make_pair(make_pair(I_C_Diff, I_C_ZD), make_pair(PhaseDiff_res, ChoosePhase(i)));
	}
	else if (PhaseDiff_res == InterPhase_Fault_AB)
	{
		if (ZeroDiff_res == InterPhaseGround_Fault_AB)
			return make_pair(make_pair(max(I_A_Diff, I_B_Diff), min(I_A_ZD, I_B_ZD)), make_pair(ZeroDiff_res, ChoosePhase(i)));
		else
			return make_pair(make_pair(max(I_A_Diff, I_B_Diff), min(I_A_ZD, I_B_ZD)), make_pair(PhaseDiff_res, ChoosePhase(i)));
	}
	else if (PhaseDiff_res == InterPhase_Fault_BC)
	{
		if (ZeroDiff_res == InterPhaseGround_Fault_BC)
			return make_pair(make_pair(max(I_B_Diff, I_C_Diff), min(I_B_ZD, I_C_ZD)), make_pair(ZeroDiff_res, ChoosePhase(i)));
		else
			return make_pair(make_pair(max(I_B_Diff, I_C_Diff), min(I_B_ZD, I_C_ZD)), make_pair(PhaseDiff_res, ChoosePhase(i)));
	}
	else if (PhaseDiff_res == InterPhase_Fault_CA)
	{
		if (ZeroDiff_res == InterPhaseGround_Fault_CA)
			return make_pair(make_pair(max(I_C_Diff, I_A_Diff), min(I_C_ZD, I_A_ZD)), make_pair(ZeroDiff_res, ChoosePhase(i)));
		else
			return make_pair(make_pair(max(I_C_Diff, I_A_Diff), min(I_C_ZD, I_A_ZD)), make_pair(PhaseDiff_res, ChoosePhase(i)));
	}
	else if (PhaseDiff_res == ThreePhase_Fault)
	{
		return make_pair(make_pair(max(I_A_Diff, I_B_Diff, I_C_Diff), min(I_A_ZD, I_B_ZD, I_C_ZD)), make_pair(PhaseDiff_res, ChoosePhase(i)));
	}
	else
		return pair<pair<double, double>, pair<int,char> >();
}

int WeekFeedBack(int IsStart, int RAS, pair<pair<double, double>, pair<int, char> > I_Cacu, vector<Electric_Voltage> U_m, vector<Electric_Current> I_m)
{
	auto I_DiffSetValue = UseSetValue.GetValue(ProtectDevice, "差动动作电流定值");
	auto U0 = GetZeroSeq(U_m[0] , U_m[1] , U_m[2]);
	if (IsStart == 0&& RAS==1)
	{
		if (I_Cacu.second.second == 'A' && U_m[0].GetVValid() < 36 && I_Cacu.first.first > I_DiffSetValue)
			return 1;
		if (I_Cacu.second.second == 'B' && U_m[1].GetVValid() < 36 && I_Cacu.first.first > I_DiffSetValue)
			return 1;
		if (I_Cacu.second.second == 'C' && U_m[2].GetVValid() < 36 && I_Cacu.first.first > I_DiffSetValue)
			return 1;
	}
	else
		return 0;
}

int RemoteCallStart(int IsStart, int RAS, pair<pair<double, double>, pair<int, char>> I_Cacu, vector<Electric_Voltage> U_m, vector<Electric_Current> I_m)
{
	auto I_DiffSetValue = UseSetValue.GetValue(ProtectDevice, "差动动作电流定值");
	if (IsStart == 0 && RAS == 1)
	{
		if (I_Cacu.second.second == 'A' && U_m[0].GetVValid() > 8 && I_Cacu.first.first > I_DiffSetValue)
			return 1;
		if (I_Cacu.second.second == 'B' && U_m[1].GetVValid() > 8 && I_Cacu.first.first > I_DiffSetValue)
			return 1;
		if (I_Cacu.second.second == 'C' && U_m[2].GetVValid() > 8 && I_Cacu.first.first > I_DiffSetValue)
			return 1;
	}
	else
		return 0;
}

int CurrentDiffAlgor(double I_D, double I_B)
{
	auto I_Set = UseSetValue.GetValue(ProtectDevice, "差动动作电流定值");
	if (I_D > I_Set)
	{
		if (I_D < 3 * I_Set && I_D>(0.6 * I_B))
			return 1;
		else if (I_D > 3 * I_Set && I_D>(0.8 * I_B - I_Set))
			return 1;
		else
			return 0;
	}
	return 0;
}

void InputVoltage(vector<Electric_Voltage>& U_m)
{
	char line[1024];
	getchar();
	cin.getline(line, 1024);
	stringstream word(line);
	string U_A_V, U_A_T, U_B_V, U_B_T, U_C_V, U_C_T;
	word >> U_A_V;
	word >> U_A_T;
	word >> U_B_V;
	word >> U_B_T;
	word >> U_C_V;
	word >> U_C_T;
	Electric_Voltage U_A(atof(U_A_V.c_str()), atof(U_A_T.c_str()));
	Electric_Voltage U_B(atof(U_B_V.c_str()), atof(U_B_T.c_str()));
	Electric_Voltage U_C(atof(U_C_V.c_str()), atof(U_C_T.c_str()));
	U_m.push_back(U_A);
	U_m.push_back(U_B);
	U_m.push_back(U_C);
}

void InputCurrent(vector<Electric_Current>& I_m)
{
	char line[1024];
	fflush(stdin);
	cin.getline(line, 1024);
	stringstream word(line);
	string I_A_V, I_A_T, I_B_V, I_B_T, I_C_V, I_C_T;
	word >> I_A_V;
	word >> I_A_T;
	word >> I_B_V;
	word >> I_B_T;
	word >> I_C_V;
	word >> I_C_T;
	Electric_Current I_A(atof(I_A_V.c_str()), atof(I_A_T.c_str()));
	Electric_Current I_B(atof(I_B_V.c_str()), atof(I_B_T.c_str()));
	Electric_Current I_C(atof(I_C_V.c_str()), atof(I_C_T.c_str()));
	I_m.push_back(I_A);
	I_m.push_back(I_B);
	I_m.push_back(I_C);
}