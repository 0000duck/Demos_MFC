
// 11_skinh_demo.h : 11_skinh_demo Ӧ�ó������ͷ�ļ�
//
#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"       // ������


// CMy11_skinh_demoApp:
// �йش����ʵ�֣������ 11_skinh_demo.cpp
//

class CMy11_skinh_demoApp : public CWinAppEx
{
public:
	CMy11_skinh_demoApp();


// ��д
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// ʵ��
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CMy11_skinh_demoApp theApp;
