#pragma once


// MFCDec 对话框

class MFCDec : public CDialogEx
{
	DECLARE_DYNAMIC(MFCDec)

public:
	MFCDec(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~MFCDec();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG7 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	int last;
	int fun;
	afx_msg void OnBnClickedOk();
	virtual BOOL OnInitDialog();
};
