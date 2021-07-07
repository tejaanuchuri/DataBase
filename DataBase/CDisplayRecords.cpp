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
    DDX_Control(pDX, IDC_LIST_DISPLAY_DATA_FORM_DATABASE, m_list_control_data);
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
    UpdateData(FALSE);  //data flow direction database -> ui
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
    ListView_SetExtendedListViewStyle(m_list_control_data, LVS_EX_GRIDLINES);

    // Column width and heading
    m_list_control_data.SetRedraw(TRUE);
    m_list_control_data.InsertColumn(0, _T("Emp ID"), LVCFMT_LEFT);
    m_list_control_data.InsertColumn(1, _T("Name"), LVCFMT_CENTER);
    m_list_control_data.InsertColumn(2, _T("Age"), LVCFMT_LEFT);

    m_list_control_data.SetColumnWidth(0, LVSCW_AUTOSIZE);
    int nc = m_list_control_data.GetColumnWidth(0);
    m_list_control_data.SetColumnWidth(0, LVSCW_AUTOSIZE_USEHEADER);
    int nh = m_list_control_data.GetColumnWidth(0);
    m_list_control_data.SetColumnWidth(0, max(nc, nh));

    m_list_control_data.SetColumnWidth(1, LVSCW_AUTOSIZE);
     nc = m_list_control_data.GetColumnWidth(1);
    m_list_control_data.SetColumnWidth(1, LVSCW_AUTOSIZE_USEHEADER);
     nh = m_list_control_data.GetColumnWidth(1);
    m_list_control_data.SetColumnWidth(1, max(nc, nh));

    m_list_control_data.SetColumnWidth(2, LVSCW_AUTOSIZE);
     nc = m_list_control_data.GetColumnWidth(2);
    m_list_control_data.SetColumnWidth(2, LVSCW_AUTOSIZE_USEHEADER);
     nh = m_list_control_data.GetColumnWidth(1);
    m_list_control_data.SetColumnWidth(2, max(nc, nh));

    // Loop through each record
    while (!recset.IsEOF()) {
        // Copy each column into a variable
        recset.GetFieldValue(L"ID", strID);
        recset.GetFieldValue(L"Name", strName);
        recset.GetFieldValue(L"Age", strAge);

        // Insert values into the list control
        m_list_control_data.InsertItem(0, strID);
        m_list_control_data.InsertItem( 1, strName);
        m_list_control_data.InsertItem(2, strAge);

        // goto next record
        recset.MoveNext();
    }


        //AfxMessageBox(L"Database Connected sucessfully...!");
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
    m_list_control_data.DeleteAllItems();
    int iNbrOfColumns=0,i;
    CHeaderCtrl* pHeader = (CHeaderCtrl*)m_list_control_data.GetDlgItem(0);
    if (pHeader) {
        iNbrOfColumns = pHeader->GetItemCount();
    }
    for (i = iNbrOfColumns; i >= 0; i--) {
        m_list_control_data.DeleteColumn(i);
    }
}