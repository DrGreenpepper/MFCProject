#pragma once

#include<string>
// MFCLogin 对话框

class MFCLogin : public CDialogEx
{
	DECLARE_DYNAMIC(MFCLogin)

public:
	MFCLogin(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~MFCLogin();
	void SetInfo(std::string, std::string);
// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG1 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持
	void setInfo(std::string, std::string);
	DECLARE_MESSAGE_MAP()
public:
	std::string usrName,password;
	afx_msg void OnBnClickedOk();
	afx_msg void OnBnClickedCancel();
};
