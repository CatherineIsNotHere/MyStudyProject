#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
	�ַ�������
*/
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

/*
	�ַ�������
*/
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

/*
	�ַ����Ƚ�
*/
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

/*
	�ַ�������
*/
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

/*
	���ص�һ�γ����ַ�����ָ��
*/
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

/*
	���ַ�Ϊ�����ָ��ַ���
*/
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

/*
	�ַ��������ַ���ַ
*/
char* myStrchr(const char *s, int c)
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
	char name1[128] = {};
	char* name2 = { "�ҽ�1" };
	printf("strcpy��\n");
	printf("�ַ���Ϊ%s\n", name2);
	char* name3 = myStrcpy(name1, name2);
	printf("�������ַ���Ϊ%s\n\n", name2);

	///////////////////////////////////////

	printf("strcat��\n");
	char name4[128]={ "hello" };
	char* name5 = { "world" };
	printf("�ַ���1Ϊ%s\n", name4);
	printf("�ַ���2Ϊ%s\n", name5);
	char* name6 = myStrcat(name4, name5);
	printf("�ַ������Ӻ�Ϊ%s\n\n", name6);

	///////////////////////////////////////

	char* name7 = { "hello" };
	char* name8 = { "hello" };
	printf("�ַ���1Ϊ%s\n", name7);
	printf("�ַ���2Ϊ%s\n", name8);
	int cat = myStrcmp(name7,name8);
	printf("�ַ����ȽϺ�Ϊ%d\n\n", cat);

	///////////////////////////////////////

	char* name9 = {"helloworld"};
	printf("�ַ���Ϊ%s\n", name9);
	int num = myStrlen(name9);
	printf("�ַ�������Ϊ%d\n\n", num);

	///////////////////////////////////////

	char* name10 = { "helloworld" };
	char* name11 = {"rl"};
	printf("�ַ���1Ϊ%s\n", name10);
	printf("���ֵ��ַ���Ϊ%s\n", name11);
	int stnum = myStrstr(name10,name11);
	printf("�ַ�����һ�γ�����%d\n\n", stnum);

	///////////////////////////////////////

	char h[] = { "hello world" };
	char* de = " l";
	printf("�ַ���1Ϊ%s\n", h);
	printf("�ָ���ַ�Ϊ%s(ע��ǰ���пո�)\n", de);
	char* token = nullptr;
	token = myStrtok(h, de);
	printf("��һ�ηָ��Ϊ��%s\n", token);
	token = myStrtok(nullptr, de);
	printf("�ڶ��ηָ��Ϊ��%s\n\n", token);

	///////////////////////////////////////

	char h2[] = { "hellao world" };
	printf("�ַ���1Ϊ%s\n", h2);
	int ch = 97;
	printf("���ҵ�����Ϊ%d\n", ch);
	char* location = myStrchr(h2,ch);
	printf("���Һ�ĵ�ַΪ%xd\n",location);

	system("pause");
}