
// 13_skin++_demoView.cpp : CMy13_skin_demoView ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "13_skin++_demo.h"
#endif

#include "13_skin++_demoDoc.h"
#include "13_skin++_demoView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMy13_skin_demoView

IMPLEMENT_DYNCREATE(CMy13_skin_demoView, CView)

BEGIN_MESSAGE_MAP(CMy13_skin_demoView, CView)
	// ��׼��ӡ����
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
END_MESSAGE_MAP()

// CMy13_skin_demoView ����/����

CMy13_skin_demoView::CMy13_skin_demoView()
{
	// TODO: �ڴ˴���ӹ������

}

CMy13_skin_demoView::~CMy13_skin_demoView()
{
}

BOOL CMy13_skin_demoView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CMy13_skin_demoView ����

void CMy13_skin_demoView::OnDraw(CDC* /*pDC*/)
{
	CMy13_skin_demoDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
}


// CMy13_skin_demoView ��ӡ

BOOL CMy13_skin_demoView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Ĭ��׼��
	return DoPreparePrinting(pInfo);
}

void CMy13_skin_demoView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӷ���Ĵ�ӡǰ���еĳ�ʼ������
}

void CMy13_skin_demoView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӵ�ӡ����е��������
}


// CMy13_skin_demoView ���

#ifdef _DEBUG
void CMy13_skin_demoView::AssertValid() const
{
	CView::AssertValid();
}

void CMy13_skin_demoView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMy13_skin_demoDoc* CMy13_skin_demoView::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMy13_skin_demoDoc)));
	return (CMy13_skin_demoDoc*)m_pDocument;
}
#endif //_DEBUG


// CMy13_skin_demoView ��Ϣ�������
