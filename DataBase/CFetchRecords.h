#pragma once


// CFetchRecords dialog

class CFetchRecords : public CDialog
{
	DECLARE_DYNAMIC(CFetchRecords)

public:
	CFetchRecords(CWnd* pParent = nullptr);   // standard constructor
	virtual ~CFetchRecords();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_DISPLAY };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnSqloperationDisplayallemployeerecords();
	afx_msg void OnBnClickedButtonFetchEmpRecords();
	CListBox m_ListControl;
	CListCtrl n_control;
};
