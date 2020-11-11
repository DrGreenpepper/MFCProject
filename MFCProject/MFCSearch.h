#pragma once


// MFCSearch 对话框

class MFCSearch : public CDialogEx
{
	DECLARE_DYNAMIC(MFCSearch)

public:
	MFCSearch(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~MFCSearch();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG2 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CComboBox opt;
	CString info;
	int statu;
	virtual BOOL OnInitDialog();
	afx_msg void OnBnClickedOk();
	afx_msg void OnBnClickedCancel();
};
