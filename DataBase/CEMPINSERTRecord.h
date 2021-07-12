#pragma once


// CEMPINSERTRecord dialog

class CEMPINSERTRecord : public CDialog
{
	DECLARE_DYNAMIC(CEMPINSERTRecord)

public:
	CEMPINSERTRecord(CWnd* pParent = nullptr);   // standard constructor
	virtual ~CEMPINSERTRecord();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_EMP_INSERT_RECORDDLG};
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	CString EMP_Title;
	CString EDIT_FirstName;
	CString EDIT_LastName;
	CString EMP_Gender;
	COleDateTime EMP_BirthDate;
	CString EMP_PhoneNumber;
	CString EMP_Email;
	CString EMP_Address1;
	CString EMP_CITY;
	afx_msg void OnEnChangeEdit9();
	CString EMP_COUNTRY;
	CString EMP_PostalCode;
	afx_msg void OnBnClickedButtonInsertEmpRecords();
};
