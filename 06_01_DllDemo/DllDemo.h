#pragma once
//�ú������dll��Ŀ�ڲ�ʹ��__declspec(dllexport)����  
//��dll��Ŀ�ⲿʹ��ʱ����__declspec(dllimport)����  

//Ϊ��ȥ������VC���п������������Ŀ�������棬ʹ�þ�̬MFC


#define DLLDEMO_EXPORTS //ָ����������ʵҲ���Բ��á���
#ifdef DLLDEMO_EXPORTS  
#define DLLDEMO_API __declspec(dllexport)  
#else  
#define DLLDEMO_API __declspec(dllimport)  
#endif 
//#define DLLDEMO_API __declspec(dllexport)
extern "C" DLLDEMO_API int __stdcall Add(int a, int b); //���Extern ��C�� �ú��������������������Բ��ܵ���

extern "C" DLLDEMO_API int __stdcall Sub(int a, int b);