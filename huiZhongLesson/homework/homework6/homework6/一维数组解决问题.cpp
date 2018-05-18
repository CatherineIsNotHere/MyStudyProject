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

/*
	数组的归并
	*/
//int* mergeArr(int* arr1, int* arr2, int mergeSize){
//	static int* arr3 = new int[mergeSize]{};
//	int* marr = arr3;
//	for (int i = 0; i < 10; i++)
//		*marr++ = *arr1++;
//	for (int i = 0; i < 10; i++)
//		*marr++ = *arr2++;
//	return arr3;
//}

/*
	数组的排序（冒泡倒序）
	*/
//int* sortPop(int* arr, int arrsz){
//	int t = 0;
//	for (int i = 0; i < arrsz; i++)
//	{
//		for (int j = i + 1; j < arrsz; j++)
//		{
//			if (arr[i] < arr[j]){
//				t = arr[i];
//				arr[i] = arr[j];
//				arr[j] = t;
//			}
//		}
//	}
//	return arr;
//}
/*
	数组的查找
	*/
//int scanArr(int* arr, int arrsz, int num){
//	int k = -1;
//	for (int i = 0; i < arrsz; i++)
//	if (arr[i] == num){
//		k = i + 1;
//		break;
//	}
//	return k;
//}

/*
	数组的最大值
	*/
//int arrMax(int* arr, int arrsz){
//	int maxNum = arr[0];
//	for (int i = 1; i < arrsz; i++)
//	if (maxNum < arr[i])
//		maxNum = arr[i];
//	return maxNum;
//}
/*
	数组的最小值
	*/
//int arrMin(int* arr, int arrsz){
//	int minNum = arr[0];
//	for (int i = 1; i < arrsz; i++)
//	if (minNum > arr[i])
//		minNum = arr[i];
//	return minNum;
//}

/*
	数组的逆序输出
	*/
//void arrInvert(int* arr, int arrsz){
//	cout << "逆序输出为：";
//	for (int i = arrsz - 1; i >= 0; i--)
//		cout << arr[i] << ",";
//	cout << endl;
//}

/*
	九宫格输出
	*/


void main(){
	//数组的归并
	//int arr1[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	//int arr2[10] = { 10, 9, 8, 7, 6, 5, 4, 3, 2, 1 };
	//int* arr3 = mergeArr(arr1, arr2, 20);
	//cout << "数组1为：";
	//for (int i = 0; i < 10; i++)
	//	cout << arr1[i] << ",";
	//cout << endl;
	//cout << "数组2为：";
	//for (int i = 0; i < 10; i++)
	//	cout << arr2[i] << ",";
	//cout << endl;
	//cout << "合并后数组为：";
	//for (int i = 0; i < 20; i++)
	//	cout << *arr3++ << ",";
	//cout << endl;

	//数组的排序
	//int arrSort[16] = { 5, 10, 6, 2, 1, 8, 9, 50, 2, 4, 3, 8, 64, 2, 78, 3 };
	//cout << "排序前：";
	//for (int i = 0; i < 16; i++)
	//	cout << arrSort[i] << ",";
	//cout << endl;
	//sortPop(arrSort, 16);
	//cout << "排序后：";
	//for (int i = 0; i < 16; i++)
	//	cout << arrSort[i] << ",";
	//cout << endl;

	//数组的查找
	//int arrScan[10] = { 5, 7, 8, 9, 6, 2, 4, 1, 3, 5 };
	//cout << "要遍历的数组为：";
	//for (int i = 0; i < 10; i++)
	//	cout << arrScan[i] << ",";
	//cout << endl;
	//int c = 5;
	//cout << "要查找的数为：" << c << endl;
	//int a = scanArr(arrScan, 10, c);
	//cout << "查找后该数在第" << a << "位" << endl;

	//数组的最大值和最小值
	//int arrmm[10] = { 5, 8, 9, 4, 6, 1, 3, 7, 20, 15 };
	//cout << "原数组为：";
	//for (int i = 0; i < 10; i++)
	//	cout << arrmm[i]<<",";
	//cout << endl;
	//cout << "最大值为：" << arrMax(arrmm,10)<<endl;
	//cout << "最小值为：" << arrMin(arrmm, 10) << endl;

	//数组的逆序输出
	//int arrIn[10]{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	//cout << "原数组为：";
	//for (int i = 0; i < 10; i++)
	//	cout << arrIn[i] << ",";
	//cout << endl;
	//arrInvert(arrIn, 10);

	//int arrszof[5] = {1,2,3,4,5};
	//cout << "原数组为：";
	//for (int i = 0; i < 5; i++)
	//	cout << arrszof[i];
	//cout << endl;
	//cout<<"数组的长度为："<<sizeof(arrszof)/sizeof(int)<<endl;

	//9宫格的输出
	//srand((int)time(NULL));
	//int arrNine[9] = {};//原数组
	//int arrDouble[4] = { 2, 4, 6, 8 };
	//arrNine[4] = 5;//固定值
	//int num = 0;
	//for (int i = 0; i < 2; i++)//四角固定
	//{
	//	num = rand() % 4;
	//	if (arrDouble[num] == -1){
	//		i--;
	//		continue;
	//	}
	//	if (i == 0){
	//		arrNine[0] = arrDouble[num];
	//		arrNine[8] = 15 - arrNine[0] - arrNine[4];
	//	}
	//	if (i==1){
	//		arrNine[2] = arrDouble[num];
	//		arrNine[6] = 15-arrNine[2]-arrNine[4];
	//	}
	//	arrDouble[num] = -1;
	//	arrDouble[3 - num] = -1;
	//}
	////中间值直接算出来
	//arrNine[1] = 15 - arrNine[2] - arrNine[0];
	//arrNine[3] = 15 - arrNine[0] - arrNine[6];
	//arrNine[5] = 15 - arrNine[2] - arrNine[8];
	//arrNine[7] = 15 - arrNine[8] - arrNine[6];
	//for (int i = 0; i < 9; i++)
	//{
	//	cout << "|" << arrNine[i] << "|";
	//	if (i%3==2){
	//		cout << endl;
	//	}
	//}

	//使用字符数组表示52张扑克牌，并洗牌输出；
	srand((int)time(NULL));
	char puke[52] = { 0 };
	char color[4] = { 1, 14, 27, 40 };//红桃，黑桃，梅花，方片
	char pnum[13] = { 1, 2,3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13 };
	int csz = 4;
	int numsz = 13;
	int inum = 0;//已经生成牌的个数 到52停止
	int pukenum = 0;
	int colornum = 0;
	bool canUse = true;
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
			if ((int)color[colornum]==1)
				cout << "红桃" << (int)pnum[pukenum] <<",";
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
			if (inum%13==0){
				cout << endl;
			}

		}
		if (inum>=52){
			break;
		}
		canUse = true;
		//以上即可实现功能。
		//int allcolor = 0;
		//for (int i = 1; i <= numsz; i++)
		//{
		//	for (inum; inum > 0; inum--){
		//		if (color[csz - 1] + i == puke[inum]){
		//			allcolor++;
		//		}
		//	}
		//}
		//if (allcolor==13){
		//	csz--;
		//}
	}

	system("pause");
}