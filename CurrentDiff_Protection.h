#pragma once
#include "res.h"
#include <cstdio>
#include <iostream>
#include "Electric_Current.h"
#include "Electric_Voltage.h"
#include "Protection_Lib.h"
#include "Resistance_Impedance.h"
class CurrentDiff_Protection
{
public:
	int ProtectStart();//保护是否启动，自判断，弱馈启动和远方召唤启动另行判断
	void SendActionSingle();//是否发送允许信号
	void SelfSideStart();//本侧保护状态确认
	int OtherProtectStart();//弱馈启动和远方召唤启动
	double GetI_Diff();//获取差动电流
	double GetI_B();//获取制动电流
	CurrentDiff_Protection(vector<Electric_Voltage> U_m, vector<Electric_Current> I_m, int Loop, int Breaker);
	CurrentDiff_Protection();
	friend void SyncCPStat(CurrentDiff_Protection& CP_m, CurrentDiff_Protection& CP_n);//同步双侧保护的状态量
	friend void AllSideStart(CurrentDiff_Protection& CP_m, CurrentDiff_Protection& CP_n);//双侧的保护状态确认
	friend void CurrentDiffProtection(CurrentDiff_Protection& CP_m, CurrentDiff_Protection& CP_n);//差动保护联调算法
	void CurrentDiffProtectionLoop();//自环状态下
	ActionState GetProtectAcionState();
	void SetProtectActionState(ActionState);
	double GetActionTime();
	int GetIsStart();
	int GetIsWeedBack();
	void SetBKState(int BK);
	void SetUI(vector<Electric_Voltage> U, vector<Electric_Current> I);

private:
	vector<Electric_Voltage> U_OnSide;//本侧电压
	vector<Electric_Current> I_OnSide;//本侧电流
	vector<Electric_Voltage> U_OffSide;//对侧电压
	vector<Electric_Current> I_OffSide;//对侧电流
	pair<pair<double, double>, pair<int, char> > I_DB;//差动电流、制动电流、故障类型数据集合
	int ChannelLoop;//通道是否自环,0不自环，1自环
	int BreakerStat;//断路器状态，0分闸位置，1合闸位置
	int ReceiveActionSingle;//对侧发送至本侧允许信号
	int SendActionSingleStat;//发送至对侧的允许信号
	int IsStart;//本侧装置是否启动
	int IsWeedBack;//判断本侧是否弱馈启动
	ActionState ProtectActionState;
	double ActionTime;
};