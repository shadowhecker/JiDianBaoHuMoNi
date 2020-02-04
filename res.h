#pragma once
#include<iostream>
#include<complex>
#include<chrono>
#include<cmath>
#include<cstdlib>
#include<complex>
#include<vector>
#include<utility>
#include<map>
#include"SettingValue.h"
#include<ctime>
#include<windows.h>
#include<random>
#include<istream>
using namespace std;
using namespace chrono;
constexpr auto M_PI = 3.1415926;
constexpr auto ANGULARFREQUENCY = M_PI * 100;
typedef double ANGLE;//�Ƕȶ���Ϊdouble����
typedef double AMPERE;//���������ֵ��λ���࣬��ֵ����ѡ��double
typedef int ActionState;//����������������
constexpr auto DYNAMICS = 0x0001;
constexpr auto STATIC = 0x0002;
typedef double VOLTAGE;//�����ѹ��ֵ��λ���أ���ֵ����ѡ��double
extern system_clock::time_point software_start_time;
constexpr auto SingleEarth_Fault_A = 0x0003;//A��ӵض�·
constexpr auto SingleEarth_Fault_B = 0x0004;//B��ӵض�·
constexpr auto SingleEarth_Fault_C = 0x0005;//C��ӵض�·
constexpr auto InterPhase_Fault_AB = 0x0006;//AB����·
constexpr auto InterPhase_Fault_BC = 0x0007;//BC����·
constexpr auto InterPhase_Fault_CA = 0x0008;//AC����·
constexpr auto ThreePhase_Fault = 0x0009;//�����·
constexpr auto InterPhaseGround_Fault_AB = 0x000A;//AB���ӵض�·
constexpr auto InterPhaseGround_Fault_BC = 0x000B;//BC���ӵض�·
constexpr auto InterPhaseGround_Fault_CA = 0x000C;//AC���ӵض�·
constexpr auto Judge_Fault_ERROR = 0x000D;//�����б����
constexpr auto ProtectAction_A = 0x000E;//����A�ද��
constexpr auto ProtectAction_B = 0x000F;//����B�ද��
constexpr auto ProtectAction_C = 0x0010;//����C�ද��
constexpr auto ProtectAction_AB = 0x0011;//����AB����·����
constexpr auto ProtectAction_BC = 0x0012;//����BC����·����
constexpr auto ProtectAction_CA = 0x0013;//����CA����·����
constexpr auto ProtectAction_ABN = 0x0014;//����AB����·�ӵ�����
constexpr auto ProtectAction_BCN = 0x0015;//����BC����·�ӵ�����
constexpr auto ProtectAction_CAN = 0x0016;//����CA����·�ӵ�����
constexpr auto ProtectAction_ABC = 0x0017;//����ABC�����·����
constexpr auto ProtectNoAction = 0x0018;//����������
constexpr auto Protect500LP = 0x0100;//500kV��·����
constexpr auto ��_DPFixDelay = 30;//�����ι�����ʱ
extern SettingValue UseSetValue;
extern string ProtectDevice;
void TranslateProtectState(ActionState stat);
int CompareDouble(double a, double b);
void FixTimeDelay(double time);
double FixTimeError(double TRand);
extern clock_t StartTime, EndTime;
extern map<int, int> FaultToProtection;