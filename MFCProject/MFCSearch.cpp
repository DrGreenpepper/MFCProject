// MFCSearch.cpp: 实现文件
//

#include "pch.h"
#include "MFCProject.h"
#include "MFCSearch.h"
#include "afxdialogex.h"


// MFCSearch 对话框

IMPLEMENT_DYNAMIC(MFCSearch, CDialogEx)

MFCSearch::MFCSearch(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG2, pParent)
{
}

MFCSearch::~MFCSearch()
{
}

void MFCSearch::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_COMBO1, opt);
}


BEGIN_MESSAGE_MAP(MFCSearch, CDialogEx)
	ON_BN_CLICKED(IDOK, &MFCSearch::OnBnClickedOk)
	ON_BN_CLICKED(IDCANCEL, &MFCSearch::OnBnClickedCancel)
END_MESSAGE_MAP()


// MFCSearch 消息处理程序

BOOL MFCSearch::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化
	opt.AddString(_T("电话"));
	opt.AddString(_T("姓名"));
	opt.AddString(_T("生日"));
	opt.SetCurSel(0);
	return TRUE;  // return TRUE unless you set the focus to a control
				  // 异常: OCX 属性页应返回 FALSE
}


void MFCSearch::OnBnClickedOk()
{
	// TODO: 在此添加控件通知处理程序代码
	CString str;
	//CString str2;
	GetDlgItemText(IDC_Search, str);
	//MessageBox(str);
	if (str.GetLength() > 0) {
		statu = opt.GetCurSel();
		//str2.Format(_T("%d"), statu);
		//MessageBox(str2);
		info = str;
		EndDialog(1);
	}
	else {
		MessageBox(_T("请输入搜索内容"));
	}
}


void MFCSearch::OnBnClickedCancel()
{
	// TODO: 在此添加控件通知处理程序代码
	EndDialog(0);
	CDialogEx::OnCancel();
}
