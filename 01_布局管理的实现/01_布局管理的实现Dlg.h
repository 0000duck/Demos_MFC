
// 01_���ֹ����ʵ��Dlg.h : ͷ�ļ�
//

#pragma once

#pragma region AutoFit
/**
*  �ؼ��洰�ڱ仯�Ŀ��Ƶ�Ԫ
**/
typedef struct tagCONTROL
{
	CWnd*	m_pWnd;				//ָ��ؼ���ָ��
	CRect	m_rectWnd;			//�ؼ���ռ����
	int		m_nMoveXPercent,	//�ؼ���x���ƶ��İٷֱ�
		m_nMoveYPercent,	//�ؼ���y���ƶ��İٷֱ�
		m_nZoomXPercent,	//�ؼ���x�����ŵİٷֱ�
		m_nZoomYPercent;	//�ؼ���y�����ŵİٷֱ�
}ControlInfo, *lpControlInfo;

typedef		CArray<lpControlInfo>	CTRLLIST;	//�ؼ���������Ϣ��
#pragma endregion



// CMy01_���ֹ����ʵ��Dlg �Ի���
class CMy01_���ֹ����ʵ��Dlg : public CDialogEx
{
	// ����
public:
	CMy01_���ֹ����ʵ��Dlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MY01__DIALOG };
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


#pragma region AutoFit
public:
	~CMy01_���ֹ����ʵ��Dlg();

	void	SetMinSize(int nWidth, int nHeight);
	void	FreeCtrlInfoList();
	void	MakeCtrlFit(CWnd* pWnd, int nMoveXPercent = 0, int nMoveYPercent = 0, int nZoomXPercent = 0, int nZoomYPercent = 0);
	void	CancelCtrlFit(HWND hWnd);
	afx_msg void OnSize(UINT nType, int cx, int cy);
	afx_msg void OnGetMinMaxInfo(MINMAXINFO* lpMMI);

	int			m_nWinWidth,		//���ڵĿ��
				m_nWinHeight;		//���ڵĸ߶�
	POINT		m_ptMinTrackSize;	//���ڵ���С��С
	CTRLLIST	m_listCtrlInfo;		//�ؼ�������Ϣ������  
#pragma endregion

	//afx_msg void OnNcPaint();
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
	afx_msg void OnEnterSizeMove();
	afx_msg void OnExitSizeMove();
	afx_msg void OnNcCalcSize(BOOL bCalcValidRects, NCCALCSIZE_PARAMS* lpncsp);
};
