
// 15_02_mmap_write.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CMy15_02_mmap_writeApp: 
// �йش����ʵ�֣������ 15_02_mmap_write.cpp
//

class CMy15_02_mmap_writeApp : public CWinApp
{
public:
	CMy15_02_mmap_writeApp();

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern CMy15_02_mmap_writeApp theApp;