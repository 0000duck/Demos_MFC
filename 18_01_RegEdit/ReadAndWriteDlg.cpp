
// ReadAndWriteDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "ReadAndWrite.h"
#include "ReadAndWriteDlg.h"
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


// CReadAndWriteDlg �Ի���



CReadAndWriteDlg::CReadAndWriteDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_READANDWRITE_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CReadAndWriteDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CReadAndWriteDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, &CReadAndWriteDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CReadAndWriteDlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON3, &CReadAndWriteDlg::OnBnClickedButton3)
END_MESSAGE_MAP()


// CReadAndWriteDlg ��Ϣ�������

BOOL CReadAndWriteDlg::OnInitDialog()
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

void CReadAndWriteDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CReadAndWriteDlg::OnPaint()
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
HCURSOR CReadAndWriteDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


//д�ı���д��ֵ���͵�����
void CReadAndWriteDlg::OnBnClickedButton1()
{
	HKEY hKey = nullptr;
	//�����ɹ�,���õ�hKey,һ��ע�����,�����������ע���
	if (ERROR_SUCCESS != RegCreateKey(HKEY_CURRENT_USER, TEXT("SoftWare\\Test"), &hKey))
	{
		AfxMessageBox(TEXT("����ע���ʧ��"));
		return;
	}
	//д��ע��� //����  //���� //�ַ�����
	//ֻ��д��һ��value
	if (ERROR_SUCCESS != RegSetValueA(hKey, "subkey", REG_SZ, "Test", 4)) //subkey��������ļ�����
	{
		AfxMessageBox(TEXT("д��ע���ʧ��"));
		return;
	}
	if (hKey == nullptr)
	{
		return;
	}
	DWORD dwData = 100;
	LONG lRet = 0;
	//�����������д������Value                      //����            //����        //����
	if (ERROR_SUCCESS != (lRet = RegSetValueEx(hKey, TEXT("other"), 0, REG_DWORD, (CONST BYTE*)&dwData, 4)))
	{
		AfxMessageBox(TEXT("д��ע���ʧ��Ex"));
		return;
	}

	if (ERROR_SUCCESS != (lRet = RegSetValueExA(hKey, TEXT("SubValue1"), 0, REG_SZ, (CONST BYTE*)"abcdef", 6)))
	{
		AfxMessageBox(TEXT("д��ע���ʧ��Ex"));
		return;
	}

	AfxMessageBox(TEXT("д��ע���ɹ�!"));
	RegCloseKey(hKey);
}



//����ֵ���͵�����
void CReadAndWriteDlg::OnBnClickedButton2()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	LONG lValue = 0;
	//�ȶ�ȡ���ݵĳ���
	RegQueryValue(HKEY_CURRENT_USER, TEXT("SoftWare\\Test"), nullptr, &lValue);  //��Ĭ��ֵ
	TCHAR *pBuf = new TCHAR[lValue];
	RegQueryValueA(HKEY_CURRENT_USER, TEXT("SoftWare\\Test"), pBuf, &lValue);
	AfxMessageBox(pBuf);

	HKEY hKey = nullptr;
	DWORD dwTpye = 0;
	DWORD dwValue = sizeof(DWORD);//�����Сһ��Ҫ�������,��������(234)
	LPDWORD dwData = new DWORD;//һ��Ҫ�����ڴ�,����Ҳ�����
	LONG lRet = 0;
	//��ע���
	RegOpenKeyEx(HKEY_CURRENT_USER, TEXT("SoftWare\\Test"), 0, KEY_ALL_ACCESS, &hKey);
	//RegOpenKey(HKEY_LOCAL_MACHINE, TEXT("SoftWare\\Test"), &hKey);
	//��ע���                                          //valuename      //����value���� //���ݻ����� //��������С
	if (ERROR_SUCCESS != (lRet = RegQueryValueEx(hKey, TEXT("other"), 0, &dwTpye, (LPBYTE)dwData, &dwValue)))
	{
		AfxMessageBox(TEXT("��ȡע���ʧ��!"));
		return;
	}
	AfxMessageBox(TEXT("��ȡע���ɹ�!"));
	CString s;
	s.Format(TEXT("data = %d"), *dwData);
	AfxMessageBox(s);
	delete dwData;


	
	


}

//��ȡ�ı�����ֵ
void CReadAndWriteDlg::OnBnClickedButton3()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������

	HKEY hKey = nullptr;
	DWORD dwTpye = REG_SZ;
	DWORD dwValue = 255;//��СҪ�ͻ�������Сһ�£���Ȼ�ᱨ��ֱ��д��һ���OK��
	LPDWORD dwData = new DWORD;//һ��Ҫ�����ڴ�,����Ҳ�����
	char buf[255];
	LONG lRet = 0;
	//��ע���
	RegOpenKeyEx(HKEY_CURRENT_USER, TEXT("SOFTWARE\\Slice\\Params\\SerialPort"), 0, KEY_ALL_ACCESS, &hKey);
	//RegOpenKey(HKEY_LOCAL_MACHINE, TEXT("SoftWare\\Test"), &hKey);
	//��ע���                                          //valuename      //����value���� //���ݻ����� //��������С
	if (ERROR_SUCCESS != (lRet = RegQueryValueExA(hKey, TEXT("PortName"), 0, &dwTpye, (LPBYTE)buf, &dwValue)))
	{
		AfxMessageBox(TEXT("��ȡע���ʧ��!"));
		return;
	}
	AfxMessageBox(TEXT("��ȡע���ɹ�!"));

	AfxMessageBox(buf);
	delete dwData;


}
