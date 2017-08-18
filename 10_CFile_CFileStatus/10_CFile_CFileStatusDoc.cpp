
// 10_CFile_CFileStatusDoc.cpp : CMy10_CFile_CFileStatusDoc ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "10_CFile_CFileStatus.h"
#endif

#include "10_CFile_CFileStatusDoc.h"

#include <propkey.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CMy10_CFile_CFileStatusDoc

IMPLEMENT_DYNCREATE(CMy10_CFile_CFileStatusDoc, CDocument)

BEGIN_MESSAGE_MAP(CMy10_CFile_CFileStatusDoc, CDocument)
END_MESSAGE_MAP()


// CMy10_CFile_CFileStatusDoc ����/����

CMy10_CFile_CFileStatusDoc::CMy10_CFile_CFileStatusDoc()
{
	// TODO: �ڴ����һ���Թ������

}

CMy10_CFile_CFileStatusDoc::~CMy10_CFile_CFileStatusDoc()
{
}

BOOL CMy10_CFile_CFileStatusDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: �ڴ�������³�ʼ������
	// (SDI �ĵ������ø��ĵ�)

	return TRUE;
}




// CMy10_CFile_CFileStatusDoc ���л�

void CMy10_CFile_CFileStatusDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: �ڴ���Ӵ洢����
	}
	else
	{
		// TODO: �ڴ���Ӽ��ش���
	}
}

#ifdef SHARED_HANDLERS

// ����ͼ��֧��
void CMy10_CFile_CFileStatusDoc::OnDrawThumbnail(CDC& dc, LPRECT lprcBounds)
{
	// �޸Ĵ˴����Ի����ĵ�����
	dc.FillSolidRect(lprcBounds, RGB(255, 255, 255));

	CString strText = _T("TODO: implement thumbnail drawing here");
	LOGFONT lf;

	CFont* pDefaultGUIFont = CFont::FromHandle((HFONT) GetStockObject(DEFAULT_GUI_FONT));
	pDefaultGUIFont->GetLogFont(&lf);
	lf.lfHeight = 36;

	CFont fontDraw;
	fontDraw.CreateFontIndirect(&lf);

	CFont* pOldFont = dc.SelectObject(&fontDraw);
	dc.DrawText(strText, lprcBounds, DT_CENTER | DT_WORDBREAK);
	dc.SelectObject(pOldFont);
}

// ������������֧��
void CMy10_CFile_CFileStatusDoc::InitializeSearchContent()
{
	CString strSearchContent;
	// ���ĵ����������������ݡ�
	// ���ݲ���Ӧ�ɡ�;���ָ�

	// ����:     strSearchContent = _T("point;rectangle;circle;ole object;")��
	SetSearchContent(strSearchContent);
}

void CMy10_CFile_CFileStatusDoc::SetSearchContent(const CString& value)
{
	if (value.IsEmpty())
	{
		RemoveChunk(PKEY_Search_Contents.fmtid, PKEY_Search_Contents.pid);
	}
	else
	{
		CMFCFilterChunkValueImpl *pChunk = NULL;
		ATLTRY(pChunk = new CMFCFilterChunkValueImpl);
		if (pChunk != NULL)
		{
			pChunk->SetTextValue(PKEY_Search_Contents, value, CHUNK_TEXT);
			SetChunkValue(pChunk);
		}
	}
}

#endif // SHARED_HANDLERS

// CMy10_CFile_CFileStatusDoc ���

#ifdef _DEBUG
void CMy10_CFile_CFileStatusDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CMy10_CFile_CFileStatusDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CMy10_CFile_CFileStatusDoc ����
