
// 04_�����½���Dlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "04_�����½���.h"
#include "04_�����½���Dlg.h"
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


// CMy04_�����½���Dlg �Ի���



CMy04_�����½���Dlg::CMy04_�����½���Dlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_MY04__DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMy04_�����½���Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CMy04_�����½���Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BTN_CREATEPROCESS, &CMy04_�����½���Dlg::OnBnClickedBtnCreateprocess)
END_MESSAGE_MAP()


// CMy04_�����½���Dlg ��Ϣ�������

BOOL CMy04_�����½���Dlg::OnInitDialog()
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

void CMy04_�����½���Dlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CMy04_�����½���Dlg::OnPaint()
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
HCURSOR CMy04_�����½���Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


void StartProcess(LPCTSTR szCmdLine);
void CMy04_�����½���Dlg::OnBnClickedBtnCreateprocess()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������

	//STARTUPINFO si;
	//PROCESS_INFORMATION pi;

	//ZeroMemory(&si, sizeof(si));
	//si.cb = sizeof(si);
	////si.wShowWindow = SW_HIDE; //default is SW_SHOW
	//ZeroMemory(&pi, sizeof(pi));
	//LPTSTR szCmdline = _tcsdup(TEXT("calc.exe"));

	//// Start the child process. 
	//if (!CreateProcess(NULL,   // No module name (use command line)
	//	szCmdline,        // Command line
	//	NULL,           // Process handle not inheritable
	//	NULL,           // Thread handle not inheritable
	//	FALSE,          // Set handle inheritance to FALSE
	//	0,              // No creation flags
	//	NULL,           // Use parent's environment block
	//	NULL,           // Use parent's starting directory 
	//	&si,            // Pointer to STARTUPINFO structure
	//	&pi)           // Pointer to PROCESS_INFORMATION structure
	//	)
	//{
	//	printf("CreateProcess failed (%d).\n", GetLastError());
	//	return;
	//}

	//// Wait until child process exits.
	////WaitForSingleObject(pi.hProcess, INFINITE);

	//// Close process and thread handles. 
	//CloseHandle(pi.hProcess);
	//CloseHandle(pi.hThread);
	//delete[] szCmdline; //_tcsdup�Ƕ��Ϸ�����ڴ�

	StartProcess(_T("Calc.exe"));
}


void StartProcess(LPCTSTR cmdLine)
{
	STARTUPINFO si;
	PROCESS_INFORMATION pi;

	ZeroMemory(&si, sizeof(si));
	si.cb = sizeof(si);
	//si.wShowWindow = SW_HIDE; //default is SW_SHOW
	ZeroMemory(&pi, sizeof(pi));
	LPTSTR szCmdline = _tcsdup(cmdLine);

	// Start the child process. 
	if (!CreateProcess(NULL,   // No module name (use command line)
		szCmdline,        // Command line
		NULL,           // Process handle not inheritable
		NULL,           // Thread handle not inheritable
		FALSE,          // Set handle inheritance to FALSE
		0,              // No creation flags
		NULL,           // Use parent's environment block
		NULL,           // Use parent's starting directory 
		&si,            // Pointer to STARTUPINFO structure
		&pi)           // Pointer to PROCESS_INFORMATION structure
		)
	{
		printf("CreateProcess failed (%d).\n", GetLastError());
		AfxMessageBox(_T("Error on createProcess,please check the path is right!"));
		delete[] szCmdline; //_tcsdup�Ƕ��Ϸ�����ڴ�
		return;
	}

	// Wait until child process exits.
	//WaitForSingleObject(pi.hProcess, INFINITE);

	// Close process and thread handles. 
	CloseHandle(pi.hProcess);
	CloseHandle(pi.hThread);
	delete[] szCmdline; //_tcsdup�Ƕ��Ϸ�����ڴ�
}
