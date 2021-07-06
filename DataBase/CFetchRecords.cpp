// CFetchRecords.cpp : implementation file
//

#include "pch.h"
#include "DataBase.h"
#include "CFetchRecords.h"
#include "afxdialogex.h"


#include "odbcinst.h"
#include "afxdb.h"

// CFetchRecords dialog

IMPLEMENT_DYNAMIC(CFetchRecords, CDialog)

CFetchRecords::CFetchRecords(CWnd* pParent /*=nullptr*/)
	: CDialog(IDD_DIALOG_DISPLAY, pParent)
{

}

CFetchRecords::~CFetchRecords()
{
}

void CFetchRecords::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST_DISPLAY, m_ListControl);
}


BEGIN_MESSAGE_MAP(CFetchRecords, CDialog)
	ON_COMMAND(ID_SQLOPERATION_DISPLAYALLEMPLOYEERECORDS, &CFetchRecords::OnSqloperationDisplayallemployeerecords)
	ON_BN_CLICKED(IDC_BUTTON_FETCH_RECORDS, &CFetchRecords::OnBnClickedButtonFetchRecords)
END_MESSAGE_MAP()


// CFetchRecords message handlers


void CFetchRecords::OnSqloperationDisplayallemployeerecords()
{
	
}


void CFetchRecords::OnBnClickedButtonFetchRecords()
{
	CDatabase database;
	CString sDsn;
	CString SqlString;
    int iRec = 0;
	// Build ODBC connection string
	sDsn.Format(_T("Driver={Microsoft Access Driver (*.mdb, *.accdb)};Dbq=C:\\Users\\admin.teja\\Documents\\AdminApp.accdb;Uid=Admin;Pwd=;"));
	TRY{
		// Open the database
		database.Open(NULL,false,false,sDsn);
    // Allocate the recordset
    CRecordset recset(&database);

    // Build the SQL statement
    SqlString = "SELECT ID, Name, Age FROM Admin";

    // Execute the query

    recset.Open(CRecordset::forwardOnly, SqlString, CRecordset::readOnly);
    // Reset List control if there is any data
    //ResetListControl();
    // populate Grids
    ListView_SetExtendedListViewStyle(m_ListControl, LVS_EX_GRIDLINES);

    // Column width and heading
    m_ListControl.InsertColumn(0, "Emp ID", LVCFMT_LEFT, -1, 0);
    m_ListControl.InsertColumn(1, "Name", LVCFMT_LEFT, -1, 1);
    m_ListControl.InsertColumn(2, "Age", LVCFMT_LEFT, -1, 1);
    m_ListControl.SetColumnWidth(0, 120);
    m_ListControl.SetColumnWidth(1, 200);
    m_ListControl.SetColumnWidth(2, 200);

    // Loop through each record
    while (!recset.IsEOF()) {
        // Copy each column into a variable
        recset.GetFieldValue("ID", strID);
        recset.GetFieldValue("Name", strName);
        recset.GetFieldValue("Age", strAge);

        // Insert values into the list control
        iRec = m_ListControl.InsertItem(0, strID, 0);
        m_ListControl.SetItemText(0, 1, strName);
        m_ListControl.SetItemText(0, 2, strAge);

        // goto next record
        recset.MoveNext();
    }
		AfxMessageBox(L"Database Connected sucessfully...!");
		// Close the database
		database.Close();
	}CATCH(CDBException, e) {
		// If a database exception occured, show error msg
		AfxMessageBox(L"Database error: ");
	}
	END_CATCH;
}
