
// 11_skinh_demoView.cpp : CMy11_skinh_demoView ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "11_skinh_demo.h"
#endif

#include "11_skinh_demoDoc.h"
#include "11_skinh_demoView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMy11_skinh_demoView

IMPLEMENT_DYNCREATE(CMy11_skinh_demoView, CView)

BEGIN_MESSAGE_MAP(CMy11_skinh_demoView, CView)
	// ��׼��ӡ����
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_SIZE()
END_MESSAGE_MAP()

// CMy11_skinh_demoView ����/����

CMy11_skinh_demoView::CMy11_skinh_demoView()
{
	// TODO: �ڴ˴���ӹ������

}

CMy11_skinh_demoView::~CMy11_skinh_demoView()
{
}

BOOL CMy11_skinh_demoView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CMy11_skinh_demoView ����

void CMy11_skinh_demoView::OnDraw(CDC* /*pDC*/)
{
	CMy11_skinh_demoDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
}


// CMy11_skinh_demoView ��ӡ

BOOL CMy11_skinh_demoView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Ĭ��׼��
	return DoPreparePrinting(pInfo);
}

void CMy11_skinh_demoView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӷ���Ĵ�ӡǰ���еĳ�ʼ������
}

void CMy11_skinh_demoView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӵ�ӡ����е��������
}


// CMy11_skinh_demoView ���

#ifdef _DEBUG
void CMy11_skinh_demoView::AssertValid() const
{
	CView::AssertValid();
}

void CMy11_skinh_demoView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMy11_skinh_demoDoc* CMy11_skinh_demoView::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMy11_skinh_demoDoc)));
	return (CMy11_skinh_demoDoc*)m_pDocument;
}
#endif //_DEBUG


// CMy11_skinh_demoView ��Ϣ�������


void CMy11_skinh_demoView::OnSize(UINT nType, int cx, int cy)
{
	CView::OnSize(nType, cx, cy);

	// TODO: �ڴ˴������Ϣ����������
	switch (nType)
	{
	//case SIZE_RESTORED:
	//	AfxMessageBox(L"���񵽴��ڻ�ԭ��Ϣ");
	//	break;
	case SIZE_MINIMIZED:
		AfxMessageBox(L"���񵽴�����С����Ϣ");
		break;
	case SIZE_MAXIMIZED:
		AfxMessageBox(L"���񵽴��������Ϣ");
		break;
	}
}
