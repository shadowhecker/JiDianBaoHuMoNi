//
//                            _ooOoo_
//                           o8888888o
//                           88" . "88
//                           (| -_- |)
//                            O\ = /O
//                        ____/`---'\____
//                      .   ' \\| |// `.
//                       / \\||| 8 |||// \
//                     / _||||| -8- |||||- \
//                       | | \\\ 8 /// | |
//                     | \_| ''\-8-/'' | |
//                      \ .-\__ `8` ___/-. /
//                   ___`. .' /--8--\ `. . __
//                ."" '< `.___\_<8>_/___.' >'"".
//               | | : `- \`.;`\ 8 /`;.`/ - ` : | |
//                 \ \ `-. \_ __\ /__ _/ .-` / /
//         ======`-.____`-.___\_____/___.-`____.-'======
//                            `=---='
//
//         .............................................
//                  佛祖保佑                  永无BUG
// ProtectSimulationDlg.cpp: 实现文件
//
#include "framework.h"
#include "ProtectSimulation.h"
#include "ProtectSimulationDlg.h"
#include "Protection_Lib.h"
#include "afxdialogex.h"
#include "CDlgAttion.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

static double seconds_v = 0;
static double milliseconds_v = 0;

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
public:
	afx_msg void OnBnClickedMfclink1();
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
	ON_BN_CLICKED(IDC_MFCLINK1, &CAboutDlg::OnBnClickedMfclink1)
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
	DDX_Control(pDX, IDC_EDIT_TIME, m_systime);
	DDX_Control(pDX, IDC_TAB_UI, m_TAB);
}

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
	ON_COMMAND(ID_MENU_ABOUT, &CProtectSimulationDlg::OnMenuAbout)
	ON_WM_TIMER()
	ON_BN_CLICKED(IDC_BUTTON3, &CProtectSimulationDlg::OnClickedButton3)
	ON_WM_RBUTTONDOWN()
	ON_COMMAND(ID_32782, &CProtectSimulationDlg::On_AddState)
	ON_NOTIFY(TCN_SELCHANGE, IDC_TAB_UI, &CProtectSimulationDlg::OnTcnSelchangeTabUi)
	ON_COMMAND(ID_32783, &CProtectSimulationDlg::On_DeleteState)
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
	m_TAB.InsertItem(0, _T("第一态"));
	CPage1.Create(IDD_DIALOG_OneState, GetDlgItem(IDC_TAB_UI));
	CRect rs;
	GetDlgItem(IDC_TAB_UI)->GetClientRect(&rs);
	//设置属性页的大小和位置
	rs.top += 21;
	rs.bottom -= 0;
	rs.left += 0;
	rs.right -= 0;
	CPage1.MoveWindow(&rs);
	CPage1.ShowWindow(TRUE);
	m_TAB.SetCurSel(0);
	m_Time = { 0,0,0,0 };
	GetDlgItem(IDC_BUTTON3)->EnableWindow(FALSE);
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
	GetDlgItem(IDC_BUTTON3)->EnableWindow(TRUE);
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
		StartTime = clock();
		CPage1.UpdateUIInput();
		TGW_Protect.InitializeUI(CPage1.m_U, CPage1.m_I);
		UpdateFromSet(TGW_Protect);
		DeviceGetTime();
		SetTimer(TIME_DEVICE_COUNT, 1, NULL);
		SetTimer(TIME_DEVICE_FIRST, m_Time[0]*1000, NULL);
		DeviceCurrentDiffAction();//装置动作行
	}
		break;
	case 1:
	{
		UpdateData(TRUE);
		vector<Electric_Voltage> U_m;
		vector<Electric_Current> I_m;
		InputUData(U_m);
		InputIData(I_m);
		StartTime = clock();
		TGW931 TP_OnSide(U_m, I_m);
		UpdateFromSet(TP_OnSide);
		vector<Electric_Voltage> U_m_OffSide;
		vector<Electric_Current> I_m_OffSide;
		InputUData_OffSide(U_m_OffSide);
		InputIData_OffSide(I_m_OffSide);
		TGW931 TP_OffSide(U_m_OffSide, I_m_OffSide);
		UpdateFromSet_OffSide(TP_OffSide);
		CurrentDiffProtection(TP_OnSide.CP, TP_OffSide.CP);
		AppendText(IDC_EDIT_TEXT2, _T("本侧保护：\r\n"));
		AppendText(IDC_EDIT_TEXT3, _T("对侧保护：\r\n"));
		ProtectReport(TP_OnSide.CP.GetProtectAcionState(),IDC_EDIT_TEXT2, TP_OnSide);
		ProtectReport(TP_OffSide.CP.GetProtectAcionState(),IDC_EDIT_TEXT3, TP_OffSide);
		UpdateBKState(TP_OnSide);
		UpdateBKState_OffSide(TP_OffSide);
		CString str;
		if (TP_OnSide.CP.GetIsStart() == 1&& TP_OnSide.CP.GetIsWeedBack()==1)
		{
			AppendText(IDC_EDIT_TEXT2, _T("保护弱馈启动\r\n"));
		}
		if (TP_OnSide.CP.GetIsStart() == 1 && TP_OnSide.CP.GetIsWeedBack() == 0)
		{
			AppendText(IDC_EDIT_TEXT2, _T("保护启动\r\n"));
		}
		if (TP_OffSide.CP.GetIsStart() == 1 && TP_OffSide.CP.GetIsWeedBack() == 1)
		{
			AppendText(IDC_EDIT_TEXT3, _T("保护弱馈启动\r\n"));
		}
		if (TP_OffSide.CP.GetIsStart() == 1 && TP_OffSide.CP.GetIsWeedBack() == 0)
		{
			AppendText(IDC_EDIT_TEXT3, _T("保护启动\r\n"));
		}

		AppendText(IDC_EDIT_TEXT2, _T("差动保护动作：差动电流="));
		str.Format(_T("%.3lf"), TP_OnSide.CP.GetI_Diff());
		AppendText(IDC_EDIT_TEXT2, str);
		AppendText(IDC_EDIT_TEXT2, _T("    制动电流="));
		str.Format(_T("%.3lf"), TP_OnSide.CP.GetI_B());
		AppendText(IDC_EDIT_TEXT2, str);
		if (TP_OnSide.CP.GetActionTime() != 0)
		{
			AppendText(IDC_EDIT_TEXT2, _T("\r\n动作时间："));
			CString strT;
			strT.Format(_T("%.1lf"), TP_OnSide.CP.GetActionTime());
			AppendText(IDC_EDIT_TEXT2, strT);
			AppendText(IDC_EDIT_TEXT2, _T("ms\r\n"));
		}
		AppendText(IDC_EDIT_TEXT2, _T("\r\n"));

		AppendText(IDC_EDIT_TEXT3, _T("差动保护动作：差动电流="));
		str.Format(_T("%.3lf"), TP_OffSide.CP.GetI_Diff());
		AppendText(IDC_EDIT_TEXT3, str);
		AppendText(IDC_EDIT_TEXT3, _T("    制动电流="));
		str.Format(_T("%.3lf"), TP_OffSide.CP.GetI_B());
		AppendText(IDC_EDIT_TEXT3, str);
		if (TP_OffSide.CP.GetActionTime() != 0)
		{
			AppendText(IDC_EDIT_TEXT3, _T("\r\n动作时间："));
			CString strT;
			strT.Format(_T("%.1lf"), min(TP_OnSide.CP.GetActionTime(), TP_OffSide.CP.GetActionTime()));
			AppendText(IDC_EDIT_TEXT3, strT);
			AppendText(IDC_EDIT_TEXT3, _T("ms\r\n"));
		}
		AppendText(IDC_EDIT_TEXT3, _T("\r\n"));
	}
		break;
	case 2:
	{
		UpdateData(FALSE);
		StartTime = clock();
		CPage1.UpdateUIInput();
		TGW_Protect.InitializeUI(CPage1.m_U, CPage1.m_I);
		UpdateFromSet(TGW_Protect);
		DeviceGetTime();
		SetTimer(TIME_DEVICE_COUNT, 1, NULL);
		SetTimer(TIME_DEVICE_FIRST, m_Time[0] * 1000, NULL);
		DeviceDistanceAction();
	}
		break;
	case 3:
	{
		UpdateData(FALSE);
		StartTime = clock();
		CPage1.UpdateUIInput();
		TGW_Protect.InitializeUI(CPage1.m_U, CPage1.m_I);
		UpdateFromSet(TGW_Protect);
		DeviceGetTime();
		SetTimer(TIME_DEVICE_COUNT, 1, NULL);
		SetTimer(TIME_DEVICE_FIRST, m_Time[0] * 1000, NULL);
		DeviceZeroSeqAction();
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
		GetDlgItem(IDC_EDIT_TIME)->ShowWindow(FALSE);
		GetDlgItem(IDC_STATIC_TIME)->ShowWindow(FALSE);

		GetDlgItem(IDC_TAB_UI)->ShowWindow(FALSE);
		CPage1.ShowWindow(FALSE);
		GetDlgItem(IDC_STATIC_MS)->ShowWindow(FALSE);
		GetDlgItem(IDC_STATIC_GP1)->ShowWindow(TRUE);
		GetDlgItem(IDC_STATIC1)->ShowWindow(TRUE);
		GetDlgItem(IDC_STATIC2)->ShowWindow(TRUE);
		GetDlgItem(IDC_STATIC3)->ShowWindow(TRUE);
		GetDlgItem(IDC_STATIC4)->ShowWindow(TRUE);
		GetDlgItem(IDC_STATIC5)->ShowWindow(TRUE);
		GetDlgItem(IDC_STATIC6)->ShowWindow(TRUE);
		GetDlgItem(IDC_STATIC7)->ShowWindow(TRUE);
		GetDlgItem(IDC_STATIC8)->ShowWindow(TRUE);
		GetDlgItem(IDC_STATIC9)->ShowWindow(TRUE);
		GetDlgItem(IDC_STATIC10)->ShowWindow(TRUE);
		GetDlgItem(IDC_STATIC11)->ShowWindow(TRUE);
		GetDlgItem(IDC_STATIC12)->ShowWindow(TRUE);

		GetDlgItem(IDC_EDIT1)->ShowWindow(TRUE);
		GetDlgItem(IDC_EDIT2)->ShowWindow(TRUE);
		GetDlgItem(IDC_EDIT3)->ShowWindow(TRUE);
		GetDlgItem(IDC_EDIT4)->ShowWindow(TRUE);
		GetDlgItem(IDC_EDIT5)->ShowWindow(TRUE);
		GetDlgItem(IDC_EDIT6)->ShowWindow(TRUE);
		GetDlgItem(IDC_EDIT7)->ShowWindow(TRUE);
		GetDlgItem(IDC_EDIT8)->ShowWindow(TRUE);
		GetDlgItem(IDC_EDIT9)->ShowWindow(TRUE);
		GetDlgItem(IDC_EDIT10)->ShowWindow(TRUE);
		GetDlgItem(IDC_EDIT11)->ShowWindow(TRUE);
		GetDlgItem(IDC_EDIT12)->ShowWindow(TRUE);

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
		GetDlgItem(IDC_EDIT_TIME)->ShowWindow(TRUE);
		GetDlgItem(IDC_STATIC_TIME)->ShowWindow(TRUE);

		GetDlgItem(IDC_TAB_UI)->ShowWindow(TRUE);
		CPage1.ShowWindow(TRUE);
		GetDlgItem(IDC_STATIC_MS)->ShowWindow(TRUE);
		GetDlgItem(IDC_STATIC_GP1)->ShowWindow(FALSE);
		GetDlgItem(IDC_STATIC1)->ShowWindow(FALSE);
		GetDlgItem(IDC_STATIC2)->ShowWindow(FALSE);
		GetDlgItem(IDC_STATIC3)->ShowWindow(FALSE);
		GetDlgItem(IDC_STATIC4)->ShowWindow(FALSE);
		GetDlgItem(IDC_STATIC5)->ShowWindow(FALSE);
		GetDlgItem(IDC_STATIC6)->ShowWindow(FALSE);
		GetDlgItem(IDC_STATIC7)->ShowWindow(FALSE);
		GetDlgItem(IDC_STATIC8)->ShowWindow(FALSE);
		GetDlgItem(IDC_STATIC9)->ShowWindow(FALSE);
		GetDlgItem(IDC_STATIC10)->ShowWindow(FALSE);
		GetDlgItem(IDC_STATIC11)->ShowWindow(FALSE);
		GetDlgItem(IDC_STATIC12)->ShowWindow(FALSE);

		GetDlgItem(IDC_EDIT1)->ShowWindow(FALSE);
		GetDlgItem(IDC_EDIT2)->ShowWindow(FALSE);
		GetDlgItem(IDC_EDIT3)->ShowWindow(FALSE);
		GetDlgItem(IDC_EDIT4)->ShowWindow(FALSE);
		GetDlgItem(IDC_EDIT5)->ShowWindow(FALSE);
		GetDlgItem(IDC_EDIT6)->ShowWindow(FALSE);
		GetDlgItem(IDC_EDIT7)->ShowWindow(FALSE);
		GetDlgItem(IDC_EDIT8)->ShowWindow(FALSE);
		GetDlgItem(IDC_EDIT9)->ShowWindow(FALSE);
		GetDlgItem(IDC_EDIT10)->ShowWindow(FALSE);
		GetDlgItem(IDC_EDIT11)->ShowWindow(FALSE);
		GetDlgItem(IDC_EDIT12)->ShowWindow(FALSE);
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
void CProtectSimulationDlg::ProtectReport(int stat,int nID,TGW931& TP)
{
	switch (stat)
	{
	case ProtectAction_A:
		AppendText(nID, _T("A相故障\r\n保护跳A相\r\n"));
		TP.BK.OffBKA();
		break;
	case ProtectAction_B:
		AppendText(nID, _T("B相故障\r\n保护跳B相\r\n"));
		TP.BK.OffBKB();
		break;
	case ProtectAction_C:
		AppendText(nID, _T("C相故障\r\n保护跳C相\r\n"));
		TP.BK.OffBKC();
		break;
	case ProtectAction_AB:
		AppendText(nID, _T("AB相间故障\r\n保护三跳\r\n"));
		TP.BK.OffBKABC();
		break;
	case ProtectAction_BC:
		AppendText(nID, _T("BC相间故障\r\n保护三跳\r\n"));
		TP.BK.OffBKABC();
		break;
	case ProtectAction_CA:
		AppendText(nID, _T("AC相间故障\r\n保护三跳\r\n"));
		TP.BK.OffBKABC();
		break;
	case ProtectAction_ABN:
		AppendText(nID, _T("AB相间短路接地故障\r\n保护三跳\r\n"));
		TP.BK.OffBKABC();
		break;
	case ProtectAction_BCN:
		AppendText(nID, _T("BC相间短路接地故障\r\n保护三跳\r\n"));
		TP.BK.OffBKABC();
		break;
	case ProtectAction_CAN:
		AppendText(nID, _T("AC相间短路接地故障\r\n保护三跳\r\n"));
		TP.BK.OffBKABC();
		break;
	case ProtectAction_ABC:
		AppendText(nID, _T("ABC三相短路故障\r\n保护三跳\r\n"));
		TP.BK.OffBKABC();
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
		AppendText(IDC_EDIT_TEXT, _T("\r\n"));
		break;
	case JieDiJuLi_ⅡAction:
		AppendText(IDC_EDIT_TEXT, _T("接地距离Ⅱ段动作：电阻="));
		str.Format(_T("%.3lf"), R);
		AppendText(IDC_EDIT_TEXT, str);
		AppendText(IDC_EDIT_TEXT, _T("    电抗="));
		str.Format(_T("%.3lf"), jX);
		AppendText(IDC_EDIT_TEXT, str);
		AppendText(IDC_EDIT_TEXT, _T("\r\n"));
		break;
	case JieDiJuLi_ⅢAction:
		AppendText(IDC_EDIT_TEXT, _T("接地距离Ⅲ段动作：电阻="));
		str.Format(_T("%.3lf"), R);
		AppendText(IDC_EDIT_TEXT, str);
		AppendText(IDC_EDIT_TEXT, _T("    电抗="));
		str.Format(_T("%.3lf"), jX);
		AppendText(IDC_EDIT_TEXT, str);
		AppendText(IDC_EDIT_TEXT, _T("\r\n"));
		break;
	case XiangJianJuLi_ⅠAction:
		AppendText(IDC_EDIT_TEXT, _T("相间距离Ⅰ段动作：电阻="));
		str.Format(_T("%.3lf"), R);
		AppendText(IDC_EDIT_TEXT, str);
		AppendText(IDC_EDIT_TEXT, _T("    电抗="));
		str.Format(_T("%.3lf"), jX);
		AppendText(IDC_EDIT_TEXT, str);
		AppendText(IDC_EDIT_TEXT, _T("\r\n"));
		break;
	case XiangJianJuLi_ⅡAction:
		AppendText(IDC_EDIT_TEXT, _T("相间距离Ⅱ段动作：电阻="));
		str.Format(_T("%.3lf"), R);
		AppendText(IDC_EDIT_TEXT, str);
		AppendText(IDC_EDIT_TEXT, _T("    电抗="));
		str.Format(_T("%.3lf"), jX);
		AppendText(IDC_EDIT_TEXT, str);
		AppendText(IDC_EDIT_TEXT, _T("\r\n"));
		break;
	case XiangJianJuLi_ⅢAction:
		AppendText(IDC_EDIT_TEXT, _T("相间距离Ⅲ段动作：电阻="));
		str.Format(_T("%.3lf"), R);
		AppendText(IDC_EDIT_TEXT, str);
		AppendText(IDC_EDIT_TEXT, _T("    电抗="));
		str.Format(_T("%.3lf"), jX);
		AppendText(IDC_EDIT_TEXT, str);
		AppendText(IDC_EDIT_TEXT, _T("\r\n"));
		break;
	default:
		break;
	}
}

void CProtectSimulationDlg::OnClickedButton2()
{
	m_EditText.SetWindowTextW(_T(""));
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
	if (m_ChooseProtect == 1)
	{
		m_EditText2.SetWindowTextW(_T(""));
		m_EditText3.SetWindowTextW(_T(""));
		
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

	}
	else
	{
		CPage1.GetDlgItem(IDC_EDIT14)->SetWindowTextW(_T("57.74"));
		CPage1.GetDlgItem(IDC_EDIT15)->SetWindowTextW(_T("57.74"));
		CPage1.GetDlgItem(IDC_EDIT16)->SetWindowTextW(_T("57.74"));
		CPage1.GetDlgItem(IDC_EDIT17)->SetWindowTextW(_T("0"));
		CPage1.GetDlgItem(IDC_EDIT18)->SetWindowTextW(_T("-120"));
		CPage1.GetDlgItem(IDC_EDIT19)->SetWindowTextW(_T("120"));
		CPage1.GetDlgItem(IDC_EDIT20)->SetWindowTextW(_T("0"));
		CPage1.GetDlgItem(IDC_EDIT21)->SetWindowTextW(_T("0"));
		CPage1.GetDlgItem(IDC_EDIT22)->SetWindowTextW(_T("0"));
		CPage1.GetDlgItem(IDC_EDIT23)->SetWindowTextW(_T("0"));
		CPage1.GetDlgItem(IDC_EDIT24)->SetWindowTextW(_T("-120"));
		CPage1.GetDlgItem(IDC_EDIT25)->SetWindowTextW(_T("120"));
		CPage1.GetDlgItem(IDC_EDIT_TIME)->SetWindowTextW(_T("0"));
		UpdateData(FALSE);
	}
	m_systime.SetWindowTextW(_T("00:000"));
	seconds_v = 0;
	milliseconds_v = 0;
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
		AppendText(IDC_EDIT_TEXT, _T("\r\n"));
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
		AppendText(IDC_EDIT_TEXT, _T("\r\n"));
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

void CAboutDlg::OnBnClickedMfclink1()
{
	// TODO: 在此添加控件通知处理程序代码
}

void CProtectSimulationDlg::OnMenuAbout()
{
	CAboutDlg dlg;
	dlg.DoModal();
	// TODO: 在此添加命令处理程序代码
}
// //更新装置的断路器状态
void CProtectSimulationDlg::UpdateBKState(TGW931& TP)//
{
	if (TP.BK.IsBKON())
	{
		((CButton*)GetDlgItem(IDC_RADIO13))->SetCheck(TRUE);
		((CButton*)GetDlgItem(IDC_RADIO14))->SetCheck(FALSE);
	}
	else
	{
		((CButton*)GetDlgItem(IDC_RADIO13))->SetCheck(FALSE);
		((CButton*)GetDlgItem(IDC_RADIO14))->SetCheck(TRUE);
	}
	if (TP.BK.IsBKAON())
	{
		((CButton*)GetDlgItem(IDC_RADIO1))->SetCheck(TRUE);
		((CButton*)GetDlgItem(IDC_RADIO2))->SetCheck(FALSE);
	}
	else
	{
		((CButton*)GetDlgItem(IDC_RADIO1))->SetCheck(FALSE);
		((CButton*)GetDlgItem(IDC_RADIO2))->SetCheck(TRUE);
	}
	if (TP.BK.IsBKBON())
	{
		((CButton*)GetDlgItem(IDC_RADIO3))->SetCheck(TRUE);
		((CButton*)GetDlgItem(IDC_RADIO4))->SetCheck(FALSE);
	}
	else
	{
		((CButton*)GetDlgItem(IDC_RADIO3))->SetCheck(FALSE);
		((CButton*)GetDlgItem(IDC_RADIO4))->SetCheck(TRUE);
	}
	if (TP.BK.IsBKCON())
	{
		((CButton*)GetDlgItem(IDC_RADIO5))->SetCheck(TRUE);
		((CButton*)GetDlgItem(IDC_RADIO6))->SetCheck(FALSE);
	}
	else
	{
		((CButton*)GetDlgItem(IDC_RADIO5))->SetCheck(FALSE);
		((CButton*)GetDlgItem(IDC_RADIO6))->SetCheck(TRUE);
	}
	UpdateData(FALSE);
	// TODO: 在此处添加实现代码.
}
// //从用户设定界面返回开关状态
void CProtectSimulationDlg::UpdateFromSet(TGW931& TP)
{
	if (((CButton*)GetDlgItem(IDC_RADIO1))->GetCheck())
		TP.BK.OnBKA();
	else
		TP.BK.OffBKA();
	if (((CButton*)GetDlgItem(IDC_RADIO3))->GetCheck())
		TP.BK.OnBKB();
	else
		TP.BK.OffBKB();
	if (((CButton*)GetDlgItem(IDC_RADIO5))->GetCheck())
		TP.BK.OnBKC();
	else
		TP.BK.OffBKC();
	if (((CButton*)GetDlgItem(IDC_RADIO13))->GetCheck())
	{
		TP.BK.OnBKA();
		TP.BK.OnBKB();
		TP.BK.OnBKC();
	}
	else
	{
		TP.BK.OffBKA();
		TP.BK.OffBKB();
		TP.BK.OffBKC();
	}
	TP.UpdateProtectBKState();
	// TODO: 在此处添加实现代码.
}

void CProtectSimulationDlg::UpdateBKState_OffSide(TGW931& TP)//
{
	if (TP.BK.IsBKON())
	{
		((CButton*)GetDlgItem(IDC_RADIO15))->SetCheck(TRUE);
		((CButton*)GetDlgItem(IDC_RADIO16))->SetCheck(FALSE);
	}
	else
	{
		((CButton*)GetDlgItem(IDC_RADIO15))->SetCheck(FALSE);
		((CButton*)GetDlgItem(IDC_RADIO16))->SetCheck(TRUE);
	}
	if (TP.BK.IsBKAON())
	{
		((CButton*)GetDlgItem(IDC_RADIO7))->SetCheck(TRUE);
		((CButton*)GetDlgItem(IDC_RADIO8))->SetCheck(FALSE);
	}
	else
	{
		((CButton*)GetDlgItem(IDC_RADIO7))->SetCheck(FALSE);
		((CButton*)GetDlgItem(IDC_RADIO8))->SetCheck(TRUE);
	}
	if (TP.BK.IsBKBON())
	{
		((CButton*)GetDlgItem(IDC_RADIO9))->SetCheck(TRUE);
		((CButton*)GetDlgItem(IDC_RADIO10))->SetCheck(FALSE);
	}
	else
	{
		((CButton*)GetDlgItem(IDC_RADIO9))->SetCheck(FALSE);
		((CButton*)GetDlgItem(IDC_RADIO10))->SetCheck(TRUE);
	}
	if (TP.BK.IsBKCON())
	{
		((CButton*)GetDlgItem(IDC_RADIO11))->SetCheck(TRUE);
		((CButton*)GetDlgItem(IDC_RADIO12))->SetCheck(FALSE);
	}
	else
	{
		((CButton*)GetDlgItem(IDC_RADIO11))->SetCheck(FALSE);
		((CButton*)GetDlgItem(IDC_RADIO12))->SetCheck(TRUE);
	}
	UpdateData(FALSE);
	// TODO: 在此处添加实现代码.
}
// //从用户设定界面返回开关状态
void CProtectSimulationDlg::UpdateFromSet_OffSide(TGW931& TP)
{
	if (((CButton*)GetDlgItem(IDC_RADIO7))->GetCheck())
		TP.BK.OnBKA();
	else
		TP.BK.OffBKA();
	if (((CButton*)GetDlgItem(IDC_RADIO9))->GetCheck())
		TP.BK.OnBKB();
	else
		TP.BK.OffBKB();
	if (((CButton*)GetDlgItem(IDC_RADIO11))->GetCheck())
		TP.BK.OnBKC();
	else
		TP.BK.OffBKC();
	if (((CButton*)GetDlgItem(IDC_RADIO15))->GetCheck())
	{
		TP.BK.OnBKA();
		TP.BK.OnBKB();
		TP.BK.OnBKC();
	}
	else
	{
		TP.BK.OffBKA();
		TP.BK.OffBKB();
		TP.BK.OffBKC();
	}
	TP.UpdateProtectBKState();
	// TODO: 在此处添加实现代码.
}

void CProtectSimulationDlg::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	CString str;
	switch (nIDEvent)
	{
	case TIME_DEVICE_COUNT:
		milliseconds_v++;
		if (milliseconds_v >= 63)
		{
			milliseconds_v = 0;
			seconds_v++;
		}
		str.Format(_T("%02.0f:%03.0f"), seconds_v, milliseconds_v);
		m_systime.SetWindowTextW(str);
		UpdateData(FALSE);
		break;
	case TIME_DEVICE_FIRST:
		TGW_Protect.ClearUI();
		KillTimer(TIME_DEVICE_FIRST);
		KillTimer(TIME_DEVICE_COUNT);
		str.Format(_T("%02.0f:%03.0f"), floor(m_Time[0]), (m_Time[0] - floor(m_Time[0])) * 1000);
		m_systime.SetWindowTextW(str); 
		UpdateData(FALSE);
		GetDlgItem(IDC_BUTTON3)->EnableWindow(FALSE);
		break;
	case TIME_DEVICE_CP_FIRST:
		if (TGW_Protect.IsBKOffSuccess(TGW_Protect.CP.GetProtectAcionState()))
		{
			switch (TGW_Protect.CP.GetProtectAcionState())
			{
			case ProtectAction_A:
				AppendText(IDC_EDIT_TEXT, _T("A相跳闸成功\r\n"));
				KillTimer(TIME_DEVICE_CP_SECOND);
				KillTimer(TIME_DEVICE_CP_THIRD);
				KillTimer(TIME_DEVICE_CP_FORTH);
				break;
			case ProtectAction_B:
				AppendText(IDC_EDIT_TEXT, _T("B相跳闸成功\r\n"));
				KillTimer(TIME_DEVICE_CP_SECOND);
				KillTimer(TIME_DEVICE_CP_THIRD);
				KillTimer(TIME_DEVICE_CP_FORTH);
				break;
			case ProtectAction_C:
				AppendText(IDC_EDIT_TEXT, _T("C相跳闸成功\r\n"));
				KillTimer(TIME_DEVICE_CP_SECOND);
				KillTimer(TIME_DEVICE_CP_THIRD);
				KillTimer(TIME_DEVICE_CP_FORTH);
				break;
			case ProtectNoAction:
				KillTimer(TIME_DEVICE_CP_FIRST);
				KillTimer(TIME_DEVICE_CP_THIRD);
				KillTimer(TIME_DEVICE_CP_SECOND);
				break;
			default:
				AppendText(IDC_EDIT_TEXT, _T("三相跳闸成功\r\n"));
				KillTimer(TIME_DEVICE_CP_SECOND);
				KillTimer(TIME_DEVICE_CP_THIRD);
				KillTimer(TIME_DEVICE_CP_FORTH);
				break;
			}
		}
		else
		{
			switch (TGW_Protect.CP.GetProtectAcionState())
			{
			case ProtectAction_A:
				AppendText(IDC_EDIT_TEXT, _T("A相单跳失败,补跳单相\r\n"));
				TGW_Protect.BK.OffBKA();
				TGW_Protect.CP.SetProtectActionState(ProtectAction_A);
				UpdateBKState(TGW_Protect);
				break;
			case ProtectAction_B:
				AppendText(IDC_EDIT_TEXT, _T("B相单失败,补跳单相\r\n"));
				TGW_Protect.BK.OffBKB();
				TGW_Protect.CP.SetProtectActionState(ProtectAction_B);
				UpdateBKState(TGW_Protect);
				break;
			case ProtectAction_C:
				AppendText(IDC_EDIT_TEXT, _T("C相单跳失败,补跳单相\r\n"));
				TGW_Protect.BK.OffBKC();
				TGW_Protect.CP.SetProtectActionState(ProtectAction_C);
				UpdateBKState(TGW_Protect);
				break;
			case ProtectNoAction:
				KillTimer(TIME_DEVICE_CP_FIRST);
				KillTimer(TIME_DEVICE_CP_SECOND);
				break;
			default:
				AppendText(IDC_EDIT_TEXT, _T("三相跳闸失败，永跳闭锁重合闸\r\n"));
				TGW_Protect.BK.OffBKABC();
				TGW_Protect.CP.SetProtectActionState(ProtectAction_ABC);
				KillTimer(TIME_DEVICE_CP_THIRD);
				break;
			}
		}
		KillTimer(TIME_DEVICE_CP_FIRST);
		break;
	case TIME_DEVICE_CP_SECOND:
		if (TGW_Protect.IsBKOffSuccess(TGW_Protect.CP.GetProtectAcionState()) && TGW_Protect.CP.GetProtectAcionState() == ProtectAction_ABC)
		{
			AppendText(IDC_EDIT_TEXT, _T("永跳成功\r\n"));
			KillTimer(TIME_DEVICE_CP_SECOND);
			KillTimer(TIME_DEVICE_CP_THIRD);
			KillTimer(TIME_DEVICE_CP_FORTH);
			break;
		}
		if (!TGW_Protect.IsBKOffSuccess(TGW_Protect.CP.GetProtectAcionState()) && TGW_Protect.CP.GetProtectAcionState() == ProtectAction_ABC)
		{
			KillTimer(TIME_DEVICE_CP_SECOND);
			KillTimer(TIME_DEVICE_CP_THIRD);
			break;
		}
		if (TGW_Protect.IsBKOffSuccess(TGW_Protect.CP.GetProtectAcionState()) && TGW_Protect.CP.GetProtectAcionState() != ProtectAction_ABC)
		{
			AppendText(IDC_EDIT_TEXT, _T("补跳单相成功\r\n"));
			KillTimer(TIME_DEVICE_CP_SECOND);
			KillTimer(TIME_DEVICE_CP_THIRD);
			KillTimer(TIME_DEVICE_CP_FORTH);
			break;
		}
		else
		{
			switch (TGW_Protect.CP.GetProtectAcionState())
			{
			case ProtectAction_A:
				AppendText(IDC_EDIT_TEXT, _T("A相补跳失败,永跳闭锁重合闸\r\n"));
				TGW_Protect.BK.OffBKABC();
				UpdateBKState(TGW_Protect);
				TGW_Protect.CP.SetProtectActionState(ProtectAction_ABC);
				KillTimer(TIME_DEVICE_CP_SECOND);
				break;
			case ProtectAction_B:
				AppendText(IDC_EDIT_TEXT, _T("B相补跳失败,永跳闭锁重合闸\r\n"));
				TGW_Protect.BK.OffBKABC();
				UpdateBKState(TGW_Protect);
				TGW_Protect.CP.SetProtectActionState(ProtectAction_ABC);
				KillTimer(TIME_DEVICE_CP_SECOND);
				break;
			case ProtectAction_C:
				AppendText(IDC_EDIT_TEXT, _T("C相补跳失败,永跳闭锁重合闸\r\n"));
				TGW_Protect.BK.OffBKABC();
				UpdateBKState(TGW_Protect);
				TGW_Protect.CP.SetProtectActionState(ProtectAction_ABC);
				KillTimer(TIME_DEVICE_CP_SECOND);
				break;
			}
		}
		break;
	case TIME_DEVICE_CP_THIRD:
		if (TGW_Protect.IsBKOffSuccess(TGW_Protect.CP.GetProtectAcionState()))
		{
			AppendText(IDC_EDIT_TEXT, _T("永跳成功\r\n"));
			KillTimer(TIME_DEVICE_CP_THIRD);
			KillTimer(TIME_DEVICE_CP_FORTH);
		}
		else
		{
			KillTimer(TIME_DEVICE_CP_THIRD);
		}
		break;
	case TIME_DEVICE_CP_FORTH:
		AppendText(IDC_EDIT_TEXT, _T("永跳失败\r\n"));
		KillTimer(TIME_DEVICE_CP_FORTH);
		break;
	case TIME_DEVICE_DP_FIRST:
		if (TGW_Protect.IsBKOffSuccess(TGW_Protect.DP.GetProtectAcionState()))
		{
			switch (TGW_Protect.DP.GetProtectAcionState())
			{
			case ProtectAction_A:
				AppendText(IDC_EDIT_TEXT, _T("A相跳闸成功\r\n"));
				KillTimer(TIME_DEVICE_DP_SECOND);
				KillTimer(TIME_DEVICE_DP_THIRD);
				KillTimer(TIME_DEVICE_DP_FORTH);
				break;
			case ProtectAction_B:
				AppendText(IDC_EDIT_TEXT, _T("B相跳闸成功\r\n"));
				KillTimer(TIME_DEVICE_DP_SECOND);
				KillTimer(TIME_DEVICE_DP_THIRD);
				KillTimer(TIME_DEVICE_DP_FORTH);
				break;
			case ProtectAction_C:
				AppendText(IDC_EDIT_TEXT, _T("C相跳闸成功\r\n"));
				KillTimer(TIME_DEVICE_DP_SECOND);
				KillTimer(TIME_DEVICE_DP_THIRD);
				KillTimer(TIME_DEVICE_DP_FORTH);
				break;
			case ProtectNoAction:
				KillTimer(TIME_DEVICE_DP_FIRST);
				KillTimer(TIME_DEVICE_DP_THIRD);
				KillTimer(TIME_DEVICE_DP_SECOND);
				break;
			default:
				AppendText(IDC_EDIT_TEXT, _T("三相跳闸成功\r\n"));
				KillTimer(TIME_DEVICE_DP_SECOND);
				KillTimer(TIME_DEVICE_DP_THIRD);
				KillTimer(TIME_DEVICE_DP_FORTH);
				break;
			}
		}
		else
		{
			switch (TGW_Protect.DP.GetProtectAcionState())
			{
			case ProtectAction_A:
				AppendText(IDC_EDIT_TEXT, _T("A相单跳失败,补跳单相\r\n"));
				TGW_Protect.BK.OffBKA();
				TGW_Protect.DP.SetProtectActionState(ProtectAction_A);
				UpdateBKState(TGW_Protect);
				break;
			case ProtectAction_B:
				AppendText(IDC_EDIT_TEXT, _T("B相单失败,补跳单相\r\n"));
				TGW_Protect.BK.OffBKB();
				TGW_Protect.DP.SetProtectActionState(ProtectAction_B);
				UpdateBKState(TGW_Protect);
				break;
			case ProtectAction_C:
				AppendText(IDC_EDIT_TEXT, _T("C相单跳失败,补跳单相\r\n"));
				TGW_Protect.BK.OffBKC();
				TGW_Protect.DP.SetProtectActionState(ProtectAction_C);
				UpdateBKState(TGW_Protect);
				break;
			case ProtectNoAction:
				KillTimer(TIME_DEVICE_DP_FIRST);
				KillTimer(TIME_DEVICE_DP_SECOND);
				break;
			default:
				AppendText(IDC_EDIT_TEXT, _T("三相跳闸失败，永跳闭锁重合闸\r\n"));
				TGW_Protect.BK.OffBKABC();
				TGW_Protect.DP.SetProtectActionState(ProtectAction_ABC);
				KillTimer(TIME_DEVICE_DP_THIRD);
				break;
			}
		}
		KillTimer(TIME_DEVICE_DP_FIRST);
		break;
	case TIME_DEVICE_DP_SECOND:
		if (TGW_Protect.IsBKOffSuccess(TGW_Protect.DP.GetProtectAcionState()) && TGW_Protect.DP.GetProtectAcionState() == ProtectAction_ABC)
		{
			AppendText(IDC_EDIT_TEXT, _T("永跳成功\r\n"));
			KillTimer(TIME_DEVICE_DP_SECOND);
			KillTimer(TIME_DEVICE_DP_THIRD);
			KillTimer(TIME_DEVICE_DP_FORTH);
			break;
		}
		if (!TGW_Protect.IsBKOffSuccess(TGW_Protect.DP.GetProtectAcionState()) && TGW_Protect.DP.GetProtectAcionState() == ProtectAction_ABC)
		{
			KillTimer(TIME_DEVICE_DP_SECOND);
			KillTimer(TIME_DEVICE_DP_THIRD);
			break;
		}
		if (TGW_Protect.IsBKOffSuccess(TGW_Protect.DP.GetProtectAcionState()) && TGW_Protect.DP.GetProtectAcionState() != ProtectAction_ABC)
		{
			AppendText(IDC_EDIT_TEXT, _T("补跳单相成功\r\n"));
			KillTimer(TIME_DEVICE_DP_SECOND);
			KillTimer(TIME_DEVICE_DP_THIRD);
			KillTimer(TIME_DEVICE_DP_FORTH);
			break;
		}
		else
		{
			switch (TGW_Protect.DP.GetProtectAcionState())
			{
			case ProtectAction_A:
				AppendText(IDC_EDIT_TEXT, _T("A相补跳失败,永跳闭锁重合闸\r\n"));
				TGW_Protect.BK.OffBKABC();
				UpdateBKState(TGW_Protect);
				TGW_Protect.DP.SetProtectActionState(ProtectAction_ABC);
				KillTimer(TIME_DEVICE_DP_SECOND);
				break;
			case ProtectAction_B:
				AppendText(IDC_EDIT_TEXT, _T("B相补跳失败,永跳闭锁重合闸\r\n"));
				TGW_Protect.BK.OffBKABC();
				UpdateBKState(TGW_Protect);
				TGW_Protect.DP.SetProtectActionState(ProtectAction_ABC);
				KillTimer(TIME_DEVICE_DP_SECOND);
				break;
			case ProtectAction_C:
				AppendText(IDC_EDIT_TEXT, _T("C相补跳失败,永跳闭锁重合闸\r\n"));
				TGW_Protect.BK.OffBKABC();
				UpdateBKState(TGW_Protect);
				TGW_Protect.DP.SetProtectActionState(ProtectAction_ABC);
				KillTimer(TIME_DEVICE_DP_SECOND);
				break;
			}
		}
		break;
	case TIME_DEVICE_DP_THIRD:
		if (TGW_Protect.IsBKOffSuccess(TGW_Protect.DP.GetProtectAcionState()))
		{
			AppendText(IDC_EDIT_TEXT, _T("永跳成功\r\n"));
			KillTimer(TIME_DEVICE_DP_THIRD);
			KillTimer(TIME_DEVICE_DP_FORTH);
		}
		else
		{
			KillTimer(TIME_DEVICE_DP_THIRD);
		}
		break;
	case TIME_DEVICE_DP_FORTH:
		AppendText(IDC_EDIT_TEXT, _T("永跳失败\r\n"));
		KillTimer(TIME_DEVICE_DP_FORTH);
		break;
	case TIME_DEVICE_ZP_FIRST:
		if (TGW_Protect.IsBKOffSuccess(TGW_Protect.ZP.GetProtectAcionState()))
		{
			switch (TGW_Protect.ZP.GetProtectAcionState())
			{
			case ProtectAction_A:
				AppendText(IDC_EDIT_TEXT, _T("A相跳闸成功\r\n"));
				KillTimer(TIME_DEVICE_ZP_SECOND);
				KillTimer(TIME_DEVICE_ZP_THIRD);
				KillTimer(TIME_DEVICE_ZP_FORTH);
				break;
			case ProtectAction_B:
				AppendText(IDC_EDIT_TEXT, _T("B相跳闸成功\r\n"));
				KillTimer(TIME_DEVICE_ZP_SECOND);
				KillTimer(TIME_DEVICE_ZP_THIRD);
				KillTimer(TIME_DEVICE_ZP_FORTH);
				break;
			case ProtectAction_C:
				AppendText(IDC_EDIT_TEXT, _T("C相跳闸成功\r\n"));
				KillTimer(TIME_DEVICE_ZP_SECOND);
				KillTimer(TIME_DEVICE_ZP_THIRD);
				KillTimer(TIME_DEVICE_ZP_FORTH);
				break;
			case ProtectNoAction:
				KillTimer(TIME_DEVICE_ZP_FIRST);
				KillTimer(TIME_DEVICE_ZP_THIRD);
				KillTimer(TIME_DEVICE_ZP_SECOND);
				break;
			default:
				AppendText(IDC_EDIT_TEXT, _T("三相跳闸成功\r\n"));
				KillTimer(TIME_DEVICE_ZP_SECOND);
				KillTimer(TIME_DEVICE_ZP_THIRD);
				KillTimer(TIME_DEVICE_ZP_FORTH);
				break;
			}
		}
		else
		{
			switch (TGW_Protect.ZP.GetProtectAcionState())
			{
			case ProtectAction_A:
				AppendText(IDC_EDIT_TEXT, _T("A相单跳失败,补跳单相\r\n"));
				TGW_Protect.BK.OffBKA();
				TGW_Protect.ZP.SetProtectActionState(ProtectAction_A);
				UpdateBKState(TGW_Protect);
				break;
			case ProtectAction_B:
				AppendText(IDC_EDIT_TEXT, _T("B相单失败,补跳单相\r\n"));
				TGW_Protect.BK.OffBKB();
				TGW_Protect.ZP.SetProtectActionState(ProtectAction_B);
				UpdateBKState(TGW_Protect);
				break;
			case ProtectAction_C:
				AppendText(IDC_EDIT_TEXT, _T("C相单跳失败,补跳单相\r\n"));
				TGW_Protect.BK.OffBKC();
				TGW_Protect.ZP.SetProtectActionState(ProtectAction_C);
				UpdateBKState(TGW_Protect);
				break;
			case ProtectNoAction:
				KillTimer(TIME_DEVICE_ZP_FIRST);
				KillTimer(TIME_DEVICE_ZP_SECOND);
				break;
			default:
				AppendText(IDC_EDIT_TEXT, _T("三相跳闸失败，永跳闭锁重合闸\r\n"));
				TGW_Protect.BK.OffBKABC();
				TGW_Protect.ZP.SetProtectActionState(ProtectAction_ABC);
				KillTimer(TIME_DEVICE_ZP_THIRD);
				break;
			}
		}
		KillTimer(TIME_DEVICE_ZP_FIRST);
		break;
	case TIME_DEVICE_ZP_SECOND:
		if (TGW_Protect.IsBKOffSuccess(TGW_Protect.ZP.GetProtectAcionState()) && TGW_Protect.ZP.GetProtectAcionState() == ProtectAction_ABC)
		{
			AppendText(IDC_EDIT_TEXT, _T("永跳成功\r\n"));
			KillTimer(TIME_DEVICE_ZP_SECOND);
			KillTimer(TIME_DEVICE_ZP_THIRD);
			KillTimer(TIME_DEVICE_ZP_FORTH);
			break;
		}
		if (!TGW_Protect.IsBKOffSuccess(TGW_Protect.ZP.GetProtectAcionState()) && TGW_Protect.ZP.GetProtectAcionState() == ProtectAction_ABC)
		{
			KillTimer(TIME_DEVICE_ZP_SECOND);
			KillTimer(TIME_DEVICE_ZP_THIRD);
			break;
		}
		if (TGW_Protect.IsBKOffSuccess(TGW_Protect.ZP.GetProtectAcionState()) && TGW_Protect.ZP.GetProtectAcionState() != ProtectAction_ABC)
		{
			AppendText(IDC_EDIT_TEXT, _T("补跳单相成功\r\n"));
			KillTimer(TIME_DEVICE_ZP_SECOND);
			KillTimer(TIME_DEVICE_ZP_THIRD);
			KillTimer(TIME_DEVICE_ZP_FORTH);
			break;
		}
		else
		{
			switch (TGW_Protect.ZP.GetProtectAcionState())
			{
			case ProtectAction_A:
				AppendText(IDC_EDIT_TEXT, _T("A相补跳失败,永跳闭锁重合闸\r\n"));
				TGW_Protect.BK.OffBKABC();
				UpdateBKState(TGW_Protect);
				TGW_Protect.ZP.SetProtectActionState(ProtectAction_ABC);
				KillTimer(TIME_DEVICE_ZP_SECOND);
				break;
			case ProtectAction_B:
				AppendText(IDC_EDIT_TEXT, _T("B相补跳失败,永跳闭锁重合闸\r\n"));
				TGW_Protect.BK.OffBKABC();
				UpdateBKState(TGW_Protect);
				TGW_Protect.ZP.SetProtectActionState(ProtectAction_ABC);
				KillTimer(TIME_DEVICE_ZP_SECOND);
				break;
			case ProtectAction_C:
				AppendText(IDC_EDIT_TEXT, _T("C相补跳失败,永跳闭锁重合闸\r\n"));
				TGW_Protect.BK.OffBKABC();
				UpdateBKState(TGW_Protect);
				TGW_Protect.ZP.SetProtectActionState(ProtectAction_ABC);
				KillTimer(TIME_DEVICE_ZP_SECOND);
				break;
			}
		}
		break;
	case TIME_DEVICE_ZP_THIRD:
		if (TGW_Protect.IsBKOffSuccess(TGW_Protect.ZP.GetProtectAcionState()))
		{
			AppendText(IDC_EDIT_TEXT, _T("永跳成功\r\n"));
			KillTimer(TIME_DEVICE_ZP_THIRD);
			KillTimer(TIME_DEVICE_ZP_FORTH);
		}
		else
		{
			KillTimer(TIME_DEVICE_ZP_THIRD);
		}
		break;
	case TIME_DEVICE_ZP_FORTH:
		AppendText(IDC_EDIT_TEXT, _T("永跳失败\r\n"));
		KillTimer(TIME_DEVICE_ZP_FORTH);
		break;
	case TIME_DEVICE_ZP_ALG_2:
	{
		auto U_I = Caculate_UZ_IZ(TGW_Protect.ZP.GetU_m(), TGW_Protect.ZP.GetI_m());
		EndTime = clock();
		if (TGW_Protect.ZP.ZPCoreAlgorithmQuad_Ⅱ())
		{
			TGW_Protect.ZP.SetActionTime((double)(EndTime - StartTime) / (CLOCKS_PER_SEC) * 1000);
			TGW_Protect.ZP.SetProtectActionState(FaultToProtection[U_I.second]);
			TGW_Protect.ZP.SetWhich_Protection(LinXuDianLiu_ⅡAction);
			ProtectReport(TGW_Protect.ZP.GetProtectAcionState(), IDC_EDIT_TEXT, TGW_Protect);
			UpdateBKState(TGW_Protect);
			AppendText(IDC_EDIT_TEXT, _T("动作时间："));
			CString strT;
			strT.Format(_T("%.1lf"), TGW_Protect.ZP.GetActionTime());
			AppendText(IDC_EDIT_TEXT, strT);
			AppendText(IDC_EDIT_TEXT, _T("ms\r\n"));
			ProtectActionReport_ZP(TGW_Protect.ZP.GetWhich_Protection(), TGW_Protect.ZP.GetUZ(), TGW_Protect.ZP.GetIZ());
			SetTimer(TIME_DEVICE_ZP_FIRST, 150, NULL);
			SetTimer(TIME_DEVICE_ZP_SECOND, 300, NULL);
			SetTimer(TIME_DEVICE_ZP_THIRD, 450, NULL);
			SetTimer(TIME_DEVICE_ZP_FORTH, 5000, NULL);
			KillTimer(TIME_DEVICE_ZP_ALG_2);
			KillTimer(TIME_DEVICE_ZP_ALG_3);
		}
		KillTimer(TIME_DEVICE_ZP_ALG_2);
		break;
	}
	case TIME_DEVICE_ZP_ALG_3:
	{
		auto i = Caculate_UZ_IZ(TGW_Protect.ZP.GetU_m(), TGW_Protect.ZP.GetI_m());
		EndTime = clock();
		if (TGW_Protect.ZP.ZPCoreAlgorithmQuad_Ⅲ())
		{
			TGW_Protect.ZP.SetActionTime((double)(EndTime - StartTime) / (CLOCKS_PER_SEC) * 1000);
			TGW_Protect.ZP.SetProtectActionState(FaultToProtection[i.second]);
			TGW_Protect.ZP.SetWhich_Protection(LinXuDianLiu_ⅢAction);
			ProtectReport(TGW_Protect.ZP.GetProtectAcionState(), IDC_EDIT_TEXT, TGW_Protect);
			UpdateBKState(TGW_Protect);
			AppendText(IDC_EDIT_TEXT, _T("动作时间："));
			CString strT;
			strT.Format(_T("%.1lf"), TGW_Protect.ZP.GetActionTime());
			AppendText(IDC_EDIT_TEXT, strT);
			AppendText(IDC_EDIT_TEXT, _T("ms\r\n"));
			ProtectActionReport_ZP(TGW_Protect.ZP.GetWhich_Protection(), TGW_Protect.ZP.GetUZ(), TGW_Protect.ZP.GetIZ());
			SetTimer(TIME_DEVICE_ZP_FIRST, 150, NULL);
			SetTimer(TIME_DEVICE_ZP_SECOND, 300, NULL);
			SetTimer(TIME_DEVICE_ZP_THIRD, 450, NULL);
			SetTimer(TIME_DEVICE_ZP_FORTH, 5000, NULL);
			KillTimer(TIME_DEVICE_ZP_ALG_2);
			KillTimer(TIME_DEVICE_ZP_ALG_3);
		}
		else
		{
			TGW_Protect.ZP.SetActionTime(0);
			TGW_Protect.ZP.SetProtectActionState(ProtectNoAction);
			TGW_Protect.ZP.SetWhich_Protection(ProtectNoAction);
			KillTimer(TIME_DEVICE_ZP_ALG_2);
			KillTimer(TIME_DEVICE_ZP_ALG_3);
		}
		break;
	}
	case TIME_DEVICE_DP_ALG_1:
	{
		auto Z_m = CaculateZ_m(TGW_Protect.DP.GetU_m(), TGW_Protect.DP.GetI_m());
		EndTime = clock();
		if (TGW_Protect.DP.DPCoreAlgorithmQuad_Ⅰ(Z_m.second))
		{
			TGW_Protect.DP.SetActionTime((double)(EndTime - StartTime) / (CLOCKS_PER_SEC) * 1000);
			TGW_Protect.DP.SetProtectActionState(FaultToProtection[Z_m.second]);
			ProtectReport(TGW_Protect.DP.GetProtectAcionState(), IDC_EDIT_TEXT, TGW_Protect);
			UpdateBKState(TGW_Protect);
			AppendText(IDC_EDIT_TEXT, _T("动作时间："));
			CString strT;
			strT.Format(_T("%.1lf"), TGW_Protect.DP.GetActionTime());
			AppendText(IDC_EDIT_TEXT, strT);
			AppendText(IDC_EDIT_TEXT, _T("ms\r\n"));
			ProtectActionReport_DP(TGW_Protect.DP.GetWhich_Protection(), TGW_Protect.DP.GetZ_m().first.ReturnR(), TGW_Protect.DP.GetZ_m().first.ReturnX());
			SetTimer(TIME_DEVICE_DP_FIRST, 150, NULL);
			SetTimer(TIME_DEVICE_DP_SECOND, 300, NULL);
			SetTimer(TIME_DEVICE_DP_THIRD, 450, NULL);
			SetTimer(TIME_DEVICE_DP_FORTH, 5000, NULL);
			KillTimer(TIME_DEVICE_DP_ALG_2);
			KillTimer(TIME_DEVICE_DP_ALG_3);
		}
		KillTimer(TIME_DEVICE_DP_ALG_1);
		break;
	}
	case TIME_DEVICE_DP_ALG_2:
	{
		auto Z_m = CaculateZ_m(TGW_Protect.DP.GetU_m(), TGW_Protect.DP.GetI_m());
		EndTime = clock();
		if (TGW_Protect.DP.DPCoreAlgorithmQuad_Ⅱ(Z_m.second))
		{
			TGW_Protect.DP.SetActionTime((double)(EndTime - StartTime) / (CLOCKS_PER_SEC) * 1000);
			TGW_Protect.DP.SetProtectActionState(FaultToProtection[Z_m.second]);
			ProtectReport(TGW_Protect.DP.GetProtectAcionState(), IDC_EDIT_TEXT, TGW_Protect);
			UpdateBKState(TGW_Protect);
			AppendText(IDC_EDIT_TEXT, _T("动作时间："));
			CString strT;
			strT.Format(_T("%.1lf"), TGW_Protect.DP.GetActionTime());
			AppendText(IDC_EDIT_TEXT, strT);
			AppendText(IDC_EDIT_TEXT, _T("ms\r\n"));
			ProtectActionReport_DP(TGW_Protect.DP.GetWhich_Protection(), TGW_Protect.DP.GetZ_m().first.ReturnR(), TGW_Protect.DP.GetZ_m().first.ReturnX());
			SetTimer(TIME_DEVICE_DP_FIRST, 150, NULL);
			SetTimer(TIME_DEVICE_DP_SECOND, 300, NULL);
			SetTimer(TIME_DEVICE_DP_THIRD, 450, NULL);
			SetTimer(TIME_DEVICE_DP_FORTH, 5000, NULL);
			KillTimer(TIME_DEVICE_DP_ALG_3);
		}
		KillTimer(TIME_DEVICE_DP_ALG_2);
		break;
	}
	case TIME_DEVICE_DP_ALG_3:
	{
		auto Z_m = CaculateZ_m(TGW_Protect.DP.GetU_m(), TGW_Protect.DP.GetI_m());
		EndTime = clock();
		if (TGW_Protect.DP.DPCoreAlgorithmQuad_Ⅲ(Z_m.second))
		{
			TGW_Protect.DP.SetActionTime((double)(EndTime - StartTime) / (CLOCKS_PER_SEC) * 1000);
			TGW_Protect.DP.SetProtectActionState(FaultToProtection[Z_m.second]);
			ProtectReport(TGW_Protect.DP.GetProtectAcionState(), IDC_EDIT_TEXT, TGW_Protect);
			UpdateBKState(TGW_Protect);
			AppendText(IDC_EDIT_TEXT, _T("动作时间："));
			CString strT;
			strT.Format(_T("%.1lf"), TGW_Protect.DP.GetActionTime());
			AppendText(IDC_EDIT_TEXT, strT);
			AppendText(IDC_EDIT_TEXT, _T("ms\r\n"));
			ProtectActionReport_DP(TGW_Protect.DP.GetWhich_Protection(), TGW_Protect.DP.GetZ_m().first.ReturnR(), TGW_Protect.DP.GetZ_m().first.ReturnX());
			SetTimer(TIME_DEVICE_DP_FIRST, 150, NULL);
			SetTimer(TIME_DEVICE_DP_SECOND, 300, NULL);
			SetTimer(TIME_DEVICE_DP_THIRD, 450, NULL);
			SetTimer(TIME_DEVICE_DP_FORTH, 5000, NULL);
			KillTimer(TIME_DEVICE_DP_ALG_3);
		}
		else
		{
			TGW_Protect.ZP.SetActionTime(0);
			TGW_Protect.ZP.SetProtectActionState(ProtectNoAction);
			TGW_Protect.ZP.SetWhich_Protection(ProtectNoAction);
			KillTimer(TIME_DEVICE_DP_ALG_1);
			KillTimer(TIME_DEVICE_DP_ALG_2);
			KillTimer(TIME_DEVICE_DP_ALG_3);
		}
		break;
	}
	}
}

void CProtectSimulationDlg::OnClickedButton3()
{
	KillTimer(TIME_DEVICE_COUNT);
	if (CPage1.GetDlgItem(IDC_EDIT_TIME) != 0)
	{
		CString str;
		str.Format(_T("%02.0f:%03.0f"), floor(m_Time[0]), (m_Time[0] - floor(m_Time[0])) * 1000);
		m_systime.SetWindowTextW(str);
		UpdateData(FALSE);
	}
	TGW_Protect.ClearUI();
	KillTimer(TIME_DEVICE_FIRST);
	if (m_ChooseProtect == 0)
	{
		KillTimer(TIME_DEVICE_CP_FIRST);
		KillTimer(TIME_DEVICE_CP_SECOND);
		KillTimer(TIME_DEVICE_CP_THIRD);
		KillTimer(TIME_DEVICE_CP_FORTH);
	}
	if (m_ChooseProtect == 2)
	{
		KillTimer(TIME_DEVICE_DP_FIRST);
		KillTimer(TIME_DEVICE_DP_SECOND);
		KillTimer(TIME_DEVICE_DP_THIRD);
		KillTimer(TIME_DEVICE_DP_FORTH);
		KillTimer(TIME_DEVICE_DP_ALG_1);
		KillTimer(TIME_DEVICE_DP_ALG_2);
		KillTimer(TIME_DEVICE_DP_ALG_3);
	}
	if (m_ChooseProtect == 3)
	{
		KillTimer(TIME_DEVICE_ZP_FIRST);
		KillTimer(TIME_DEVICE_ZP_SECOND);
		KillTimer(TIME_DEVICE_ZP_THIRD);
		KillTimer(TIME_DEVICE_ZP_FORTH);
		KillTimer(TIME_DEVICE_ZP_ALG_2);
		KillTimer(TIME_DEVICE_ZP_ALG_3);
	}
	GetDlgItem(IDC_BUTTON3)->EnableWindow(FALSE);
	// TODO: 在此添加控件通知处理程序代码
}

void CProtectSimulationDlg::DeviceCurrentDiffAction()
{
	TGW_Protect.CP.CurrentDiffProtectionLoop();
	AppendText(IDC_EDIT_TEXT, _T("本侧保护：\r\n"));
	ProtectReport(TGW_Protect.CP.GetProtectAcionState(), IDC_EDIT_TEXT, TGW_Protect);
	SetTimer(TIME_DEVICE_CP_FIRST, 150, NULL);
	SetTimer(TIME_DEVICE_CP_SECOND, 300, NULL);
	SetTimer(TIME_DEVICE_CP_THIRD, 450, NULL);
	SetTimer(TIME_DEVICE_CP_FORTH, 5000, NULL);
	UpdateBKState(TGW_Protect);
	CString str;
	if (TGW_Protect.CP.GetIsStart() == 1)
	{
		AppendText(IDC_EDIT_TEXT, _T("保护启动\r\n"));
	}
	if (TGW_Protect.CP.GetProtectAcionState() == ProtectNoAction)
	{
		KillTimer(TIME_DEVICE_COUNT);
		KillTimer(TIME_DEVICE_FIRST);
		KillTimer(TIME_DEVICE_CP_FIRST);
		KillTimer(TIME_DEVICE_CP_SECOND);
		KillTimer(TIME_DEVICE_CP_THIRD);
		KillTimer(TIME_DEVICE_CP_FORTH);
	}
	else
	{
		AppendText(IDC_EDIT_TEXT, _T("差动保护动作：差动电流="));
		str.Format(_T("%.3lf"), TGW_Protect.CP.GetI_Diff());
		AppendText(IDC_EDIT_TEXT, str);
		AppendText(IDC_EDIT_TEXT, _T("    制动电流="));
		str.Format(_T("%.3lf"), TGW_Protect.CP.GetI_B());
		AppendText(IDC_EDIT_TEXT, str);
		if (TGW_Protect.CP.GetActionTime() != 0)
		{
			AppendText(IDC_EDIT_TEXT, _T("\r\n动作时间："));
			CString strT;
			strT.Format(_T("%.1lf"), TGW_Protect.CP.GetActionTime());
			AppendText(IDC_EDIT_TEXT, strT);
			AppendText(IDC_EDIT_TEXT, _T("ms\r\n"));
		}
		AppendText(IDC_EDIT_TEXT, _T("\r\n"));
	}
	// TODO: 在此处添加实现代码.
}

void CProtectSimulationDlg::DeviceGetTime()
{
	m_Time[0]=CPage1.m_Time;
}

void CProtectSimulationDlg::DeviceDistanceAction()
{
	if (CurrentBrustStart(TGW_Protect.DP.GetI_m()))
		AppendText(IDC_EDIT_TEXT, _T("保护启动\r\n"));
	TGW_Protect.DP.DistanceProtection();
	if (TGW_Protect.DP.GetFault() == ProtectNoAction)
	{
		KillTimer(TIME_DEVICE_COUNT);
		KillTimer(TIME_DEVICE_FIRST);
		KillTimer(TIME_DEVICE_DP_ALG_1);
		KillTimer(TIME_DEVICE_DP_ALG_2);
		KillTimer(TIME_DEVICE_DP_ALG_3);
	}
	// TODO: 在此处添加实现代码.
}

void CProtectSimulationDlg::DeviceZeroSeqAction()
{
	if (CurrentBrustStart(TGW_Protect.ZP.GetI_m()))
		AppendText(IDC_EDIT_TEXT, _T("保护启动\r\n"));
	TGW_Protect.ZP.ZeroSeqProtection();
	if (TGW_Protect.ZP.GetFault() == ProtectNoAction)
	{
		KillTimer(TIME_DEVICE_COUNT);
		KillTimer(TIME_DEVICE_FIRST);
		KillTimer(TIME_DEVICE_ZP_ALG_2);
		KillTimer(TIME_DEVICE_ZP_ALG_3);
	}
	// TODO: 在此处添加实现代码.
}

void CProtectSimulationDlg::OnRButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	CMenu   menu;   //定义下面要用到的cmenu对象
	menu.LoadMenu(IDR_MENU2); //装载自定义的右键菜单 
	CMenu* pContextMenu = menu.GetSubMenu(0); //获取第一个弹出菜单，所以第一个菜单必须有子菜单 
	CPoint point1;//定义一个用于确定光标位置的位置  
	GetCursorPos(&point1);//获取当前光标的位置，以便使得菜单可以跟随光标  
	pContextMenu->TrackPopupMenu(TPM_LEFTALIGN | TPM_RIGHTBUTTON, point1.x, point1.y, AfxGetMainWnd()); //在指定位置显示弹出菜单
	CDialog::OnRButtonDown(nFlags, point1);
}

void CProtectSimulationDlg::On_AddState()
{
	switch (m_TAB.GetItemCount())
	{
	case 1:
	{
		m_TAB.InsertItem(1, _T("第二态"));
		CPage2.Create(IDD_DIALOG_TwoState, GetDlgItem(IDC_TAB_UI));
		CRect rs;
		GetDlgItem(IDC_TAB_UI)->GetClientRect(&rs);
		//设置属性页的大小和位置
		rs.top += 21;
		rs.bottom -= 0;
		rs.left += 0;
		rs.right -= 0;
		CPage2.MoveWindow(&rs);
		CPage2.ShowWindow(TRUE);
		CPage1.ShowWindow(FALSE);
		m_TAB.SetCurSel(1);
		break;
	}
	case 2:
	{
		m_TAB.InsertItem(2, _T("第三态"));
		CPage3.Create(IDD_DIALOG_ThreeState, GetDlgItem(IDC_TAB_UI));
		CRect rs;
		GetDlgItem(IDC_TAB_UI)->GetClientRect(&rs);
		//设置属性页的大小和位置
		rs.top += 21;
		rs.bottom -= 0;
		rs.left += 0;
		rs.right -= 0;
		CPage3.MoveWindow(&rs);
		CPage3.ShowWindow(TRUE);
		CPage1.ShowWindow(FALSE);
		CPage2.ShowWindow(FALSE);
		m_TAB.SetCurSel(2);
		break;
	}
	case 3:
	{
		m_TAB.InsertItem(3, _T("第四态"));
		CPage4.Create(IDD_DIALOG_FourState, GetDlgItem(IDC_TAB_UI));
		CRect rs;
		GetDlgItem(IDC_TAB_UI)->GetClientRect(&rs);
		//设置属性页的大小和位置
		rs.top += 21;
		rs.bottom -= 0;
		rs.left += 0;
		rs.right -= 0;
		CPage4.MoveWindow(&rs);
		CPage4.ShowWindow(TRUE);
		CPage1.ShowWindow(FALSE);
		CPage2.ShowWindow(FALSE);
		CPage3.ShowWindow(FALSE);
		m_TAB.SetCurSel(3);
		break;
	}
	}
	// TODO: 在此添加命令处理程序代码
}

void CProtectSimulationDlg::OnTcnSelchangeTabUi(NMHDR* pNMHDR, LRESULT* pResult)
{
	// TODO: 在此添加控件通知处理程序代码
	CRect tabRect;
	GetDlgItem(IDC_TAB_UI)->GetClientRect(&tabRect);
	//设置属性页的大小和位置
	tabRect.top += 21;
	tabRect.bottom -= 0;
	tabRect.left += 0;
	tabRect.right -= 0;
	switch (m_TAB.GetCurSel())
	{
	case 0:
		CPage1.ShowWindow(TRUE);
		if(CPage2.m_hWnd!=NULL)
			CPage2.ShowWindow(FALSE);
		if (CPage3.m_hWnd != NULL)
			CPage3.ShowWindow(FALSE);
		if (CPage4.m_hWnd != NULL)
			CPage4.ShowWindow(FALSE);
		break;
	case 1:
		CPage1.ShowWindow(FALSE);
		if (CPage2.m_hWnd != NULL)
			CPage2.ShowWindow(TRUE);
		if (CPage3.m_hWnd != NULL)
			CPage3.ShowWindow(FALSE);
		if (CPage4.m_hWnd != NULL)
			CPage4.ShowWindow(FALSE);
		break;
	case 2:
		CPage1.ShowWindow(FALSE);
		if (CPage2.m_hWnd != NULL)
			CPage2.ShowWindow(FALSE);
		if (CPage3.m_hWnd != NULL)
			CPage3.ShowWindow(TRUE);
		if (CPage4.m_hWnd != NULL)
			CPage4.ShowWindow(FALSE);
		break;
	case 3:
		CPage1.ShowWindow(FALSE);
		if (CPage2.m_hWnd != NULL)
			CPage2.ShowWindow(FALSE);
		if (CPage3.m_hWnd != NULL)
			CPage3.ShowWindow(FALSE);
		if (CPage4.m_hWnd != NULL)
			CPage4.ShowWindow(TRUE);
		break;
	}
	*pResult = 0;
}

void CProtectSimulationDlg::On_DeleteState()
{
	CRect tabRect;
	GetDlgItem(IDC_TAB_UI)->GetClientRect(&tabRect);
	//设置属性页的大小和位置
	tabRect.top += 21;
	tabRect.bottom -= 0;
	tabRect.left += 0;
	tabRect.right -= 0;
	int i = m_TAB.GetCurSel();
	if(i==0)
	{
		CDlgAttion dlg;
		dlg.DoModal();
	}
	else
	{
		int m = m_TAB.GetItemCount();
		m_TAB.SetCurSel(m - 2);
		m_TAB.DeleteItem(m-1);
		switch (m - 1)
		{
		case 1:
			CPage2.DestroyWindow();
			CPage1.ShowWindow(TRUE);
			break;
		case 2:
			CPage3.DestroyWindow();
			CPage2.ShowWindow(TRUE);
			break;
		case 3:
			CPage4.DestroyWindow();
			CPage3.ShowWindow(TRUE);
			break;
		}
		
	}
	// TODO: 在此添加命令处理程序代码
}
