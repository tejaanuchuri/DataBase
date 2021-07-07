#pragma once


// CDisplayRecords dialog

class CDisplayRecords : public CDialogEx
{
	DECLARE_DYNAMIC(CDisplayRecords)

public:
	CDisplayRecords(CWnd* pParent = nullptr);   // standard constructor
	virtual ~CDisplayRecords();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_DATA_DISPLAY };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	void ResetListControl();

	DECLARE_MESSAGE_MAP()
public:
	CListCtrl listdata;
	afx_msg void OnBnClickedOk();
	afx_msg void OnBnClickedButtonFetchEmpRecords();
};
