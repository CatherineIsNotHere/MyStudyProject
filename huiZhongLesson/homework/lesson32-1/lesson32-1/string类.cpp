#include <stdio.h>
#include <string>
using namespace std;

void main(){
	string s0;
	string s1("aaaa");
	string s2(s1);
	string s3 = "abcdefg";
	string s4(s3, 3);//跳过前三个
	string s5(s3, 2, 3);//跳过前两个数三个
	string s6(10, 'x');//十个x
	string s7(s3.begin(),s3.begin()+3);//从s3开始数三个
	char sss[] = { "123456" };
	string s8(sss);

	s8.push_back('A');//string是字符数组封装，pushback只能在后边插入字符
	string s9=s8+s8;
	s9.append("333");
	s9.insert(s9.begin()+1,'x');//在开头加1位置插入x
	s9 += "===";

	for (int i = 0; i < s9.size(); i++)
	{
		printf("%c",s9[i]);
	}
	printf("\n");
	for (string::reverse_iterator rit = s9.rbegin(); rit <s9.rend(); rit++)//string的反向迭代器
	{
		printf("%c", *rit);
	}
	s9.erase(s9.begin());//擦除第一个
	s9.erase(s9.begin(), s9.end() - 2);//擦除第一个到倒数第三个
	s9.clear();

	string s10 = "abcdef";
	s10.replace(2,3,"AAAAA");//从第二个到后边三个替换成五个A
	s10.replace(s10.begin(),s10.begin()+2,"XXXXXX");
	s10.replace(2,2,2,'Z');

	string s = "dog brid chicken bird cat";
	s.find("brid");
	s.rfind("rbird");
	s.find_first_of("13r98");
	s.find_first_not_of("dog bird 2018");

	string a1 = "abc";
	string a2 = "abcdefg";
	a1.compare(a2);

}
