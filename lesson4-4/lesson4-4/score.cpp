#include <stdio.h>
/*
	��%e, %E�� %f,�������η�����ָ����Ҫ��С��λ��. ����,%12.6f
	����������ʾ12λ����,������6λС���ĸ�����.
*/
void main(){
	float math = 100;
	float english = 100;
	float physics = 100;
	float chinese = 100;
	printf("��������ѧ�ɼ���  ");
	scanf_s("%f/n", &math);
	printf("������Ӣ��ɼ���  ");
	scanf_s("%f/n", &english);
	printf("����������ɼ���  ");
	scanf_s("%f/n", &physics);
	printf("���������ĳɼ���  ");
	scanf_s("%f/n", &chinese);

	printf("�ɼ�Ϊ��\n%d\n%d\n%d\n%d\n", math, english, physics, chinese);
	int sum = math + english + physics + chinese;
	printf("�����ܳɼ�Ϊ��%d\n", sum);
	printf("����ƽ���ɼ�Ϊ��%3.2f", float(sum/4));
}