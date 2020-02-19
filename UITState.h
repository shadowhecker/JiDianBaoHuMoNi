#pragma once
#include "Electric_Current.h"
#include "Electric_Voltage.h"
#include "res.h"
#include "CDlgUIOne.h"
class UITState//��ȡ�û������״̬���ʼ����Ŀ�е�״̬����,��Ϊ�����ͽ����״̬��תվ
{
public:
	vector<Electric_Voltage> U;
	vector<Electric_Current> I;
	double m_Time;
public:
	UITState();
	UITState(CDlgUIOne CPage);
	UITState& operator=(UITState& Item);
	void GetPageState(vector<Electric_Voltage>& item_U,vector<Electric_Current>& item_I,double item_T);
};

