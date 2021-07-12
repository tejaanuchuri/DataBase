// CEMPINSERTRecord.cpp : implementation file
//

#include "pch.h"
#include "DataBase.h"
#include "CEMPINSERTRecord.h"
#include "afxdialogex.h"


#include "odbcinst.h"
#include "afxdb.h"
#include "CEMPHomePage.h"

// CEMPINSERTRecord dialog

IMPLEMENT_DYNAMIC(CEMPINSERTRecord, CDialog)

CEMPINSERTRecord::CEMPINSERTRecord(CWnd* pParent /*=nullptr*/)
	: CDialog(IDD_DIALOG_EMP_INSERT_RECORDDLG, pParent)
	, EMP_Title(_T(""))
	, EDIT_FirstName(_T(""))
	, EDIT_LastName(_T(""))
	, EMP_Gender(_T(""))
	, EMP_BirthDate(COleDateTime::GetCurrentTime())
	, EMP_PhoneNumber(_T(""))
	, EMP_Email(_T(""))
	, EMP_Address1(_T(""))
	, EMP_CITY(_T(""))
	, EMP_COUNTRY(_T(""))
	, EMP_PostalCode(_T(""))
{

}

CEMPINSERTRecord::~CEMPINSERTRecord()
{
}

void CEMPINSERTRecord::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_CBString(pDX, IDC_COMBO_TITLE, EMP_Title);
	DDX_Text(pDX, IDC_EDIT_FIRSTNAME, EDIT_FirstName);
	DDX_Text(pDX, IDC_EDIT_LASTNAME, EDIT_LastName);
	DDX_CBString(pDX, IDC_COMBO_GENDER, EMP_Gender);
	DDX_MonthCalCtrl(pDX, IDC_MONTHCALENDAR_BIRTHDATE, EMP_BirthDate);
	DDX_Text(pDX, IDC_EDIT_PHONENUMBER, EMP_PhoneNumber);
	DDV_MaxChars(pDX, EMP_PhoneNumber, 10);
	DDX_Text(pDX, IDC_EDIT_EMAIL, EMP_Email);
	DDX_Text(pDX, IDC_EDIT_ADDRESS1, EMP_Address1);
	DDX_Text(pDX, IDC_EDIT_CITY, EMP_CITY);
	DDX_Text(pDX, IDC_EDIT_COUNTRY, EMP_COUNTRY);
	DDX_Text(pDX, IDC_EDIT_POSTALCODE, EMP_PostalCode);
	DDV_MaxChars(pDX, EMP_PostalCode, 6);
}


BEGIN_MESSAGE_MAP(CEMPINSERTRecord, CDialog)
	ON_EN_CHANGE(IDC_EDIT_POSTALCODE, &CEMPINSERTRecord::OnEnChangeEdit9)
	ON_BN_CLICKED(IDC_BUTTON_INSERT_EMP_RECORDS, &CEMPINSERTRecord::OnBnClickedButtonInsertEmpRecords)
END_MESSAGE_MAP()


// CEMPINSERTRecord message handlers


void CEMPINSERTRecord::OnEnChangeEdit9()
{
	// TODO:  If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialog::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.

	// TODO:  Add your control notification handler code here
}


void CEMPINSERTRecord::OnBnClickedButtonInsertEmpRecords()
{
	CEMPINSERTRecord dlg;
	UpdateData(TRUE); // flow direction database <- ui
	//if (dlg.DoModal() == IDD_DIALOG_INSERT) {

	CDatabase database;
	CString sDsn;
	CString SqlString;

	if (EMP_Title.IsEmpty()) {
		AfxMessageBox(L"Title Must Be Required ...!");
		CEMPINSERTRecord dlg;
		dlg.DoModal();
	}
	
	else {
		// Build ODBC connection string
		sDsn.Format(_T("Driver={ODBC Driver 17 for SQL Server};Server=FYYP1N2;Dbq=C:\\Program Files\\Microsoft SQL Server\\MSSQL15.MSSQLSERVER\\MSSQL\\DATA\\AdminApp.mdf;Trusted_Connection=yes"));
		TRY{
			// Open the database
			database.Open(NULL,false,false,sDsn);
		//MessageBoxW(L"Are You Sure ?", L"Insert a Record",MB_YESNO);

		CString out = L" ,";
		CString quo = L"'";
		SqlString.Append(_T("INSERT INTO AdminApp.dbo.EmployeeTable(Title,FirstName,LastName,Gender,BirthDate,MobilePhone,EMail,Address1,City,Country,PostalCode) VALUES ("));
		SqlString.Append(quo);
		SqlString.Append(EMP_Title);
		SqlString.Append(quo);
		SqlString.Append(out);

		SqlString.Append(quo);
		SqlString.Append(EDIT_FirstName);
		SqlString.Append(quo);
		SqlString.Append(out);

		SqlString.Append(quo);
		SqlString.Append(EDIT_LastName);
		SqlString.Append(quo);
		SqlString.Append(out);

		SqlString.Append(quo);
		SqlString.Append(EMP_Gender);
		SqlString.Append(quo);
		SqlString.Append(out);

		COleDateTime dt(EMP_BirthDate);
		SqlString.Append(quo);
		SqlString.Append(dt.Format(_T("%Y-%m-%d")));
		SqlString.Append(quo);
		SqlString.Append(out);

		if (EMP_PhoneNumber.IsEmpty()) {
			SqlString.Append(L"''");
		}
		else {
			SqlString.Append(EMP_PhoneNumber);
		}
			SqlString.Append(out);
			SqlString.Append(quo);
			SqlString.Append(EMP_Email);
			SqlString.Append(quo);
			SqlString.Append(out);

			SqlString.Append(quo);
			SqlString.Append(EMP_Address1);
			SqlString.Append(quo);
			SqlString.Append(out);

			SqlString.Append(quo);
			SqlString.Append(EMP_CITY);
			SqlString.Append(quo);
			SqlString.Append(out);
						SqlString.Append(quo);
			SqlString.Append(EMP_COUNTRY);
			SqlString.Append(quo);
			SqlString.Append(out);
			if (EMP_PostalCode.IsEmpty()) {
				SqlString.Append(L"''");
			}
			else {
				SqlString.Append(EMP_PostalCode);
			}
				SqlString.Append(_T(" )"));

				//AfxMessageBox(SqlString);
				database.ExecuteSQL(SqlString);
				AfxMessageBox(L"Insert Record sucessfully...!");
				// Close the database
				database.Close();
		}CATCH(CDBException, e) {
			// If a database exception occured, show error msg
			AfxMessageBox(L"Database error: " + e->m_strError);
		}
		END_CATCH;
	}






}
