
// 04_�����½���.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CMy04_�����½���App: 
// �йش����ʵ�֣������ 04_�����½���.cpp
//

class CMy04_�����½���App : public CWinApp
{
public:
	CMy04_�����½���App();

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern CMy04_�����½���App theApp;