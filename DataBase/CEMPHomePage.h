#pragma once


// CEMPHomePage dialog

class CEMPHomePage : public CDialog
{
	DECLARE_DYNAMIC(CEMPHomePage)

public:
	CEMPHomePage(CWnd* pParent = nullptr);   // standard constructor
	virtual ~CEMPHomePage();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_EMPHOMEPAGE };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButtonInsertEmprecord();
};
