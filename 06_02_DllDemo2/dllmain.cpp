// dllmain.cpp : ���� DLL Ӧ�ó������ڵ㡣
#include "stdafx.h"
#include <iostream>
using namespace std;


//DllMain������DLLģ���Ĭ����ڵ㡣��Windows����DLLģ��ʱ������һ������
//ϵͳ���ȵ���ȫ�ֶ���Ĺ��캯����Ȼ�����ȫ�ֺ���DLLMain��
//DLLMain���������ڽ�DLL���Ӽ��ص�����ʱ�����ã���DLLģ������̷���ʱ���Լ�����ʱ��Ҳ�����á�

//APIENTRY����DLL������ڵ�
BOOL APIENTRY DllMain(HMODULE hModule,
	DWORD  ul_reason_for_call,
	LPVOID lpReserved
)
{
	switch (ul_reason_for_call)
	{
	case DLL_PROCESS_ATTACH:
		cout << "DLL_PROCESS_ATTACH" << endl;
		break;
	case DLL_THREAD_ATTACH:
		cout << "DLL_THREAD_ATTACH" << endl;
		break;
	case DLL_THREAD_DETACH:
		cout << "DLL_THREAD_DETACH" << endl;
		break;
	case DLL_PROCESS_DETACH:
		cout << "DLL_PROCESS_DETACH" << endl;
		break;
	}
	return TRUE;
}

//�������Աû��ΪDLLģ���дһ��DLLMain������
//ϵͳ����������п�������һ�������κβ�����ȱʡDLLMain
//�����汾���ڵ����߳���������ֹʱ��DLLMain����Ҳ�����á�