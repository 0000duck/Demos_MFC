
// 01_���ֹ����ʵ��.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CMy01_���ֹ����ʵ��App: 
// �йش����ʵ�֣������ 01_���ֹ����ʵ��.cpp
//

class CMy01_���ֹ����ʵ��App : public CWinApp
{
public:
	CMy01_���ֹ����ʵ��App();

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern CMy01_���ֹ����ʵ��App theApp;