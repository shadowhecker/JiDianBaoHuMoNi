// CDlgUITwo.cpp: 实现文件
//

#include "pch.h"
#include "ProtectSimulation.h"
#include "CDlgUITwo.h"
#include "afxdialogex.h"


// CDlgUITwo 对话框

IMPLEMENT_DYNAMIC(CDlgUITwo, CDialogEx)

CDlgUITwo::CDlgUITwo(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG_TwoState, pParent)
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

CDlgUITwo::~CDlgUITwo()
{
}

void CDlgUITwo::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT14, m_UAV);
	DDX_Text(pDX, IDC_EDIT15, m_UBV);
	DDX_Text(pDX, IDC_EDIT16, m_UCV);
	DDX_Text(pDX, IDC_EDIT17, m_UAT);
	DDX_Text(pDX, IDC_EDIT18, m_UBT);
	DDX_Text(pDX, IDC_EDIT19, m_UCT);
	DDX_Text(pDX, IDC_EDIT20, m_IAV);
	//  DDX_Text(pDX, IDC_EDIT21, IBV);
	DDX_Text(pDX, IDC_EDIT21, m_IBV);
	DDX_Text(pDX, IDC_EDIT22, m_ICV);
	DDX_Text(pDX, IDC_EDIT23, m_IAT);
	DDX_Text(pDX, IDC_EDIT24, m_IBT);
	DDX_Text(pDX, IDC_EDIT25, m_ICT);
	DDX_Text(pDX, IDC_EDIT_TIME, m_Time);
}


BEGIN_MESSAGE_MAP(CDlgUITwo, CDialogEx)
END_MESSAGE_MAP()


// CDlgUITwo 消息处理程序


BOOL CDlgUITwo::OnInitDialog()
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
	m_U = { Electric_Voltage(m_UAV,m_UAT),Electric_Voltage(m_UBV,m_UBT) ,Electric_Voltage(m_UCV,m_UCT) };
	m_I = { Electric_Current(m_IAV,m_IAT),Electric_Current(m_IBV,m_IBT) ,Electric_Current(m_ICV,m_ICT) };
	// TODO:  在此添加额外的初始化

	return TRUE;  // return TRUE unless you set the focus to a control
				  // 异常: OCX 属性页应返回 FALSE
}


void CDlgUITwo::InputUData()
{
	UpdateData(TRUE);
	Electric_Voltage U_A(m_UAV, m_UAT);
	Electric_Voltage U_B(m_UBV, m_UBT);
	Electric_Voltage U_C(m_UCV, m_UCT);
	m_U[0] = U_A;
	m_U[1] = U_B;
	m_U[2] = U_C;
	// TODO: 在此处添加实现代码.
}


void CDlgUITwo::InputIData()
{
	UpdateData(TRUE);
	Electric_Current I_A(m_IAV, m_IAT);
	Electric_Current I_B(m_IBV, m_IBT);
	Electric_Current I_C(m_ICV, m_ICT);
	m_I[0] = I_A;
	m_I[1] = I_B;
	m_I[2] = I_C;
	// TODO: 在此处添加实现代码.
}


void CDlgUITwo::UpdateUIInput()
{
	UpdateData(TRUE);
	InputUData();
	InputIData();
	// TODO: 在此处添加实现代码.
}
