
// 03_�������屳��.h : 03_�������屳�� Ӧ�ó������ͷ�ļ�
//
#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"       // ������


// CMy03_�������屳��App:
// �йش����ʵ�֣������ 03_�������屳��.cpp
//

class CMy03_�������屳��App : public CWinAppEx
{
public:
	CMy03_�������屳��App();


// ��д
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// ʵ��
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CMy03_�������屳��App theApp;
