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
	srand((int)time(NULL));
	int arrNine[9] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	int arrGarb[9] = {};
	int num = 0;
	for (int i = 0; i < 9; i++)
	{
		num=rand() % 10;
		for (int j = 0; j < 9; j++)
		{
		}
	}

	system("pause");
}