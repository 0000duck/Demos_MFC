
// 02_�ļ�IO����Dlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "02_�ļ�IO����.h"
#include "02_�ļ�IO����Dlg.h"
#include "afxdialogex.h"
#include "YXPFileIO.h"
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
	ON_BN_CLICKED(IDC_BUTTON4, &CMy02_�ļ�IO����Dlg::OnBnClickedButton4)
	ON_BN_CLICKED(IDC_BUTTON5, &CMy02_�ļ�IO����Dlg::OnBnClickedButton5)
	ON_BN_CLICKED(IDC_BUTTON6, &CMy02_�ļ�IO����Dlg::OnBnClickedButton6)
	ON_BN_CLICKED(IDC_BUTTON7, &CMy02_�ļ�IO����Dlg::OnBnClickedButton7)
	ON_BN_CLICKED(IDC_BUTTON8, &CMy02_�ļ�IO����Dlg::OnBnClickedButton8)
	ON_BN_CLICKED(IDC_BUTTON9, &CMy02_�ļ�IO����Dlg::OnBnClickedButton9)
	ON_BN_CLICKED(IDC_BUTTON10, &CMy02_�ļ�IO����Dlg::OnBnClickedButton10)
	ON_BN_CLICKED(IDC_BUTTON11, &CMy02_�ļ�IO����Dlg::OnBnClickedButton11)
	ON_BN_CLICKED(IDC_BUTTON12, &CMy02_�ļ�IO����Dlg::OnBnClickedButton12)
	ON_BN_CLICKED(IDC_BUTTON13, &CMy02_�ļ�IO����Dlg::OnBnClickedButton13)
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

	//bool b = YXPFileIO::FindOrCreateDirectory("E:\\a\\����");


	bool b1 = YXPFileIO::RecurMkDir("E:\\a1\\b1");
	 b1 = YXPFileIO::RecurMkDir("E:\\a1\\����");

	//bool b2 = YXPFileIO::SuperMkDir(_T("E:\\a2\\b2\\"));
	//bool b3 = YXPFileIO::SuperMkDir(_T("E:/a3/b3")); //������/

}


void CMy02_�ļ�IO����Dlg::OnBnClickedButton2()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	bool b = YXPFileIO::FolderExists(("E:\\caffe-windows\\"));
	bool b2 = YXPFileIO::FolderExists(("E:\\caffe-windows"));
	bool b3 = YXPFileIO::FolderExists(("E:/caffe-windows/"));
	bool b1 = YXPFileIO::FolderExists(("E:\\caffe-windows1\\"));//false
	bool b4 = YXPFileIO::FolderExists(("E:\\"));
}


void CMy02_�ļ�IO����Dlg::OnBnClickedButton3()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	using namespace std;
	vector<string> vecFiles;
	//YXPFileIO::GetDirectoryFiles("E:\\caffe-windows", vecFiles, true);//�õ����ļ��в���\\���������ļ�

	//
	//YXPFileIO::GetDirectoryFiles("E:\\caffe-windows\\", vecFiles, false, true); //������Դ�\\(�޸���)���������ļ���
	//YXPFileIO::GetDirectoryFiles("E:\\caffe-windows\\", vecFiles, true, true); //�ļ���+�ļ�

	////��������÷�
	//YXPFileIO::GetDirectoryFiles("E:/caffe-windows/", vecFiles);//Ҳ��Ҫ��/�������и�ƴ����Ҫ�ǣ��õ�\\���е�ƴ��

	string path(YXPFileIO::BrowseFolder("��ѡ��Ҫ�򿪵�Ŀ¼",this->m_hWnd));
	YXPFileIO::GetDirectoryFiles((path), vecFiles, true, false, ".docx");
	YXPFileIO::GetDirectoryFiles((path), vecFiles, true, false, "",".rar");
	YXPFileIO::GetDirectoryFiles((path), vecFiles, false, false, "", ".rar");


}


void CMy02_�ļ�IO����Dlg::OnBnClickedButton4()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������


//#define FILE_SHARE_READ                 0x00000001  
//#define FILE_SHARE_WRITE                0x00000002  
//#define FILE_SHARE_DELETE               0x00000004  
//#define FILE_ATTRIBUTE_READONLY             0x00000001  
//#define FILE_ATTRIBUTE_HIDDEN               0x00000002  
//#define FILE_ATTRIBUTE_SYSTEM               0x00000004  
//#define FILE_ATTRIBUTE_DIRECTORY            0x00000010  
//#define FILE_ATTRIBUTE_ARCHIVE              0x00000020  
//#define FILE_ATTRIBUTE_DEVICE               0x00000040  
//#define FILE_ATTRIBUTE_NORMAL               0x00000080


	DWORD attr;
	CString path = _T("E:\\Libs_Cpp\\boost_1_64_0\\INSTALL");
	attr = GetFileAttributes(path);
	path = _T("E:\\Libs_Cpp\\boost_1_64_0\\test1.txt"); //ͨ���ļ�����FILE_ATTRIBUTE_ARCHIVE,�������֮�������صĻ��ͻ�FILE_ATTRIBUTE_HIDDEN�����Ǽӣ���ֻ������
	attr = GetFileAttributes(path);
	path = _T("E:\\Libs_Cpp\\boost_1_64_0\\test2.txt");
	attr = GetFileAttributes(path);
	path = _T("E:\\Libs_Cpp\\boost_1_64_0\\test4.txt");
	attr = GetFileAttributes(path);

	path = _T("E:\\Libs_Cpp\\boost_1_64_0\\test5");
	attr = GetFileAttributes(path);
	path = _T("E:\\Libs_Cpp\\boost_1_64_0\\test5.txt"); //�����ھ���-1
	attr = GetFileAttributes(path);

	bool b1 = (DWORD)-1 == attr;

	bool b = (attr != (DWORD)(-1)) &&
		(attr & FILE_ATTRIBUTE_DIRECTORY);
}


void CMy02_�ļ�IO����Dlg::OnBnClickedButton5()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������

	string selectedFolder = YXPFileIO::BrowseFolder("",this->m_hWnd);
	MessageBox(CString(selectedFolder.c_str()));
}


void CMy02_�ļ�IO����Dlg::OnBnClickedButton6()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	string selectedFolder = YXPFileIO::BrowseFolder("", this->m_hWnd);
	YXPFileIO::DeleteDirectory((selectedFolder),false);

}


void CMy02_�ļ�IO����Dlg::OnBnClickedButton7()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	USES_CONVERSION;
	MessageBox(A2W(YXPFileIO::GetFileNameNoExt("E:\\DSD\\A.TXT").c_str()));
	MessageBox(A2W(YXPFileIO::GetFileNameNoExt("A.TXT").c_str()));
	MessageBox(A2W(YXPFileIO::GetFileNameNoPath("E:\\DSD\\A.TXT").c_str()));

}


void CMy02_�ļ�IO����Dlg::OnBnClickedButton8()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	USES_CONVERSION;

	MessageBox(A2W(YXPFileIO::GetFileNameExt("E:\\DSD\\A.TXT").c_str()));

}


void CMy02_�ļ�IO����Dlg::OnBnClickedButton9()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������

	MessageBox(YXPFileIO::CheckFileExt("A.txt",".TXT")?L"True":L"False");
	MessageBox(YXPFileIO::CheckFileExt("A.txt", ".txt") ? L"True" : L"False");
	MessageBox(YXPFileIO::CheckFileExt("A.txt", ".tx") ? L"True" : L"False");


}


void CMy02_�ļ�IO����Dlg::OnBnClickedButton10()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������

	bool b = YXPFileIO::Rename("E:\\a","E:\\b");
	b = YXPFileIO::Rename("E:\\a", "E:\\b",true);

	//int i = rename("E:\\a", "E:\\b");

}


void CMy02_�ļ�IO����Dlg::OnBnClickedButton11()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	USES_CONVERSION;
	
	AfxMessageBox(A2W(YXPFileIO::GetAppStdStringPath().c_str()));
}


void CMy02_�ļ�IO����Dlg::OnBnClickedButton12()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������

	bool b = YXPFileIO::CopyDirFiles("E:\\a", "E:\\b", false);

}


void CMy02_�ļ�IO����Dlg::OnBnClickedButton13()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	std::string str = YXPFileIO::BrowseFile();

}
