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
#include <afxwin.h>
#include<random>
#include<istream>
using namespace std;
using namespace chrono;
constexpr auto M_PI = 3.1415926;
constexpr auto ANGULARFREQUENCY = M_PI * 100;
typedef double ANGLE;//角度定义为double类型
typedef double AMPERE;//定义电流幅值单位安培，数值类型选用double
typedef int ActionState;//保护动作反馈类型
constexpr auto DYNAMICS = 0x0001;
constexpr auto STATIC = 0x0002;
typedef double VOLTAGE;//定义电压幅值单位伏特，数值类型选用double
extern system_clock::time_point software_start_time;
constexpr auto SingleEarth_Fault_A = 0x0003;//A相接地短路
constexpr auto SingleEarth_Fault_B = 0x0004;//B相接地短路
constexpr auto SingleEarth_Fault_C = 0x0005;//C相接地短路
constexpr auto InterPhase_Fault_AB = 0x0006;//AB相间短路
constexpr auto InterPhase_Fault_BC = 0x0007;//BC相间短路
constexpr auto InterPhase_Fault_CA = 0x0008;//AC相间短路
constexpr auto ThreePhase_Fault = 0x0009;//三相短路
constexpr auto InterPhaseGround_Fault_AB = 0x000A;//AB相间接地短路
constexpr auto InterPhaseGround_Fault_BC = 0x000B;//BC相间接地短路
constexpr auto InterPhaseGround_Fault_CA = 0x000C;//AC相间接地短路
constexpr auto Judge_Fault_ERROR = 0x000D;//故障判别错误
constexpr auto ProtectAction_A = 0x000E;//保护A相动作
constexpr auto ProtectAction_B = 0x000F;//保护B相动作
constexpr auto ProtectAction_C = 0x0010;//保护C相动作
constexpr auto ProtectAction_AB = 0x0011;//保护AB相间短路三跳
constexpr auto ProtectAction_BC = 0x0012;//保护BC相间短路三跳
constexpr auto ProtectAction_CA = 0x0013;//保护CA相间短路三跳
constexpr auto ProtectAction_ABN = 0x0014;//保护AB相间短路接地三跳
constexpr auto ProtectAction_BCN = 0x0015;//保护BC相间短路接地三跳
constexpr auto ProtectAction_CAN = 0x0016;//保护CA相间短路接地三跳
constexpr auto ProtectAction_ABC = 0x0017;//保护ABC三相短路三跳
constexpr auto JieDiJuLi_ⅠAction = 0x0019;//接地距离Ⅰ段动作
constexpr auto JieDiJuLi_ⅡAction = 0x0020;//接地距离Ⅱ段动作
constexpr auto JieDiJuLi_ⅢAction = 0x0021;//接地距离Ⅲ段动作
constexpr auto XiangJianJuLi_ⅠAction = 0x0022;//相间距离Ⅰ段动作
constexpr auto XiangJianJuLi_ⅡAction = 0x0023;//相间距离Ⅱ段动作
constexpr auto XiangJianJuLi_ⅢAction = 0x0024;//相间距离Ⅲ段动作
constexpr auto LinXuDianLiu_ⅡAction = 0x0025;//零序电流Ⅱ段动作
constexpr auto LinXuDianLiu_ⅢAction = 0x0024;//零序电流Ⅲ段动作

constexpr auto ProtectNoAction = 0x0018;//保护不动作
constexpr auto Protect500LP = 0x0100;//500kV线路保护
constexpr auto Ⅰ_DPFixDelay = 30;//距离Ⅰ段固有延时
extern SettingValue UseSetValue;
extern string ProtectDevice;
void TranslateProtectState(ActionState stat);
int CompareDouble(double a, double b);
void FixTimeDelay(double time);
double FixTimeError(double TRand);
extern clock_t StartTime, EndTime;
extern map<int, int> FaultToProtection;