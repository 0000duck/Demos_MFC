
// 05_�ı�����.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CMy05_�ı�����App: 
// �йش����ʵ�֣������ 05_�ı�����.cpp
//

class CMy05_�ı�����App : public CWinApp
{
public:
	CMy05_�ı�����App();

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern CMy05_�ı�����App theApp;