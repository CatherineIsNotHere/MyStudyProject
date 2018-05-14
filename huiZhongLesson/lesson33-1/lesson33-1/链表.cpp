#include<stdio.h>
#include <iostream>
#include<list>
#include<stdlib.h>;
using namespace std;

bool Fun(int& v);

class CFun{
public:
	bool operator() (const int& v) {
		return v == 1;
	}

};

void main(){
	list<int> f1;
	list<int> f2(4,100);
	list<int> f3(f2.begin(),f2.end());
	list<int> f4(f3);

	int arr[] = { 1, 2, 3 };
	list<int> f5(arr, arr + sizeof(arr) / sizeof(arr[0]));
	for (list<int>::iterator it = f5.begin(); it!=f5.end(); it++)
	{
		cout << *it << endl;
	}
	f5.size();
	f5.empty();
	f5.push_back(100); 
	f5.push_front(111);

	f5.pop_back();
	f5.pop_front();

	f5.insert(f5.begin(),40);
	f5.insert(f5.begin(), f2.begin(), f2.end());

	f5.erase(f5.begin());

	f5.resize(3);
	f5.swap(f2);

	list<int>::iterator it = f5.begin();
	f5.splice(it,f2);
	f5.remove(100);
	f5.sort();
	f5.merge(f2);
	f5.reverse();

	f5.remove_if(Fun);//»Øµ÷º¯Êý

	f5.remove_if(CFun());
	system("pause");
}

bool Fun(int& v){
	return v == 1;
}