
// 12_skin_magic_demoView.cpp : CMy12_skin_magic_demoView ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "12_skin_magic_demo.h"
#endif

#include "12_skin_magic_demoDoc.h"
#include "12_skin_magic_demoView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMy12_skin_magic_demoView

IMPLEMENT_DYNCREATE(CMy12_skin_magic_demoView, CView)

BEGIN_MESSAGE_MAP(CMy12_skin_magic_demoView, CView)
	// ��׼��ӡ����
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
END_MESSAGE_MAP()

// CMy12_skin_magic_demoView ����/����

CMy12_skin_magic_demoView::CMy12_skin_magic_demoView()
{
	// TODO: �ڴ˴���ӹ������

}

CMy12_skin_magic_demoView::~CMy12_skin_magic_demoView()
{
}

BOOL CMy12_skin_magic_demoView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CMy12_skin_magic_demoView ����

void CMy12_skin_magic_demoView::OnDraw(CDC* /*pDC*/)
{
	CMy12_skin_magic_demoDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
}


// CMy12_skin_magic_demoView ��ӡ

BOOL CMy12_skin_magic_demoView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Ĭ��׼��
	return DoPreparePrinting(pInfo);
}

void CMy12_skin_magic_demoView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӷ���Ĵ�ӡǰ���еĳ�ʼ������
}

void CMy12_skin_magic_demoView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӵ�ӡ����е��������
}


// CMy12_skin_magic_demoView ���

#ifdef _DEBUG
void CMy12_skin_magic_demoView::AssertValid() const
{
	CView::AssertValid();
}

void CMy12_skin_magic_demoView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMy12_skin_magic_demoDoc* CMy12_skin_magic_demoView::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMy12_skin_magic_demoDoc)));
	return (CMy12_skin_magic_demoDoc*)m_pDocument;
}
#endif //_DEBUG


// CMy12_skin_magic_demoView ��Ϣ�������
