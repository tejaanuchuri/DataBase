// CUserRecordDelete.cpp : implementation file
//

#include "pch.h"
#include "DataBase.h"
#include "CUserRecordDelete.h"
#include "afxdialogex.h"


#include "odbcinst.h"
#include "afxdb.h"
// CUserRecordDelete dialog

IMPLEMENT_DYNAMIC(CUserRecordDelete, CDialog)

CUserRecordDelete::CUserRecordDelete(CWnd* pParent /*=nullptr*/)
	: CDialog(IDD_DIALOG_DELETE_RECORD, pParent)
	, m_empid(_T(""))
{

}

CUserRecordDelete::~CUserRecordDelete()
{
}

void CUserRecordDelete::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT_EMPID, m_empid);
}


BEGIN_MESSAGE_MAP(CUserRecordDelete, CDialog)
	ON_BN_CLICKED(IDC_BUTTON_DELETE, &CUserRecordDelete::OnBnClickedButtonDelete)
	ON_BN_CLICKED(IDOK, &CUserRecordDelete::OnBnClickedOk)
END_MESSAGE_MAP()


// CUserRecordDelete message handlers


void CUserRecordDelete::OnBnClickedButtonDelete()
{
	UpdateData(TRUE); // flow direction database <- ui
	//if (dlg.DoModal() == IDD_DIALOG_INSERT) {
	CString id = m_empid;

	CDatabase database;
	CString sDsn;
	CString SqlString;

	// Build ODBC connection string
	sDsn.Format(_T("Driver={Microsoft Access Driver (*.mdb, *.accdb)};Dbq=C:\\Users\\admin.teja\\Documents\\AdminApp.accdb;Uid=Admin;Pwd=;"));
	TRY{
		// Open the database
		database.Open(NULL,false,false,sDsn);
		SqlString = L"DELETE FROM Admin WHERE ID = ";


		SqlString.Append(id);
		//AfxMessageBox(SqlString);
		database.ExecuteSQL(SqlString);
		AfxMessageBox(L"Delete record sucessfully...!");
		// Close the database
		database.Close();
	}CATCH(CDBException, e) {
		// If a database exception occured, show error msg
		AfxMessageBox(L"Database error: " + e->m_strError);
	}
	END_CATCH;
	CDialog::OnOK();
}


void CUserRecordDelete::OnBnClickedOk()
{
	// TODO: Add your control notification handler code here
	CDialog::OnOK();
}
