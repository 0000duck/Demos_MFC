
// 13_skin++_demoView.h : CMy13_skin_demoView ��Ľӿ�
//

#pragma once


class CMy13_skin_demoView : public CView
{
protected: // �������л�����
	CMy13_skin_demoView();
	DECLARE_DYNCREATE(CMy13_skin_demoView)

// ����
public:
	CMy13_skin_demoDoc* GetDocument() const;

// ����
public:

// ��д
public:
	virtual void OnDraw(CDC* pDC);  // ��д�Ի��Ƹ���ͼ
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// ʵ��
public:
	virtual ~CMy13_skin_demoView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // 13_skin++_demoView.cpp �еĵ��԰汾
inline CMy13_skin_demoDoc* CMy13_skin_demoView::GetDocument() const
   { return reinterpret_cast<CMy13_skin_demoDoc*>(m_pDocument); }
#endif

