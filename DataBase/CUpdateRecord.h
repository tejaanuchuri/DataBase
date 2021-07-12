#pragma once


// CUpdateRecord dialog

class CUpdateRecord : public CDialog
{
	DECLARE_DYNAMIC(CUpdateRecord)

public:
	CUpdateRecord(CWnd* pParent = nullptr);   // standard constructor
	virtual ~CUpdateRecord();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_UPDATE_RECORD };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	CString e_empid;
	CString d_name;
	CString d_age;
	CEdit u_name;
	CString u_age;
	CString U_name;
	afx_msg void OnBnClickedButtonCheck();
	afx_msg void OnBnClickedButton2();
};
