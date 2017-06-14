#include "stdafx.h"
#include "YXPFileIO.h"

using namespace std;

YXPFileIO::YXPFileIO()
{
}


YXPFileIO::~YXPFileIO()
{
}


//����ָ��Ŀ¼���丸Ŀ¼�������
bool YXPFileIO::FindOrCreateDirectory(const char *pszPath)
{
	USES_CONVERSION;
	WIN32_FIND_DATA fd;
	HANDLE hFind = ::FindFirstFileW(A2W(pszPath), &fd);
	while (hFind != INVALID_HANDLE_VALUE)
	{
		if (fd.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY)
		{
			//::AfxMessageBox(_T("Ŀ¼���ڣ�"));
			return true;
		}
	}

	if (!::CreateDirectory(A2W(pszPath), NULL))
	{
		//char szDir[MAX_PATH];
		::AfxMessageBox(_T("����Ŀ¼ʧ��"));
		return false;
	}
	else
	{
		return true;
		//::AfxMessageBox(_T("����Ŀ¼�ɹ�"));
	}
}



// �ж�Ŀ¼�Ƿ����(/��\\�����ԣ����󲻴���\\������)  
bool YXPFileIO::FolderExists(CString s)
{
	DWORD attr;
	attr = GetFileAttributes(s);
	return (attr != (DWORD)(-1)) &&
		(attr & FILE_ATTRIBUTE_DIRECTORY);
}

bool YXPFileIO::FileExists(CString s)
{
	DWORD attr;
	attr = GetFileAttributes(s);
	return (attr != (DWORD)(-1)) &&
		(attr & FILE_ATTRIBUTE_ARCHIVE); //���������صĻ���ֻ���Ķ��ܼ�⵽
}


// �ݹ鴴��Ŀ¼������ʹ��/��ֻ��\\�����󲻴���\\������)
// ���Ŀ¼�Ѿ����ڻ��ߴ����ɹ�����TRUE  
bool YXPFileIO::SuperMkDir(CString P)
{
	int len = P.GetLength();
	if (len < 2) return false;

	if ('\\' == P[len - 1])
	{
		P = P.Left(len - 1);
		len = P.GetLength();
	}
	if (len <= 0) return false;

	if (len <= 3)
	{
		if (FolderExists(P))return true;
		else return false;
	}

	if (FolderExists(P))return true;

	CString Parent;
	Parent = P.Left(P.ReverseFind('\\'));

	if (Parent.GetLength() <= 0)return false;

	bool Ret = SuperMkDir(Parent);

	if (Ret)
	{
		SECURITY_ATTRIBUTES sa;
		sa.nLength = sizeof(SECURITY_ATTRIBUTES);
		sa.lpSecurityDescriptor = NULL;
		sa.bInheritHandle = 0;
		Ret = (CreateDirectory(P, &sa) == TRUE);
		return Ret;
	}
	else
		return false;
}


//ȡ��ָ���ļ����µ��ļ����ļ������ƣ����ݹ飬ֻȡһ��Ŀ¼����ȫ����\\������/��������Դ�\\(�޸���),
void YXPFileIO::GetDirectoryFiles(const string &strFolder,
	vector<string> &strVecFileNames,
	bool OnlyFiles,
	bool OnlyDirectories,
	const string &extInclude,
	const string &extExclude)
{
	USES_CONVERSION;
	if (OnlyFiles&&OnlyDirectories)  //���������ѡ�У���ô���������ļ���ֱ��Ĭ�ϲ�ѡ��
	{
		OnlyFiles = false;
		OnlyDirectories = false;
	}

	strVecFileNames.clear();
	struct _finddata_t filefind;
	string  curr = strFolder + "\\*.*";
	int  done = 0;
	int  handle;
	if ((handle = _findfirst(curr.c_str(), &filefind)) == -1)
		return;

	string tempfolder = strFolder;
	if (strFolder[strFolder.size() - 1] != '\\')
	{
		tempfolder += "\\";
	}

	while (!(done = _findnext(handle, &filefind)))
	{
		if (!strcmp(filefind.name, ".."))  //�ô˷�����һ���ҵ����ļ�����Զ��".."��������Ҫ�����ж�
			continue;
		if (OnlyFiles)
		{
			//TODO::����Ӧ�û�һ�²�Ҫ��A2W,�����ļ��������ܻ�ܵ�
			CString temp = A2W((tempfolder + filefind.name).c_str());
			if (FileExists(temp))
			{
				strVecFileNames.push_back(tempfolder + filefind.name);
			}
		}
		else if (OnlyDirectories)
		{
			CString temp = A2W((tempfolder + filefind.name).c_str());
			if (FolderExists(temp))
			{
				strVecFileNames.push_back(tempfolder + filefind.name);
			}
		}
		else
		{
			strVecFileNames.push_back(tempfolder + filefind.name);
		}

	}
	_findclose(handle);
}