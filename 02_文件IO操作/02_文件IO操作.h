
// 02_�ļ�IO����.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CMy02_�ļ�IO����App: 
// �йش����ʵ�֣������ 02_�ļ�IO����.cpp
//

class CMy02_�ļ�IO����App : public CWinApp
{
public:
	CMy02_�ļ�IO����App();

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern CMy02_�ļ�IO����App theApp;