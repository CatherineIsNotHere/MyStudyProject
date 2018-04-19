#include <stdio.h>
//■□
void main(){
	printf("■■■■■■■■■■■■■■■■■■■迷宫■■■■■■■■■■■■■■■■■■■");
	char a[40][40];//定义40*40的二维数组
	int n = 40;
	int i, j;//i=列号y=行号
	for (j = 1; j <= 39; j++){//遍历每一列
		if (j = 1){
			for (i = 1; i <= 39; i++){
				if (i != 2){
					a[j][i] = '■';
				}
				else{
					a[j][i] = '  ';
				}
			}
		}
		else{
			/*for (i = 1; i <= 40; i++){
				if (i != 2){
					printf("■");
				}
				else{
					printf("  ");
				}
			}*/
		}
	}
}