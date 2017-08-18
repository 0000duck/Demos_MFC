
// 10_CFile_CFileStatusView.cpp : CMy10_CFile_CFileStatusView ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "10_CFile_CFileStatus.h"
#endif

#include "10_CFile_CFileStatusDoc.h"
#include "10_CFile_CFileStatusView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMy10_CFile_CFileStatusView

IMPLEMENT_DYNCREATE(CMy10_CFile_CFileStatusView, CView)

BEGIN_MESSAGE_MAP(CMy10_CFile_CFileStatusView, CView)
	// ��׼��ӡ����
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_COMMAND(ID_A_FILESTATUS, &CMy10_CFile_CFileStatusView::OnAFilestatus)
END_MESSAGE_MAP()

// CMy10_CFile_CFileStatusView ����/����

CMy10_CFile_CFileStatusView::CMy10_CFile_CFileStatusView()
{
	// TODO: �ڴ˴���ӹ������

}

CMy10_CFile_CFileStatusView::~CMy10_CFile_CFileStatusView()
{
}

BOOL CMy10_CFile_CFileStatusView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CMy10_CFile_CFileStatusView ����

void CMy10_CFile_CFileStatusView::OnDraw(CDC* /*pDC*/)
{
	CMy10_CFile_CFileStatusDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
}


// CMy10_CFile_CFileStatusView ��ӡ

BOOL CMy10_CFile_CFileStatusView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Ĭ��׼��
	return DoPreparePrinting(pInfo);
}

void CMy10_CFile_CFileStatusView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӷ���Ĵ�ӡǰ���еĳ�ʼ������
}

void CMy10_CFile_CFileStatusView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӵ�ӡ����е��������
}


// CMy10_CFile_CFileStatusView ���

#ifdef _DEBUG
void CMy10_CFile_CFileStatusView::AssertValid() const
{
	CView::AssertValid();
}

void CMy10_CFile_CFileStatusView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMy10_CFile_CFileStatusDoc* CMy10_CFile_CFileStatusView::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMy10_CFile_CFileStatusDoc)));
	return (CMy10_CFile_CFileStatusDoc*)m_pDocument;
}
#endif //_DEBUG


// CMy10_CFile_CFileStatusView ��Ϣ�������


void CMy10_CFile_CFileStatusView::OnAFilestatus()
{
	// TODO: �ڴ���������������
	CString Filename("I:\\My Documents\\My Desktop\\�ޱ���.png");
	CFile file;
	file.Open(Filename, CFile::modeRead);
	CFileStatus status;
	file.GetStatus(status);

}
