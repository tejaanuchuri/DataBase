// CFetchEmpData.cpp : implementation file
//

#include "pch.h"
#include "DataBase.h"
#include "CFetchEmpData.h"
#include "afxdialogex.h"


// CFetchEmpData dialog

IMPLEMENT_DYNAMIC(CFetchEmpData, CDialog)

CFetchEmpData::CFetchEmpData(CWnd* pParent /*=nullptr*/)
	: CDialog(IDD_DIALOG_DATA_DISPLAY, pParent)
{

}

CFetchEmpData::~CFetchEmpData()
{
}

void CFetchEmpData::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CFetchEmpData, CDialog)
END_MESSAGE_MAP()


// CFetchEmpData message handlers
