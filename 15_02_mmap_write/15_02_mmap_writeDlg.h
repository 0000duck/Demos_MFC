
// 15_02_mmap_writeDlg.h : ͷ�ļ�
//

#pragma once


// CMy15_02_mmap_writeDlg �Ի���
class CMy15_02_mmap_writeDlg : public CDialogEx
{
// ����
public:
	CMy15_02_mmap_writeDlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MY15_02_MMAP_WRITE_DIALOG };
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
	LPTSTR m_pszMapView;//ָ��ӳ��ĵ�ַ�ռ�

	afx_msg void OnBnClickedBtnWriteData();
};
