
// 11_skinh_demoView.h : CMy11_skinh_demoView ��Ľӿ�
//

#pragma once


class CMy11_skinh_demoView : public CView
{
protected: // �������л�����
	CMy11_skinh_demoView();
	DECLARE_DYNCREATE(CMy11_skinh_demoView)

// ����
public:
	CMy11_skinh_demoDoc* GetDocument() const;

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
	virtual ~CMy11_skinh_demoView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnSize(UINT nType, int cx, int cy);
};

#ifndef _DEBUG  // 11_skinh_demoView.cpp �еĵ��԰汾
inline CMy11_skinh_demoDoc* CMy11_skinh_demoView::GetDocument() const
   { return reinterpret_cast<CMy11_skinh_demoDoc*>(m_pDocument); }
#endif

