#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;

/*
	ʹ��1ά���������⣺
	����Ĺ鲢���������������Ĳ��ң���������ֵ����Сֵ�������������������鳤�ȣ�
	9���������ʹ���ַ���������ʾ52���˿��ƣ�Ȼ��ϴ�ƺ������Ҫ��ÿ�����13����
	*/

/*
	����Ĺ鲢
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
	���������ð�ݵ���
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
	����Ĳ���
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
	��������ֵ
	*/
//int arrMax(int* arr, int arrsz){
//	int maxNum = arr[0];
//	for (int i = 1; i < arrsz; i++)
//	if (maxNum < arr[i])
//		maxNum = arr[i];
//	return maxNum;
//}
/*
	�������Сֵ
	*/
//int arrMin(int* arr, int arrsz){
//	int minNum = arr[0];
//	for (int i = 1; i < arrsz; i++)
//	if (minNum > arr[i])
//		minNum = arr[i];
//	return minNum;
//}

/*
	������������
	*/
//void arrInvert(int* arr, int arrsz){
//	cout << "�������Ϊ��";
//	for (int i = arrsz - 1; i >= 0; i--)
//		cout << arr[i] << ",";
//	cout << endl;
//}

/*
	�Ź������
*/


void main(){

	//����Ĺ鲢
	//int arr1[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	//int arr2[10] = { 10, 9, 8, 7, 6, 5, 4, 3, 2, 1 };
	//int* arr3 = mergeArr(arr1, arr2, 20);
	//cout << "����1Ϊ��";
	//for (int i = 0; i < 10; i++)
	//	cout << arr1[i] << ",";
	//cout << endl;
	//cout << "����2Ϊ��";
	//for (int i = 0; i < 10; i++)
	//	cout << arr2[i] << ",";
	//cout << endl;
	//cout << "�ϲ�������Ϊ��";
	//for (int i = 0; i < 20; i++)
	//	cout << *arr3++ << ",";
	//cout << endl;

	//���������
	//int arrSort[16] = { 5, 10, 6, 2, 1, 8, 9, 50, 2, 4, 3, 8, 64, 2, 78, 3 };
	//cout << "����ǰ��";
	//for (int i = 0; i < 16; i++)
	//	cout << arrSort[i] << ",";
	//cout << endl;
	//sortPop(arrSort, 16);
	//cout << "�����";
	//for (int i = 0; i < 16; i++)
	//	cout << arrSort[i] << ",";
	//cout << endl;

	//����Ĳ���
	//int arrScan[10] = { 5, 7, 8, 9, 6, 2, 4, 1, 3, 5 };
	//cout << "Ҫ����������Ϊ��";
	//for (int i = 0; i < 10; i++)
	//	cout << arrScan[i] << ",";
	//cout << endl;
	//int c = 5;
	//cout << "Ҫ���ҵ���Ϊ��" << c << endl;
	//int a = scanArr(arrScan, 10, c);
	//cout << "���Һ�����ڵ�" << a << "λ" << endl;

	//��������ֵ����Сֵ
	//int arrmm[10] = { 5, 8, 9, 4, 6, 1, 3, 7, 20, 15 };
	//cout << "ԭ����Ϊ��";
	//for (int i = 0; i < 10; i++)
	//	cout << arrmm[i]<<",";
	//cout << endl;
	//cout << "���ֵΪ��" << arrMax(arrmm,10)<<endl;
	//cout << "��СֵΪ��" << arrMin(arrmm, 10) << endl;

	//������������
	//int arrIn[10]{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	//cout << "ԭ����Ϊ��";
	//for (int i = 0; i < 10; i++)
	//	cout << arrIn[i] << ",";
	//cout << endl;
	//arrInvert(arrIn, 10);

	//int arrszof[5] = {1,2,3,4,5};
	//cout << "ԭ����Ϊ��";
	//for (int i = 0; i < 5; i++)
	//	cout << arrszof[i];
	//cout << endl;
	//cout<<"����ĳ���Ϊ��"<<sizeof(arrszof)/sizeof(int)<<endl;

	//9��������
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