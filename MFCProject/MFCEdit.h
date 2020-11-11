#pragma once


// MFCEdit 对话框
#include "MFCDataBase.h"
class MFCEdit : public CDialogEx
{
	DECLARE_DYNAMIC(MFCEdit)

public:
	MFCEdit(MFCDataBase* database,CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~MFCEdit();
	int num;
	MFCDataBase* database;
// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG4 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CListCtrl mc_listHistory;
	virtual BOOL OnInitDialog();
	afx_msg void OnLvnItemchangedList1(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnDblclkList1(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton3();
	afx_msg void OnBnClickedButton4();
	afx_msg void OnBnClickedButton2();
};
