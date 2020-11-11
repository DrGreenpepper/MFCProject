// MFCAdd.cpp: 实现文件
//

#include "pch.h"
#include "MFCProject.h"
#include "MFCAdd.h"
#include "afxdialogex.h"


// MFCAdd 对话框

IMPLEMENT_DYNAMIC(MFCAdd, CDialogEx)

MFCAdd::MFCAdd(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG6, pParent)
{

}

MFCAdd::~MFCAdd()
{
}

void MFCAdd::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(MFCAdd, CDialogEx)
	ON_BN_CLICKED(IDOK, &MFCAdd::OnBnClickedOk)
	ON_BN_CLICKED(IDCANCEL, &MFCAdd::OnBnClickedCancel)
END_MESSAGE_MAP()


// MFCAdd 消息处理程序


void MFCAdd::OnBnClickedOk()
{
	// TODO: 在此添加控件通知处理程序代码
	CString str;
	int num;
	GetDlgItemText(IDC_AddNum, str);
	num = _ttoi(str);
	if (num < 0) {
		MessageBox(_T("数值不能小于0"));
	}
	else {
		this->num = num;
		EndDialog(1);
	}
}


void MFCAdd::OnBnClickedCancel()
{
	// TODO: 在此添加控件通知处理程序代码
	EndDialog(0);
	CDialogEx::OnCancel();
}


BOOL MFCAdd::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化
	SetDlgItemText(IDC_AddNum,_T("0"));
	return TRUE;  // return TRUE unless you set the focus to a control
				  // 异常: OCX 属性页应返回 FALSE
}
