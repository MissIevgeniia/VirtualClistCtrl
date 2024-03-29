#pragma once


// Диалоговое окно InputDlg

class InputDlg : public CDialogEx
{
	DECLARE_DYNAMIC(InputDlg)

public:
	InputDlg(CWnd* pParent = nullptr);   // стандартный конструктор
	virtual ~InputDlg();

// Данные диалогового окна
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_INPUTDLG};
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // поддержка DDX/DDV

	DECLARE_MESSAGE_MAP()
public:
	CString m_Int;
	CString m_Double;
	CString m_String;
};
