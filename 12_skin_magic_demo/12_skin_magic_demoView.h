
// 12_skin_magic_demoView.h : CMy12_skin_magic_demoView ��Ľӿ�
//

#pragma once


class CMy12_skin_magic_demoView : public CView
{
protected: // �������л�����
	CMy12_skin_magic_demoView();
	DECLARE_DYNCREATE(CMy12_skin_magic_demoView)

// ����
public:
	CMy12_skin_magic_demoDoc* GetDocument() const;

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
	virtual ~CMy12_skin_magic_demoView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // 12_skin_magic_demoView.cpp �еĵ��԰汾
inline CMy12_skin_magic_demoDoc* CMy12_skin_magic_demoView::GetDocument() const
   { return reinterpret_cast<CMy12_skin_magic_demoDoc*>(m_pDocument); }
#endif

