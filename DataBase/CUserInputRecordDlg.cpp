// CUserInputRecordDlg.cpp : implementation file
//

#include "pch.h"
#include "DataBase.h"
#include "CUserInputRecordDlg.h"
#include "afxdialogex.h"

#include "odbcinst.h"
#include "afxdb.h"
// CUserInputRecordDlg dialog

IMPLEMENT_DYNAMIC(CUserInputRecordDlg, CDialogEx)

CUserInputRecordDlg::CUserInputRecordDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG_INSERT, pParent)
	, i_id(_T(""))
	, i_name(_T(""))
	, i_age(_T(""))
{

}

CUserInputRecordDlg::~CUserInputRecordDlg()
{
}

void CUserInputRecordDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT_ID, i_id);
	DDX_Text(pDX, IDC_EDIT_NAME, i_name);
	DDX_Text(pDX, IDC_EDIT_AGE, i_age);
}


BEGIN_MESSAGE_MAP(CUserInputRecordDlg, CDialogEx)
	ON_COMMAND(ID_SQLOPERATION_INSERTEMPLOYEERECORD, &CUserInputRecordDlg::OnSqloperationInsertemployeerecord)
	ON_BN_CLICKED(IDC_BUTTON_INSERT, &CUserInputRecordDlg::OnBnClickedButtonInsert)
END_MESSAGE_MAP()


// CUserInputRecordDlg message handlers


void CUserInputRecordDlg::OnSqloperationInsertemployeerecord()
{

}


void CUserInputRecordDlg::OnBnClickedButtonInsert()
{
	//CUserInputRecordDlg dlg;
	UpdateData(TRUE); // flow direction database <- ui
	//if (dlg.DoModal() == IDD_DIALOG_INSERT) {
		
		CDatabase database;
		CString sDsn;
		CString SqlString;
		CString strId = i_id;
		CString strName = i_name;
		CString strAge = i_age;

		// Build ODBC connection string
		sDsn.Format(_T("Driver={Microsoft Access Driver (*.mdb, *.accdb)};Dbq=C:\\Users\\admin.teja\\Documents\\AdminApp.accdb;Uid=Admin;Pwd=;"));
		TRY{
			// Open the database
			database.Open(NULL,false,false,sDsn);
			SqlString = L"INSERT INTO Admin (ID,Name,Age) VALUES (";


			CString out = L" ,";
			CString quo = L"'";
			SqlString.Append(strId);
			SqlString.Append(out);
			SqlString.Append(quo);
			SqlString.Append(strName);
			SqlString.Append(quo);
			SqlString.Append(out);
			SqlString.Append(strAge);
			SqlString.Append(_T(")"));
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
	//}
}
