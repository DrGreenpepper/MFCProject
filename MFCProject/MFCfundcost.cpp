// MFCfundcost.cpp: 实现文件
//

#include "pch.h"
#include "MFCProject.h"
#include "MFCfundcost.h"
#include "afxdialogex.h"


// MFCfundcost 对话框

IMPLEMENT_DYNAMIC(MFCfundcost, CDialogEx)

MFCfundcost::MFCfundcost(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG5, pParent)
{

}

MFCfundcost::~MFCfundcost()
{
}

void MFCfundcost::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(MFCfundcost, CDialogEx)
	ON_BN_CLICKED(IDOK, &MFCfundcost::OnBnClickedOk)
	ON_BN_CLICKED(IDCANCEL, &MFCfundcost::OnBnClickedCancel)
END_MESSAGE_MAP()


// MFCfundcost 消息处理程序


void MFCfundcost::OnBnClickedOk()
{
	// TODO: 在此添加控件通知处理程序代码
	CString fundcost, decrease;
	GetDlgItemText(IDC_FundCost, fundcost);
	GetDlgItemText(IDC_Decrease, decrease);
	fun = _ttof(fundcost);
	double dec = _ttof(decrease);
	fun *= dec / 10.0;
	fun = double(int(fun * 100)) / 100.0;
	if (fun > last) {
		MessageBox(_T("余额不足"));
	}
	else {
		EndDialog(1);
	}
	SetDlgItemText(IDC_FundCost, fundcost);
	SetDlgItemText(IDC_Decrease, decrease);
}


void MFCfundcost::OnBnClickedCancel()
{
	// TODO: 在此添加控件通知处理程序代码
	EndDialog(0);
	CDialogEx::OnCancel();
}


BOOL MFCfundcost::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	SetDlgItemText(IDC_Decrease, _T("10"));
	SetDlgItemText(IDC_FundCost, _T("0"));
	// TODO:  在此添加额外的初始化

	return TRUE;  // return TRUE unless you set the focus to a control
				  // 异常: OCX 属性页应返回 FALSE
}
