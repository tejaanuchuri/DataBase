
// DataBaseView.cpp : implementation of the CDataBaseView class
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "DataBase.h"
#endif

#include "DataBaseDoc.h"
#include "DataBaseView.h"
#include "resource.h"
#include "CUserDlg.h"
#include "CUserInputRecordDlg.h"
#include "CFetchRecords.h"
#include "CDisplayRecords.h"
#include "CUserRecordDelete.h"
#include "CUpdateRecord.h"
#include "CEMPHomePage.h"
#include "CDisplayEmpRecords.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CDataBaseView

IMPLEMENT_DYNCREATE(CDataBaseView, CView)

BEGIN_MESSAGE_MAP(CDataBaseView, CView)
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CDataBaseView::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
	ON_COMMAND(ID_SQLOPERATION_TESTDATABASECONNECTION, &CDataBaseView::OnSqloperationTestdatabaseconnection)
	ON_COMMAND(ID_SQLOPERATION_INSERTEMPLOYEERECORD, &CDataBaseView::OnSqloperationInsertemployeerecord)
	ON_COMMAND(ID_SQLOPERATION_DISPLAYALLEMPLOYEERECORDS, &CDataBaseView::OnSqloperationDisplayallemployeerecords)
	ON_COMMAND(ID_SQLOPERATION_DELETEEMPLOYEERECORD, &CDataBaseView::OnSqloperationDeleteemployeerecord)
	ON_COMMAND(ID_SQLOPERATION_UPDATETHEEMPLOYEERECORD, &CDataBaseView::OnSqloperationUpdatetheemployeerecord)
	ON_COMMAND(ID_ADMINAPP_EMPLOYEESECTION, &CDataBaseView::OnAdminappEmployeesection)
END_MESSAGE_MAP()

// CDataBaseView construction/destruction

CDataBaseView::CDataBaseView() noexcept
{
	// TODO: add construction code here

}

CDataBaseView::~CDataBaseView()
{
}

BOOL CDataBaseView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

// CDataBaseView drawing

void CDataBaseView::OnDraw(CDC* /*pDC*/)
{
	CDataBaseDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: add draw code for native data here
}


// CDataBaseView printing



void CDataBaseView::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CDataBaseView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CDataBaseView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CDataBaseView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

void CDataBaseView::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CDataBaseView::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CDataBaseView diagnostics

#ifdef _DEBUG
void CDataBaseView::AssertValid() const
{
	CView::AssertValid();
}

void CDataBaseView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CDataBaseDoc* CDataBaseView::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CDataBaseDoc)));
	return (CDataBaseDoc*)m_pDocument;
}
#endif //_DEBUG


// CDataBaseView message handlers


void CDataBaseView::OnSqloperationTestdatabaseconnection()
{

	AfxMessageBox(L"We are going to Connect To Database...! ");
	CUserDlg Dlg;
	Dlg.DoModal();

}


void CDataBaseView::OnSqloperationInsertemployeerecord()
{
	CUserInputRecordDlg dlg;
	if (dlg.DoModal() == IDOK) {

	}
}


void CDataBaseView::OnSqloperationDisplayallemployeerecords()
{
	CDisplayEmpRecords _dlg;
	if (_dlg.DoModal() == IDOK) {

	}
}


void CDataBaseView::OnSqloperationDeleteemployeerecord()
{
	CUserRecordDelete _dlg;
	if (_dlg.DoModal() == IDOK) {

	}
}


void CDataBaseView::OnSqloperationUpdatetheemployeerecord()
{
	CUpdateRecord dlg;
	if (dlg.DoModal() == IDOK) {

	}
}


void CDataBaseView::OnAdminappEmployeesection()
{
	CEMPHomePage dlg;
	if (dlg.DoModal() == IDOK) {

	}
}
