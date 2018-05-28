#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;

/*
	使用1维数组解决问题：
	数组的归并；数组的排序；数组的查找；数组的最大值和最小值；数组的逆序输出；数组长度；
	9宫格输出；使用字符数组来表示52张扑克牌，然后洗牌后输出，要求每行输出13张牌
	*/

void main(){
	//数组的归并排序
	int arr1[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	int arr2[10] = { 10, 9, 8, 7, 6, 5, 4, 3, 2, 1 };
	int arr3[20] = {};
	for (int i = 0; i < sizeof(arr1) / sizeof(int); i++)
		arr3[i] = arr1[i];
	for (int i = 0; i < sizeof(arr2) / sizeof(int); i++)
		arr3[10 + i] = arr2[i];
	cout << "数组1为：";
	for (int i = 0; i < sizeof(arr1) / sizeof(int); i++)
		cout << arr1[i] << ",";
	cout << endl;
	cout << "数组2为：";
	for (int i = 0; i < sizeof(arr2) / sizeof(int); i++)
		cout << arr2[i] << ",";
	cout << endl;
	int t = 0;
	for (int i = 0; i < sizeof(arr3) / sizeof(int); i++)
		for (int j = i + 1; j < sizeof(arr3) / sizeof(int); j++)
		{
			if (arr3[i] < arr3[j]){
				t = arr3[i];
				arr3[i] = arr3[j];
				arr3[j] = t;
			}
		}
	cout << "归并排序后：";
	for (int i = 0; i < sizeof(arr3) / sizeof(int); i++)
		cout << arr3[i] << ",";
	cout << endl;
	cout << endl;

	//数组的查找
	int arrScan[10] = { 5, 7, 8, 9, 6, 2, 4, 1, 3, 5 };
	cout << "要遍历的数组为：";
	for (int i = 0; i < sizeof(arrScan) / sizeof(int); i++)
		cout << arrScan[i] << ",";
	cout << endl;
	int c = 5;
	cout << "要查找的数为：" << c << endl;
	int k = -1;
	for (int i = 0; i < sizeof(arrScan) / sizeof(int); i++)
	if (arrScan[i] == c){
		k = i + 1;
		break;
	}
	cout << "查找后该数在第" << k << "位" << endl;
	cout << endl;

	//数组的最大值和最小值
	int arrmm[10] = { 5, 8, 9, 4, 6, 1, 3, 7, 20, 15 };
	cout << "原数组为：";
	for (int i = 0; i < 10; i++)
		cout << arrmm[i] << ",";
	cout << endl;
	int maxNum = arrmm[0];
	int minNum = arrmm[0];
	for (int i = 1; i < sizeof(arrmm) / sizeof(int); i++){
		if (maxNum < arrmm[i])
			maxNum = arrmm[i];
		if (minNum > arrmm[i])
			minNum = arrmm[i];
	}
	cout << "最大值为：" << maxNum << endl;
	cout << "最小值为：" << minNum << endl;
	cout << endl;

	//数组的逆序输出
	int arrIn[10]{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	cout << "原数组为：";
	for (int i = 0; i < 10; i++)
		cout << arrIn[i] << ",";
	cout << endl;
	cout << "逆序输出为：";
	for (int i = sizeof(arrIn) / sizeof(int)-1; i >= 0; i--)
		cout << arrIn[i] << ",";
	cout << endl;
	cout << endl;

	int arrszof[5] = { 1, 2, 3, 4, 5 };
	cout << "原数组为：";
	for (int i = 0; i < sizeof(arrszof) / sizeof(int); i++)
		cout << arrszof[i] << ",";
	cout << endl;
	cout << "数组的长度为：" << sizeof(arrszof) / sizeof(int) << endl;
	cout << endl;

	//9宫格的输出
	srand((int)time(NULL));
	int arrNine[9] = {};//原数组
	int arrDouble[4] = { 2, 4, 6, 8 };
	arrNine[4] = 5;//固定值
	int num = 0;
	for (int i = 0; i < 2; i++)//四角固定
	{
		num = rand() % 4;
		if (arrDouble[num] == -1){
			i--;
			continue;
		}
		if (i == 0){
			arrNine[0] = arrDouble[num];
			arrNine[8] = 15 - arrNine[0] - arrNine[4];
		}
		if (i == 1){
			arrNine[2] = arrDouble[num];
			arrNine[6] = 15 - arrNine[2] - arrNine[4];
		}
		arrDouble[num] = -1;
		arrDouble[3 - num] = -1;
	}
	//中间值直接算出来
	arrNine[1] = 15 - arrNine[2] - arrNine[0];
	arrNine[3] = 15 - arrNine[0] - arrNine[6];
	arrNine[5] = 15 - arrNine[2] - arrNine[8];
	arrNine[7] = 15 - arrNine[8] - arrNine[6];
	cout << "九宫格：" << endl;
	for (int i = 0; i < 9; i++)
	{
		cout << "|" << arrNine[i] << "|";
		if (i % 3 == 2){
			cout << endl;
		}
	}
	cout << endl;


	//使用字符数组表示52张扑克牌，并洗牌输出；
	srand((int)time(NULL));
	char puke[52] = { 0 };
	char color[4] = { 1, 14, 27, 40 };//红桃，黑桃，梅花，方片
	char pnum[13] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13 };
	int csz = 4;
	int numsz = 13;
	int inum = 0;//已经生成牌的个数 到52停止
	int pukenum = 0;
	int colornum = 0;
	bool canUse = true;
	cout << "扑克牌输出：" << endl;
	while (true){
		pukenum = rand() % numsz;
		colornum = rand() % csz;
		for (int i = 0; i < inum; i++)//生成的重复puke
		{
			if (pnum[pukenum] + color[colornum] == puke[i]){
				canUse = false;
				break;
			}
		}
		if (canUse){
			if ((int)color[colornum] == 1)
				cout << "红桃" << (int)pnum[pukenum] << ",";
			else if ((int)color[colornum] == 14)
				cout << "黑桃" << (int)pnum[pukenum] << ",";
			else if ((int)color[colornum] == 27)
				cout << "梅花" << (int)pnum[pukenum] << ",";
			else if ((int)color[colornum] == 40)
				cout << "方片" << (int)pnum[pukenum] << ",";
			else
				cout << "错误" << endl;
			puke[inum] = pnum[pukenum] + color[colornum];
			inum++;
			if (inum % 13 == 0){
				cout << endl;
			}

		}
		if (inum >= 52){
			break;
		}
		canUse = true;
		//复杂度较大
	}

	system("pause");
}