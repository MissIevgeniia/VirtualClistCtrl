
// MFCMainDlg.h: файл заголовка
//

#pragma once
#include "MyList.h"
#include "Vector.h"

// Диалоговое окно MFCMainDlg
class MFCMainDlg : public CDialogEx
{
// Создание
public:
	MFCMainDlg(CWnd* pParent = nullptr);	// стандартный конструктор

// Данные диалогового окна
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MFCVIRTUALLIST_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// поддержка DDX/DDV


// Реализация
protected:
	HICON m_hIcon;

	// Созданные функции схемы сообщений
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	CListCtrl m_List;
	MyList Data;
	Vector<MyList> My_List;
	int Width;
	afx_msg void OnLvnGetdispinfoList1(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton3();
	afx_msg void OnBnClickedButton2();
	//afx_msg void OnNMCustomdrawList1(NMHDR *pNMHDR, LRESULT *pResult);
};
