// 06_02_DllDemo2.cpp : ���� DLL Ӧ�ó���ĵ���������
//

#include "stdafx.h"
#include "06_02_DllDemo2.h"


// ���ǵ���������һ��ʾ��
MY06_02_DLLDEMO2_API int nMy06_02_DllDemo2=0;

// ���ǵ���������һ��ʾ����
MY06_02_DLLDEMO2_API int fnMy06_02_DllDemo2(void)
{
    return 42;
}

// �����ѵ�����Ĺ��캯����
// �й��ඨ�����Ϣ������� 06_02_DllDemo2.h
CMy06_02_DllDemo2::CMy06_02_DllDemo2()
{
    return;
}
