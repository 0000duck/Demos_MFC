
// 15_01_mmap_read.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CMy15_01_mmap_readApp: 
// �йش����ʵ�֣������ 15_01_mmap_read.cpp
//

class CMy15_01_mmap_readApp : public CWinApp
{
public:
	CMy15_01_mmap_readApp();

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern CMy15_01_mmap_readApp theApp;