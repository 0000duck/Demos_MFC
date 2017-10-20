
// 16_01_pipeDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "16_01_pipe.h"
#include "16_01_pipeDlg.h"
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


// CMy16_01_pipeDlg �Ի���



CMy16_01_pipeDlg::CMy16_01_pipeDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_MY16_01_PIPE_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMy16_01_pipeDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CMy16_01_pipeDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, &CMy16_01_pipeDlg::OnBnClickedButton1)
END_MESSAGE_MAP()


// CMy16_01_pipeDlg ��Ϣ�������

BOOL CMy16_01_pipeDlg::OnInitDialog()
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
	SetDlgItemTextW(IDC_EDITCMD, _T("ipconfig.exe"));
	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

void CMy16_01_pipeDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CMy16_01_pipeDlg::OnPaint()
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
HCURSOR CMy16_01_pipeDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CMy16_01_pipeDlg::OnBnClickedButton1()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	SetDlgItemTextW(IDC_EDITRESULT, _T(""));
	CString               m_Host;
	CString               strCmd;
	GetDlgItemText(IDC_EDITCMD,strCmd);
	m_Host = _T("c:\\windows\\system32\\") + strCmd;  //strCmd = "ipconfig.exe"  

													  //�����ܵ�  
	HANDLE                   hReadPipe;
	HANDLE                   hWritePipe;
	SECURITY_ATTRIBUTES      sat;                            //��ȫ���Խṹ  
	sat.nLength = sizeof(SECURITY_ATTRIBUTES);  //�ṹ���С  
	sat.bInheritHandle = true;                         //ָ����ȫ�������Ķ����ܷ��½��̼̳�  
	sat.lpSecurityDescriptor = NULL;                         //��ȫ������,NULL: ʹ��Ĭ�ϵ�   
	if (!CreatePipe(&hReadPipe, &hWritePipe, &sat, NULL))
	{
		MessageBox(_T("Create Pipe Error!"));
		return;
	}

	//��������  
	STARTUPINFO                 startupinfo;             //������Ϣ  
	PROCESS_INFORMATION   pinfo;
	startupinfo.cb = sizeof(STARTUPINFO); //�ṹ���С   
	GetStartupInfo(&startupinfo);                  //��ȡ��ǰ���̵���Ϣ  
	startupinfo.dwFlags = STARTF_USESHOWWINDOW | STARTF_USESTDHANDLES;
	startupinfo.hStdError = hWritePipe;
	startupinfo.hStdOutput = hWritePipe;
	startupinfo.wShowWindow = SW_HIDE;
	if (!CreateProcess(NULL, m_Host.GetBuffer(), NULL, NULL,
		TRUE, NULL, NULL, NULL, &startupinfo, &pinfo))
	{
		MessageBox(_T("create process error!"));
		return;
	}
	CloseHandle(hWritePipe); //�����̹ر�д��

	//��ȡ�ܵ���Ϣ  
	BYTE       buffer[1024];
	DWORD    byteRead;
	while (true)
	{
		RtlZeroMemory(buffer, 1024);
		if (ReadFile(hReadPipe, buffer, 1023, &byteRead, NULL) == NULL) //������ķ��ؿ��˾ʹ���д���Ѿ��رղ��Ҷ�����
		{
			break;
		}
		CString str(buffer);
		CString preTxt;
		GetDlgItemText(IDC_EDITRESULT, preTxt);
		SetDlgItemTextW(IDC_EDITRESULT, preTxt + str);
	
	}
	CloseHandle(hReadPipe);
	m_Host.ReleaseBuffer();

}
