// CDisplayEmpRecords.cpp : implementation file
//

#include "pch.h"
#include "DataBase.h"
#include "CDisplayEmpRecords.h"
#include "afxdialogex.h"


#include "odbcinst.h"
#include "afxdb.h"

// CDisplayEmpRecords dialog

IMPLEMENT_DYNAMIC(CDisplayEmpRecords, CDialog)

CDisplayEmpRecords::CDisplayEmpRecords(CWnd* pParent /*=nullptr*/)
	: CDialog(IDD_DIALOG_DISPLAY_EMP_RECORDS, pParent)
{

}

CDisplayEmpRecords::~CDisplayEmpRecords()
{
}

void CDisplayEmpRecords::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST_EMPRECORDS, m_list);
}


BEGIN_MESSAGE_MAP(CDisplayEmpRecords, CDialog)
	ON_BN_CLICKED(IDC_BUTTON_FETCHEMPRECORDS, &CDisplayEmpRecords::OnBnClickedButtonFetchemprecords)
END_MESSAGE_MAP()


// CDisplayEmpRecords message handlers


void CDisplayEmpRecords::OnBnClickedButtonFetchemprecords()
{
	UpdateData(TRUE);  //data flow direction database -> ui
	CDisplayEmpRecords dlg;
	CDatabase database;
	CString sDsn;
	CString SqlString;
	CString strID;
	CString strName;
	CString strAge;
	int iRec = 0;

	sDsn.Format(_T("Driver={Microsoft Access Driver (*.mdb, *.accdb)};Dbq=C:\\Users\\admin.teja\\Documents\\AdminApp.accdb;Uid=Admin;Pwd=;"));
	TRY{
		// Open the database
		 CRecordset recset(&database);
		database.Open(NULL,false,false,sDsn);
		SqlString = "SELECT ID, Name, Age FROM Admin";

	recset.Open(CRecordset::forwardOnly, SqlString, CRecordset::readOnly);
	ResetListControl();
	ListView_SetExtendedListViewStyle(m_list, LVS_EX_GRIDLINES);
	m_list.InsertColumn(
		0,              // Rank/order of item
		L"ID",          // Caption for this header
		LVCFMT_LEFT,    // Relative position of items under header
		100);           // Width of items under header

	m_list.InsertColumn(1, L"Name", LVCFMT_CENTER, 80);
	m_list.InsertColumn(2, L"Age", LVCFMT_LEFT, 100);

	while (!recset.IsEOF()) {
		// Copy each column into a variable
		recset.GetFieldValue(L"ID", strID);
		recset.GetFieldValue(L"Name", strName);
		recset.GetFieldValue(L"Age", strAge);

		// Insert values into the list control
		iRec = m_list.InsertItem(0, strID,0);
		m_list.SetItemText(0,1, strName);
		m_list.SetItemText(0,2, strAge);

		// goto next record
		recset.MoveNext();
	}
	//AfxMessageBox(L"Connect sucessfully...!");
	// Close the database
	database.Close();
	}CATCH(CDBException, e) {
		// If a database exception occured, show error msg
		AfxMessageBox(L"Database error: " + e->m_strError);
	}
	END_CATCH;
}
void CDisplayEmpRecords::ResetListControl() {
	m_list.DeleteAllItems();
	int iNbrOfColumns = 0, i;
	CHeaderCtrl* pHeader = (CHeaderCtrl*)m_list.GetDlgItem(0);
	if (pHeader) {
		iNbrOfColumns = pHeader->GetItemCount();
	}
	for (i = iNbrOfColumns; i >= 0; i--) {
		m_list.DeleteColumn(i);
	}
}