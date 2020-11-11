#pragma once


// MFCfundcost 对话框

class MFCfundcost : public CDialogEx
{
	DECLARE_DYNAMIC(MFCfundcost)

public:
	MFCfundcost(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~MFCfundcost();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG5 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	double last;
	double fun;
	afx_msg void OnBnClickedOk();
	afx_msg void OnBnClickedCancel();
	virtual BOOL OnInitDialog();
};
