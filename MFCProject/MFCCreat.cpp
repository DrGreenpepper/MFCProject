// MFCCreat.cpp: 实现文件
//

#include "pch.h"
#include "MFCProject.h"
#include "MFCCreat.h"
#include "afxdialogex.h"


// MFCCreat 对话框

IMPLEMENT_DYNAMIC(MFCCreat, CDialogEx)

MFCCreat::MFCCreat(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG3, pParent)
{

}

MFCCreat::~MFCCreat()
{
}

void MFCCreat::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(MFCCreat, CDialogEx)
	ON_BN_CLICKED(IDOK, &MFCCreat::OnBnClickedOk)
END_MESSAGE_MAP()


// MFCCreat 消息处理程序


void MFCCreat::OnBnClickedOk()
{
	// TODO: 在此添加控件通知处理程序代码
	CString a, b, c, d, e, f;
	GetDlgItemText(IDC_CreatName, a);
	GetDlgItemText(IDC_CreatTel, b);
	GetDlgItemText(IDC_CreatFund, c);
	GetDlgItemText(IDC_CreatTimes, d);
	GetDlgItemText(IDC_CreatBirthD, e);
	GetDlgItemText(IDC_CreatBirthM, f);
	_int64 tel = 0; double fund = 0; int times = 0, Mouth = 0, Day = 0;
	tel = _ttoi64(b); fund = _ttof(c); times = _ttoi(d); Day = _ttoi(e); Mouth = _ttoi(f);
	//MessageBox(_("1"));
	if (tel<long long(10000000000) || tel>long long(20000000000)) {
		MessageBox(_T("电话号码格式错误"));
	}
	else if (fund < 0 || times < 0) {
		MessageBox(_T("初始资金或次数应大于零"));
	}
	else if (Mouth > 12 || Mouth < 1 || Day>31 || Day < 1) {
		MessageBox(_T("生日有误"));
	}
	else if (a.GetLength()==0) {
		MessageBox(_T("姓名不能为空"));
	}
	else{
		newdata.name = a; newdata.fund = fund; newdata.times = times; newdata.tel = tel;
		std::string str;
		str += '0' + (Mouth / 10);
		str += '0' + (Mouth % 10);
		str += '0' + (Day / 10);
		str += '0' + (Day % 10);
		newdata.birth = str.c_str();
		EndDialog(1);
	}
	SetDlgItemText(IDC_CreatName, a);
	SetDlgItemText(IDC_CreatTel, b);
	SetDlgItemText(IDC_CreatFund, c);
	SetDlgItemText(IDC_CreatTimes, d);
	SetDlgItemText(IDC_CreatBirthD, e);
	SetDlgItemText(IDC_CreatBirthM, f);
}


BOOL MFCCreat::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	SetDlgItemText(IDC_CreatFund, _T("0"));
	SetDlgItemText(IDC_CreatTimes, _T("0"));
	// TODO:  在此添加额外的初始化

	return TRUE;  // return TRUE unless you set the focus to a control
				  // 异常: OCX 属性页应返回 FALSE
}
