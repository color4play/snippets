// FileUtils.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CFileUtilsApp:
// �йش����ʵ�֣������ FileUtils.cpp
//

class CFileUtilsApp : public CWinApp
{
public:
	CFileUtilsApp();

// ��д
	public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern CFileUtilsApp theApp;