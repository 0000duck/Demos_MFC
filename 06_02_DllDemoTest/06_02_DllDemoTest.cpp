// 06_02_DllDemoTest.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <iostream>
using namespace std;

#pragma region DLL����ʾ��
//һ��Ҫ���������ط���һ����ͷ�ļ���һ����.dll�ļ���һ����.lib�ļ�
#include <DllDemo.h>
#pragma comment(lib,"06_01_DllDemo.lib")
#include <06_02_DllDemo2.h>
#pragma comment(lib,"06_02_DllDemo2.lib")
#include <Dll1.h>
#pragma comment(lib,"Dll1.lib")

//lib �ļ�ѡ������Ŀ���ԣ�������-����-���ӿ�Ŀ¼
//.h �ļ�����Ŀ���ԣ�C\C++-����-��������Ŀ¼,��dllmain�Ĳ���Ҫdllmain.cpp��ֻ��Ҫͷ�ļ�
//dll �ļ�Ҫ��ͬһĿ¼(���Ը��ģ���ͨ��������������)
#pragma endregion


#pragma region ����DllĿ¼�Ĵ���

//Ӧ�ó���ʹ��LoadLibrary��ʽ���ӣ���ô����������Ĳ����п���ָ��DLL�ļ�������·����
//�����ָ��·�������ǽ�����ʽ���ӣ�Windows����ѭ���������˳������λDLL��
//1�� ����EXE�ļ���Ŀ¼��
//2�� ���̵ĵ�ǰ����Ŀ¼��
//3�� WindowsϵͳĿ¼��
//4�� WindowsĿ¼��
//5�� ����Path���������е�һϵ��Ŀ¼��
#pragma endregion

#pragma region ����dll����Ŀ¼��һ�㶼���ã��ͷ�exe��ͬĿ¼���
//����һ��
//
//ѡ��ǰ���̣��һ�
//"Properties" -> "Configuration Properties" -> "Debugging"��
//��"Working Directory"����dll��·���Ϳ�����

//����������ʾָ��
//CString strDllPath = GetExePath() + _T("System");
//SetDllDirectory(strDllPath);

//��������������Ŀ�Ļ�������

#pragma endregion


int main()
{
	int c = Add(1, 2); //���Կ�����һ�������������ģ�ֱ�Ӿ��ܵ��Ե��ϵ�
	int d = Sub(2, 1);
	cout << c << endl;

	CMy06_02_DllDemo2 dllClass; //�������dll������dllmain�����Կ���attach��detatch
	int e = fnMy06_02_DllDemo2();
	
	AddClass clsAd; //��ͬ��������ģ���Ҫ����ֱ��F11��ȥ������
	int f = clsAd.output(1, 2);



    return 0;
}

