#pragma once
#include "Electric_Current.h"
#include "Electric_Voltage.h"
#include "res.h"
#include "CDlgUIOne.h"
class UITState//��ȡ�û������״̬���ʼ����Ŀ�е�״̬����,��Ϊ�����ͽ����״̬��תվ
{
private:
	vector<Electric_Voltage> U;
	vector<Electric_Current> I;
	int m_Time;
public:
	UITState();
	UITState(CDlgUIOne CPage);
	UITState& operator=(UITState& Item);
	void GetPageState(CDlgUIOne CPage);
};

