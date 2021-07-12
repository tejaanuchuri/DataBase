
// DataBaseView.h : interface of the CDataBaseView class
//

#pragma once


class CDataBaseView : public CView
{
protected: // create from serialization only
	CDataBaseView() noexcept;
	DECLARE_DYNCREATE(CDataBaseView)

// Attributes
public:
	CDataBaseDoc* GetDocument() const;

// Operations
public:

// Overrides
public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// Implementation
public:
	virtual ~CDataBaseView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	afx_msg void OnFilePrintPreview();
	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnSqloperationTestdatabaseconnection();
	afx_msg void OnSqloperationInsertemployeerecord();
	afx_msg void OnSqloperationDisplayallemployeerecords();
	afx_msg void OnSqloperationDeleteemployeerecord();
	afx_msg void OnSqloperationUpdatetheemployeerecord();
	afx_msg void OnAdminappEmployeesection();
};

#ifndef _DEBUG  // debug version in DataBaseView.cpp
inline CDataBaseDoc* CDataBaseView::GetDocument() const
   { return reinterpret_cast<CDataBaseDoc*>(m_pDocument); }
#endif

