
// 13_skin++_demo.h : 13_skin++_demo Ӧ�ó������ͷ�ļ�
//
#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"       // ������
#include <string>

// CMy13_skin_demoApp:
// �йش����ʵ�֣������ 13_skin++_demo.cpp
//

class CMy13_skin_demoApp : public CWinApp
{
public:
	CMy13_skin_demoApp();


// ��д
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// ʵ��
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()


	
	void SetSkin(std::string strSkinFile);

	static DWORD ThreadKill(LPVOID lp);
};

extern CMy13_skin_demoApp theApp;
