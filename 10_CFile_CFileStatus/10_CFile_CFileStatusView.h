
// 10_CFile_CFileStatusView.h : CMy10_CFile_CFileStatusView ��Ľӿ�
//

#pragma once


class CMy10_CFile_CFileStatusView : public CView
{
protected: // �������л�����
	CMy10_CFile_CFileStatusView();
	DECLARE_DYNCREATE(CMy10_CFile_CFileStatusView)

// ����
public:
	CMy10_CFile_CFileStatusDoc* GetDocument() const;

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
	virtual ~CMy10_CFile_CFileStatusView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnAFilestatus();
};

#ifndef _DEBUG  // 10_CFile_CFileStatusView.cpp �еĵ��԰汾
inline CMy10_CFile_CFileStatusDoc* CMy10_CFile_CFileStatusView::GetDocument() const
   { return reinterpret_cast<CMy10_CFile_CFileStatusDoc*>(m_pDocument); }
#endif

