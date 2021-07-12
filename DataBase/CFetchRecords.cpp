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
	DDX_Control(pDX, IDC_LIST_DISPLAY_DATA, n_control);
}


BEGIN_MESSAGE_MAP(CFetchRecords, CDialog)
	ON_COMMAND(ID_SQLOPERATION_DISPLAYALLEMPLOYEERECORDS, &CFetchRecords::OnSqloperationDisplayallemployeerecords)
	ON_BN_CLICKED(IDC_BUTTON_FETCH_RECORDS, &CFetchRecords::OnBnClickedButtonFetchEmpRecords)
END_MESSAGE_MAP()


// CFetchRecords message handlers


void CFetchRecords::OnSqloperationDisplayallemployeerecords()
{

}


void CFetchRecords::OnBnClickedButtonFetchEmpRecords()
{
	//CFetchRecords dlg;
	CDatabase database;
	CString sDsn;
	CString SqlString;
	CString strID, strName, strAge;
	int iRec = 0;
	sDsn.Format(_T("Driver={Microsoft Access Driver (*.mdb, *.accdb)};Dbq=C:\\Users\\admin.teja\\Documents\\AdminApp.accdb;Uid=Admin;Pwd=;"));
	TRY{
		// Open the database
		database.Open(NULL,false,false,sDsn);
		CRecordset recset(&database);

		// Build the SQL statement
		SqlString = "SELECT ID, Name, Age FROM Admin";

		// Execute the query

		recset.Open(CRecordset::forwardOnly, SqlString, CRecordset::readOnly);

		// populate Grids
		/*ListView_SetExtendedListViewStyle(n_control, LVS_EX_GRIDLINES);

		// Column width and heading
		n_control.InsertColumn(0, L"Emp ID", LVCFMT_LEFT);
		n_control.InsertColumn(1, L"Name", LVCFMT_LEFT);
		n_control.InsertColumn(2, L"Age", LVCFMT_LEFT);


		while (!recset.IsEOF()) {
			// Copy each column into a variable
			recset.GetFieldValue(L"ID", strID);
			recset.GetFieldValue(L"Name", strName);
			recset.GetFieldValue(L"Age", strAge);

			// Insert values into the list control
			n_control.InsertItem(0, strID);
			n_control.InsertItem(1, strName);
			n_control.InsertItem(2, strAge);

			// goto next record
			recset.MoveNext();
		}
		*/
		AfxMessageBox(L"Database Connected sucessfully...!");
		// Close the database
		database.Close();
	}CATCH(CDBException, e) {
		// If a database exception occured, show error msg
		AfxMessageBox(L"Database error: ");
	}
	END_CATCH;
}
