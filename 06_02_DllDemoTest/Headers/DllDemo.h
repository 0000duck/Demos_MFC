#pragma once
//�ú������dll��Ŀ�ڲ�ʹ��__declspec(dllexport)����  
//��dll��Ŀ�ⲿʹ��ʱ����__declspec(dllimport)����  
//��DLL_IMPLEMENT��SimpleDLL.cpp�ж���  

//Ϊ��ȥ������VC���п������������Ŀ�������棬ʹ�þ�̬MFC

#ifdef DLL_IMPLEMENT  
#define DLL_API __declspec(dllexport)  
#else  
#define DLL_API __declspec(dllimport)  
#endif 
#define DLLDEMO_API __declspec(dllexport)
extern "C" DLLDEMO_API int __stdcall Add(int a, int b); //���Extern ��C�� �ú��������������������Բ��ܵ���

extern "C" DLLDEMO_API int __stdcall Sub(int a, int b);