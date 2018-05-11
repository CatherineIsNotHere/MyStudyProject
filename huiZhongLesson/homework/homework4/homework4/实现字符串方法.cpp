#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* myStrcpy(char* str1, char* str2){
	if (str1 == nullptr&&str2 == nullptr)
		return nullptr;
	char* str3 = str1;
	*str1 = {};
	while (*str2 != '\0'){
		*str1 = *str2;
		str1++;
		str2++;
	}
	return str3;
}

char* myStrcat(char* str1, char* str2){
	if (str1 == nullptr&&str2 == nullptr)
		return nullptr;
	char* str3 = str1;
	while (*str3 != '\0'){
		str3++;
	}
	while (*str2 != '\0'){
		*str3 = *str2;
		str3++;
		str2++;
	}
	return str1;
}

int myStrcmp(char* str1, char* str2){
	if (str1 == nullptr&&str2 == nullptr)
		return 0;
	if (str1 == nullptr)
		return -1;
	if (str2 == nullptr)
		return 1;
	while (true){
		if (*str1 == '\0'&&*str2 == '\0'){
			return 0;
		}
		if (*str1 == *str2){
			str1++;
			str2++;
			continue;
		}
		else if (*str1 > *str2 || *str2 == '\0'){
			return 1;
		}
		else if (*str1 < *str2 || *str1 == '\0'){
			return -1;
		}
	}
}

int myStrlen(char* str1){
	if (str1 == nullptr)
		return 0;
	int i = 0;
	while (*str1 != '\0'){
		str1++;
		i++;
	}
	return i;
}

int myStrstr(char* str1, char* str2){
	if (str1 == nullptr&&str2 == nullptr)
		return 0;
	int i = 0;;
	int j = 0;;
	while (*str1 != '\0'){//ѭ��str1
		if (*str2 == *str1){
			char* str3 = str1;
			char* str4 = str2;
			j = i + 1;
			while (*str4 != '\0'){
				if (*str4 != *str3){
					j = 0;
					break;
				}
				else{
					str4++;
					str3++;
					continue;
				}
			}
		}
		str1++;
		i++;
		if (j != 0){
			break;
		}
	}
	return j;
}

char* MySAVE_PTR = nullptr;

char* myStrtok(char* s, char* d){
	if (d == nullptr)
		return nullptr;
	char* copys;
	if (s == nullptr)
		copys = MySAVE_PTR;
	else
		copys = s;
	char* t = nullptr;
	while (*d != '\0'){//ͨ����ѭ���ҵ�s����d�������ַ��ָ���ǰ���ַ���ַ
		char* newEqual = copys;//��¼��У���
		char* isFirstEqual = copys;
		while (*newEqual != '\0'){
			if (*newEqual == *d){//�ҵ���ͬ�ַ�������ʱ��ȷ���Ƿ�Ϊ�ǰ����ͬ�ַ�
				if (newEqual - isFirstEqual == 0){//�������ַ���ǰ��û���κζ�����ƥ�䣬�򲻱�Ƿָ�
					isFirstEqual++;
					newEqual++;
					copys++;
					continue;
				}
				if (t != nullptr&&t > newEqual)//���ָ�벻Ϊ���Ҳ����ǰ����ͬ�ַ�ָ��
					t = newEqual;//����ǰ��ָ��
				else if (t == nullptr)//Ϊ��ֱ�Ӹ���
					t = newEqual;
				break;
			}
			newEqual++;
		}
		d++;
	}
	MySAVE_PTR = t + 1;
	//�ҵ�������ַ���ȡ
	int size = t - copys;
	char* slipStr = new char[size + 1]{};
	char* slipStrBegin = slipStr;
	for (size; size > 0; size--)
	{
		*slipStr = *copys;
		copys++;
		slipStr++;
	}
	slipStr = slipStrBegin;
	return slipStr;
}

char* myStrchr(const char *s, int c)//�ַ��������ַ�
{
	if (s == NULL)
		return NULL;
	while (*s != '\0')
	{
		if (*s == (char)c)
			return (char *)s;
		s++;
	}
	return NULL;
}



void main(){
	/*char name1[128] = {};
	char* name2 = { "�ҽ�1" };
	char* name3 = myStrcpy(name1, name2);*/

	///////////////////////////////////////

	/*char name4[128]={ "hello" };
	char* name5 = { "world" };
	char* name6 = myStrcat(name4, name5);*/

	///////////////////////////////////////

	/*char* name7 = { "hello" };
	char* name8 = { "hello" };
	int cat = myStrcmp(name7,name8);*/

	///////////////////////////////////////

	/*char* name9 = {};
	int num = myStrlen(name9);*/

	///////////////////////////////////////

	//char* name10 = { "helloworld" };
	//char* name11 = {"rl"};
	//int stnum = myStrstr(name10,name11);

	///////////////////////////////////////

	//char h[] = { "hello world" };
	//char* de = " l";
	//char* token = nullptr;
	//token = myStrtok(h, de);
	//printf("%s\n", token);
	//token = myStrtok(nullptr, de);
	//printf("%s\n", token);

	char h[] = { "hellao world" };
	int ch = 97;
	char* location = myStrchr(h,ch);
	printf("%xd\n",location);
	system("pause");
}