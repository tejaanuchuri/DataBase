#pragma once


// CUserDlg dialog

class CUserDlg : public CDialog
{
	DECLARE_DYNAMIC(CUserDlg)

public:
	CUserDlg(CWnd* pParent = nullptr);   // standard constructor
	virtual ~CUserDlg();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton1();
};
