// CUpdateRecord.cpp : implementation file
//

#include "pch.h"
#include "DataBase.h"
#include "CUpdateRecord.h"
#include "afxdialogex.h"


#include "odbcinst.h"
#include "afxdb.h"
// CUpdateRecord dialog

IMPLEMENT_DYNAMIC(CUpdateRecord, CDialog)

CUpdateRecord::CUpdateRecord(CWnd* pParent /*=nullptr*/)
	: CDialog(IDD_DIALOG_UPDATE_RECORD, pParent)
	, e_empid(_T(""))
	, d_name(_T(""))
	, d_age(_T(""))
	, u_age(_T(""))
	, U_name(_T(""))
{

}

CUpdateRecord::~CUpdateRecord()
{
}

void CUpdateRecord::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT_EMPID, e_empid);
	DDX_Text(pDX, IDC_EDIT_DISPLAYNAME, d_name);
	DDX_Text(pDX, IDC_EDIT_DISPLAYAGE, d_age);
	DDX_Control(pDX, IDC_EDIT_UNAME, u_name);
	DDX_Text(pDX, IDC_EDIT_UAge, u_age);
	DDX_Text(pDX, IDC_EDIT_UNAME, U_name);
}


BEGIN_MESSAGE_MAP(CUpdateRecord, CDialog)
	ON_BN_CLICKED(IDC_BUTTON_CHECK, &CUpdateRecord::OnBnClickedButtonCheck)
    ON_BN_CLICKED(IDC_BUTTON2, &CUpdateRecord::OnBnClickedButton2)
END_MESSAGE_MAP()


// CUpdateRecord message handlers


void CUpdateRecord::OnBnClickedButtonCheck()
{

    UpdateData(TRUE);  //data flow direction database -> ui
    CUpdateRecord dlg;
    CDatabase database;
    CString sDsn;
    CString SqlString;
    CString strID=e_empid;
    AfxMessageBox(strID);
    CString strName;
    CString strAge;
    int iRec = 0;
    
    sDsn.Format(_T("Driver={Microsoft Access Driver (*.mdb, *.accdb)};Dbq=C:\\Users\\admin.teja\\Documents\\AdminApp.accdb;Uid=Admin;Pwd=;"));
    TRY{
        // Open the database
        database.Open(NULL,false,false,sDsn);

    // Allocate the recordset
    CRecordset recset(&database);

    // Build the SQL statement
    SqlString = "SELECT ID, Name, Age FROM Admin WHERE ID = ";
    SqlString.Append(strID);
    // Execute the query
    
    recset.Open(CRecordset::forwardOnly, SqlString, CRecordset::readOnly);
    if (recset.IsEOF()) {
        AfxMessageBox(_T("No Record Found...!"));
        return;
    }
    while (!recset.IsEOF()) {
        // Copy each column into a variable
        recset.GetFieldValue(L"ID", strID);
        recset.GetFieldValue(L"Name", strName);
        recset.GetFieldValue(L"Age", strAge);
        AfxMessageBox(_T("Name : ") + strName + _T(" Age : ") + strAge);
        recset.MoveNext();
    }


    //AfxMessageBox(L"Database Connected sucessfully...!");
    // Close the database
    database.Close();
    }CATCH(CDBException, e) {
        // If a database exception occured, show error msg
        AfxMessageBox(L"Database error: " + e->m_strError);
    }
    END_CATCH;
	//}
}


void CUpdateRecord::OnBnClickedButton2()
{
    UpdateData(TRUE);  //data flow direction database -> ui
    CUpdateRecord dlg;
    CDatabase database;
    CString sDsn;
    CString SqlString;
    CString strID = e_empid;
    CString strName = U_name;
    CString strAge = u_age;
    int iRec = 0;

    sDsn.Format(_T("Driver={Microsoft Access Driver (*.mdb, *.accdb)};Dbq=C:\\Users\\admin.teja\\Documents\\AdminApp.accdb;Uid=Admin;Pwd=;"));
    TRY{
        // Open the database
        database.Open(NULL,false,false,sDsn);

    // Allocate the recordset
    CRecordset recset(&database);

    // Build the SQL statement
    SqlString.Append(_T("UPDATE Admin SET Name = "));
    SqlString.Append(_T("'"));
    SqlString.Append(strName);
    SqlString.Append(_T("'"));
    SqlString.Append(_T(" , Age = "));
    SqlString.Append(strAge);
    SqlString.Append(_T(" WHERE ID = "));
    SqlString.Append(strID);

    AfxMessageBox(SqlString);
    // Execute the query
    database.ExecuteSQL(SqlString);
    AfxMessageBox(L"Update Record sucessfully...!");
    // Close the database
    database.Close();
    }CATCH(CDBException, e) {
        // If a database exception occured, show error msg
        AfxMessageBox(L"Database error: " + e->m_strError);
    }
    END_CATCH;
}
