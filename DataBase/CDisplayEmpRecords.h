#pragma once


// CDisplayEmpRecords dialog

class CDisplayEmpRecords : public CDialog
{
	DECLARE_DYNAMIC(CDisplayEmpRecords)

public:
	CDisplayEmpRecords(CWnd* pParent = nullptr);   // standard constructor
	virtual ~CDisplayEmpRecords();

	// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_DISPLAY_EMP_RECORDS };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);
	void ResetListControl();// DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	CListCtrl m_list;
	afx_msg void OnBnClickedButtonFetchemprecords();
};
