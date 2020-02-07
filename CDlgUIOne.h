#pragma once


// CDlgUIOne 对话框

class CDlgUIOne : public CDialogEx
{
	DECLARE_DYNAMIC(CDlgUIOne)

public:
	CDlgUIOne(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~CDlgUIOne();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_OneState };
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
	double m_IBV;
//	CString m_ICV;
	double m_ICV;
	double m_IAT;
	double m_IBT;
	double m_ICT;
	int m_Time;
	virtual BOOL OnInitDialog();
	Electric_Voltage m_U;
};
