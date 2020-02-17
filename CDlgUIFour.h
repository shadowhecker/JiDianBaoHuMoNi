#pragma once
#include <cstdio>
#include <iostream>
#include "Electric_Current.h"
#include "Electric_Voltage.h"
#include "Protection_Lib.h"
#include "Distance_Protection.h"
#include "res.h"
#include "ZeroSeq_Protection.h"
#include "CurrentDiff_Protection.h"

// CDlgFour 对话框

class CDlgUIFour : public CDlgUIOne
{
	DECLARE_DYNAMIC(CDlgUIFour)

public:
	CDlgUIFour(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~CDlgUIFour();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_FourState };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	double m_Time;
	double m_UAV;
	double m_UBV;
	double m_UCV;
	double m_UAT;
	double m_UBT;
	double m_UCT;
	double m_IAV;
	double m_IBV;
	double m_ICV;
	double m_IAT;
	double m_IBT;
	double m_ICT;
	vector<Electric_Voltage> m_U;
	vector<Electric_Current> m_I;
	virtual BOOL OnInitDialog();
	void InputUData();
	void InputIData();
	void UpdataUIInput();
};
