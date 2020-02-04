#include "res.h"

system_clock::time_point software_start_time = system_clock::now();

SettingValue UseSetValue;
string ProtectDevice = "500kV��·����";
clock_t StartTime = 0, EndTime = 0;
map<int, int> FaultToProtection = { {SingleEarth_Fault_A,ProtectAction_A},{SingleEarth_Fault_B,ProtectAction_B},
									{SingleEarth_Fault_C,ProtectAction_C},{InterPhase_Fault_AB,ProtectAction_AB},
									{InterPhase_Fault_BC,ProtectAction_BC},{InterPhase_Fault_CA,ProtectAction_CA},
									{ThreePhase_Fault,ProtectAction_ABC},{InterPhaseGround_Fault_AB,ProtectAction_ABN},
									{InterPhaseGround_Fault_BC,ProtectAction_BCN},{InterPhaseGround_Fault_CA,ProtectAction_CAN}
};
void TranslateProtectState(ActionState stat)
{
	switch (stat)
	{
	case ProtectAction_A:
		cout << "A�����" << endl;
		cout << "������A��" << endl;
		break;
	case ProtectAction_B:
		cout << "B�����" << endl;
		cout << "������B��" << endl;
		break;
	case ProtectAction_C:
		cout << "C�����" << endl;
		cout << "������C��" << endl;
		break;
	case ProtectAction_AB:
		cout << "AB������" << endl;
		cout << "��������" << endl;
		break;
	case ProtectAction_BC:
		cout << "BC������" << endl;
		cout << "��������" << endl;
		break;
	case ProtectAction_CA:
		cout << "AC������" << endl;
		cout << "��������" << endl;
		break;
	case ProtectAction_ABN:
		cout << "AB����·�ӵع���" << endl;
		cout << "��������" << endl;
		break;
	case ProtectAction_BCN:
		cout << "BC����·�ӵع���" << endl;
		cout << "��������" << endl;
		break;
	case ProtectAction_CAN:
		cout << "AC����·�ӵع���" << endl;
		cout << "��������" << endl;
		break;
	case ProtectAction_ABC:
		cout << "ABC�����·����" << endl;
		cout << "��������" << endl;
		break;
	case ProtectNoAction:
		cout << "�޹���" << endl;
		break;
	default:
		break;
	}
}

int CompareDouble(double a, double b)
{
	if ((a - b) > 0.01)
		return 1;
	if ((a - b) < -0.01)
		return -1;
	if ((a - b) > -0.01 && (a - b) < 0.01)
		return 0;
}

void FixTimeDelay(double time)
{
	Sleep(time);
}

double FixTimeError(double TRand)
{
	default_random_engine dre(clock());
	if (TRand == 30)
	{
		uniform_real_distribution<double> dr(100, 300);
		return dr(dre) / 100;
	}
	else
	{
		uniform_real_distribution<double> dr(TRand*1000, 3 * TRand*1000);
		return dr(dre) / 100;
	}
}