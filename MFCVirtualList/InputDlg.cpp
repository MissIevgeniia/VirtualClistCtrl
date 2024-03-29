// InputDlg.cpp: файл реализации
//

#include "stdafx.h"
#include "MFCVirtualList.h"
#include "InputDlg.h"
#include "afxdialogex.h"


// Диалоговое окно InputDlg

IMPLEMENT_DYNAMIC(InputDlg, CDialogEx)

InputDlg::InputDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_INPUTDLG, pParent)
	, m_Int(_T(""))
	, m_Double(_T(""))
	, m_String(_T(""))
{

}

InputDlg::~InputDlg()
{
}

void InputDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, m_Int);
	DDX_Text(pDX, IDC_EDIT2, m_Double);
	DDX_Text(pDX, IDC_EDIT3, m_String);
}


BEGIN_MESSAGE_MAP(InputDlg, CDialogEx)
END_MESSAGE_MAP()


// Обработчики сообщений InputDlg
