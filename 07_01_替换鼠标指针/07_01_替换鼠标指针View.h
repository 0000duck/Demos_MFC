
// 07_01_�滻���ָ��View.h : CMy07_01_�滻���ָ��View ��Ľӿ�
//

#pragma once


class CMy07_01_�滻���ָ��View : public CView
{
protected: // �������л�����
	CMy07_01_�滻���ָ��View();
	DECLARE_DYNCREATE(CMy07_01_�滻���ָ��View)

// ����
public:
	CMy07_01_�滻���ָ��Doc* GetDocument() const;

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
	virtual ~CMy07_01_�滻���ָ��View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
public:
	bool m_bLbDown;
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg BOOL OnSetCursor(CWnd* pWnd, UINT nHitTest, UINT message);
};

#ifndef _DEBUG  // 07_01_�滻���ָ��View.cpp �еĵ��԰汾
inline CMy07_01_�滻���ָ��Doc* CMy07_01_�滻���ָ��View::GetDocument() const
   { return reinterpret_cast<CMy07_01_�滻���ָ��Doc*>(m_pDocument); }
#endif

