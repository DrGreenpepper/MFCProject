
// MFCProjectDlg.cpp: 实现文件
//

#include "pch.h"
#include "framework.h"
#include "MFCProject.h"
#include "MFCProjectDlg.h"
#include "afxdialogex.h"
#include "MFCLogin.h"
#include "MFCSearch.h"
#include "MFCCreat.h"
#include"MFCEdit.h"
#include<iostream>
#include<fstream>
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


// CMFCProjectDlg 对话框



CMFCProjectDlg::CMFCProjectDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_MFCPROJECT_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMFCProjectDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST1, m_list);
}

BEGIN_MESSAGE_MAP(CMFCProjectDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, &CMFCProjectDlg::OnBnClickedSearch)
	ON_BN_CLICKED(IDC_BUTTON2, &CMFCProjectDlg::OnBnClickedButton2)
	ON_NOTIFY(LVN_ITEMCHANGED, IDC_LIST1, &CMFCProjectDlg::OnLvnItemchangedList1)
	ON_NOTIFY(NM_DBLCLK, IDC_LIST1, &CMFCProjectDlg::OnDblclkList1)
	ON_BN_CLICKED(IDC_BUTTON3, &CMFCProjectDlg::OnBnClickedButton3)
END_MESSAGE_MAP()


// CMFCProjectDlg 消息处理程序

BOOL CMFCProjectDlg::OnInitDialog()
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
	std::ifstream finn;
	finn.open("option.opt");
	int check = 0;
	while (finn >> check);
	finn.close();
	if (check == 0) {
		std::ofstream foutt;
		foutt.open("option.opt");
		foutt << "111"<<std::endl;
		system("mkdir .\\data");
	}
	MFCLogin login;
	int ret = 0; 
	std::string usrname, password;
	usrname = "admin"; password = "admin";
	login.SetInfo(usrname, password);
	while (true) {
		ret = login.DoModal();
		if(ret==-1)exit(0);
		if (ret == 1)break;
	}
	login.~MFCLogin();
	Database.init();
	CString tpal;
	tpal.Format(_T("%lld月\t%lld日"), (Database.GetTime() / 1000000) % 100, ((Database.GetTime() / 10000) % 100));
	SetDlgItemText(IDC_DATE, tpal);
	tpal.Format(_T("%d"), int(Database.idx.size()));
	SetDlgItemText(IDC_VIPNUM, tpal);

	CRect rect;
	m_list.GetClientRect(&rect);
	m_list.SetExtendedStyle(m_list.GetExtendedStyle() | LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES);
	m_list.InsertColumn(0, _T("编号"), LVCFMT_CENTER, rect.Width() / 14);
	m_list.InsertColumn(1, _T("姓名"), LVCFMT_CENTER, rect.Width() / 8);
	m_list.InsertColumn(2, _T("手机号"), LVCFMT_CENTER, rect.Width() /3);
	m_list.InsertColumn(3, _T("生日"), LVCFMT_CENTER, rect.Width() / 8);
	m_list.InsertColumn(4, _T("注册日期"), LVCFMT_CENTER, rect.Width() / 3);
	m_list.InsertColumn(5, _T("备注"), LVCFMT_CENTER, rect.Width() / 3);

	// 更新数据
	finn.open("idx.swp");
	std::ofstream foutt;
	
	dataIdx tp;
	int flag = 0;
	std::string tpname, tpbirth;
	while (finn >> tp.num >> tpname >> tp.tel >> tpbirth >> tp.fund >> tp.times >> tp.clock) {
		flag = 1;
		tp.name = tpname.c_str(); tp.birth = tpbirth.c_str();
		Database.idx[tp.num - 1] = tp;
	}
	if (flag) {
		foutt.open("idx.idx");
		for (unsigned i = 0; i < Database.idx.size(); i++) {
			tpname = CT2A(Database.idx[i].name);
			tpbirth = CT2A(Database.idx[i].birth);
			foutt << Database.idx[i].num << " " << tpname << " " << Database.idx[i].tel << " " << tpbirth << " " << Database.idx[i].fund << " " << Database.idx[i].times << " " << Database.idx[i].clock << std::endl;
		}
		foutt.close();
	}
	
	foutt.open("idx.swp");
	foutt.close();
	Database.fout.open("idx.swp");
	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CMFCProjectDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CMFCProjectDlg::OnPaint()
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
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CMFCProjectDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CMFCProjectDlg::OnBnClickedSearch()
{
	MFCSearch sc;
	
	int ret=sc.DoModal();
	if (ret == 1) {
		if (sc.statu == 0) {
			_int64 tel = _ttoi64(sc.info);
			//MessageBox(sc.info);
			Database.SearchTel(tel);
		}
		if (sc.statu == 1||sc.statu==2) {
			Database.SearchStr(sc.statu,sc.info);
		}
	}
	m_list.DeleteAllItems();
	CString tp;
	for (unsigned j = 0; j < Database.List.size(); j++) {
		int i = Database.List[j]-1;
		tp.Format(_T("%d"), Database.idx[i].num);
		m_list.InsertItem(j, tp);
		m_list.SetItemText(j,1, Database.idx[i].name);
		tp.Format(_T("%lld"), Database.idx[i].tel);
		m_list.SetItemText(j, 2, tp);
		m_list.SetItemText(j, 3, Database.idx[i].birth);
		tp.Format(_T("%lld"), Database.idx[i].clock);
		m_list.SetItemText(j, 4, tp);
	}

	// TODO: 在此添加控件通知处理程序代码
}

//CreatButton
void CMFCProjectDlg::OnBnClickedButton2()
{
	MFCCreat creat;
	int ret = creat.DoModal();
	if (ret == 1) {
		creat.newdata.num = Database.idx.size()+1;//分配num
		creat.newdata.clock = Database.GetTime();
		Database.idx.push_back(creat.newdata);//加入idx
		std::string name, birth;
		name = CT2A(creat.newdata.name);
		birth = CT2A(creat.newdata.birth);
		Database.idxout << creat.newdata.num << " " << name << " " << creat.newdata.tel << " " << birth << " "
			<< creat.newdata.fund << " " << creat.newdata.times<<" "  <<Database.GetTime()<< std::endl;//输出到idx文件里
		CString tp; 
	//	tp.Format(_T("%lld"), Database.GetTime());
	//	MessageBox(tp);
		tp.Format(_T("Fund:%.2lf-Times:%d"), creat.newdata.fund, creat.newdata.times);
		Database.SaveHistory(creat.newdata.num, 0, tp);//输出到对应的history文件里
		tp.Format(_T("%d"), creat.newdata.num);
		MessageBox(_T("创建成功"));
		tp.Format(_T("%d"), int(Database.idx.size()));
		SetDlgItemText(IDC_VIPNUM, tp);
	}
	// TODO: 在此添加控件通知处理程序代码
}


void CMFCProjectDlg::OnLvnItemchangedList1(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMLISTVIEW pNMLV = reinterpret_cast<LPNMLISTVIEW>(pNMHDR);
	// TODO: 在此添加控件通知处理程序代码
	*pResult = 0;
}


void CMFCProjectDlg::OnDblclkList1(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMITEMACTIVATE pNMItemActivate = reinterpret_cast<LPNMITEMACTIVATE>(pNMHDR);
	// TODO: 在此添加控件通知处理程序代码
	MFCEdit edit(&Database);
	edit.num = pNMItemActivate->iItem;
	if (edit.num > Database.List.size())return;
	edit.num = Database.List[edit.num];
	int res=edit.DoModal();

	*pResult = 0;
}


void CMFCProjectDlg::OnBnClickedButton3()
{
	MFCLogin login;
	std::string usrname, password;
	usrname = "admin"; password = "admin";
	login.SetInfo(usrname, password);
	int ret;
	while (true) {
		ret = login.DoModal();
		if (ret == -1)exit(0);
		if (ret == 1)break;
	}
	// TODO: 在此添加控件通知处理程序代码
}
