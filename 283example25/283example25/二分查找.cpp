#include "stdio.h"

void binery_search(int arr[],int l,int key){
	int first = 0;
	int last = l - 1;
	int count = 0;
	int mid = 0;
	bool suc=false;
	while (first<last){
		count++;
		mid = (first + last) / 2;
		if (key<arr[mid]){
			last = mid-1;
		}
		else if (key>arr[mid]){
			first = mid + 1;
		}
		else if (key==arr[mid]){
			printf("���ҳɹ����ܹ�����%d�β���\n",count);
			suc = true;
			break;
		}
	}
	if (!suc){
		printf("����ʧ�ܣ��ܹ�����%d��\n",count);
	}
}

void main(){
	int l = 0;
	printf("���������鳤�ȣ�\n");
	scanf_s("%d",&l);
	int* arr = new int[l];
	for (int i = 0; i < l; i++)
	{
		arr[i] = i;
	}
	printf("��������Ҫ���ҵ���0~%d��\n",l-1);
	int key=0;
	scanf_s("%d", &key); 
	binery_search(arr,l,key);
}