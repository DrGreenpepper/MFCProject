// MFCLogin.cpp: 实现文件
//

#include "pch.h"
#include "MFCProject.h"
#include "MFCLogin.h"
#include "afxdialogex.h"
#include <string>
// MFCLogin 对话框

IMPLEMENT_DYNAMIC(MFCLogin, CDialogEx)

MFCLogin::MFCLogin(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG1, pParent)
{

}

MFCLogin::~MFCLogin()
{
}

void MFCLogin::SetInfo(std::string a, std::string b)
{
	this->setInfo(a, b);
}

void MFCLogin::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

void MFCLogin::setInfo(std::string name, std::string password)
{
	this->usrName = name;
	this->password = password;
}


BEGIN_MESSAGE_MAP(MFCLogin, CDialogEx)
	ON_BN_CLICKED(IDOK, &MFCLogin::OnBnClickedOk)
	ON_BN_CLICKED(IDCANCEL, &MFCLogin::OnBnClickedCancel)
END_MESSAGE_MAP()


// MFCLogin 消息处理程序


void MFCLogin::OnBnClickedOk()
{
	// TODO: 在此添加控件通知处理程序代码
	CDialogEx::OnOK();
	CString CSusrname, CSpassword;
	GetDlgItemText(IDC_userName, CSusrname);
	GetDlgItemText(IDC_Password, CSpassword);
	if (CSusrname == this->usrName.c_str()&&CSpassword==this->usrName.c_str()) {
		EndDialog(1);
	}
	else {
		MessageBox(_T("密码错误"));
		EndDialog(0);
	}
}


void MFCLogin::OnBnClickedCancel()
{
	// TODO: 在此添加控件通知处理程序代码
	CDialogEx::OnCancel();
	EndDialog(-1);
}
