
// 12_skin_magic_demo.h : 12_skin_magic_demo Ӧ�ó������ͷ�ļ�
//
#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"       // ������


// CMy12_skin_magic_demoApp:
// �йش����ʵ�֣������ 12_skin_magic_demo.cpp
//

class CMy12_skin_magic_demoApp : public CWinAppEx
{
public:
	CMy12_skin_magic_demoApp();


// ��д
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// ʵ��
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CMy12_skin_magic_demoApp theApp;
