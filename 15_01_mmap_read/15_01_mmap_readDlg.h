
// 15_01_mmap_readDlg.h : ͷ�ļ�
//

#pragma once


// CMy15_01_mmap_readDlg �Ի���
class CMy15_01_mmap_readDlg : public CDialogEx
{
// ����
public:
	CMy15_01_mmap_readDlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MY15_01_MMAP_READ_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��


// ʵ��
protected:
	HICON m_hIcon;

	// ���ɵ���Ϣӳ�亯��
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()

public:
	HANDLE m_hMapObject;//ӳ�������
	LPTSTR  m_pszMapView;

	afx_msg void OnBnClickedBtnReadInfo();
};
