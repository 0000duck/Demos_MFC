
// 14_01_CFlleDialog��ѡDlg.h : ͷ�ļ�
//

#pragma once


// CMy14_01_CFlleDialog��ѡDlg �Ի���
class CMy14_01_CFlleDialog��ѡDlg : public CDialogEx
{
// ����
public:
	CMy14_01_CFlleDialog��ѡDlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MY14_01_CFLLEDIALOG_DIALOG };
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
	afx_msg void OnBnClickedButton1();
};
