
// ProtectSimulationDlg.h: 头文件
//

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
#include "TGW931.h"
#include "CDlgUIOne.h"
// CProtectSimulationDlg 对话框

class CProtectSimulationDlg : public CDialogEx
{
// 构造
public:
	CProtectSimulationDlg(CWnd* pParent = nullptr);	// 标准构造函数
	//CBrush m_brush;//用于自定义颜色
	//CDC m_memDC;//屏幕DC兼容的内存DC
	//CBitmap m_Bmp;//位图
	//CWnd* m_pDrawWnd;//用于保存静态文本框的对象指针
// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_PROTECTSIMULATION_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持
	void InitialDBB();
	void DrawOnMem();
	//在静态区域画图
	void DrawOnStaticArea();

// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnMenuDp();
	CEdit m_EditText;
	int m_ChooseProtect;
	afx_msg void OnClickedButton1();
	CEdit m_Edit_UAV;
	CEdit m_Edit_UBV;
	CEdit m_Edit_UCV;
	CEdit m_Edit_UAT;
	CEdit m_Edit_UBT;
	CEdit m_Edit_UCT;
	CEdit m_Edit_IAV;
	CEdit m_Edit_IBV;
	CEdit m_Edit_ICV;
	CEdit m_Edit_IAT;
	CEdit m_Edit_IBT;
	CEdit m_Edit_ICT;
	// //根据菜单所选的保护类型切换画面
	void FrameSwitch(int ChooseProtect);
	void AppendText(int controlId, CString strAdd);
	// //输出报文
	void ProtectReport(int stat,int nID, TGW931& TP);
	void InputUData(vector<Electric_Voltage>& U_m);
	void InputIData(vector<Electric_Current>& I_m);
	afx_msg LRESULT OnNcHitTest(CPoint point);
//	CEdit m_EditPaint;
	// //画向量
	void DrawArrow(CPoint p1, CPoint p2, double theta, int length);
	void ProtectActionReport_DP(ActionState Stat, double R, double jX);
	afx_msg void OnClickedButton2();
	afx_msg void OnMenuZp();
	void ProtectActionReport_ZP(ActionState stat, Electric_Voltage UZ, Electric_Current IZ);
	afx_msg void OnMenuCpl();
//	CButton m_BK_OnSIde;
	CButton m_BKB_OnSide;
	CButton m_BKA_OnSide;
	CButton m_BKC_OnSide;
	CButton m_BK_OnSide;
	CButton m_BKA_OffSide;
	CButton m_BKB_OffSide;
	CButton m_BKC_OffSide;
	CButton m_BK_OffSide;
	afx_msg void OnClickedRadio13();
	afx_msg void OnRadio14();
	afx_msg void OnClickedRadio15();
	afx_msg void OnRadio16();
	int GetBKState(int BK);
	afx_msg void OnMenuCp();
	CEdit m_UAV_OffSide;
	CEdit m_UBV_OffSide;
	CEdit m_UCV_OffSide;
	CEdit m_UAT_OffSide;
	CEdit m_UBT_OffSide;
	CEdit m_UCT_OffSide;
	CEdit m_IAV_OffSide;
	CEdit m_IBV_OffSide;
	CEdit m_ICV_OffSide;
	CEdit m_IAT_OffSide;
	CEdit m_IBT_OffSide;
	CEdit m_ICT_OffSide;
	void InputUData_OffSide(vector<Electric_Voltage>& U_m);
	void InputIData_OffSide(vector<Electric_Current>& I_m);
	CEdit m_EditText2;
	CEdit m_EditText3;
	afx_msg void OnMenuAbout();
	// //更新装置的断路器状态
	void UpdateBKState(TGW931& TP);
	// //从用户设定界面返回开关状态
	void UpdateFromSet(TGW931& TP);
	void UpdateBKState_OffSide(TGW931& TP);
	void UpdateFromSet_OffSide(TGW931& TP);
	TGW931 TGW_Protect;
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	CEdit m_systime;
	afx_msg void OnClickedButton3();
	CTabCtrl m_TAB;
	CDlgUIOne CPage1;
	void DeviceCurrentDiffAction();
	vector<double> m_Time;
	void DeviceGetTime();
};
