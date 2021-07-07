#pragma once


// CUserRecordDelete dialog

class CUserRecordDelete : public CDialog
{
	DECLARE_DYNAMIC(CUserRecordDelete)

public:
	CUserRecordDelete(CWnd* pParent = nullptr);   // standard constructor
	virtual ~CUserRecordDelete();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_DELETE_RECORD };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	CString m_empid;
	afx_msg void OnBnClickedButtonDelete();
	afx_msg void OnBnClickedOk();
};
