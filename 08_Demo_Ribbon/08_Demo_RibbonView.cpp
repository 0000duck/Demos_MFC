// ��� MFC ʾ��Դ������ʾ���ʹ�� MFC Microsoft Office Fluent �û����� 
// (��Fluent UI��)����ʾ�������ο���
// ���Բ��䡶Microsoft ������ο����� 
// MFC C++ ������渽����ص����ĵ���  
// ���ơ�ʹ�û�ַ� Fluent UI ����������ǵ����ṩ�ġ�  
// ��Ҫ�˽��й� Fluent UI ��ɼƻ�����ϸ��Ϣ������� 
// http://go.microsoft.com/fwlink/?LinkId=238214��
//
// ��Ȩ����(C) Microsoft Corporation
// ��������Ȩ����

// 08_Demo_RibbonView.cpp : CMy08_Demo_RibbonView ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "08_Demo_Ribbon.h"
#endif

#include "08_Demo_RibbonDoc.h"
#include "08_Demo_RibbonView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMy08_Demo_RibbonView

IMPLEMENT_DYNCREATE(CMy08_Demo_RibbonView, CView)

BEGIN_MESSAGE_MAP(CMy08_Demo_RibbonView, CView)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
END_MESSAGE_MAP()

// CMy08_Demo_RibbonView ����/����

CMy08_Demo_RibbonView::CMy08_Demo_RibbonView()
{
	// TODO: �ڴ˴���ӹ������

}

CMy08_Demo_RibbonView::~CMy08_Demo_RibbonView()
{
}

BOOL CMy08_Demo_RibbonView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CMy08_Demo_RibbonView ����

void CMy08_Demo_RibbonView::OnDraw(CDC* /*pDC*/)
{
	CMy08_Demo_RibbonDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
}

void CMy08_Demo_RibbonView::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CMy08_Demo_RibbonView::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CMy08_Demo_RibbonView ���

#ifdef _DEBUG
void CMy08_Demo_RibbonView::AssertValid() const
{
	CView::AssertValid();
}

void CMy08_Demo_RibbonView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMy08_Demo_RibbonDoc* CMy08_Demo_RibbonView::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMy08_Demo_RibbonDoc)));
	return (CMy08_Demo_RibbonDoc*)m_pDocument;
}
#endif //_DEBUG


// CMy08_Demo_RibbonView ��Ϣ�������
