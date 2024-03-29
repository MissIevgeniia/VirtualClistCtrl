
// MFCMain.cpp: файл реализации
//
#include "stdafx.h"
#include "MFCVirtualList.h"
#include "MFCMainDlg.h"
#include "afxdialogex.h"
#include "InputDlg.h" 

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// Диалоговое окно CAboutDlg используется для описания сведений о приложении

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// Данные диалогового окна
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // поддержка DDX/DDV

// Реализация
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)

END_MESSAGE_MAP()


// Диалоговое окно MFCMainDlg



MFCMainDlg::MFCMainDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_MFCVIRTUALLIST_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void MFCMainDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST1, m_List);
}

BEGIN_MESSAGE_MAP(MFCMainDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_NOTIFY(LVN_GETDISPINFO, IDC_LIST1, OnLvnGetdispinfoList1)
	ON_BN_CLICKED(IDC_BUTTON1, &MFCMainDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON3, &MFCMainDlg::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON2, &MFCMainDlg::OnBnClickedButton2)
	//ON_NOTIFY(NM_CUSTOMDRAW, IDC_LIST1, &MFCMainDlg::OnNMCustomdrawList1)
END_MESSAGE_MAP()


// Обработчики сообщений MFCMainDlg

BOOL MFCMainDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Добавление пункта "О программе..." в системное меню.

	// IDM_ABOUTBOX должен быть в пределах системной команды.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Задает значок для этого диалогового окна.  Среда делает это автоматически,
	//  если главное окно приложения не является диалоговым
	SetIcon(m_hIcon, TRUE);			// Крупный значок
	SetIcon(m_hIcon, FALSE);		// Мелкий значок

	// TODO: добавьте дополнительную инициализацию
	for (int i = 0; i < 20; i++) {
		Data.SetData(i, i + 0.5, _TEXT("test string"));
		My_List.add(Data);
	};
	m_List.SetExtendedStyle(m_List.GetExtendedStyle() | LVS_EX_FULLROWSELECT);
	m_List.SetItemCountEx(My_List.Getsize());
	Width = m_List.GetStringWidth((LPCTSTR)"Test String and some space");
	m_List.InsertColumn(0, (LPCTSTR) _TEXT("INT"), LVCFMT_LEFT, Width, 0);
	m_List.InsertColumn(1, (LPCTSTR) _TEXT("Double"), LVCFMT_LEFT, Width, 1);
	m_List.InsertColumn(2, (LPCTSTR) _TEXT("String"), LVCFMT_LEFT, Width, 2);
	return TRUE;  // возврат значения TRUE, если фокус не передан элементу управления
}

void MFCMainDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// При добавлении кнопки свертывания в диалоговое окно нужно воспользоваться приведенным ниже кодом,
//  чтобы нарисовать значок.  Для приложений MFC, использующих модель документов или представлений,
//  это автоматически выполняется рабочей областью.

void MFCMainDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // контекст устройства для рисования

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Выравнивание значка по центру клиентского прямоугольника
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Нарисуйте значок
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// Система вызывает эту функцию для получения отображения курсора при перемещении
//  свернутого окна.
HCURSOR MFCMainDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

void MFCMainDlg::OnLvnGetdispinfoList1(NMHDR *pNMHDR, LRESULT *pResult)
{
	LV_DISPINFO* pDispInfo = (LV_DISPINFO*)pNMHDR;
	LV_ITEM* pItem = &(pDispInfo)->item;
	int nIndex = pItem->iItem;
	MyList DataItem = My_List[nIndex];
	if (pItem->mask & LVIF_TEXT) { //требуется текст?
		switch (pItem->iSubItem) {
		case(0):
			lstrcpyn(pItem->pszText, DataItem.GetIntAsWSTR(), pItem->cchTextMax);
			break;
		case(1):
			lstrcpyn(pItem->pszText, DataItem.GetDoubleAsWSTR(), pItem->cchTextMax);
			break;
		case(2):
			lstrcpyn(pItem->pszText, DataItem.GetString(), pItem->cchTextMax);
			break;
		default:
			break;
		}

	}
}


void MFCMainDlg::OnBnClickedButton1()
{
	InputDlg DlgInput;
	if (DlgInput.DoModal() == IDOK) {
		CString sText = DlgInput.m_Int;
		/*GetDlgItemText(IDC_EDIT1, sText);*/
		int iNum = _wtoi(sText);
		sText = DlgInput.m_Double;
		double dNum = _wtof(sText);
		sText = DlgInput.m_String;
		wchar_t* String = new wchar_t[20];
		wcscpy_s(String, 20, sText);
		MyList Item;
		Item.SetData(iNum, dNum, String);
		My_List.add(Item);
		m_List.SetItemCountEx(My_List.Getsize());
		delete[] String;
	}
}


void MFCMainDlg::OnBnClickedButton3()
{
	My_List.Clear();
	m_List.SetItemCountEx(My_List.Getsize());
}


void MFCMainDlg::OnBnClickedButton2()
{
	int i = m_List.GetSelectionMark();
	My_List.del(i);
	m_List.SetItemCountEx(My_List.Getsize());
	m_List.RedrawItems(i,My_List.Getsize());
}


//void MFCMainDlg::OnNMCustomdrawList1(NMHDR *pNMHDR, LRESULT *pResult)
//{
//	//LPNMCUSTOMDRAW pNMCD = reinterpret_cast<LPNMCUSTOMDRAW>(pNMHDR);
//	NMLVCUSTOMDRAW* pLVCD = reinterpret_cast<NMLVCUSTOMDRAW*>(pNMHDR);
//	SetWindowLong(pNMHDR->hwndFrom, DWL_MSGRESULT, CDRF_DODEFAULT);
//	/**pResult = CDRF_DODEFAULT;*/
//
//	switch (pLVCD->nmcd.dwDrawStage)
//	{
//	case CDDS_PREPAINT:
//		/**pResult = CDRF_NOTIFYITEMDRAW;*/
//		SetWindowLong(pNMHDR->hwndFrom, DWL_MSGRESULT, CDRF_NOTIFYITEMDRAW);
//		break;
//	case CDDS_ITEMPREPAINT:
//		/**pResult = CDRF_NOTIFYSUBITEMDRAW;*/
//		SetWindowLong(pNMHDR->hwndFrom, DWL_MSGRESULT, CDRF_NOTIFYSUBITEMDRAW);
//		break;
//
//	case (CDDS_ITEMPREPAINT | CDDS_SUBITEM):
//	{
//		if (0 == pLVCD->iSubItem) {
//			pLVCD->clrText = RGB(150, 0, 0);
//		}
//		else if (1 == pLVCD->iSubItem) {
//			pLVCD->clrText = RGB(255, 0, 0);
//		}
//		else if (2 == pLVCD->iSubItem) {
//			pLVCD->clrText = RGB(200, 0, 20);
//		}
//		SetWindowLong(pNMHDR->hwndFrom, DWL_MSGRESULT, CDRF_NEWFONT);
//		//*pResult = CDRF_NEWFONT;
//	}
//	break;
//	}
//}
