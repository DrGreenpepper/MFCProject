#pragma once


// MFCAdd 对话框

class MFCAdd : public CDialogEx
{
	DECLARE_DYNAMIC(MFCAdd)

public:
	MFCAdd(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~MFCAdd();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG6 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();
	int num;
	afx_msg void OnBnClickedCancel();
	virtual BOOL OnInitDialog();
};
