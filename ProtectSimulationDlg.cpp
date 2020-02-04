
// ProtectSimulationDlg.cpp: 实现文件
//
#include "framework.h"
#include "ProtectSimulation.h"
#include "ProtectSimulationDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CProtectSimulationDlg 对话框



CProtectSimulationDlg::CProtectSimulationDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_PROTECTSIMULATION_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CProtectSimulationDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT_TEXT, m_EditText);
	DDX_Control(pDX, IDC_EDIT1, m_Edit_UAV);
	//  DDX_Control(pDX, IDC_EDIT2, m_Edit_UAT);
	DDX_Control(pDX, IDC_EDIT2, m_Edit_UBV);
	DDX_Control(pDX, IDC_EDIT3, m_Edit_UCV);
	DDX_Control(pDX, IDC_EDIT4, m_Edit_UAT);
	DDX_Control(pDX, IDC_EDIT5, m_Edit_UBT);
	DDX_Control(pDX, IDC_EDIT6, m_Edit_UCT);
	DDX_Control(pDX, IDC_EDIT7, m_Edit_IAV);
	DDX_Control(pDX, IDC_EDIT8, m_Edit_IBV);
	DDX_Control(pDX, IDC_EDIT9, m_Edit_ICV);
	DDX_Control(pDX, IDC_EDIT10, m_Edit_IAT);
	DDX_Control(pDX, IDC_EDIT11, m_Edit_IBT);
	DDX_Control(pDX, IDC_EDIT12, m_Edit_ICT);
}

void CProtectSimulationDlg::InitialDBB()
{
	CRect rt;
	m_pDrawWnd->GetClientRect(&rt);
	CDC* sDC = m_pDrawWnd->GetDC();
	// 为屏幕DC创建兼容的内存DC
	if (!m_memDC.CreateCompatibleDC(sDC))//
	{
		::PostQuitMessage(0);
	}

	// 创建位图,不能是m_memDC，否则无颜色
	m_Bmp.CreateCompatibleBitmap(sDC, rt.Width(), rt.Height());//m_memDC
	// 相当于选择画布,m_pDrawWnd->
	::SelectObject(m_memDC.GetSafeHdc(), m_Bmp);
	m_pDrawWnd->ReleaseDC(sDC);
}

void CProtectSimulationDlg::DrawOnMem()
{
	CRect rect;
	m_pDrawWnd->GetClientRect(&rect);
	//COLORREF crl = GetSysColor(COLOR_3DFACE);
	//m_memDC.FillSolidRect(rect, crl); 
	//m_memDC.FillSolidRect(&rect, 0x00FFFFFF);// 白色填充, 注意,这次是画在内存设备环境上
	CPen pen(PS_SOLID, 1, RGB(255, 0, 0));
	m_memDC.SelectObject(&pen);

	//画图部分
	m_memDC.MoveTo(rect.right, rect.bottom);
	m_memDC.LineTo(rect.left, rect.top);
}

void CProtectSimulationDlg::DrawOnStaticArea()
{
	CWnd* pWnd = GetDlgItem(IDC_STATIC);//获得静态文本框的窗口对象
	CRect rect;
	pWnd->GetClientRect(&rect);
	//
	CDC* pDC = pWnd->GetDC();//
	//
	DrawOnMem();
	// 一次性的将内存设备环境上绘制完毕的图形"贴"到屏幕上
	pDC->BitBlt(0, 0, rect.Width(), rect.Height(), &m_memDC, 0, 0, SRCCOPY);
	pWnd->ReleaseDC(pDC);//
}

BEGIN_MESSAGE_MAP(CProtectSimulationDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_COMMAND(ID_MENU_DP, &CProtectSimulationDlg::OnMenuDp)
	ON_BN_CLICKED(IDC_BUTTON1, &CProtectSimulationDlg::OnClickedButton1)
END_MESSAGE_MAP()


// CProtectSimulationDlg 消息处理程序

BOOL CProtectSimulationDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// 设置此对话框的图标。  当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码
	CMenu menu;
	menu.LoadMenuW(IDR_MENU1);
	SetMenu(&menu);
	m_brush.CreateSolidBrush(RGB(255, 0, 0));//初始化画刷
	m_pDrawWnd = GetDlgItem(IDC_STATIC_PAINT);//获得静态窗口对象指针
	InitialDBB();// 初始化双缓冲相关的数据
	if (UseSetValue.IsEmpty())
	{
		m_EditText.SetWindowTextW(_T("定值初始化成功\n"));
		UpdateData(false);
	}
	else
	{
		m_EditText.SetWindowTextW(_T("定值初始化失败\n"));
		UpdateData(false);
	}

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CProtectSimulationDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。  对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CProtectSimulationDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
		//重绘图像区域
		PAINTSTRUCT ps;
		CRect rt;
		m_pDrawWnd->GetClientRect(&rt);
		CDC* pDC = m_pDrawWnd->BeginPaint(&ps);
		DrawOnMem();
		pDC->BitBlt(0, 0, rt.Width(), rt.Height(), &m_memDC, 0, 0, SRCCOPY);
		m_pDrawWnd->EndPaint(&ps);
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CProtectSimulationDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CProtectSimulationDlg::OnMenuDp()
{
	m_ChooseProtect = 2;//切换至距离保护的标志
	CString strAdd = _T("切换至距离保护调试");
	AppendText(IDC_EDIT_TEXT,strAdd);
	FrameSwitch(m_ChooseProtect);
}


void CProtectSimulationDlg::OnClickedButton1()
{
	switch (m_ChooseProtect)
	{
	case 0:
		break;
	case 1:
		break;
	case 2:
	{
		UpdateData(FALSE);
		vector<Electric_Voltage> U_m;
		vector<Electric_Current> I_m;
		InputUData(U_m);
		InputIData(I_m);
		Distance_Protection DP(U_m, I_m);
		StartTime = clock();
		auto J = DP.DistanceProtection();
		ProtectReport(J);
	}
		break;
	case 3:
		break;
	default:
		break;
	}
	
}


// //根据菜单所选的保护类型切换画面
void CProtectSimulationDlg::FrameSwitch(int ChooseProtect)
{
	if (ChooseProtect == 1)
	{
		GetDlgItem(IDC_STATIC_GP1)->SetWindowTextW(_T("本侧保护"));
		GetDlgItem(IDC_STATIC_DUICE)->ShowWindow(TRUE);
		GetDlgItem(IDC_STATIC13)->ShowWindow(TRUE);
		GetDlgItem(IDC_STATIC14)->ShowWindow(TRUE);
		GetDlgItem(IDC_STATIC15)->ShowWindow(TRUE);
		GetDlgItem(IDC_STATIC16)->ShowWindow(TRUE);
		GetDlgItem(IDC_STATIC17)->ShowWindow(TRUE);
		GetDlgItem(IDC_STATIC18)->ShowWindow(TRUE);
		GetDlgItem(IDC_STATIC19)->ShowWindow(TRUE);
		GetDlgItem(IDC_STATIC20)->ShowWindow(TRUE);
		GetDlgItem(IDC_STATIC21)->ShowWindow(TRUE);
		GetDlgItem(IDC_STATIC22)->ShowWindow(TRUE);
		GetDlgItem(IDC_STATIC23)->ShowWindow(TRUE);
		GetDlgItem(IDC_STATIC24)->ShowWindow(TRUE);
		GetDlgItem(IDC_EDIT14)->ShowWindow(TRUE);
		GetDlgItem(IDC_EDIT15)->ShowWindow(TRUE);
		GetDlgItem(IDC_EDIT16)->ShowWindow(TRUE);
		GetDlgItem(IDC_EDIT17)->ShowWindow(TRUE);
		GetDlgItem(IDC_EDIT18)->ShowWindow(TRUE);
		GetDlgItem(IDC_EDIT19)->ShowWindow(TRUE);
		GetDlgItem(IDC_EDIT20)->ShowWindow(TRUE);
		GetDlgItem(IDC_EDIT21)->ShowWindow(TRUE);
		GetDlgItem(IDC_EDIT22)->ShowWindow(TRUE);
		GetDlgItem(IDC_EDIT23)->ShowWindow(TRUE);
		GetDlgItem(IDC_EDIT24)->ShowWindow(TRUE);
		GetDlgItem(IDC_EDIT25)->ShowWindow(TRUE);
	}
	else
	{
		GetDlgItem(IDC_STATIC_GP1)->SetWindowTextW(_T("电压量/电流量"));
		GetDlgItem(IDC_STATIC_DUICE)->ShowWindow(FALSE);
		GetDlgItem(IDC_STATIC13)->ShowWindow(FALSE);
		GetDlgItem(IDC_STATIC14)->ShowWindow(FALSE);
		GetDlgItem(IDC_STATIC15)->ShowWindow(FALSE);
		GetDlgItem(IDC_STATIC16)->ShowWindow(FALSE);
		GetDlgItem(IDC_STATIC17)->ShowWindow(FALSE);
		GetDlgItem(IDC_STATIC18)->ShowWindow(FALSE);
		GetDlgItem(IDC_STATIC19)->ShowWindow(FALSE);
		GetDlgItem(IDC_STATIC20)->ShowWindow(FALSE);
		GetDlgItem(IDC_STATIC21)->ShowWindow(FALSE);
		GetDlgItem(IDC_STATIC22)->ShowWindow(FALSE);
		GetDlgItem(IDC_STATIC23)->ShowWindow(FALSE);
		GetDlgItem(IDC_STATIC24)->ShowWindow(FALSE);
		GetDlgItem(IDC_EDIT14)->ShowWindow(FALSE);
		GetDlgItem(IDC_EDIT15)->ShowWindow(FALSE);
		GetDlgItem(IDC_EDIT16)->ShowWindow(FALSE);
		GetDlgItem(IDC_EDIT17)->ShowWindow(FALSE);
		GetDlgItem(IDC_EDIT18)->ShowWindow(FALSE);
		GetDlgItem(IDC_EDIT19)->ShowWindow(FALSE);
		GetDlgItem(IDC_EDIT20)->ShowWindow(FALSE);
		GetDlgItem(IDC_EDIT21)->ShowWindow(FALSE);
		GetDlgItem(IDC_EDIT22)->ShowWindow(FALSE);
		GetDlgItem(IDC_EDIT23)->ShowWindow(FALSE);
		GetDlgItem(IDC_EDIT24)->ShowWindow(FALSE);
		GetDlgItem(IDC_EDIT25)->ShowWindow(FALSE);
	}
	// TODO: 在此处添加实现代码.
}


void CProtectSimulationDlg::AppendText(int controlId, CString strAdd)
{
	((CEdit*)GetDlgItem(controlId))->SetSel(GetDlgItem(controlId)->GetWindowTextLength(), GetDlgItem(controlId)->GetWindowTextLength());
	((CEdit*)GetDlgItem(controlId))->ReplaceSel(strAdd + L"\n");
	// TODO: 在此处添加实现代码.
}



// //输出报文
void CProtectSimulationDlg::ProtectReport(int stat)
{
	switch (stat)
	{
	case ProtectAction_A:
		AppendText(IDC_EDIT_TEXT, _T("A相故障\n保护跳A相\n"));
		break;
	case ProtectAction_B:
		AppendText(IDC_EDIT_TEXT, _T("B相故障\n保护跳B相\n"));
		break;
	case ProtectAction_C:
		AppendText(IDC_EDIT_TEXT, _T("C相故障\n保护跳C相\n"));
		break;
	case ProtectAction_AB:
		AppendText(IDC_EDIT_TEXT, _T("AB相间故障\n保护三跳\n"));
		break;
	case ProtectAction_BC:
		AppendText(IDC_EDIT_TEXT, _T("BC相间故障\n保护三跳\n"));
		break;
	case ProtectAction_CA:
		AppendText(IDC_EDIT_TEXT, _T("AC相间故障\n保护三跳\n"));
		break;
	case ProtectAction_ABN:
		AppendText(IDC_EDIT_TEXT, _T("AB相间短路接地故障\n保护三跳\n"));
		break;
	case ProtectAction_BCN:
		AppendText(IDC_EDIT_TEXT, _T("BC相间短路接地故障\n保护三跳\n"));
		break;
	case ProtectAction_CAN:
		AppendText(IDC_EDIT_TEXT, _T("AC相间短路接地故障\n保护三跳\n"));
		break;
	case ProtectAction_ABC:
		AppendText(IDC_EDIT_TEXT, _T("ABC三相短路故障\n保护三跳\n"));
		break;
	case ProtectNoAction:
		AppendText(IDC_EDIT_TEXT, _T("无故障\n"));
		break;
	default:
		break;
	}
	// TODO: 在此处添加实现代码.
}


void CProtectSimulationDlg::InputUData(vector<Electric_Voltage>& U_m)
{
	CString U_A_V, U_A_T, U_B_V, U_B_T, U_C_V, U_C_T;
	m_Edit_UAV.GetWindowTextW(U_A_V);
	m_Edit_UAT.GetWindowTextW(U_A_T);
	m_Edit_UBV.GetWindowTextW(U_B_V);
	m_Edit_UBT.GetWindowTextW(U_B_T);
	m_Edit_UCV.GetWindowTextW(U_C_V);
	m_Edit_UCT.GetWindowTextW(U_C_T);
	Electric_Voltage U_A(_ttof(U_A_V), _ttof(U_A_T));
	Electric_Voltage U_B(_ttof(U_B_V), _ttof(U_B_T));
	Electric_Voltage U_C(_ttof(U_C_V), _ttof(U_C_T));
	U_m.push_back(U_A);
	U_m.push_back(U_B);
	U_m.push_back(U_C);
}


void CProtectSimulationDlg::InputIData(vector<Electric_Current>& I_m)
{
	CString I_A_V, I_A_T, I_B_V, I_B_T, I_C_V, I_C_T;
	m_Edit_IAV.GetWindowTextW(I_A_V);
	m_Edit_IAT.GetWindowTextW(I_A_T);
	m_Edit_IBV.GetWindowTextW(I_B_V);
	m_Edit_IBT.GetWindowTextW(I_B_T);
	m_Edit_ICV.GetWindowTextW(I_C_V);
	m_Edit_ICT.GetWindowTextW(I_C_T);
	Electric_Current I_A(_ttof(I_A_V), _ttof(I_A_T));
	Electric_Current I_B(_ttof(I_B_V), _ttof(I_B_T));
	Electric_Current I_C(_ttof(I_C_V), _ttof(I_C_T));
	I_m.push_back(I_A);
	I_m.push_back(I_B);
	I_m.push_back(I_C);
	// TODO: 在此处添加实现代码.
}
