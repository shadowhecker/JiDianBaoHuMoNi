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

// CDlgUITwo 对话框

class CDlgUITwo : public CDlgUIOne
{
	DECLARE_DYNAMIC(CDlgUITwo)

public:
	CDlgUITwo(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~CDlgUITwo();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_TwoState };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	double m_UAV;
	double m_UBV;
	double m_UCV;
	double m_UAT;
	double m_UBT;
	double m_UCT;
	double m_IAV;
//	double IBV;
	double m_IBV;
	double m_ICV;
	double m_IAT;
	double m_IBT;
	double m_ICT;
	double m_Time;
	vector<Electric_Voltage> m_U;
	vector<Electric_Current> m_I;
	virtual BOOL OnInitDialog();
	void InputUData();
	void InputIData();
	void UpdateUIInput();
};
