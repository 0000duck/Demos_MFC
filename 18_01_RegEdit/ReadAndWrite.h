
// ReadAndWrite.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CReadAndWriteApp: 
// �йش����ʵ�֣������ ReadAndWrite.cpp
//

class CReadAndWriteApp : public CWinApp
{
public:
	CReadAndWriteApp();

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern CReadAndWriteApp theApp;