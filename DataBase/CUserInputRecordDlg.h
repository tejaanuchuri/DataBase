#pragma once


// CUserInputRecordDlg dialog

class CUserInputRecordDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CUserInputRecordDlg)

public:
	CUserInputRecordDlg(CWnd* pParent = nullptr);   // standard constructor
	virtual ~CUserInputRecordDlg();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_INSERT };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnSqloperationInsertemployeerecord();
	CString i_id;
	CString i_name;
	CString i_age;
	afx_msg void OnBnClickedButtonInsert();
};
