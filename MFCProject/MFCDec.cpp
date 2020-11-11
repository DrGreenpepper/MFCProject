// MFCDec.cpp: 实现文件
//

#include "pch.h"
#include "MFCProject.h"
#include "MFCDec.h"
#include "afxdialogex.h"


// MFCDec 对话框

IMPLEMENT_DYNAMIC(MFCDec, CDialogEx)

MFCDec::MFCDec(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG7, pParent)
{

}

MFCDec::~MFCDec()
{
}

void MFCDec::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(MFCDec, CDialogEx)
	ON_BN_CLICKED(IDOK, &MFCDec::OnBnClickedOk)
END_MESSAGE_MAP()


// MFCDec 消息处理程序


void MFCDec::OnBnClickedOk()
{
	// TODO: 在此添加控件通知处理程序代码
	CString timescost;
	GetDlgItemText(IDC_TimesCost, timescost);
	fun = _ttoi(timescost);
	if (fun > last) {
		MessageBox(_T("余额不足"));
	}
	else {
		EndDialog(1);
	}
	SetDlgItemText(IDC_TimesCost, timescost);
}


BOOL MFCDec::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	SetDlgItemText(IDC_TimesCost, _T("0"));
	// TODO:  在此添加额外的初始化

	return TRUE;  // return TRUE unless you set the focus to a control
				  // 异常: OCX 属性页应返回 FALSE
}
