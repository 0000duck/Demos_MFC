
// 02_�ļ�IO����Dlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "02_�ļ�IO����.h"
#include "02_�ļ�IO����Dlg.h"
#include "afxdialogex.h"
#include "YXPFileIO.h"

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


// CMy02_�ļ�IO����Dlg �Ի���



CMy02_�ļ�IO����Dlg::CMy02_�ļ�IO����Dlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_MY02_IO_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMy02_�ļ�IO����Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CMy02_�ļ�IO����Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, &CMy02_�ļ�IO����Dlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CMy02_�ļ�IO����Dlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON3, &CMy02_�ļ�IO����Dlg::OnBnClickedButton3)
END_MESSAGE_MAP()


// CMy02_�ļ�IO����Dlg ��Ϣ�������

BOOL CMy02_�ļ�IO����Dlg::OnInitDialog()
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

	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

void CMy02_�ļ�IO����Dlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CMy02_�ļ�IO����Dlg::OnPaint()
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
HCURSOR CMy02_�ļ�IO����Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}




void CMy02_�ļ�IO����Dlg::OnBnClickedButton1()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������

	bool b = YXPFileIO::FindOrCreateDirectory("E:\\a\\b");


	bool b1 = YXPFileIO::SuperMkDir(_T("E:\\a1\\b1"));
	bool b2 = YXPFileIO::SuperMkDir(_T("E:\\a2\\b2\\"));
	bool b3 = YXPFileIO::SuperMkDir(_T("E:/a3/b3")); //������/

}


void CMy02_�ļ�IO����Dlg::OnBnClickedButton2()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	bool b = YXPFileIO::FolderExists(_T("E:\\caffe-windows\\"));
	bool b2 = YXPFileIO::FolderExists(_T("E:\\caffe-windows"));
	bool b3 = YXPFileIO::FolderExists(_T("E:/caffe-windows/"));
	bool b1 = YXPFileIO::FolderExists(_T("E:\\caffe-windows1\\"));//false
	bool b4 = YXPFileIO::FolderExists(_T("E:\\"));
}


void CMy02_�ļ�IO����Dlg::OnBnClickedButton3()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	using namespace std;
	vector<string> vecFiles;
	YXPFileIO::GetDirectoryFiles("E:\\caffe-windows", vecFiles,"","");//�õ����ļ��в���\\��

	//�������ִ����÷�
	YXPFileIO::GetDirectoryFiles("E:\\caffe-windows\\", vecFiles, "", ""); //��Ҫ�����\\��
	YXPFileIO::GetDirectoryFiles("E:/caffe-windows/", vecFiles,"","");//Ҳ��Ҫ��/�������и�ƴ����Ҫ�ǣ��õ�\\���е�ƴ��


}
