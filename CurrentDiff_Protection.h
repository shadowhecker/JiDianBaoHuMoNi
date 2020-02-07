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
	int ProtectStart();//�����Ƿ����������жϣ�����������Զ���ٻ����������ж�
	void SendActionSingle();//�Ƿ��������ź�
	void SelfSideStart();//���ౣ��״̬ȷ��
	int OtherProtectStart();//����������Զ���ٻ�����
	double GetI_Diff();//��ȡ�����
	double GetI_B();//��ȡ�ƶ�����
	CurrentDiff_Protection(vector<Electric_Voltage> U_m, vector<Electric_Current> I_m, int Loop, int Breaker);
	CurrentDiff_Protection();
	friend void SyncCPStat(CurrentDiff_Protection& CP_m, CurrentDiff_Protection& CP_n);//ͬ��˫�ౣ����״̬��
	friend void AllSideStart(CurrentDiff_Protection& CP_m, CurrentDiff_Protection& CP_n);//˫��ı���״̬ȷ��
	friend void CurrentDiffProtection(CurrentDiff_Protection& CP_m, CurrentDiff_Protection& CP_n);//����������㷨
	void CurrentDiffProtectionLoop();//�Ի�״̬��
	ActionState GetProtectAcionState();
	void SetProtectActionState(ActionState);
	double GetActionTime();
	int GetIsStart();
	int GetIsWeedBack();
	void SetBKState(int BK);
	void SetUI(vector<Electric_Voltage> U, vector<Electric_Current> I);

private:
	vector<Electric_Voltage> U_OnSide;//�����ѹ
	vector<Electric_Current> I_OnSide;//�������
	vector<Electric_Voltage> U_OffSide;//�Բ��ѹ
	vector<Electric_Current> I_OffSide;//�Բ����
	pair<pair<double, double>, pair<int, char> > I_DB;//��������ƶ������������������ݼ���
	int ChannelLoop;//ͨ���Ƿ��Ի�,0���Ի���1�Ի�
	int BreakerStat;//��·��״̬��0��բλ�ã�1��բλ��
	int ReceiveActionSingle;//�Բ෢�������������ź�
	int SendActionSingleStat;//�������Բ�������ź�
	int IsStart;//����װ���Ƿ�����
	int IsWeedBack;//�жϱ����Ƿ���������
	ActionState ProtectActionState;
	double ActionTime;
};