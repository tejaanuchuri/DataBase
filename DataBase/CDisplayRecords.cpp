// CDisplayRecords.cpp : implementation file
//

#include "pch.h"
#include "DataBase.h"
#include "CDisplayRecords.h"
#include "afxdialogex.h"

#include "odbcinst.h"
#include "afxdb.h"

// CDisplayRecords dialog

IMPLEMENT_DYNAMIC(CDisplayRecords, CDialogEx)

CDisplayRecords::CDisplayRecords(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG_DATA_DISPLAY, pParent)
{

}

CDisplayRecords::~CDisplayRecords()
{
}

void CDisplayRecords::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST_DATADISPLAY, listdata);
}


BEGIN_MESSAGE_MAP(CDisplayRecords, CDialogEx)
	ON_BN_CLICKED(IDOK, &CDisplayRecords::OnBnClickedOk)
    ON_BN_CLICKED(IDC_BUTTON_FETCH_RECORDS, &CDisplayRecords::OnBnClickedButtonFetchEmpRecords)
END_MESSAGE_MAP()


// CDisplayRecords message handlers


void CDisplayRecords::OnBnClickedOk()
{
	
	CDialogEx::OnOK();
}


void CDisplayRecords::OnBnClickedButtonFetchEmpRecords()
{
    CDisplayRecords dlg;
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
        database.Open(NULL,false,false,sDsn);

    // Allocate the recordset
    CRecordset recset(&database);

    // Build the SQL statement
    SqlString = "SELECT ID, Name, Age FROM Admin";

    // Execute the query

    recset.Open(CRecordset::forwardOnly, SqlString, CRecordset::readOnly);
    // Reset List control if there is any data
    ResetListControl();
    // populate Grids
    ListView_SetExtendedListViewStyle(listdata, LVS_EX_GRIDLINES);

    // Column width and heading
    listdata.InsertColumn(0, L"Emp ID", LVCFMT_LEFT, -1, 0);
    listdata.InsertColumn(1, L"Name", LVCFMT_LEFT, -1, 1);
    listdata.InsertColumn(2, L"Age", LVCFMT_LEFT, -1, 1);
    listdata.SetColumnWidth(0, 120);
    listdata.SetColumnWidth(1, 200);
    listdata.SetColumnWidth(2, 200);

    // Loop through each record
    while (!recset.IsEOF()) {
        // Copy each column into a variable
        recset.GetFieldValue(L"ID", strID);
        recset.GetFieldValue(L"Name", strName);
        recset.GetFieldValue(L"Age", strAge);

        // Insert values into the list control
        iRec = listdata.InsertItem(0, strID, 0);
        listdata.SetItemText(0, 1, strName);
        listdata.SetItemText(0, 2, strAge);

        // goto next record
        recset.MoveNext();
    }


        AfxMessageBox(L"Database Connected sucessfully...!");
        // Close the database
        database.Close();
    }CATCH(CDBException, e) {
        // If a database exception occured, show error msg
        AfxMessageBox(L"Database error: "+e->m_strError);
    }
    END_CATCH;
    //CDisplayRecords::OnOK();
}
void CDisplayRecords::ResetListControl() {
    listdata.DeleteAllItems();
    int iNbrOfColumns=0,i;
    CHeaderCtrl* pHeader = (CHeaderCtrl*)listdata.GetDlgItem(0);
    if (pHeader) {
        iNbrOfColumns = pHeader->GetItemCount();
    }
    for (i = iNbrOfColumns; i >= 0; i--) {
        listdata.DeleteColumn(i);
    }
}