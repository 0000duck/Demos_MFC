
// 07_01_�滻���ָ��.h : 07_01_�滻���ָ�� Ӧ�ó������ͷ�ļ�
//
#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"       // ������


// CMy07_01_�滻���ָ��App:
// �йش����ʵ�֣������ 07_01_�滻���ָ��.cpp
//

class CMy07_01_�滻���ָ��App : public CWinAppEx
{
public:
	CMy07_01_�滻���ָ��App();


// ��д
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// ʵ��
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CMy07_01_�滻���ָ��App theApp;
