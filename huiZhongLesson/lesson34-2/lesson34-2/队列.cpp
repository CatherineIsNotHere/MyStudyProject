#include <iostream>
#include <queue>

using namespace std;

void main(){
	queue<int> q1;
	for (int i = 0; i < 5; i++)
	{
		q1.push(i);//Èë¶Ó
		cout << q1.back() << endl;
	}
	q1.empty();
	q1.size();
	while (!q1.empty())
	{
		cout << q1.front() << endl;
		q1.pop();
	}
	

}