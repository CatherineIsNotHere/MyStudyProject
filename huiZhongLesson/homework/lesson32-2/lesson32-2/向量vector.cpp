#include <stdlib.h>
#include <stdio.h>
#include <vector>
using namespace std;

void main(){
	vector<int> vec1(5,1);//³õÊ¼»¯5¸ö1
	vector<int> vec2(vec1);
	vector<int> vec3(vec1.begin(),vec1.begin() + 3);

	size_t c = vec2.size();
	c = vec2.max_size();
	vec2.resize(10);
	vec2.capacity();
	bool b = vec2.empty();
	vec2.clear();
	vec2.assign(7,100);
	vec2.push_back(9);
	vec2.pop_back();
	int a[] = { 500, 501, 502 };
	vec2.insert(vec2.begin(), a, a + 3);

	for (vector<int>::iterator it = vec2.begin(); it!=vec2.end(); it++)
	{
		printf("%d",*it);
	}
	int n = vec2[1];
	n = vec2.at(1);
	n = vec2.front();
	n = vec2.back();
	
	int* p = vec2.data();


}