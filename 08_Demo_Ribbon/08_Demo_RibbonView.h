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

// 08_Demo_RibbonView.h : CMy08_Demo_RibbonView ��Ľӿ�
//

#pragma once


class CMy08_Demo_RibbonView : public CView
{
protected: // �������л�����
	CMy08_Demo_RibbonView();
	DECLARE_DYNCREATE(CMy08_Demo_RibbonView)

// ����
public:
	CMy08_Demo_RibbonDoc* GetDocument() const;

// ����
public:

// ��д
public:
	virtual void OnDraw(CDC* pDC);  // ��д�Ի��Ƹ���ͼ
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// ʵ��
public:
	virtual ~CMy08_Demo_RibbonView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	afx_msg void OnFilePrintPreview();
	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // 08_Demo_RibbonView.cpp �еĵ��԰汾
inline CMy08_Demo_RibbonDoc* CMy08_Demo_RibbonView::GetDocument() const
   { return reinterpret_cast<CMy08_Demo_RibbonDoc*>(m_pDocument); }
#endif

