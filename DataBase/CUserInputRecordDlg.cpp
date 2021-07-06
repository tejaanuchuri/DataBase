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
	CUserInputRecordDlg dlg;
	CDatabase database;
	CString sDsn;
	CString SqlString;
	CString strId = dlg.i_id,strName = dlg.i_name,strAge = i_age;
	CString out;
	out.Append(strId);
	out.Append(L"\n");
	out.Append(strName);
	out.Append(L"\n");
	out.Append(strAge);
	AfxMessageBox(L"hello........."+strName);
	// Build ODBC connection string
	sDsn.Format(_T("Driver={Microsoft Access Driver (*.mdb, *.accdb)};Dbq=C:\\Users\\admin.teja\\Documents\\AdminApp.accdb;Uid=Admin;Pwd=;"));
	TRY{
		// Open the database
		database.Open(NULL,false,false,sDsn);
		SqlString = "INSERT INTO Admin (ID,Name,Age) VALUES (55,'Sanjay',69)";
		database.ExecuteSQL(SqlString);
		AfxMessageBox(L"Database Connected sucessfully...!");
		// Close the database
		database.Close();
	}CATCH(CDBException, e) {
		// If a database exception occured, show error msg
		AfxMessageBox(L"Database error: ");
	}
	END_CATCH;
}
