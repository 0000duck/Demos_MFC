
// 07_01_�滻���ָ��View.cpp : CMy07_01_�滻���ָ��View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "07_01_�滻���ָ��.h"
#endif

#include "07_01_�滻���ָ��Doc.h"
#include "07_01_�滻���ָ��View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMy07_01_�滻���ָ��View

IMPLEMENT_DYNCREATE(CMy07_01_�滻���ָ��View, CView)

BEGIN_MESSAGE_MAP(CMy07_01_�滻���ָ��View, CView)
	// ��׼��ӡ����
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_MOUSEMOVE()
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	ON_WM_SETCURSOR()
END_MESSAGE_MAP()

// CMy07_01_�滻���ָ��View ����/����

CMy07_01_�滻���ָ��View::CMy07_01_�滻���ָ��View()
{
	// TODO: �ڴ˴���ӹ������
	m_bLbDown = false;
}

CMy07_01_�滻���ָ��View::~CMy07_01_�滻���ָ��View()
{
}

BOOL CMy07_01_�滻���ָ��View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CMy07_01_�滻���ָ��View ����

void CMy07_01_�滻���ָ��View::OnDraw(CDC* /*pDC*/)
{
	CMy07_01_�滻���ָ��Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
}


// CMy07_01_�滻���ָ��View ��ӡ

BOOL CMy07_01_�滻���ָ��View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Ĭ��׼��
	return DoPreparePrinting(pInfo);
}

void CMy07_01_�滻���ָ��View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӷ���Ĵ�ӡǰ���еĳ�ʼ������
}

void CMy07_01_�滻���ָ��View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӵ�ӡ����е��������
}


// CMy07_01_�滻���ָ��View ���

#ifdef _DEBUG
void CMy07_01_�滻���ָ��View::AssertValid() const
{
	CView::AssertValid();
}

void CMy07_01_�滻���ָ��View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMy07_01_�滻���ָ��Doc* CMy07_01_�滻���ָ��View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMy07_01_�滻���ָ��Doc)));
	return (CMy07_01_�滻���ָ��Doc*)m_pDocument;
}
#endif //_DEBUG


// CMy07_01_�滻���ָ��View ��Ϣ�������

#include <iostream>
using namespace std;
void CMy07_01_�滻���ָ��View::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	if (m_bLbDown) 
	{
#pragma region �����ﴦ��Ļ���ÿ������ƶ��ֻ�����������ʽ
		//�μ�MSDN:
		//Your application can change the design of the cursor by using the SetCursor function
		//and specifying a different cursor handle.However, when the cursor moves,
		//the system redraws the class cursor at the new location.
		//To prevent the class cursor from being redrawn, you must process the WM_SETCURSOR message.
		//Each time the cursor moves and mouse input is not captured, 
		//the system sends this message to the window in which the cursor is moving.
		
		
		//auto cursor = LoadCursorA(AfxGetApp()->m_hInstance, MAKEINTRESOURCEA(IDC_CURSOR3));
		//::SetCursor(cursor);
#pragma endregion

		//m_bLbDown = true;
	}
	else
	{

	}

	CView::OnMouseMove(nFlags, point);
}


void CMy07_01_�滻���ָ��View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	m_bLbDown = true;
	CView::OnLButtonDown(nFlags, point);
}


void CMy07_01_�滻���ָ��View::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	m_bLbDown = false;
	CView::OnLButtonUp(nFlags, point);
}


//OnSetCursor����Ϣ WM_SETCURSOR ����
//The WM_SETCURSOR message is sent to a window if the mouse causes the cursor to move within a window and mouse input is not captured.
//
//������ˣ�ֻҪ����ƶ�OnMouseMOve�ͻ��Զ����� WM_SETCURSOR�Ӷ�����OnSetCursor���������Ƹı����ָ��ĳ���ʱ��һ�㲻Ҫ��OnMouseMOve�¼��е���SetCursor����������ָ����˸���������ָ����״����ķ����ǣ�
//��OnMouseMove��ʹ��һ��������ס������crect�е������״��Ȼ����OnSetCursor����SetCursor�������

BOOL CMy07_01_�滻���ָ��View::OnSetCursor(CWnd* pWnd, UINT nHitTest, UINT message)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	auto cursor = LoadCursorA(AfxGetApp()->m_hInstance, MAKEINTRESOURCEA(IDC_CURSOR3));
	::SetCursor(cursor);
	return TRUE;
	//return CView::OnSetCursor(pWnd, nHitTest, message); //�������ε�ϵͳ��setCursor
}
