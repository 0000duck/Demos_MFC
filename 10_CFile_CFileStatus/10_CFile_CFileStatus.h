
// 10_CFile_CFileStatus.h : 10_CFile_CFileStatus Ӧ�ó������ͷ�ļ�
//
#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"       // ������


// CMy10_CFile_CFileStatusApp:
// �йش����ʵ�֣������ 10_CFile_CFileStatus.cpp
//

class CMy10_CFile_CFileStatusApp : public CWinAppEx
{
public:
	CMy10_CFile_CFileStatusApp();


// ��д
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// ʵ��
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CMy10_CFile_CFileStatusApp theApp;
