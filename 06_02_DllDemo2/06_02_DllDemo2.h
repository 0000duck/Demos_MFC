// ���� ifdef ���Ǵ���ʹ�� DLL �������򵥵�
// ��ı�׼�������� DLL �е������ļ��������������϶���� MY06_02_DLLDEMO2_EXPORTS
// ���ű���ġ���ʹ�ô� DLL ��
// �κ�������Ŀ�ϲ�Ӧ����˷��š�������Դ�ļ��а������ļ����κ�������Ŀ���Ὣ
// MY06_02_DLLDEMO2_API ������Ϊ�Ǵ� DLL ����ģ����� DLL ���ô˺궨���
// ������Ϊ�Ǳ������ġ�
#ifdef MY06_02_DLLDEMO2_EXPORTS
#define MY06_02_DLLDEMO2_API __declspec(dllexport)
#else
#define MY06_02_DLLDEMO2_API __declspec(dllimport)
#endif

// �����Ǵ� 06_02_DllDemo2.dll ������
class MY06_02_DLLDEMO2_API CMy06_02_DllDemo2 {
public:
	CMy06_02_DllDemo2(void);
	// TODO:  �ڴ�������ķ�����
};

extern MY06_02_DLLDEMO2_API int nMy06_02_DllDemo2;

MY06_02_DLLDEMO2_API int fnMy06_02_DllDemo2(void);
