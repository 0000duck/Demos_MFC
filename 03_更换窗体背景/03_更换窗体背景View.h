
// 03_�������屳��View.h : CMy03_�������屳��View ��Ľӿ�
//

#pragma once


class CMy03_�������屳��View : public CView
{
protected: // �������л�����
	CMy03_�������屳��View();
	DECLARE_DYNCREATE(CMy03_�������屳��View)

// ����
public:
	CMy03_�������屳��Doc* GetDocument() const;

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
	virtual ~CMy03_�������屳��View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnPaint();
};

#ifndef _DEBUG  // 03_�������屳��View.cpp �еĵ��԰汾
inline CMy03_�������屳��Doc* CMy03_�������屳��View::GetDocument() const
   { return reinterpret_cast<CMy03_�������屳��Doc*>(m_pDocument); }
#endif

