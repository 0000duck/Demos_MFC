#include <iostream>


//�ܽ�:��̬���ʹ�÷�Ϊ����
//1.������̬�⣬�½���Ŀ����Ϊ��̬�����ͼ��ɣ�Ȼ������.lib�ļ�
//2.ʹ�þ�̬��,ָ����̬��·��(���ӿ�Ŀ¼)��ָ���������������ֱ��#pragma comment(lib,"xxx")
//Ҳ������ʱ��ʽָ��·�������У�����ֻҪ���ҵ�·�������ˣ�Ȼ����ͷ�ļ���Ҳ�����Ƶģ�ֻҪ���ҵ����С�

#include "../06_03_LibDemo/libDemo.h"
#pragma comment(lib,"../Debug/06_03_LibDemo.lib")
int main() 
{
	int i = LibDemo1Func();

	std::cout << i << std::endl;
	system("pause");
	return 0;

}

