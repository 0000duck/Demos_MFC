
// 16_01_pipe.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CMy16_01_pipeApp: 
// �йش����ʵ�֣������ 16_01_pipe.cpp
//

class CMy16_01_pipeApp : public CWinApp
{
public:
	CMy16_01_pipeApp();

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern CMy16_01_pipeApp theApp;