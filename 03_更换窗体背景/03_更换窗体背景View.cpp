
// 03_�������屳��View.cpp : CMy03_�������屳��View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "03_�������屳��.h"
#endif

#include "03_�������屳��Doc.h"
#include "03_�������屳��View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMy03_�������屳��View

IMPLEMENT_DYNCREATE(CMy03_�������屳��View, CView)

BEGIN_MESSAGE_MAP(CMy03_�������屳��View, CView)
	// ��׼��ӡ����
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_PAINT()
END_MESSAGE_MAP()

// CMy03_�������屳��View ����/����

CMy03_�������屳��View::CMy03_�������屳��View()
{
	// TODO: �ڴ˴���ӹ������

}

CMy03_�������屳��View::~CMy03_�������屳��View()
{
}

BOOL CMy03_�������屳��View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CMy03_�������屳��View ����

void CMy03_�������屳��View::OnDraw(CDC* /*pDC*/)
{
	CMy03_�������屳��Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
}


// CMy03_�������屳��View ��ӡ

BOOL CMy03_�������屳��View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Ĭ��׼��
	return DoPreparePrinting(pInfo);
}

void CMy03_�������屳��View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӷ���Ĵ�ӡǰ���еĳ�ʼ������
}

void CMy03_�������屳��View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӵ�ӡ����е��������
}


// CMy03_�������屳��View ���

#ifdef _DEBUG
void CMy03_�������屳��View::AssertValid() const
{
	CView::AssertValid();
}

void CMy03_�������屳��View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMy03_�������屳��Doc* CMy03_�������屳��View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMy03_�������屳��Doc)));
	return (CMy03_�������屳��Doc*)m_pDocument;
}
#endif //_DEBUG


// CMy03_�������屳��View ��Ϣ�������


void CMy03_�������屳��View::OnPaint()
{
	CPaintDC dc(this); // device context for painting
					   // TODO: �ڴ˴������Ϣ����������
					   // ��Ϊ��ͼ��Ϣ���� CView::OnPaint()

	//�������View�ര�壬Dialog��̫��
#pragma region �������屳��
	//1.��Դ���浼����Ӧλͼ
	//2.���´���
	CRect rect;
	GetClientRect(&rect); //�õ�����Ĵ�С
	CDC dcMem;
	dcMem.CreateCompatibleDC(&dc);
	CBitmap bmpBackground;
	bmpBackground.LoadBitmap(IDB_BITMAP1);//���ر���ͼƬ
	BITMAP bitMap;
	bmpBackground.GetBitmap(&bitMap);
	CBitmap* pbmpOld = dcMem.SelectObject(&bmpBackground);
	dc.StretchBlt(0, 0, rect.Width(), rect.Height(), &dcMem, 0, 0, bitMap.bmWidth, bitMap.bmHeight, SRCCOPY);

#pragma endregion

#pragma region ����ͼ��

	//1.����ͼ��
	//2. resource.h����ֱ�Ӹ�IDR_MAINFRAME��Ӧ���ļ�·��

#pragma endregion

#pragma region ���Ĵ������

	//1.MainFrame���precreatewindow��������´���:
	//cs.style &= ~(LONG)FWS_ADDTOTITLE; //������ʽ����Ȼ���ޱ���-....
	//m_strTitle = _T("3DRRESTRUCT By �Ĵ���ѧͼ����Ϣ�о���");

#pragma endregion


}
