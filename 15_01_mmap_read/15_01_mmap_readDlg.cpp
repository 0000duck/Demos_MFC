
// 15_01_mmap_readDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "15_01_mmap_read.h"
#include "15_01_mmap_readDlg.h"
#include "afxdialogex.h"

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


// CMy15_01_mmap_readDlg �Ի���



CMy15_01_mmap_readDlg::CMy15_01_mmap_readDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_MY15_01_MMAP_READ_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMy15_01_mmap_readDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CMy15_01_mmap_readDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BTN_READ_INFO, &CMy15_01_mmap_readDlg::OnBnClickedBtnReadInfo)
END_MESSAGE_MAP()


// CMy15_01_mmap_readDlg ��Ϣ�������

BOOL CMy15_01_mmap_readDlg::OnInitDialog()
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

#pragma region �ڴ�ӳ��

	//��ӳ�����
	m_hMapObject = OpenFileMapping(
		FILE_MAP_READ,   //�ɶ�ӳ��
		FALSE,           //�����̳�
		TEXT("ShareData")//�������ݵ�����
	);
	if (!m_hMapObject)
	{
		AfxMessageBox(TEXT("��ӳ��ʧ��"));
		return FALSE;
	}
	//��ȡ��������,ֻҪ�õ���鹲���ڴ�ĵ�ַ,ֻҪ��������ݷ����ı�,m_pszMapViewҲ����Ÿı�
	m_pszMapView = (LPTSTR)MapViewOfFile(m_hMapObject, FILE_SHARE_READ, 0, 0, 0);
	if (!m_pszMapView)
	{
		AfxMessageBox(TEXT("��ȡӳ������ʧ��"));
		return FALSE;
	}

	//����һ����ʱ��,һ�����ʱ����ʾ�����յ�����
	/*SetTimer(1, 50, nullptr);*/

#pragma endregion



	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

void CMy15_01_mmap_readDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CMy15_01_mmap_readDlg::OnPaint()
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
HCURSOR CMy15_01_mmap_readDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CMy15_01_mmap_readDlg::OnBnClickedBtnReadInfo()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������

	

	SetDlgItemTextW(IDC_EDIT_READINFO, m_pszMapView);
}
