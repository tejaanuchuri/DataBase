// CEMPHomePage.cpp : implementation file
//

#include "pch.h"
#include "DataBase.h"
#include "CEMPHomePage.h"
#include "afxdialogex.h"

#include "CEMPINSERTRecord.h"
// CEMPHomePage dialog

IMPLEMENT_DYNAMIC(CEMPHomePage, CDialog)

CEMPHomePage::CEMPHomePage(CWnd* pParent /*=nullptr*/)
	: CDialog(IDD_DIALOG_EMPHOMEPAGE, pParent)
{

}

CEMPHomePage::~CEMPHomePage()
{
}

void CEMPHomePage::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CEMPHomePage, CDialog)
	ON_BN_CLICKED(IDC_BUTTON_INSERT_EMPRECORD, &CEMPHomePage::OnBnClickedButtonInsertEmprecord)
END_MESSAGE_MAP()


// CEMPHomePage message handlers


void CEMPHomePage::OnBnClickedButtonInsertEmprecord()
{
	CEMPINSERTRecord dlg;
	if (dlg.DoModal() == IDOK) {

	}
}
