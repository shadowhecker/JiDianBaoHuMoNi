// CDlgUIOne.cpp: 实现文件
//

#include "pch.h"
#include "ProtectSimulation.h"
#include "CDlgUIOne.h"
#include "afxdialogex.h"


// CDlgUIOne 对话框

IMPLEMENT_DYNAMIC(CDlgUIOne, CDialogEx)

CDlgUIOne::CDlgUIOne(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG_OneState, pParent)
	, m_UAV(0)
	, m_UBV(0)
	, m_UCV(0)
	, m_UAT(0)
	, m_UBT(0)
	, m_UCT(0)
	, m_IAV(0)
	, m_IBV(0)
	, m_ICV(0)
	, m_IAT(0)
	, m_IBT(0)
	, m_ICT(0)
	, m_Time(0)
{

}

CDlgUIOne::~CDlgUIOne()
{
}

void CDlgUIOne::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT14, m_UAV);
	DDX_Text(pDX, IDC_EDIT15, m_UBV);
	DDX_Text(pDX, IDC_EDIT16, m_UCV);
	DDX_Text(pDX, IDC_EDIT17, m_UAT);
	DDX_Text(pDX, IDC_EDIT18, m_UBT);
	DDX_Text(pDX, IDC_EDIT19, m_UCT);
	DDX_Text(pDX, IDC_EDIT20, m_IAV);
	DDX_Text(pDX, IDC_EDIT21, m_IBV);
	//  DDX_Text(pDX, IDC_EDIT22, m_ICV);
	DDX_Text(pDX, IDC_EDIT22, m_ICV);
	DDX_Text(pDX, IDC_EDIT23, m_IAT);
	DDX_Text(pDX, IDC_EDIT24, m_IBT);
	DDX_Text(pDX, IDC_EDIT25, m_ICT);
	DDX_Text(pDX, IDC_EDIT_TIME, m_Time);
}


BEGIN_MESSAGE_MAP(CDlgUIOne, CDialogEx)
END_MESSAGE_MAP()


// CDlgUIOne 消息处理程序


BOOL CDlgUIOne::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	m_UAV = 57.74;
	m_UBV = 57.74;
	m_UCV = 57.74;
	m_UAT = 0;
	m_UBT = -120;
	m_UCT = 120;
	m_IAV = 0;
	m_IBV = 0;
	m_ICV = 0;
	m_IAT = 0;
	m_IBT = -120;
	m_ICT = 120;
	m_Time = 0;
	UpdateData(FALSE);
	// TODO:  在此添加额外的初始化
	return TRUE;  // return TRUE unless you set the focus to a control
				  // 异常: OCX 属性页应返回 FALSE
}


void CDlgUIOne::InputUData()
{
	UpdateData(TRUE);
	Electric_Voltage U_A(m_UAV, m_UAT);
	Electric_Voltage U_B(m_UBV, m_UBT);
	Electric_Voltage U_C(m_UCV, m_UCT);
	m_U.push_back(U_A);
	m_U.push_back(U_B);
	m_U.push_back(U_C);
	// TODO: 在此处添加实现代码.
}


void CDlgUIOne::InputIData()
{
	UpdateData(TRUE);
	Electric_Current I_A(m_IAV, m_IAT);
	Electric_Current I_B(m_IBV, m_IBT);
	Electric_Current I_C(m_ICV, m_ICT);
	m_I.push_back(I_A);
	m_I.push_back(I_B);
	m_I.push_back(I_C);
	// TODO: 在此处添加实现代码.
}


void CDlgUIOne::UpdateUIInput()
{
	UpdateData(TRUE);
	InputUData();
	InputIData();
	// TODO: 在此处添加实现代码.
}

