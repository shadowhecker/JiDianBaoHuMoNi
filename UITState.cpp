#include "UITState.h"

UITState::UITState()
{
	U =  { Electric_Voltage(0,0),Electric_Voltage(0,0),Electric_Voltage(0,0) };
	I =  { Electric_Current(0,0),Electric_Current(0,0),Electric_Current(0,0) };
	m_Time = 0;
}

UITState::UITState(CDlgUIOne CPage)
{
	CPage.UpdateUIInput();
	U = CPage.m_U;
	I = CPage.m_I;
	m_Time = CPage.m_Time;
}

UITState& UITState::operator=(UITState& Item)
{
	U = Item.U;
	I = Item.I;
	m_Time = Item.m_Time;
	return *this;
	// TODO: 在此处插入 return 语句
}

void UITState::GetPageState(vector<Electric_Voltage>& item_U, vector<Electric_Current>& item_I, double item_T)
{
	U = item_U;
	I = item_I;
	m_Time = item_T;
}
