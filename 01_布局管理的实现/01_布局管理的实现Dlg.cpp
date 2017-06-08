
// 01_���ֹ����ʵ��Dlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "01_���ֹ����ʵ��.h"
#include "01_���ֹ����ʵ��Dlg.h"
#include "afxdialogex.h"
#include <iostream>
using namespace std;
#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// ����Ӧ�ó��򡰹��ڡ��˵���� CAboutDlg �Ի���

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

// ʵ��
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CMy01_���ֹ����ʵ��Dlg �Ի���



CMy01_���ֹ����ʵ��Dlg::CMy01_���ֹ����ʵ��Dlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_MY01__DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
#pragma region AutoFit
	m_ptMinTrackSize.x = 0;
	m_ptMinTrackSize.y = 0;
#pragma endregion

}

#pragma region AutoFit
CMy01_���ֹ����ʵ��Dlg::~CMy01_���ֹ����ʵ��Dlg()
{
	FreeCtrlInfoList();
}

void CMy01_���ֹ����ʵ��Dlg::SetMinSize(int nWidth, int nHeight)
{
	ASSERT(nWidth > 0);
	ASSERT(nHeight > 0);

	//���ô�����Сֵ
	m_ptMinTrackSize.x = nWidth;
	m_ptMinTrackSize.y = nHeight;
}

void CMy01_���ֹ����ʵ��Dlg::FreeCtrlInfoList()
{
	INT_PTR	nCount = m_listCtrlInfo.GetSize();

	for (int i = 0; i < nCount; i++)
	{
		lpControlInfo pCtrlInfo = m_listCtrlInfo.ElementAt(i);
		delete pCtrlInfo;
	}

	m_listCtrlInfo.RemoveAll();
}

void CMy01_���ֹ����ʵ��Dlg::MakeCtrlFit(CWnd* pWnd, int nMoveXPercent, int nMoveYPercent, int nZoomXPercent, int nZoomYPercent)
{
	ASSERT(pWnd);									//ָ���Ƿ�Ϊ��
	ASSERT(nMoveXPercent >= 0 && nMoveXPercent <= 100);	//nMoveXPercentֵ�Ƿ���Ч
	ASSERT(nMoveYPercent >= 0 && nMoveYPercent <= 100);	//nMoveXPercentֵ�Ƿ���Ч
	ASSERT(nZoomXPercent >= 0 && nZoomXPercent <= 100);	//nMoveXPercentֵ�Ƿ���Ч
	ASSERT(nZoomYPercent >= 0 && nZoomYPercent <= 100);	//nMoveXPercentֵ�Ƿ���Ч

	lpControlInfo	pCtrlInfo = new ControlInfo;	//�����ṹָ��

													//������
	pCtrlInfo->m_pWnd = pWnd;
	pCtrlInfo->m_nMoveXPercent = nMoveXPercent;
	pCtrlInfo->m_nMoveYPercent = nMoveYPercent;
	pCtrlInfo->m_nZoomXPercent = nZoomXPercent;
	pCtrlInfo->m_nZoomYPercent = nZoomYPercent;

	pWnd->GetWindowRect(pCtrlInfo->m_rectWnd);
	ScreenToClient(&pCtrlInfo->m_rectWnd);

	m_listCtrlInfo.Add(pCtrlInfo);	//����ά���б�
}

void CMy01_���ֹ����ʵ��Dlg::CancelCtrlFit(HWND hWnd)
{
	INT_PTR	nCount = m_listCtrlInfo.GetSize();

	for (int i = 0; i < nCount; i++)
	{
		lpControlInfo pCtrlInfo = m_listCtrlInfo.ElementAt(i);
		if (pCtrlInfo->m_pWnd->GetSafeHwnd() == hWnd)
		{
			delete pCtrlInfo;
			m_listCtrlInfo.RemoveAt(i);

			break;
		}
	}
}

void CMy01_���ֹ����ʵ��Dlg::OnSize(UINT nType, int cx, int cy)
{
	//���㴰�ڿ�Ⱥ͸߶ȵĸı���
	int nIncrementX = cx - m_nWinWidth;
	int nIncrementY = cy - m_nWinHeight;

	INT_PTR	nCount = m_listCtrlInfo.GetSize();

	UINT	uFlags = SWP_NOACTIVATE | SWP_NOZORDER | SWP_NOCOPYBITS;
	for (int i = 0; i < nCount; i++)
	{
		//��ȡ�仯����ϵ��
		int	nMoveXPercent = m_listCtrlInfo[i]->m_nMoveXPercent;
		int	nMoveYPercent = m_listCtrlInfo[i]->m_nMoveYPercent;
		int	nZoomXPercent = m_listCtrlInfo[i]->m_nZoomXPercent;
		int	nZoomYPercent = m_listCtrlInfo[i]->m_nZoomYPercent;

		CWnd*	pWndCtrl = m_listCtrlInfo[i]->m_pWnd;
		HWND	hWnd = pWndCtrl->GetSafeHwnd();
		if ((NULL != pWndCtrl) && IsWindow(hWnd))
		{
			int nLeft = m_listCtrlInfo[i]->m_rectWnd.left;
			int nTop = m_listCtrlInfo[i]->m_rectWnd.top;
			int nWidth = m_listCtrlInfo[i]->m_rectWnd.Width();
			int nHeight = m_listCtrlInfo[i]->m_rectWnd.Height();

			//�����µ�λ�ò���
			nLeft += (nIncrementX*nMoveXPercent / 100);
			nTop += (nIncrementY*nMoveYPercent / 100);
			nWidth += (nIncrementX*nZoomXPercent / 100);
			nHeight += (nIncrementY*nZoomYPercent / 100);

			//  �ѿؼ��ƶ�����λ��
			pWndCtrl->MoveWindow(nLeft, nTop, nWidth, nHeight);
		}
	}

	CDialogEx::OnSize(nType, cx, cy);
	// TODO: �ڴ˴������Ϣ����������
}

void CMy01_���ֹ����ʵ��Dlg::OnGetMinMaxInfo(MINMAXINFO* lpMMI)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	//���ô��ڵ���С��С
	lpMMI->ptMinTrackSize = m_ptMinTrackSize;

	CDialogEx::OnGetMinMaxInfo(lpMMI);
}

#pragma endregion



void CMy01_���ֹ����ʵ��Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CMy01_���ֹ����ʵ��Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_WM_SIZE()
	ON_WM_GETMINMAXINFO()
	ON_WM_NCPAINT()
	ON_WM_ERASEBKGND()
	ON_WM_ENTERSIZEMOVE()
	ON_WM_EXITSIZEMOVE()
	ON_WM_NCCALCSIZE()
END_MESSAGE_MAP()


// CMy01_���ֹ����ʵ��Dlg ��Ϣ�������

BOOL CMy01_���ֹ����ʵ��Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// ��������...���˵�����ӵ�ϵͳ�˵��С�

	// IDM_ABOUTBOX ������ϵͳ���Χ�ڡ�
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// ���ô˶Ի����ͼ�ꡣ  ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	// TODO: �ڴ���Ӷ���ĳ�ʼ������
#pragma region AutoFit
	CRect	rectTemp;

	//��ȡ�ͻ�����С
	GetClientRect(rectTemp);
	//����ͻ�����Ϣ
	m_nWinWidth = rectTemp.Width();
	m_nWinHeight = rectTemp.Height();
	//��ȡ���ڴ�С
	GetWindowRect(rectTemp);
	//���ô�����Сֵ
	SetMinSize(rectTemp.Width(), rectTemp.Height());

	//����ؼ�
	MakeCtrlFit(GetDlgItem(IDC_BUTTON2), 33);
	MakeCtrlFit(GetDlgItem(IDC_BUTTON3), 66);
	MakeCtrlFit(GetDlgItem(IDC_BUTTON4), 100);

	MakeCtrlFit(GetDlgItem(IDC_EDIT1), 0, 0, 50, 50);
	MakeCtrlFit(GetDlgItem(IDC_EDIT2), 50, 0, 50, 50);
	MakeCtrlFit(GetDlgItem(IDC_EDIT3), 0, 50, 50, 50);
	MakeCtrlFit(GetDlgItem(IDC_PIC), 50, 50, 50, 50);

	MakeCtrlFit(GetDlgItem(IDOK), 100, 100);
	MakeCtrlFit(GetDlgItem(IDCANCEL), 100, 100);
#pragma endregion
	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

void CMy01_���ֹ����ʵ��Dlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ  ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CMy01_���ֹ����ʵ��Dlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // ���ڻ��Ƶ��豸������

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// ʹͼ���ڹ����������о���
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// ����ͼ��
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù��
//��ʾ��
HCURSOR CMy01_���ֹ����ʵ��Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



//void CMy01_���ֹ����ʵ��Dlg::OnNcPaint()
//{
//	// TODO: �ڴ˴������Ϣ����������
//	// ��Ϊ��ͼ��Ϣ���� CDialogEx::OnNcPaint()
//}


BOOL CMy01_���ֹ����ʵ��Dlg::OnEraseBkgnd(CDC* pDC)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ

	return CDialogEx::OnEraseBkgnd(pDC);
}


void CMy01_���ֹ����ʵ��Dlg::OnEnterSizeMove()
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	cout << "OnEnterSizeMove" << endl;
	CDialogEx::OnEnterSizeMove();
}


void CMy01_���ֹ����ʵ��Dlg::OnExitSizeMove()
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	cout << "OnExitSizeMove" << endl;

	CDialogEx::OnExitSizeMove();
}


void CMy01_���ֹ����ʵ��Dlg::OnNcCalcSize(BOOL bCalcValidRects, NCCALCSIZE_PARAMS* lpncsp)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	cout << "OnNcCalcSize" << endl;

	CDialogEx::OnNcCalcSize(bCalcValidRects, lpncsp);
}
