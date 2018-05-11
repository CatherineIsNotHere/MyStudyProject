#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
 
/*
����

1 vector�Ǳ�ʾ�ɱ��С���������������
2 ��������һ����vectorҲ���õ������洢�ռ����洢Ԫ�ء�Ҳ������ζ�ſ��Բ����±��vector
	��Ԫ�ؽ��з��ʣ�������һ����Ч�������ֲ������飬���Ĵ�С�ǿ��Զ�̬�ı�ģ���������
	��С�ᱻ�����Զ�����
3 ���ʽ���vectorʹ�ö�̬�����������洢����Ԫ�ء�����Ԫ�ز���ʱ�����������Ҫ�����·�
	���СΪ�����Ӵ洢�ռ䡣�������ǣ�����һ���µ����飬Ȼ��ȫ��Ԫ���Ƶ�������顣��
	ʱ����ԣ�����һ����Դ��۸ߵ�������Ϊÿ��һ���µ�Ԫ�ؼ��뵽������ʱ��vector��
	����ÿ�ζ����·����С��
4 vector����ռ���ԣ�vector�����һЩ����Ŀռ�����Ӧ���ܵ���������Ϊ�洢�ռ��ʵ����
	Ҫ�Ĵ洢�ռ���󡣲�ͬ�Ŀ���ò�ͬ�Ĳ���Ȩ��ռ��ʹ�ú����·��䡣����������Σ���
	�·��䶼Ӧ���Ƕ��������ļ����С����������ĩβ����һ��Ԫ�ص�ʱ�����ڳ���ʱ��ĸ���
	����ɵġ�
5 ��ˣ�vectorռ���˸���Ĵ洢�ռ䣬Ϊ�˻�ù���洢�ռ��������������һ����Ч�ķ�ʽ��
	̬������
6 ��������̬����������ȣ�deques, lists and forward_lists���� vector�ڷ���Ԫ�ص�ʱ��
	���Ӹ�Ч����ĩβ��Ӻ�ɾ��Ԫ����Ը�Ч��������������ĩβ��ɾ���Ͳ��������Ч�ʸ��͡�
	����lists��forward_listsͳһ�ĵ����������ø��á�

*/

void main()
{
//����////////////////////////////////////////////////////////////////////////
	vector<int> vec1;        //����һ��int������
	vector<int> vec2(5);     //����һ����ʼ��СΪ5��int������ʹ��0���
	vector<int> vec3(10, 1); //����һ����ʼ��СΪ10��ֵ����1������
	vector<int> vec4(vec3);   //��������tmp������ʼ��vec����
	
	int arr[5] = { 1, 2, 3, 4, 5 };
	vector<int> vec5(arr, arr + 5);      //��arr�����Ԫ�����ڳ�ʼ��vec����
	//˵������Ȼ������arr[4]Ԫ�أ�ĩβָ�붼��ָ����Ԫ�ص���һ��Ԫ�أ�
	//�����Ҫ��Ϊ�˺�vec.end()ָ��ͳһ��
	vector<int> vec6(&arr[1], &arr[4]); //��arr[1]~arr[4]��Χ�ڵ�Ԫ����Ϊvec�ĳ�ʼֵ
	vector<int> vec7(vec3.begin(), vec3.begin() + 3);  //������vec�ĵ�0������2��ֵ��ʼ��tmp

	/*
	(1).����
	
	������С�� vec.size();
	������������� vec.max_size();
	����������С�� vec.resize();
	������ʵ��С�� vec.capacity();
	�����пգ� vec.empty();
	����������С������Ԫ����ռ�洢�ռ�Ĵ�С�� vec.shrink_to_fit(); //shrink_to_fit
	*/

	size_t s = vec5.size();
	s = vec5.max_size();
	vec1.resize(10);
	vec1.capacity();
	bool r = vec1.empty();


	/*
	2). �޸�

	���Ԫ�ظ�ֵ�� vec.assign(); //�����ڳ�ʼ��ʱ��������и�ֵ
	ĩβ���Ԫ�أ� vec.push_back();
	ĩβɾ��Ԫ�أ� vec.pop_back();
	����λ�ò���Ԫ�أ� vec.insert();
	����λ��ɾ��Ԫ�أ� vec.erase();
	��������������Ԫ�أ� vec.swap();
	�������Ԫ�أ� vec.clear();

	*/

	vec1.clear();
	vec1.assign(7, 100);
	vec1.push_back(999);
	vec1.pop_back();
	int myarray[] = { 501, 502, 503 };
	vec1.insert(vec1.begin(), myarray, myarray + 3);
	vec1.erase(vec1.begin(), vec1.begin() + 3);
	vec1.swap(vec5);


	/*
	(3)������

	��ʼָ�룺vec.begin();
	ĩβָ�룺vec.end(); //ָ�����һ��Ԫ�ص���һ��λ��
	ָ�����Ŀ�ʼָ�룺 vec.cbegin(); //��˼���ǲ���ͨ�����ָ�����޸���ָ�����ݣ������ǿ���ͨ��������ʽ�޸ĵģ�����ָ��Ҳ�ǿ����ƶ��ġ�
	ָ������ĩβָ�룺 vec.cend();

	*/

	for (std::vector<int>::iterator it = vec1.begin(); it != vec1.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << '\n';
	
	std::vector<int>::reverse_iterator rit = vec1.rbegin();
	for (; rit != vec1.rend(); ++rit)
		std::cout << ' ' << *rit;
	std::cout << '\n';

	/*
	(4)Ԫ�صķ���

	�±���ʣ� vec[1]; //���������Ƿ�Խ��
	at�������ʣ� vec.at(1); //�������ߵ��������at�����Ƿ�Խ�磬�����׳�out of range�쳣
	���ʵ�һ��Ԫ�أ� vec.front();
	�������һ��Ԫ�أ� vec.back();
	����һ��ָ�룺 int* p = vec.data(); //���е�ԭ������vector���ڴ��о���һ�������洢�����飬���Կ��Է���һ��ָ��ָ��������顣������C++11�����ԡ�
	*/
	int n = vec1[2];
	n = vec1.at(3);
	n = vec1.front();
	n = vec1.back();
	int* p = vec1.data();

	/*
	Ԫ�ط�ת
	#include <algorithm>
	reverse(vec.begin(), vec.end());
	*/
	reverse(vec1.begin(), vec1.end());
	
	
	system("pause");
}