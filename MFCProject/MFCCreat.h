#pragma once


// MFCCreat 对话框
#include "MFCDataBase.h"
class MFCCreat : public CDialogEx
{
	DECLARE_DYNAMIC(MFCCreat)

public:
	MFCCreat(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~MFCCreat();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG3 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();
	dataIdx newdata;
	virtual BOOL OnInitDialog();
};
