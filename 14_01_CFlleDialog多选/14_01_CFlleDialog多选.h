
// 14_01_CFlleDialog��ѡ.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CMy14_01_CFlleDialog��ѡApp: 
// �йش����ʵ�֣������ 14_01_CFlleDialog��ѡ.cpp
//

class CMy14_01_CFlleDialog��ѡApp : public CWinApp
{
public:
	CMy14_01_CFlleDialog��ѡApp();

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern CMy14_01_CFlleDialog��ѡApp theApp;