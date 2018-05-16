#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <map>
#include <iostream>
#include <hash_map>
using namespace std;


class Monster{
public:
	Monster(int n, string name)
		:id(n)
		, hp(1000)
		, name(name)
	{

	}
	int id;
	int hp;
	string name;
};

struct xy{
	int x;
	int y;
};

void main(){
	
	map<int, Monster*> mapmonster;
	for (int m = 0; m < 10; m++)
	{
		//int index = rand() % 5;
		char s[32] = {};
		_itoa_s(m, s, sizeof(s));
		Monster* p = new Monster(m, string("m")+s);
		mapmonster[m] = p;
	}
	map<int, Monster*>::iterator it = mapmonster.begin();
	for (; it != mapmonster.end(); it++)
	{
		it->second->hp += 10;
		cout << it->second->hp << endl;
	}

	for (it = mapmonster.begin(); it != mapmonster.end(); it++)
	{
		Monster* pm = it->second;
		delete pm;
		pm = nullptr;
	}
	mapmonster.clear();
	system("pause");

	map<xy*, Monster*> map2m;
	xy* box1=new xy;
	box1->x = 1;
	box1->y = 2;
	Monster* p1 = new Monster(1, "monster1");
	map2m.insert(pair<xy*, Monster*>(box1, p1));

	xy* findbox = new xy;
	findbox->x = 1;
	findbox->y = 2;
	map<xy*, Monster*>::iterator itmon = map2m.find(findbox);//因为是指针所以找不到
	if (itmon!=map2m.end()){
		cout<<itmon->second->name<<endl;
	}


}