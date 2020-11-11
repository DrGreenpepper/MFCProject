// MFCEdit.cpp: 实现文件
//

#include "pch.h"
#include "MFCProject.h"
#include "MFCEdit.h"
#include "afxdialogex.h"
#include "MFCfundcost.h"
#include "MFCAdd.h"
#include "MFCDec.h"
// MFCEdit 对话框

IMPLEMENT_DYNAMIC(MFCEdit, CDialogEx)

MFCEdit::MFCEdit(MFCDataBase* Database,CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG4, pParent)
{
	this->database = Database;
}

MFCEdit::~MFCEdit()
{
}

void MFCEdit::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST1, mc_listHistory);
}


BEGIN_MESSAGE_MAP(MFCEdit, CDialogEx)
	ON_NOTIFY(LVN_ITEMCHANGED, IDC_LIST1, &MFCEdit::OnLvnItemchangedList1)
	ON_NOTIFY(NM_DBLCLK, IDC_LIST1, &MFCEdit::OnDblclkList1)
	ON_BN_CLICKED(IDC_BUTTON1, &MFCEdit::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON3, &MFCEdit::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON4, &MFCEdit::OnBnClickedButton4)
	ON_BN_CLICKED(IDC_BUTTON2, &MFCEdit::OnBnClickedButton2)
END_MESSAGE_MAP()


// MFCEdit 消息处理程序


BOOL MFCEdit::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	CString tp;
	SetDlgItemText(IDC_EditName, database->idx[num-1].name);
	SetDlgItemText(IDC_EditBirth, database->idx[num-1].birth);
	tp.Format(_T("%lld年%lld月%lld日"), database->idx[num - 1].clock / 100000000 , database->idx[num - 1].clock / 1000000 % 100, database->idx[num-1].clock/10000 %100);
	SetDlgItemText(IDC_EditClock, tp);
	tp.Format(_T("%lld"), database->idx[num-1].tel);
	SetDlgItemText(IDC_EditTel, tp);
	tp.Format(_T("%.2lf"), database->idx[num-1].fund);
	SetDlgItemText(IDC_EditFund, tp);
	tp.Format(_T("%ld"), database->idx[num-1].times);
	SetDlgItemText(IDC_EditTimes, tp);
	CRect rect;
	mc_listHistory.GetClientRect(&rect);
	mc_listHistory.SetExtendedStyle(mc_listHistory.GetExtendedStyle() | LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES);
	mc_listHistory.InsertColumn(1, _T("时间"), LVCFMT_CENTER, rect.Width() / 3);
	mc_listHistory.InsertColumn(2, _T("操作"), LVCFMT_CENTER, rect.Width() / 5);
	mc_listHistory.InsertColumn(4, _T("数值"), LVCFMT_CENTER, int(double(rect.Width()) / 2.5));
	mc_listHistory.InsertColumn(5, _T("备注"), LVCFMT_CENTER, rect.Width() / 4);
	// TODO:  在此添加额外的初始化
	database->GetHistory(num);
	CString opt[5] = { _T("创建账号"),_T("余额变动"),_T("次数变动") };
	int len = database->history.size();
	for (int i = 0; i < len; i++) {
		tp.Format(_T("%lld"), database->history[i].clock);
		mc_listHistory.InsertItem(i, tp);
		mc_listHistory.SetItemText(i, 1, opt[database->history[i].opt]);
		tp = database->history[i].info.c_str();
		mc_listHistory.SetItemText(i, 2, tp);
		mc_listHistory.SetItemText(i, 3, _T("无"));
	}
	return TRUE;  // return TRUE unless you set the focus to a control
				  // 异常: OCX 属性页应返回 FALSE
}


void MFCEdit::OnLvnItemchangedList1(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMLISTVIEW pNMLV = reinterpret_cast<LPNMLISTVIEW>(pNMHDR);
	// TODO: 在此添加控件通知处理程序代码
	*pResult = 0;
}


void MFCEdit::OnDblclkList1(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMITEMACTIVATE pNMItemActivate = reinterpret_cast<LPNMITEMACTIVATE>(pNMHDR);
	// TODO: 在此添加控件通知处理程序代码
	*pResult = 0;
}


void MFCEdit::OnBnClickedButton1()
{
	MFCfundcost dlg;
	CString tp = 0;
	dlg.last = database->idx[num - 1].fund;
	int ret = dlg.DoModal();
	if (ret == 1) {
		database->idx[num - 1].fund -= dlg.fun;
		tp.Format(_T("-%.2lf"), dlg.fun);
		database->SaveHistory(num, 1, tp);
		database->UpdateIdx(num);

		tp.Format(_T("%.2lf"), database->idx[num - 1].fund);
		SetDlgItemText(IDC_EditFund, tp);
	}
	// TODO: 在此添加控件通知处理程序代码
}


void MFCEdit::OnBnClickedButton3()
{
	MFCAdd dlg;
	int ret = dlg.DoModal();
	CString tp;
	if (ret == 1) {
		database->idx[num - 1].fund += 1.0*dlg.num;
		tp.Format(_T("+%d"), dlg.num);
		database->SaveHistory(num, 1, tp);
		database->UpdateIdx(num);

		tp.Format(_T("%.2lf"), database->idx[num - 1].fund);
		SetDlgItemText(IDC_EditFund, tp);
	}
	// TODO: 在此添加控件通知处理程序代码
}


void MFCEdit::OnBnClickedButton4()
{
	// TODO: 在此添加控件通知处理程序代码
	MFCAdd dlg;
	int ret = dlg.DoModal();
	CString tp;
	if (ret == 1) {
		database->idx[num - 1].times += dlg.num;
		tp.Format(_T("+%d"), dlg.num);
		database->SaveHistory(this->num, 2, tp);
		database->UpdateIdx(this->num);

		tp.Format(_T("%ld"), database->idx[num - 1].times);
		SetDlgItemText(IDC_EditTimes, tp);
	}
}


void MFCEdit::OnBnClickedButton2()
{
	// TODO: 在此添加控件通知处理程序代码
	MFCDec dlg;
	dlg.last = database->idx[num-1].times;
	int ret = dlg.DoModal();
	CString tp;
	if (ret == 1) {
		database->idx[num - 1].times -= dlg.fun;
		tp.Format(_T("%d"), -dlg.fun);
		database->SaveHistory(num, 2, tp);
		database->UpdateIdx(num);

		tp.Format(_T("%ld"), database->idx[num - 1].times);
		SetDlgItemText(IDC_EditTimes, tp);
	}
}
