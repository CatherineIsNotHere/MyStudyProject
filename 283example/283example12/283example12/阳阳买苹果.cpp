#include "stdio.h"
//����ÿ�춼����ƻ����ÿ��8ë��ÿ�����ǰһ��2����ƻ����ÿ����ƻ�����ᳬ��100�ţ����������˼��죬ƽ�����˶���Ǯ
void main(){
	int n = 2, day = 0, num = 0;
	float money = 0, averange = 0;
	while (n < 100){
		money = 0.8*n;
		day++;
		num += n;
		n = n * 2;
	}
	averange = money / day;
	printf("�����ܹ�����%d��ƻ��������%d��,ƽ������%2.3f��Ǯ", num, day, averange);
}
