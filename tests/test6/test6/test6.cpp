#include "iostream"
using namespace std;
/*
	����һ���������ؼ���const����������ʱ�����ʼ��
	#define ��һ�ֶ��峣���ķ���
*/
#define PI 3.1415926;//��ʱ����

void main(){
	const float pi = 3.1415926;
	//������ֵ��һ���������ʽ�������ܺ���ĳ������
	/*
		const int size=100*sizeof(int) //OK
		const int number = max(12,23)  //error
	*/
	cout << PI;
}