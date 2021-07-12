#pragma once


// CFetchEmpData dialog

class CFetchEmpData : public CDialog
{
	DECLARE_DYNAMIC(CFetchEmpData)

public:
	CFetchEmpData(CWnd* pParent = nullptr);   // standard constructor
	virtual ~CFetchEmpData();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_DATA_DISPLAY };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
};
