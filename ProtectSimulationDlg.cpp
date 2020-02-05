
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

	//  DDX_Control(pDX, IDC_RADIO1, m_BK_OnSIde);
	DDX_Control(pDX, IDC_RADIO3, m_BKB_OnSide);
	DDX_Control(pDX, IDC_RADIO1, m_BKA_OnSide);
	DDX_Control(pDX, IDC_RADIO5, m_BKC_OnSide);
	DDX_Control(pDX, IDC_RADIO13, m_BK_OnSide);
	DDX_Control(pDX, IDC_RADIO7, m_BKA_OffSide);
	DDX_Control(pDX, IDC_RADIO9, m_BKB_OffSide);
	DDX_Control(pDX, IDC_RADIO11, m_BKC_OffSide);
	DDX_Control(pDX, IDC_RADIO15, m_BK_OffSide);
	DDX_Control(pDX, IDC_EDIT14, m_UAV_OffSide);
	DDX_Control(pDX, IDC_EDIT15, m_UBV_OffSide);
	DDX_Control(pDX, IDC_EDIT16, m_UCV_OffSide);
	DDX_Control(pDX, IDC_EDIT17, m_UAT_OffSide);
	DDX_Control(pDX, IDC_EDIT18, m_UBT_OffSide);
	DDX_Control(pDX, IDC_EDIT19, m_UCT_OffSide);
	DDX_Control(pDX, IDC_EDIT20, m_IAV_OffSide);
	DDX_Control(pDX, IDC_EDIT21, m_IBV_OffSide);
	DDX_Control(pDX, IDC_EDIT22, m_ICV_OffSide);
	DDX_Control(pDX, IDC_EDIT23, m_IAT_OffSide);
	DDX_Control(pDX, IDC_EDIT24, m_IBT_OffSide);
	DDX_Control(pDX, IDC_EDIT25, m_ICT_OffSide);
	DDX_Control(pDX, IDC_EDIT_TEXT2, m_EditText2);
	DDX_Control(pDX, IDC_EDIT_TEXT3, m_EditText3);
}

//void CProtectSimulationDlg::InitialDBB()
//{
//	CRect rt;
//	m_pDrawWnd->GetClientRect(&rt);
//	CDC* sDC = m_pDrawWnd->GetDC();
//	// 为屏幕DC创建兼容的内存DC
//	if (!m_memDC.CreateCompatibleDC(sDC))//
//	{
//		::PostQuitMessage(0);
//	}

//	// 创建位图,不能是m_memDC，否则无颜色
//	m_Bmp.CreateCompatibleBitmap(sDC, rt.Width(), rt.Height());//m_memDC
//	// 相当于选择画布,m_pDrawWnd->
//	::SelectObject(m_memDC.GetSafeHdc(), m_Bmp);
//	m_pDrawWnd->ReleaseDC(sDC);
//}

//void CProtectSimulationDlg::DrawOnMem()
//{
//	CRect rect;
//	m_pDrawWnd->GetClientRect(&rect);
//	COLORREF crl = GetSysColor(COLOR_3DFACE);
//	m_memDC.FillSolidRect(rect, crl); 
//	m_memDC.FillSolidRect(&rect, 0x00FFFFFF);// 白色填充, 注意,这次是画在内存设备环境上
//	CPen pen(PS_SOLID, 1, RGB(0, 0, 0));
//	m_memDC.SelectObject(&pen);
//	//画横坐标
//	m_memDC.MoveTo(rect.left+15, (rect.top+(rect.bottom-rect.top)/2));
//	m_memDC.LineTo(rect.right-15, (rect.top + (rect.bottom - rect.top) / 2));
	//写R
//	CFont font;//用来设置大小、样式，颜色用dc.SetTextColor设置
//	font.CreatePointFont(80, TEXT("Arial"));//20号字
//	m_memDC.SelectObject(&font);
//	if (m_ChooseProtect == 2)
//	{
//		CRect rect_font(rect.right - 35, (rect.top + (rect.bottom - rect.top) / 2) + 5, rect.right - 15, (rect.top + (rect.bottom - rect.top) / 2) + 25);
//		m_memDC.DrawText(_T("R"), rect_font, DT_SINGLELINE | DT_CENTER | DT_VCENTER);
//	}
//	//画纵坐标
//	m_memDC.MoveTo(rect.left + (rect.right-rect.left)/2, rect.top+5);
//	m_memDC.LineTo(rect.left + (rect.right - rect.left) / 2, rect.bottom - 5);
	//写JX
//	if (m_ChooseProtect == 2)
//	{
//		CRect rect_font2 = { rect.left + (rect.right - rect.left) / 2 - 20, rect.top + 5, rect.left + (rect.right - rect.left) / 2 - 0, rect.top + 25 };
//		m_memDC.DrawText(_T("jX"), rect_font2, DT_SINGLELINE | DT_CENTER | DT_VCENTER);
//	}
	//画定值向量
//	if (m_ChooseProtect == 2)
//	{
//		CPoint p1(rect.left / 2 + rect.right / 2, rect.top / 2 + rect.bottom / 2);
//		double X_OffSet = UseSetValue.GetValue(ProtectDevice, "接地距离Ⅰ段") * cos(UseSetValue.GetValue(ProtectDevice, "线路正序灵敏角")*M_PI/180)*50;
//		double Y_OffSet = UseSetValue.GetValue(ProtectDevice, "接地距离Ⅰ段") * sin(UseSetValue.GetValue(ProtectDevice, "线路正序灵敏角")*M_PI/180)*50;
//		CPoint p2((rect.left/2 + rect.right/2)+X_OffSet, (rect.top / 2 + rect.bottom / 2)-Y_OffSet);
//		DrawArrow(p1, p2, UseSetValue.GetValue(ProtectDevice, "线路正序灵敏角"), UseSetValue.GetValue(ProtectDevice, "接地距离Ⅰ段")*4);
//	}
//}

//void CProtectSimulationDlg::DrawOnStaticArea()
//{
//	CWnd* pWnd = GetDlgItem(IDC_STATIC);//获得静态文本框的窗口对象
//	CRect rect;
//	pWnd->GetClientRect(&rect);
	//
//	CDC* pDC = pWnd->GetDC();//
	//
//	DrawOnMem();
//	// 一次性的将内存设备环境上绘制完毕的图形"贴"到屏幕上
//	pDC->BitBlt(0, 0, rect.Width(), rect.Height(), &m_memDC, 0, 0, SRCCOPY);
//	pWnd->ReleaseDC(pDC);//
//}

BEGIN_MESSAGE_MAP(CProtectSimulationDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_COMMAND(ID_MENU_DP, &CProtectSimulationDlg::OnMenuDp)
	ON_BN_CLICKED(IDC_BUTTON1, &CProtectSimulationDlg::OnClickedButton1)
	ON_WM_NCHITTEST()
	ON_BN_CLICKED(IDC_BUTTON2, &CProtectSimulationDlg::OnClickedButton2)
	ON_COMMAND(ID_MENU_ZP, &CProtectSimulationDlg::OnMenuZp)
	ON_COMMAND(ID_MENU_CPL, &CProtectSimulationDlg::OnMenuCpl)
	ON_BN_CLICKED(IDC_RADIO13, &CProtectSimulationDlg::OnClickedRadio13)
	ON_COMMAND(IDC_RADIO14, &CProtectSimulationDlg::OnRadio14)
	ON_BN_CLICKED(IDC_RADIO15, &CProtectSimulationDlg::OnClickedRadio15)
	ON_COMMAND(IDC_RADIO16, &CProtectSimulationDlg::OnRadio16)
	ON_COMMAND(ID_MENU_CP, &CProtectSimulationDlg::OnMenuCp)
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
	//m_brush.CreateSolidBrush(RGB(255, 0, 0));//初始化画刷
	//m_pDrawWnd = GetDlgItem(IDC_EDIT_PAINT);//获得静态窗口对象指针
	//InitialDBB();// 初始化双缓冲相关的数据
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
	m_Edit_UAV.SetWindowTextW(_T("57.74"));
	m_Edit_UBV.SetWindowTextW(_T("57.74"));
	m_Edit_UCV.SetWindowTextW(_T("57.74"));
    m_Edit_UAT.SetWindowTextW(_T("0"));
	m_Edit_UBT.SetWindowTextW(_T("-120"));
	m_Edit_UCT.SetWindowTextW(_T("120"));
	m_Edit_IAV.SetWindowTextW(_T("0"));
	m_Edit_IBV.SetWindowTextW(_T("0"));
	m_Edit_ICV.SetWindowTextW(_T("0"));
	m_Edit_IAT.SetWindowTextW(_T("0"));
	m_Edit_IBT.SetWindowTextW(_T("-120"));
	m_Edit_ICT.SetWindowTextW(_T("120"));
	m_UAV_OffSide.SetWindowTextW(_T("57.74"));
	m_UBV_OffSide.SetWindowTextW(_T("57.74"));
	m_UCV_OffSide.SetWindowTextW(_T("57.74"));
	m_UAT_OffSide.SetWindowTextW(_T("0"));
	m_UBT_OffSide.SetWindowTextW(_T("-120"));
	m_UCT_OffSide.SetWindowTextW(_T("120"));
	m_IAV_OffSide.SetWindowTextW(_T("0"));
	m_IBV_OffSide.SetWindowTextW(_T("0"));
	m_ICV_OffSide.SetWindowTextW(_T("0"));
	m_IAT_OffSide.SetWindowTextW(_T("0"));
	m_IBT_OffSide.SetWindowTextW(_T("-120"));
	m_ICT_OffSide.SetWindowTextW(_T("120"));
	m_ChooseProtect = -1;
	((CButton*)GetDlgItem(IDC_RADIO1))->SetCheck(TRUE);
	((CButton*)GetDlgItem(IDC_RADIO3))->SetCheck(TRUE);
	((CButton*)GetDlgItem(IDC_RADIO5))->SetCheck(TRUE);
	((CButton*)GetDlgItem(IDC_RADIO7))->SetCheck(TRUE);
	((CButton*)GetDlgItem(IDC_RADIO9))->SetCheck(TRUE);
	((CButton*)GetDlgItem(IDC_RADIO11))->SetCheck(TRUE);
	((CButton*)GetDlgItem(IDC_RADIO13))->SetCheck(TRUE);
	((CButton*)GetDlgItem(IDC_RADIO15))->SetCheck(TRUE);
	UpdateData(FALSE);
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
		//if (m_ChooseProtect == 2 || m_ChooseProtect == 3)
		//{
		//	PAINTSTRUCT ps;
		//	CRect rt;
		//	m_pDrawWnd->GetClientRect(&rt);
		//	CDC* pDC = m_pDrawWnd->BeginPaint(&ps);
		//	DrawOnMem();
		//	pDC->BitBlt(0, 0, rt.Width(), rt.Height(), &m_memDC, 0, 0, SRCCOPY);
		//	m_pDrawWnd->EndPaint(&ps);
		//}
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
	m_EditText.SetWindowTextW(_T(""));
	CString strAdd = _T("切换至距离保护调试\r\n");
	AppendText(IDC_EDIT_TEXT,strAdd);
	FrameSwitch(m_ChooseProtect);
	((CButton*)GetDlgItem(IDC_RADIO1))->EnableWindow(FALSE);
	((CButton*)GetDlgItem(IDC_RADIO2))->EnableWindow(FALSE);
	((CButton*)GetDlgItem(IDC_RADIO3))->EnableWindow(FALSE);
	((CButton*)GetDlgItem(IDC_RADIO4))->EnableWindow(FALSE);
	((CButton*)GetDlgItem(IDC_RADIO5))->EnableWindow(FALSE);
	((CButton*)GetDlgItem(IDC_RADIO6))->EnableWindow(FALSE);
	((CButton*)GetDlgItem(IDC_RADIO13))->EnableWindow(FALSE);
	((CButton*)GetDlgItem(IDC_RADIO14))->EnableWindow(FALSE);
}


void CProtectSimulationDlg::OnClickedButton1()
{
	switch (m_ChooseProtect)
	{
	case -1:
	{
		AppendText(IDC_EDIT_TEXT, _T("\r\n请先选择要调试的保护："));
		break;
	}
	case 0:
	{
		UpdateData(FALSE);
		vector<Electric_Voltage> U_m;
		vector<Electric_Current> I_m;
		InputUData(U_m);
		InputIData(I_m);
		StartTime = clock();
		CurrentDiff_Protection CP(U_m, I_m,1,GetBKState(IDC_RADIO13));
		CP.CurrentDiffProtectionLoop();
		AppendText(IDC_EDIT_TEXT, _T("本侧保护：\r\n"));
		ProtectReport(CP.GetProtectAcionState(), IDC_EDIT_TEXT);
		CString str;
		if (CP.GetIsStart() == 1)
		{
			AppendText(IDC_EDIT_TEXT, _T("保护启动\r\n"));
		}
		AppendText(IDC_EDIT_TEXT, _T("差动保护动作：差动电流="));
		str.Format(_T("%.3lf"), CP.GetI_Diff());
		AppendText(IDC_EDIT_TEXT, str);
		AppendText(IDC_EDIT_TEXT, _T("    制动电流="));
		str.Format(_T("%.3lf"), CP.GetI_B());
		AppendText(IDC_EDIT_TEXT, str);
		if (CP.GetActionTime() != 0)
		{
			AppendText(IDC_EDIT_TEXT, _T("\r\n动作时间："));
			CString strT;
			strT.Format(_T("%.1lf"), CP.GetActionTime());
			AppendText(IDC_EDIT_TEXT, strT);
			AppendText(IDC_EDIT_TEXT, _T("ms\r\n"));
		}
		AppendText(IDC_EDIT_TEXT, _T("\r\n"));
	}
		break;
	case 1:
	{
		UpdateData(FALSE);
		vector<Electric_Voltage> U_m;
		vector<Electric_Current> I_m;
		InputUData(U_m);
		InputIData(I_m);
		StartTime = clock();
		CurrentDiff_Protection CP_OnSide(U_m, I_m, 0, GetBKState(IDC_RADIO13));
		vector<Electric_Voltage> U_m_OffSide;
		vector<Electric_Current> I_m_OffSide;
		InputUData_OffSide(U_m_OffSide);
		InputIData_OffSide(I_m_OffSide);
		CurrentDiff_Protection CP_OffSide(U_m_OffSide, I_m_OffSide, 0, GetBKState(IDC_RADIO15));
		CurrentDiffProtection(CP_OnSide, CP_OffSide);
		AppendText(IDC_EDIT_TEXT2, _T("本侧保护：\r\n"));
		AppendText(IDC_EDIT_TEXT3, _T("对侧保护：\r\n"));
		ProtectReport(CP_OnSide.GetProtectAcionState(),IDC_EDIT_TEXT2);
		ProtectReport(CP_OffSide.GetProtectAcionState(),IDC_EDIT_TEXT3);
		CString str;
		if (CP_OnSide.GetIsStart() == 1&&CP_OnSide.GetIsWeedBack()==1)
		{
			AppendText(IDC_EDIT_TEXT2, _T("保护弱馈启动\r\n"));
		}
		if (CP_OnSide.GetIsStart() == 1 && CP_OnSide.GetIsWeedBack() == 0)
		{
			AppendText(IDC_EDIT_TEXT2, _T("保护启动\r\n"));
		}
		if (CP_OffSide.GetIsStart() == 1 && CP_OffSide.GetIsWeedBack() == 1)
		{
			AppendText(IDC_EDIT_TEXT3, _T("保护弱馈启动\r\n"));
		}
		if (CP_OffSide.GetIsStart() == 1 && CP_OffSide.GetIsWeedBack() == 0)
		{
			AppendText(IDC_EDIT_TEXT3, _T("保护启动\r\n"));
		}

		AppendText(IDC_EDIT_TEXT2, _T("差动保护动作：差动电流="));
		str.Format(_T("%.3lf"), CP_OnSide.GetI_Diff());
		AppendText(IDC_EDIT_TEXT2, str);
		AppendText(IDC_EDIT_TEXT2, _T("    制动电流="));
		str.Format(_T("%.3lf"), CP_OnSide.GetI_B());
		AppendText(IDC_EDIT_TEXT2, str);
		if (CP_OnSide.GetActionTime() != 0)
		{
			AppendText(IDC_EDIT_TEXT2, _T("\r\n动作时间："));
			CString strT;
			strT.Format(_T("%.1lf"), CP_OnSide.GetActionTime());
			AppendText(IDC_EDIT_TEXT2, strT);
			AppendText(IDC_EDIT_TEXT2, _T("ms\r\n"));
		}
		AppendText(IDC_EDIT_TEXT2, _T("\r\n"));

		AppendText(IDC_EDIT_TEXT3, _T("差动保护动作：差动电流="));
		str.Format(_T("%.3lf"), CP_OffSide.GetI_Diff());
		AppendText(IDC_EDIT_TEXT3, str);
		AppendText(IDC_EDIT_TEXT3, _T("    制动电流="));
		str.Format(_T("%.3lf"), CP_OffSide.GetI_B());
		AppendText(IDC_EDIT_TEXT3, str);
		if (CP_OffSide.GetActionTime() != 0)
		{
			AppendText(IDC_EDIT_TEXT3, _T("\r\n动作时间："));
			CString strT;
			strT.Format(_T("%.1lf"), min(CP_OnSide.GetActionTime(),CP_OffSide.GetActionTime()));
			AppendText(IDC_EDIT_TEXT3, strT);
			AppendText(IDC_EDIT_TEXT3, _T("ms\r\n"));
		}
		AppendText(IDC_EDIT_TEXT3, _T("\r\n"));
	}
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
		DP.DistanceProtection();
		ProtectReport(DP.GetProtectAcionState(), IDC_EDIT_TEXT);
		ProtectActionReport_DP(DP.GetWhich_Protection(),DP.GetZ_m().first.ReturnR(), DP.GetZ_m().first.ReturnX());
		if (DP.GetActionTime() != 0)
		{
			AppendText(IDC_EDIT_TEXT, _T("\r\n动作时间："));
			CString strT;
			strT.Format(_T("%.1lf"), DP.GetActionTime());
			AppendText(IDC_EDIT_TEXT, strT);
			AppendText(IDC_EDIT_TEXT, _T("ms\r\n"));
		}
		AppendText(IDC_EDIT_TEXT, _T("\r\n"));
	}
		break;
	case 3:
	{
		UpdateData(FALSE);
		vector<Electric_Voltage> U_m;
		vector<Electric_Current> I_m;
		InputUData(U_m);
		InputIData(I_m);
		ZeroSeq_Protection ZP(U_m, I_m);
		StartTime = clock();
		ZP.ZeroSeqProtection();
		ProtectReport(ZP.GetProtectAcionState(),IDC_EDIT_TEXT);
		ProtectActionReport_ZP(ZP.GetWhich_Protection(), ZP.GetUZ(), ZP.GetIZ());
		if (ZP.GetActionTime() != 0)
		{
			AppendText(IDC_EDIT_TEXT, _T("\r\n动作时间："));
			CString strT;
			strT.Format(_T("%.1lf"), ZP.GetActionTime());
			AppendText(IDC_EDIT_TEXT, strT);
			AppendText(IDC_EDIT_TEXT, _T("ms\r\n"));
		}
		AppendText(IDC_EDIT_TEXT, _T("\r\n"));
	}
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

		GetDlgItem(IDC_STATIC_OFFSIDE)->ShowWindow(TRUE);
		GetDlgItem(IDC_RADIO7)->ShowWindow(TRUE);
		GetDlgItem(IDC_RADIO8)->ShowWindow(TRUE);
		GetDlgItem(IDC_RADIO9)->ShowWindow(TRUE);
		GetDlgItem(IDC_RADIO10)->ShowWindow(TRUE);
		GetDlgItem(IDC_RADIO11)->ShowWindow(TRUE);
		GetDlgItem(IDC_RADIO12)->ShowWindow(TRUE);
		GetDlgItem(IDC_RADIO15)->ShowWindow(TRUE);
		GetDlgItem(IDC_RADIO16)->ShowWindow(TRUE);
		GetDlgItem(IDC_EDIT_TEXT)->ShowWindow(FALSE);
		GetDlgItem(IDC_EDIT_TEXT2)->ShowWindow(TRUE);
		GetDlgItem(IDC_EDIT_TEXT3)->ShowWindow(TRUE);
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

		GetDlgItem(IDC_STATIC_OFFSIDE)->ShowWindow(FALSE);
		GetDlgItem(IDC_RADIO7)->ShowWindow(FALSE);
		GetDlgItem(IDC_RADIO8)->ShowWindow(FALSE);
		GetDlgItem(IDC_RADIO9)->ShowWindow(FALSE);
		GetDlgItem(IDC_RADIO10)->ShowWindow(FALSE);
		GetDlgItem(IDC_RADIO11)->ShowWindow(FALSE);
		GetDlgItem(IDC_RADIO12)->ShowWindow(FALSE);
		GetDlgItem(IDC_RADIO15)->ShowWindow(FALSE);
		GetDlgItem(IDC_RADIO16)->ShowWindow(FALSE);
		GetDlgItem(IDC_EDIT_TEXT)->ShowWindow(TRUE);
		GetDlgItem(IDC_EDIT_TEXT2)->ShowWindow(FALSE);
		GetDlgItem(IDC_EDIT_TEXT3)->ShowWindow(FALSE);
	}
	// TODO: 在此处添加实现代码.
}


void CProtectSimulationDlg::AppendText(int controlId, CString strAdd)
{
	((CEdit*)GetDlgItem(controlId))->SetSel(GetDlgItem(controlId)->GetWindowTextLength(), GetDlgItem(controlId)->GetWindowTextLength());
	((CEdit*)GetDlgItem(controlId))->ReplaceSel(strAdd);
	// TODO: 在此处添加实现代码.
}



// //输出报文
void CProtectSimulationDlg::ProtectReport(int stat,int nID)
{
	switch (stat)
	{
	case ProtectAction_A:
		AppendText(nID, _T("A相故障\r\n保护跳A相\r\n"));
		if (nID == IDC_EDIT_TEXT3)
		{
			((CButton*)GetDlgItem(IDC_RADIO7))->SetCheck(FALSE);
			((CButton*)GetDlgItem(IDC_RADIO8))->SetCheck(TRUE);
		}
		else
		{
			((CButton*)GetDlgItem(IDC_RADIO1))->SetCheck(FALSE);
			((CButton*)GetDlgItem(IDC_RADIO2))->SetCheck(TRUE);
		}
		break;
	case ProtectAction_B:
		AppendText(nID, _T("B相故障\r\n保护跳B相\r\n"));
		if (nID == IDC_EDIT_TEXT3)
		{
			((CButton*)GetDlgItem(IDC_RADIO9))->SetCheck(FALSE);
			((CButton*)GetDlgItem(IDC_RADIO10))->SetCheck(TRUE);
		}
		else
		{
			((CButton*)GetDlgItem(IDC_RADIO3))->SetCheck(FALSE);
			((CButton*)GetDlgItem(IDC_RADIO4))->SetCheck(TRUE);
		}
		break;
	case ProtectAction_C:
		AppendText(nID, _T("C相故障\r\n保护跳C相\r\n"));
		if (nID == IDC_EDIT_TEXT3)
		{
			((CButton*)GetDlgItem(IDC_RADIO11))->SetCheck(FALSE);
			((CButton*)GetDlgItem(IDC_RADIO12))->SetCheck(TRUE);
		}
		else
		{
			((CButton*)GetDlgItem(IDC_RADIO5))->SetCheck(FALSE);
			((CButton*)GetDlgItem(IDC_RADIO6))->SetCheck(TRUE);
		}
		break;
	case ProtectAction_AB:
		AppendText(nID, _T("AB相间故障\r\n保护三跳\r\n"));
		if (nID == IDC_EDIT_TEXT3)
		{
			((CButton*)GetDlgItem(IDC_RADIO7))->SetCheck(FALSE);
			((CButton*)GetDlgItem(IDC_RADIO8))->SetCheck(TRUE);
			((CButton*)GetDlgItem(IDC_RADIO9))->SetCheck(FALSE);
			((CButton*)GetDlgItem(IDC_RADIO10))->SetCheck(TRUE);
			((CButton*)GetDlgItem(IDC_RADIO11))->SetCheck(FALSE);
			((CButton*)GetDlgItem(IDC_RADIO12))->SetCheck(TRUE);
			((CButton*)GetDlgItem(IDC_RADIO15))->SetCheck(FALSE);
			((CButton*)GetDlgItem(IDC_RADIO16))->SetCheck(TRUE);
		}
		else
		{
			((CButton*)GetDlgItem(IDC_RADIO1))->SetCheck(FALSE);
			((CButton*)GetDlgItem(IDC_RADIO2))->SetCheck(TRUE);
			((CButton*)GetDlgItem(IDC_RADIO3))->SetCheck(FALSE);
			((CButton*)GetDlgItem(IDC_RADIO4))->SetCheck(TRUE);
			((CButton*)GetDlgItem(IDC_RADIO5))->SetCheck(FALSE);
			((CButton*)GetDlgItem(IDC_RADIO6))->SetCheck(TRUE);
			((CButton*)GetDlgItem(IDC_RADIO13))->SetCheck(FALSE);
			((CButton*)GetDlgItem(IDC_RADIO14))->SetCheck(TRUE);
		}
		break;
	case ProtectAction_BC:
		AppendText(nID, _T("BC相间故障\r\n保护三跳\r\n"));
		if (nID == IDC_EDIT_TEXT3)
		{
			((CButton*)GetDlgItem(IDC_RADIO7))->SetCheck(FALSE);
			((CButton*)GetDlgItem(IDC_RADIO8))->SetCheck(TRUE);
			((CButton*)GetDlgItem(IDC_RADIO9))->SetCheck(FALSE);
			((CButton*)GetDlgItem(IDC_RADIO10))->SetCheck(TRUE);
			((CButton*)GetDlgItem(IDC_RADIO11))->SetCheck(FALSE);
			((CButton*)GetDlgItem(IDC_RADIO12))->SetCheck(TRUE);
			((CButton*)GetDlgItem(IDC_RADIO15))->SetCheck(FALSE);
			((CButton*)GetDlgItem(IDC_RADIO16))->SetCheck(TRUE);
		}
		else
		{
			((CButton*)GetDlgItem(IDC_RADIO1))->SetCheck(FALSE);
			((CButton*)GetDlgItem(IDC_RADIO2))->SetCheck(TRUE);
			((CButton*)GetDlgItem(IDC_RADIO3))->SetCheck(FALSE);
			((CButton*)GetDlgItem(IDC_RADIO4))->SetCheck(TRUE);
			((CButton*)GetDlgItem(IDC_RADIO5))->SetCheck(FALSE);
			((CButton*)GetDlgItem(IDC_RADIO6))->SetCheck(TRUE);
			((CButton*)GetDlgItem(IDC_RADIO13))->SetCheck(FALSE);
			((CButton*)GetDlgItem(IDC_RADIO14))->SetCheck(TRUE);
		}
		break;
	case ProtectAction_CA:
		AppendText(nID, _T("AC相间故障\r\n保护三跳\r\n"));
		if (nID == IDC_EDIT_TEXT3)
		{
			((CButton*)GetDlgItem(IDC_RADIO7))->SetCheck(FALSE);
			((CButton*)GetDlgItem(IDC_RADIO8))->SetCheck(TRUE);
			((CButton*)GetDlgItem(IDC_RADIO9))->SetCheck(FALSE);
			((CButton*)GetDlgItem(IDC_RADIO10))->SetCheck(TRUE);
			((CButton*)GetDlgItem(IDC_RADIO11))->SetCheck(FALSE);
			((CButton*)GetDlgItem(IDC_RADIO12))->SetCheck(TRUE);
			((CButton*)GetDlgItem(IDC_RADIO15))->SetCheck(FALSE);
			((CButton*)GetDlgItem(IDC_RADIO16))->SetCheck(TRUE);
		}
		else
		{
			((CButton*)GetDlgItem(IDC_RADIO1))->SetCheck(FALSE);
			((CButton*)GetDlgItem(IDC_RADIO2))->SetCheck(TRUE);
			((CButton*)GetDlgItem(IDC_RADIO3))->SetCheck(FALSE);
			((CButton*)GetDlgItem(IDC_RADIO4))->SetCheck(TRUE);
			((CButton*)GetDlgItem(IDC_RADIO5))->SetCheck(FALSE);
			((CButton*)GetDlgItem(IDC_RADIO6))->SetCheck(TRUE);
			((CButton*)GetDlgItem(IDC_RADIO13))->SetCheck(FALSE);
			((CButton*)GetDlgItem(IDC_RADIO14))->SetCheck(TRUE);
		}
		break;
	case ProtectAction_ABN:
		AppendText(nID, _T("AB相间短路接地故障\r\n保护三跳\r\n"));
		if (nID == IDC_EDIT_TEXT3)
		{
			((CButton*)GetDlgItem(IDC_RADIO7))->SetCheck(FALSE);
			((CButton*)GetDlgItem(IDC_RADIO8))->SetCheck(TRUE);
			((CButton*)GetDlgItem(IDC_RADIO9))->SetCheck(FALSE);
			((CButton*)GetDlgItem(IDC_RADIO10))->SetCheck(TRUE);
			((CButton*)GetDlgItem(IDC_RADIO11))->SetCheck(FALSE);
			((CButton*)GetDlgItem(IDC_RADIO12))->SetCheck(TRUE);
			((CButton*)GetDlgItem(IDC_RADIO15))->SetCheck(FALSE);
			((CButton*)GetDlgItem(IDC_RADIO16))->SetCheck(TRUE);
		}
		else
		{
			((CButton*)GetDlgItem(IDC_RADIO1))->SetCheck(FALSE);
			((CButton*)GetDlgItem(IDC_RADIO2))->SetCheck(TRUE);
			((CButton*)GetDlgItem(IDC_RADIO3))->SetCheck(FALSE);
			((CButton*)GetDlgItem(IDC_RADIO4))->SetCheck(TRUE);
			((CButton*)GetDlgItem(IDC_RADIO5))->SetCheck(FALSE);
			((CButton*)GetDlgItem(IDC_RADIO6))->SetCheck(TRUE);
			((CButton*)GetDlgItem(IDC_RADIO13))->SetCheck(FALSE);
			((CButton*)GetDlgItem(IDC_RADIO14))->SetCheck(TRUE);
		}
		break;
	case ProtectAction_BCN:
		AppendText(nID, _T("BC相间短路接地故障\r\n保护三跳\r\n"));
		if (nID == IDC_EDIT_TEXT3)
		{
			((CButton*)GetDlgItem(IDC_RADIO7))->SetCheck(FALSE);
			((CButton*)GetDlgItem(IDC_RADIO8))->SetCheck(TRUE);
			((CButton*)GetDlgItem(IDC_RADIO9))->SetCheck(FALSE);
			((CButton*)GetDlgItem(IDC_RADIO10))->SetCheck(TRUE);
			((CButton*)GetDlgItem(IDC_RADIO11))->SetCheck(FALSE);
			((CButton*)GetDlgItem(IDC_RADIO12))->SetCheck(TRUE);
			((CButton*)GetDlgItem(IDC_RADIO15))->SetCheck(FALSE);
			((CButton*)GetDlgItem(IDC_RADIO16))->SetCheck(TRUE);
		}
		else
		{
			((CButton*)GetDlgItem(IDC_RADIO1))->SetCheck(FALSE);
			((CButton*)GetDlgItem(IDC_RADIO2))->SetCheck(TRUE);
			((CButton*)GetDlgItem(IDC_RADIO3))->SetCheck(FALSE);
			((CButton*)GetDlgItem(IDC_RADIO4))->SetCheck(TRUE);
			((CButton*)GetDlgItem(IDC_RADIO5))->SetCheck(FALSE);
			((CButton*)GetDlgItem(IDC_RADIO6))->SetCheck(TRUE);
			((CButton*)GetDlgItem(IDC_RADIO13))->SetCheck(FALSE);
			((CButton*)GetDlgItem(IDC_RADIO14))->SetCheck(TRUE);
		}
		break;
	case ProtectAction_CAN:
		AppendText(nID, _T("AC相间短路接地故障\r\n保护三跳\r\n"));
		if (nID == IDC_EDIT_TEXT3)
		{
			((CButton*)GetDlgItem(IDC_RADIO7))->SetCheck(FALSE);
			((CButton*)GetDlgItem(IDC_RADIO8))->SetCheck(TRUE);
			((CButton*)GetDlgItem(IDC_RADIO9))->SetCheck(FALSE);
			((CButton*)GetDlgItem(IDC_RADIO10))->SetCheck(TRUE);
			((CButton*)GetDlgItem(IDC_RADIO11))->SetCheck(FALSE);
			((CButton*)GetDlgItem(IDC_RADIO12))->SetCheck(TRUE);
			((CButton*)GetDlgItem(IDC_RADIO15))->SetCheck(FALSE);
			((CButton*)GetDlgItem(IDC_RADIO16))->SetCheck(TRUE);
		}
		else
		{
			((CButton*)GetDlgItem(IDC_RADIO1))->SetCheck(FALSE);
			((CButton*)GetDlgItem(IDC_RADIO2))->SetCheck(TRUE);
			((CButton*)GetDlgItem(IDC_RADIO3))->SetCheck(FALSE);
			((CButton*)GetDlgItem(IDC_RADIO4))->SetCheck(TRUE);
			((CButton*)GetDlgItem(IDC_RADIO5))->SetCheck(FALSE);
			((CButton*)GetDlgItem(IDC_RADIO6))->SetCheck(TRUE);
			((CButton*)GetDlgItem(IDC_RADIO13))->SetCheck(FALSE);
			((CButton*)GetDlgItem(IDC_RADIO14))->SetCheck(TRUE);
		}
		break;
	case ProtectAction_ABC:
		AppendText(nID, _T("ABC三相短路故障\r\n保护三跳\r\n"));
		if (nID == IDC_EDIT_TEXT3)
		{
			((CButton*)GetDlgItem(IDC_RADIO7))->SetCheck(FALSE);
			((CButton*)GetDlgItem(IDC_RADIO8))->SetCheck(TRUE);
			((CButton*)GetDlgItem(IDC_RADIO9))->SetCheck(FALSE);
			((CButton*)GetDlgItem(IDC_RADIO10))->SetCheck(TRUE);
			((CButton*)GetDlgItem(IDC_RADIO11))->SetCheck(FALSE);
			((CButton*)GetDlgItem(IDC_RADIO12))->SetCheck(TRUE);
			((CButton*)GetDlgItem(IDC_RADIO15))->SetCheck(FALSE);
			((CButton*)GetDlgItem(IDC_RADIO16))->SetCheck(TRUE);
		}
		else
		{
			((CButton*)GetDlgItem(IDC_RADIO1))->SetCheck(FALSE);
			((CButton*)GetDlgItem(IDC_RADIO2))->SetCheck(TRUE);
			((CButton*)GetDlgItem(IDC_RADIO3))->SetCheck(FALSE);
			((CButton*)GetDlgItem(IDC_RADIO4))->SetCheck(TRUE);
			((CButton*)GetDlgItem(IDC_RADIO5))->SetCheck(FALSE);
			((CButton*)GetDlgItem(IDC_RADIO6))->SetCheck(TRUE);
			((CButton*)GetDlgItem(IDC_RADIO13))->SetCheck(FALSE);
			((CButton*)GetDlgItem(IDC_RADIO14))->SetCheck(TRUE);
		}
		break;
	case ProtectNoAction:
		AppendText(IDC_EDIT_TEXT, _T("无故障\r\n"));
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




LRESULT CProtectSimulationDlg::OnNcHitTest(CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	int ret = CDialog::OnNcHitTest(point);

	//if语句的前两行是用来禁止改变大小的，最后一行是用来禁止移动的
	if (HTTOP == ret || HTBOTTOM == ret || HTLEFT == ret || HTRIGHT == ret
		|| HTBOTTOMLEFT == ret || HTBOTTOMRIGHT == ret || HTTOPLEFT == ret || HTTOPRIGHT == ret || HTCAPTION == ret)
		return HTCLIENT;

	return ret;
}


// //画向量
//void CProtectSimulationDlg::DrawArrow(CPoint p1, CPoint p2, double theta, int length)
//{
//	theta = 3.1415926 * theta / 180;//转换为弧度
//	double Px, Py, P1x, P1y, P2x, P2y;
	//以P2为原点得到向量P2P1（P）
//	Px = p1.x - p2.x;
//	Py = p1.y - p2.y;
	//向量P旋转theta角得到向量P1
//	P1x = Px * cos(theta) - Py * sin(theta);
//	P1y = Px * sin(theta) + Py * cos(theta);
	//向量P旋转-theta角得到向量P2
//	P2x = Px * cos(-theta) - Py * sin(-theta);
//	P2y = Px * sin(-theta) + Py * cos(-theta);
	//伸缩向量至制定长度
//	double x1, x2;
//	x1 = sqrt(P1x * P1x + P1y * P1y);
//	P1x = P1x * length / x1;
//	P1y = P1y * length / x1;
//	x2 = sqrt(P2x * P2x + P2y * P2y);
//	P2x = P2x * length / x2;
//	P2y = P2y * length / x2;
//	//平移变量到直线的末端
//	P1x = P1x + p2.x;
//	P1y = P1y + p2.y;
//	P2x = P2x + p2.x;
//	P2y = P2y + p2.y;
//	CPen pen, pen1, * oldpen;
//	pen.CreatePen(PS_SOLID, 2, RGB(255, 0, 0));
//	pen1.CreatePen(PS_SOLID, 2, RGB(0, 0, 255));
//	oldpen = m_memDC.SelectObject(&pen);
//	m_memDC.MoveTo(p1.x, p1.y);
//	m_memDC.LineTo(p2.x, p2.y);
//	m_memDC.SelectObject(&pen1);
//	m_memDC.MoveTo(p2.x, p2.y);
//	m_memDC.LineTo(P1x, P1y);
//	m_memDC.MoveTo(p2.x, p2.y);
//	m_memDC.LineTo(P2x, P2y);
//	m_memDC.SelectObject(oldpen);
//	// TODO: 在此处添加实现代码.
//}


void CProtectSimulationDlg::ProtectActionReport_DP(ActionState Stat, double R, double jX)
{
	CString str;
	switch (Stat)
	{
	case JieDiJuLi_ⅠAction:
		AppendText(IDC_EDIT_TEXT, _T("接地距离Ⅰ段动作：电阻="));
		str.Format(_T("%.3lf"), R);
		AppendText(IDC_EDIT_TEXT, str);
		AppendText(IDC_EDIT_TEXT, _T("    电抗="));
		str.Format(_T("%.3lf"), jX);
		AppendText(IDC_EDIT_TEXT, str);
		break;
	case JieDiJuLi_ⅡAction:
		AppendText(IDC_EDIT_TEXT, _T("接地距离Ⅱ段动作：电阻="));
		str.Format(_T("%.3lf"), R);
		AppendText(IDC_EDIT_TEXT, str);
		AppendText(IDC_EDIT_TEXT, _T("    电抗="));
		str.Format(_T("%.3lf"), jX);
		AppendText(IDC_EDIT_TEXT, str);
		break;
	case JieDiJuLi_ⅢAction:
		AppendText(IDC_EDIT_TEXT, _T("接地距离Ⅲ段动作：电阻="));
		str.Format(_T("%.3lf"), R);
		AppendText(IDC_EDIT_TEXT, str);
		AppendText(IDC_EDIT_TEXT, _T("    电抗="));
		str.Format(_T("%.3lf"), jX);
		AppendText(IDC_EDIT_TEXT, str);
		break;
	case XiangJianJuLi_ⅠAction:
		AppendText(IDC_EDIT_TEXT, _T("相间距离Ⅰ段动作：电阻="));
		str.Format(_T("%.3lf"), R);
		AppendText(IDC_EDIT_TEXT, str);
		AppendText(IDC_EDIT_TEXT, _T("    电抗="));
		str.Format(_T("%.3lf"), jX);
		AppendText(IDC_EDIT_TEXT, str);
		break;
	case XiangJianJuLi_ⅡAction:
		AppendText(IDC_EDIT_TEXT, _T("相间距离Ⅱ段动作：电阻="));
		str.Format(_T("%.3lf"), R);
		AppendText(IDC_EDIT_TEXT, str);
		AppendText(IDC_EDIT_TEXT, _T("    电抗="));
		str.Format(_T("%.3lf"), jX);
		AppendText(IDC_EDIT_TEXT, str);
		break;
	case XiangJianJuLi_ⅢAction:
		AppendText(IDC_EDIT_TEXT, _T("相间距离Ⅲ段动作：电阻="));
		str.Format(_T("%.3lf"), R);
		AppendText(IDC_EDIT_TEXT, str);
		AppendText(IDC_EDIT_TEXT, _T("    电抗="));
		str.Format(_T("%.3lf"), jX);
		AppendText(IDC_EDIT_TEXT, str);
		break;
	default:
		break;
	}
}


void CProtectSimulationDlg::OnClickedButton2()
{
	m_EditText.SetWindowTextW(_T(""));
	m_EditText2.SetWindowTextW(_T(""));
	m_EditText3.SetWindowTextW(_T(""));
	((CButton*)GetDlgItem(IDC_RADIO1))->SetCheck(TRUE);
	((CButton*)GetDlgItem(IDC_RADIO2))->SetCheck(FALSE);
	((CButton*)GetDlgItem(IDC_RADIO3))->SetCheck(TRUE);
	((CButton*)GetDlgItem(IDC_RADIO4))->SetCheck(FALSE);
	((CButton*)GetDlgItem(IDC_RADIO5))->SetCheck(TRUE);
	((CButton*)GetDlgItem(IDC_RADIO6))->SetCheck(FALSE);
	((CButton*)GetDlgItem(IDC_RADIO13))->SetCheck(TRUE);
	((CButton*)GetDlgItem(IDC_RADIO14))->SetCheck(FALSE);
	((CButton*)GetDlgItem(IDC_RADIO7))->SetCheck(TRUE);
	((CButton*)GetDlgItem(IDC_RADIO8))->SetCheck(FALSE);
	((CButton*)GetDlgItem(IDC_RADIO9))->SetCheck(TRUE);
	((CButton*)GetDlgItem(IDC_RADIO10))->SetCheck(FALSE);
	((CButton*)GetDlgItem(IDC_RADIO11))->SetCheck(TRUE);
	((CButton*)GetDlgItem(IDC_RADIO12))->SetCheck(FALSE);
	((CButton*)GetDlgItem(IDC_RADIO15))->SetCheck(TRUE);
	((CButton*)GetDlgItem(IDC_RADIO16))->SetCheck(FALSE);
	m_Edit_UAV.SetWindowTextW(_T("57.74"));
	m_Edit_UBV.SetWindowTextW(_T("57.74"));
	m_Edit_UCV.SetWindowTextW(_T("57.74"));
	m_Edit_UAT.SetWindowTextW(_T("0"));
	m_Edit_UBT.SetWindowTextW(_T("-120"));
	m_Edit_UCT.SetWindowTextW(_T("120"));
	m_Edit_IAV.SetWindowTextW(_T("0"));
	m_Edit_IBV.SetWindowTextW(_T("0"));
	m_Edit_ICV.SetWindowTextW(_T("0"));
	m_Edit_IAT.SetWindowTextW(_T("0"));
	m_Edit_IBT.SetWindowTextW(_T("-120"));
	m_Edit_ICT.SetWindowTextW(_T("120"));
	m_UAV_OffSide.SetWindowTextW(_T("57.74"));
	m_UBV_OffSide.SetWindowTextW(_T("57.74"));
	m_UCV_OffSide.SetWindowTextW(_T("57.74"));
	m_UAT_OffSide.SetWindowTextW(_T("0"));
	m_UBT_OffSide.SetWindowTextW(_T("-120"));
	m_UCT_OffSide.SetWindowTextW(_T("120"));
	m_IAV_OffSide.SetWindowTextW(_T("0"));
	m_IBV_OffSide.SetWindowTextW(_T("0"));
	m_ICV_OffSide.SetWindowTextW(_T("0"));
	m_IAT_OffSide.SetWindowTextW(_T("0"));
	m_IBT_OffSide.SetWindowTextW(_T("-120"));
	m_ICT_OffSide.SetWindowTextW(_T("120"));
	// TODO: 在此添加控件通知处理程序代码
}


void CProtectSimulationDlg::OnMenuZp()
{
	m_ChooseProtect = 3;//切换至距离保护的标志
	m_EditText.SetWindowTextW(_T(""));
	CString strAdd = _T("切换至零序保护调试\r\n");
	AppendText(IDC_EDIT_TEXT, strAdd);
	FrameSwitch(m_ChooseProtect);
	((CButton*)GetDlgItem(IDC_RADIO1))->EnableWindow(FALSE);
	((CButton*)GetDlgItem(IDC_RADIO2))->EnableWindow(FALSE);
	((CButton*)GetDlgItem(IDC_RADIO3))->EnableWindow(FALSE);
	((CButton*)GetDlgItem(IDC_RADIO4))->EnableWindow(FALSE);
	((CButton*)GetDlgItem(IDC_RADIO5))->EnableWindow(FALSE);
	((CButton*)GetDlgItem(IDC_RADIO6))->EnableWindow(FALSE);
	((CButton*)GetDlgItem(IDC_RADIO13))->EnableWindow(FALSE);
	((CButton*)GetDlgItem(IDC_RADIO14))->EnableWindow(FALSE);
	// TODO: 在此添加命令处理程序代码
}


void CProtectSimulationDlg::ProtectActionReport_ZP(ActionState stat, Electric_Voltage UZ, Electric_Current IZ)
{
	CString str;
	switch (stat)
	{
	case LinXuDianLiu_ⅡAction:
		AppendText(IDC_EDIT_TEXT, _T("零序电流Ⅱ段动作：U0="));
		str.Format(_T("%.2lf"), UZ.GetVValid());
		AppendText(IDC_EDIT_TEXT, str);
		AppendText(IDC_EDIT_TEXT, _T("∠"));
		str.Format(_T("%.1lf"), arg(UZ.ReturnVComplex())*180/M_PI);
		AppendText(IDC_EDIT_TEXT, str);

		AppendText(IDC_EDIT_TEXT, _T("    I0="));
		str.Format(_T("%.2lf"), IZ.GetIValid());
		AppendText(IDC_EDIT_TEXT, str);
		AppendText(IDC_EDIT_TEXT, _T("∠"));
		str.Format(_T("%.1lf"), arg(IZ.ReturnIComplex()) * 180 / M_PI);
		AppendText(IDC_EDIT_TEXT, str);
		break;
	case LinXuDianLiu_ⅢAction:
		AppendText(IDC_EDIT_TEXT, _T("零序电流Ⅲ段动作：U0="));
		str.Format(_T("%.2lf"), UZ.GetVValid());
		AppendText(IDC_EDIT_TEXT, str);
		AppendText(IDC_EDIT_TEXT, _T("∠"));
		str.Format(_T("%.1lf"), arg(UZ.ReturnVComplex()) * 180 / M_PI);
		AppendText(IDC_EDIT_TEXT, str);

		AppendText(IDC_EDIT_TEXT, _T("    I0="));
		str.Format(_T("%.2lf"), IZ.GetIValid());
		AppendText(IDC_EDIT_TEXT, str);
		AppendText(IDC_EDIT_TEXT, _T("∠"));
		str.Format(_T("%.1lf"), arg(IZ.ReturnIComplex()) * 180 / M_PI);
		AppendText(IDC_EDIT_TEXT, str);
		break;
	default:
		break;
	}
	// TODO: 在此处添加实现代码.
}


void CProtectSimulationDlg::OnMenuCpl()
{
	m_ChooseProtect = 0;
	m_EditText.SetWindowTextW(_T(""));
	CString strAdd = _T("切换至光纤纵差保护(自环)调试\r\n");
	AppendText(IDC_EDIT_TEXT, strAdd);
	FrameSwitch(m_ChooseProtect);
	((CButton*)GetDlgItem(IDC_RADIO1))->EnableWindow(FALSE);
	((CButton*)GetDlgItem(IDC_RADIO2))->EnableWindow(FALSE);
	((CButton*)GetDlgItem(IDC_RADIO3))->EnableWindow(FALSE);
	((CButton*)GetDlgItem(IDC_RADIO4))->EnableWindow(FALSE);
	((CButton*)GetDlgItem(IDC_RADIO5))->EnableWindow(FALSE);
	((CButton*)GetDlgItem(IDC_RADIO6))->EnableWindow(FALSE);
	((CButton*)GetDlgItem(IDC_RADIO13))->EnableWindow(FALSE);
	((CButton*)GetDlgItem(IDC_RADIO14))->EnableWindow(FALSE);
	// TODO: 在此添加命令处理程序代码
}


//void CProtectSimulationDlg::OnRadio1()
//{
//	if (m_ChooseProtect==0|| m_ChooseProtect == 1)
//	{
//		m_Breaker_BenCe = 1;
//	}
//	// TODO: 在此添加命令处理程序代码
//}


//void CProtectSimulationDlg::OnRadio2()
//{
//	if (m_ChooseProtect == 0 || m_ChooseProtect == 1)
//	{
//		m_Breaker_BenCe = 0;
//	}
//	// TODO: 在此添加命令处理程序代码
//}


//void CProtectSimulationDlg::OnRadio3()
//{
//	if (m_ChooseProtect == 0 || m_ChooseProtect == 1)
//	{
//		m_Breaker_DuiCe = 1;
//	}
//	// TODO: 在此添加命令处理程序代码
//}


//void CProtectSimulationDlg::OnRadio4()
//{
//	if (m_ChooseProtect == 0 || m_ChooseProtect == 1)
//	{
//		m_Breaker_DuiCe = 0;
//	}
//	// TODO: 在此添加命令处理程序代码
//}


void CProtectSimulationDlg::OnClickedRadio13()
{
	((CButton*)GetDlgItem(IDC_RADIO1))->SetCheck(TRUE);
	((CButton*)GetDlgItem(IDC_RADIO3))->SetCheck(TRUE);
	((CButton*)GetDlgItem(IDC_RADIO5))->SetCheck(TRUE);
	((CButton*)GetDlgItem(IDC_RADIO2))->SetCheck(FALSE);
	((CButton*)GetDlgItem(IDC_RADIO4))->SetCheck(FALSE);
	((CButton*)GetDlgItem(IDC_RADIO6))->SetCheck(FALSE);
	UpdateData(FALSE);
	// TODO: 在此添加控件通知处理程序代码
}


void CProtectSimulationDlg::OnRadio14()
{
	((CButton*)GetDlgItem(IDC_RADIO2))->SetCheck(TRUE);
	((CButton*)GetDlgItem(IDC_RADIO4))->SetCheck(TRUE);
	((CButton*)GetDlgItem(IDC_RADIO6))->SetCheck(TRUE);
	((CButton*)GetDlgItem(IDC_RADIO1))->SetCheck(FALSE);
	((CButton*)GetDlgItem(IDC_RADIO3))->SetCheck(FALSE);
	((CButton*)GetDlgItem(IDC_RADIO5))->SetCheck(FALSE);
	UpdateData(FALSE);
	// TODO: 在此添加命令处理程序代码
}


void CProtectSimulationDlg::OnClickedRadio15()
{
	((CButton*)GetDlgItem(IDC_RADIO7))->SetCheck(TRUE);
	((CButton*)GetDlgItem(IDC_RADIO9))->SetCheck(TRUE);
	((CButton*)GetDlgItem(IDC_RADIO11))->SetCheck(TRUE);
	((CButton*)GetDlgItem(IDC_RADIO8))->SetCheck(FALSE);
	((CButton*)GetDlgItem(IDC_RADIO10))->SetCheck(FALSE);
	((CButton*)GetDlgItem(IDC_RADIO12))->SetCheck(FALSE);
	UpdateData(FALSE);
	// TODO: 在此添加控件通知处理程序代码
}


void CProtectSimulationDlg::OnRadio16()
{
	((CButton*)GetDlgItem(IDC_RADIO8))->SetCheck(TRUE);
	((CButton*)GetDlgItem(IDC_RADIO10))->SetCheck(TRUE);
	((CButton*)GetDlgItem(IDC_RADIO12))->SetCheck(TRUE);
	((CButton*)GetDlgItem(IDC_RADIO7))->SetCheck(FALSE);
	((CButton*)GetDlgItem(IDC_RADIO9))->SetCheck(FALSE);
	((CButton*)GetDlgItem(IDC_RADIO11))->SetCheck(FALSE);
	UpdateData(FALSE);
	// TODO: 在此添加命令处理程序代码
}


int CProtectSimulationDlg::GetBKState(int BK)
{
	// TODO: 在此处添加实现代码.
	if (((CButton*)GetDlgItem(BK))->GetCheck())
		return 1;
	return 0;
}


void CProtectSimulationDlg::OnMenuCp()
{
	m_ChooseProtect = 1;
	m_EditText.SetWindowTextW(_T(""));
	CString strAdd = _T("切换至光纤纵差保护(联调)调试\r\n");
	AppendText(IDC_EDIT_TEXT, strAdd);
	FrameSwitch(m_ChooseProtect);
	((CButton*)GetDlgItem(IDC_RADIO1))->EnableWindow(TRUE);
	((CButton*)GetDlgItem(IDC_RADIO2))->EnableWindow(TRUE);
	((CButton*)GetDlgItem(IDC_RADIO3))->EnableWindow(TRUE);
	((CButton*)GetDlgItem(IDC_RADIO4))->EnableWindow(TRUE);
	((CButton*)GetDlgItem(IDC_RADIO5))->EnableWindow(TRUE);
	((CButton*)GetDlgItem(IDC_RADIO6))->EnableWindow(TRUE);
	((CButton*)GetDlgItem(IDC_RADIO13))->EnableWindow(TRUE);
	((CButton*)GetDlgItem(IDC_RADIO14))->EnableWindow(TRUE);
	// TODO: 在此添加命令处理程序代码
}


void CProtectSimulationDlg::InputUData_OffSide(vector<Electric_Voltage>& U_m)
{
	CString U_A_V, U_A_T, U_B_V, U_B_T, U_C_V, U_C_T;
	m_UAV_OffSide.GetWindowTextW(U_A_V);
	m_UAT_OffSide.GetWindowTextW(U_A_T);
	m_UBV_OffSide.GetWindowTextW(U_B_V);
	m_UBT_OffSide.GetWindowTextW(U_B_T);
	m_UCV_OffSide.GetWindowTextW(U_C_V);
	m_UCT_OffSide.GetWindowTextW(U_C_T);
	Electric_Voltage U_A(_ttof(U_A_V), _ttof(U_A_T));
	Electric_Voltage U_B(_ttof(U_B_V), _ttof(U_B_T));
	Electric_Voltage U_C(_ttof(U_C_V), _ttof(U_C_T));
	U_m.push_back(U_A);
	U_m.push_back(U_B);
	U_m.push_back(U_C);
	// TODO: 在此处添加实现代码.
}


void CProtectSimulationDlg::InputIData_OffSide(vector<Electric_Current>& I_m)
{
	CString I_A_V, I_A_T, I_B_V, I_B_T, I_C_V, I_C_T;
	m_IAV_OffSide.GetWindowTextW(I_A_V);
	m_IAT_OffSide.GetWindowTextW(I_A_T);
	m_IBV_OffSide.GetWindowTextW(I_B_V);
	m_IBT_OffSide.GetWindowTextW(I_B_T);
	m_ICV_OffSide.GetWindowTextW(I_C_V);
	m_ICT_OffSide.GetWindowTextW(I_C_T);
	Electric_Current I_A(_ttof(I_A_V), _ttof(I_A_T));
	Electric_Current I_B(_ttof(I_B_V), _ttof(I_B_T));
	Electric_Current I_C(_ttof(I_C_V), _ttof(I_C_T));
	I_m.push_back(I_A);
	I_m.push_back(I_B);
	I_m.push_back(I_C);
	// TODO: 在此处添加实现代码.
}
