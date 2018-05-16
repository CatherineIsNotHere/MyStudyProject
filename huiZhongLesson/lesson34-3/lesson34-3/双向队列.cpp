#include <iostream>
#include<deque>

using namespace std;

void main(){
	deque<int> d1;
	deque<int> d2(3,10);
	deque<int> d3(d2);

	d2.empty();
	d2.size();
	cout << d2.front() << "," << d2.back() << endl;

	d2.push_back(1);
	d2.push_back(2);
	d2.push_front(3);
	d2.push_front(4);
	d2.pop_back();
	d2.pop_front();
}