#include<stdio.h>
#include<stdlib.h>
class Myclass{
public:
	Myclass()
		:m_nData(10)
		, m_fData(123)
	{

	}
	void Test() const{//���������в������޸��κα���ֵ
		//m_fData = 456;
	}
	void Test1(const char pname){//��ʾ�����в������޸ı���ֵ
		//pname = "aaa";
	}
	void Test1(int* const pname){//ָ�볣����ֵ��ָ�룬���ֵ��Ϊ�ǳ��������Բ��ܱ���ֵ��
		//pname = &m_fData;//��ַ�������޸ģ�ֵ����
		*pname = 2;
	}
	void Test2(const int* pname){//����ָ�룺������ָ�룬��������������ʾ���ָ������һ��ָ������ָ�루������.
		pname = &m_fData;//��ַ�����޸ģ�ֵ����
		//*pname = 2;
	}
	void Test3(const int* const pname){//��ʾ�����в������޸ı���ֵ��ַ��Ҳ�������޸ı���ֵ
		//pname = &m_fData;
		//*pname = 2;
	}

	~Myclass(){

	}

	const int m_nData;//���α�����ʾ�����޸�ֵ
	int m_fData;

};
