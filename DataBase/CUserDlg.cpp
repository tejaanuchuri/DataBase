// CUserDlg.cpp : implementation file
//

#include "pch.h"
#include "DataBase.h"
#include "CUserDlg.h"
#include "afxdialogex.h"
#include "resource.h"



#include "odbcinst.h"
#include "afxdb.h"
// CUserDlg dialog

IMPLEMENT_DYNAMIC(CUserDlg, CDialog)

CUserDlg::CUserDlg(CWnd* pParent /*=nullptr*/)
	: CDialog(IDD_DIALOG, pParent)
{

}

CUserDlg::~CUserDlg()
{
}

void CUserDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CUserDlg, CDialog)
	ON_BN_CLICKED(IDC_BUTTON1, &CUserDlg::OnBnClickedButton1)
END_MESSAGE_MAP()


// CUserDlg message handlers


void CUserDlg::OnBnClickedButton1()
{
	CDatabase database;
	CString sDsn;

	// Build ODBC connection string
	sDsn.Format(_T("Driver={Microsoft Access Driver (*.mdb, *.accdb)};Dbq=C:\\Users\\admin.teja\\Documents\\AdminApp.accdb;Uid=Admin;Pwd=;"));
	TRY{
		// Open the database
		database.Open(NULL,false,false,sDsn);

		AfxMessageBox(L"Database Connected sucessfully...!");

		// Close the database
		database.Close();
	}CATCH(CDBException, e) {
		// If a database exception occured, show error msg
		AfxMessageBox(L"Database error: ");
	}
	END_CATCH;
}
