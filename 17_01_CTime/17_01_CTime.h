
// 17_01_CTime.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CMy17_01_CTimeApp: 
// �йش����ʵ�֣������ 17_01_CTime.cpp
//

class CMy17_01_CTimeApp : public CWinApp
{
public:
	CMy17_01_CTimeApp();

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern CMy17_01_CTimeApp theApp;