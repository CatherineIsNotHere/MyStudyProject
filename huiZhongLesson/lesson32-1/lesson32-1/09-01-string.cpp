#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <map>  
#include <string>
using namespace std;


void main()
{
	/*
	String��Ĺ��캯�����£�
	1)    string s; //����һ�����ַ���s
	2)    string s(str) //�������캯������str�ĸ���Ʒ
	3)    string s(str,index) //���ַ���str�ڡ�ʼ��λ��index���Ĳ��ֵ����ַ����ĳ�ֵ
	4)    string s(str,index, n) //���ַ���str�ڡ�ʼ��index�ҳ��ȶ���n���Ĳ�����Ϊ�ַ����ĳ�ֵ
	5)    string s(cstr) //��C�ַ�����Ϊs�ĳ�ֵ
	6)    string s(chars,chars_len) //��C�ַ���ǰchars_len���ַ���Ϊ�ַ���s�ĳ�ֵ��
	7)    string s(n,c) //����һ���ַ���������n��c�ַ�
	8)    string s(str.begin(),str.end()) //������begin():end() (������end())�ڵ��ַ���Ϊ�ַ���s�ĳ�ֵ
	*/
	//����  
	{
		string s0("abcdefghijklmn");
		string s1;
		string s2(s0);
		string s3(s0, 3);
		string s4(s0, 3, 4);
		string s5("let us learn string");
		string s6("let us learn string", 6);
		string s7(10, 'x');
		string s8(s0.begin(), s0.begin() + 7);
		//���  
		cout << "s1: " << s1 << "\ns2: " << s2 << "\ns3: " << s3;
		cout << "\ns4: " << s4 << "\ns5: " << s5 << "\ns6: " << s6;
		cout << "\ns7: " << s7 << "\ns8: " << s8 << '\n';
	}



	/*
	String�ೣ�õĲ�������
	1) =,assign()   //������ֵ
	2) swap()   //���������ַ���������
	3)+=,append(),push_back() //��β������ַ�
	4) insert() //�����ַ�
	5) erase() //ɾ���ַ�
	6) clear() //ɾ��ȫ���ַ�
	7) replace() //�滻�ַ�
	8) + //�����ַ���
	9)==,!=,<,<=,>,>=,compare()  //�Ƚ��ַ���
	10)size(),length()  //�����ַ�����
	11) max_size() //�����ַ��Ŀ���������
	12) empty()  //�ж��ַ����Ƿ�Ϊ��
	13) capacity() //�������·���֮ǰ���ַ�����
	14) reserve() //����һ�����ڴ�������һ���������ַ�
	15) [ ], at() //��ȡ��һ�ַ�
	16)>>,getline() //��stream��ȡĳֵ
	17) <<  //��ıֵд��stream
	18) copy() //��ĳֵ��ֵΪһ��C_string
	19) c_str() //��������C_string����
	20) data() //���������ַ�������ʽ����
	21) substr() //����ĳ�����ַ���
	22)���Һ���
	23)begin() end() //�ṩ����STL�ĵ�����֧��
	24) rbegin() rend() //���������
	25) get_allocator() //����������
	*/

	{
		// �ַ������
		string s1;
		//β�������ַ�  
		s1.push_back('a');
		s1.push_back('b');
		s1.push_back('c');
		cout << "��ӡs1: " << s1 << endl;
		char* cArray = "efgh";
		string s2(cArray);
		cout << "��ӡs2: " << s2 << endl;
		//�ַ�����"+"����  
		cout << "��ӡs1+s2: " << s1 + s2 << endl;
		//�ַ���s1������ַ���s2  
		cout << "append��,��ӡs1: " << s1.append(s2) << endl;
		//��s1�ĵڸ��ַ�λ��ǰ�����ַ�'8'  
		s1.insert(s1.begin() + 1, '8');
		cout << "insert��,��ӡs1: " << s1 << endl;
		//�ַ�����"+="����  
		s1 += s2;
		cout << "s1+=s2��,��ӡs1: " << s1 << endl;
}
	// �ַ��ı���
	{
		char* cArray = "hello, world!";
		string s(cArray);
		//���鷽ʽ  
		for (unsigned int j = 0; j < s.size(); j++)
			cout << "��" << j << "���ַ�: " << s[j] << endl;
		//��������ʽ  
		string::reverse_iterator ri;
		cout << "�����ӡ�ַ�" << endl;
		for (ri = s.rbegin(); ri != s.rend(); ri++)
			cout << *ri << ' ';
		cout << endl;
	}

	{
		/*
	�ַ���ɾ��
	1)iterator erase(iterator p);//ɾ���ַ�����p��ָ���ַ�
	2)iterator erase(iterator first, iterator last);//ɾ���ַ����е�����
	����[first,last)�������ַ�
	3)string& erase(size_t pos = 0, size_t len = npos);//ɾ���ַ����д�����
	λ��pos��ʼ��len���ַ�
	4)void clear();//ɾ���ַ����������ַ�
	*/
		string s("12345678a");
		s.erase(s.begin());
		cout << s << endl; //��ӡ����a   
		s.erase(s.begin() + 3, s.end() - 2);
		cout << s << endl; //��ӡ����a  
		s.erase(0, 2);
		cout << s << endl; //��ӡ����a  
		s.clear();
	}

/*
�ַ����滻
1)string& replace(size_t pos, size_t n, const char *s);//����ǰ�ַ���
��pos������ʼ��n���ַ����滻���ַ���s
2)string& replace(size_t pos, size_t n, size_t n1, char c); //����ǰ�ַ���
��pos������ʼ��n���ַ����滻��n1���ַ�c
3)string& replace(iterator i1, iterator i2, const char* s);//����ǰ�ַ���
[i1,i2)�����е��ַ����滻Ϊ�ַ���s
*/
	{
		string s("hello,boy!");
		s.replace(6, 3, "gril");  //boy�滻Ϊgirl  
		cout << s << endl;      //��ӡhello gril!  
		s.replace(10, 1, 1, '.');  //��"hello gril!"��'!'�滻Ϊ'.'  
		cout << s << endl;      //��ӡhello gril.  
		s.replace(s.begin(), s.begin() + 5, "good morning");
		cout << s << endl;     //��ӡgood morning girl.  
	}

	{
		/*
	�ַ�������
	��غ����϶࣬�����оټ������õģ�
	1)size_t find (constchar* s, size_t pos = 0) const;
	//�ڵ�ǰ�ַ�����pos����λ�ÿ�ʼ�������Ӵ�s�������ҵ���λ��������
	-1��ʾ���Ҳ����Ӵ�
	2)size_t find (charc, size_t pos = 0) const;
	//�ڵ�ǰ�ַ�����pos����λ�ÿ�ʼ�������ַ�c�������ҵ���λ��������
	-1��ʾ���Ҳ����ַ�
	3)size_t rfind (constchar* s, size_t pos = npos) const;
	//�ڵ�ǰ�ַ�����pos����λ�ÿ�ʼ����������Ӵ�s�������ҵ���λ��������
	-1��ʾ���Ҳ����Ӵ�
	4)size_t rfind (charc, size_t pos = npos) const;
	//�ڵ�ǰ�ַ�����pos����λ�ÿ�ʼ����������ַ�c�������ҵ���λ��������
	-1��ʾ���Ҳ����ַ�
	5)size_tfind_first_of (const char* s, size_t pos = 0) const;
	//�ڵ�ǰ�ַ�����pos����λ�ÿ�ʼ�������Ӵ�s���ַ��������ҵ���λ��������
	-1��ʾ���Ҳ����ַ�
	6)size_tfind_first_not_of (const char* s, size_t pos = 0) const;
	//�ڵ�ǰ�ַ�����pos����λ�ÿ�ʼ�����ҵ�һ����λ���Ӵ�s���ַ���
	�����ҵ���λ��������-1��ʾ���Ҳ����ַ�
	7)size_t find_last_of(const char* s, size_t pos = npos) const;
	//�ڵ�ǰ�ַ�����pos����λ�ÿ�ʼ���������һ��λ���Ӵ�s���ַ��������ҵ���λ��������-1��ʾ���Ҳ����ַ�
	8)size_tfind_last_not_of (const char* s, size_t pos = npos) const;
	//�ڵ�ǰ�ַ�����pos����λ�ÿ�ʼ���������һ����λ���Ӵ�s���ַ��������ҵ���λ��������-1��ʾ���Ҳ����Ӵ�
	*/

		//0123456789012345678901234  
		string s("dog bird chicken bird cat");
		//�ַ�������  
		cout << s.find("bird") << endl;  //��ӡ  
		cout << (int)s.find("pig") << endl;   //��ӡ-1  
		//�ַ�����  
		cout << s.find('i', 7) << endl;   //��ӡ  
		//���ַ�����ĩβ��ʼ�����ַ���  
		cout << s.rfind("bird") << endl; //��ӡ  
		//���ַ�����ĩβ��ʼ�����ַ�  
		cout << s.rfind('i') << endl;    //��ӡ  
		//���ҵڸ�����ĳ�Ӵ����ַ�  
		cout << s.find_first_of("13r98") << endl;  //�ҵ��ַ�r,��ӡ  
		//���ҵڸ�������ĳ�ַ������ַ�  
		cout << s.find_first_not_of("dog bird 2006") << endl;  //�ҵ��ַ�c,��ӡ  
		//�������һ������ĳ�Ӵ����ַ�  
		cout << s.find_last_of("13r98") << endl;  //�ַ�r,��ӡ  
		//�������һ��������ĳ�ַ������ַ�  
		cout << s.find_last_not_of("tea") << endl;  //�ַ�c,��ӡ  
	}

	{
		/*
		�ַ����ıȽ�
		1)int compare (conststring& str) const;//����ǰ�ַ������ַ���str�Ƚϣ�
		��ȷ���0������str����1��С��str����-1
		2)int compare (size_tpos, size_t len, const char* s) const; //����ǰ�ַ�����
		Pos����λ�ÿ�ʼ��len���ַ����ɵ��ַ������ַ���s�Ƚϣ�
		��ȷ���0������str����1��С��str����-1
		3)int compare (constchar* s) const; //ֱ�ӽ���ǰ�ַ������ַ���s�Ƚϣ�
		��ȷ���0
		*/
		string s1("abcdef");
		string s2("abc");
		cout << s1.compare("abcdef") << endl;  //���,��ӡ  
		cout << s1.compare(s2) << endl;   //s1 > s2,��ӡ  
		cout << s1.compare("abyz") << endl; //s1 < "abyz",��ӡ-1  
		cout << s1.compare(0, 3, s2) << endl; //s1��ǰ���ַ�==s2,��ӡ  
	}
	system("pause");
}