
// MFCVirtualList.h: главный файл заголовка для приложения PROJECT_NAME
//

#pragma once

#ifndef __AFXWIN_H__
	#error "включить stdafx.h до включения этого файла в PCH"
#endif

#include "resource.h"		// основные символы


// CMFCVirtualListApp:
// Сведения о реализации этого класса: MFCVirtualList.cpp
//

class CMFCVirtualListApp : public CWinApp
{
public:
	CMFCVirtualListApp();

// Переопределение
public:
	virtual BOOL InitInstance();
	
// Реализация

	DECLARE_MESSAGE_MAP()
};

extern CMFCVirtualListApp theApp;
