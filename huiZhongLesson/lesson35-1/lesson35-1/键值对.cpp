#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <iostream>
#include <map>

using namespace std;

void main(){
	map<int, string> _;
	_.insert(pair<int,string>(1,"zhangsan"));
	_.insert(pair<int, string>(100, "lisi"));
	_.insert(pair<int, string>(100, "lisi2"));//��ֵʧ�ܣ�key��ͬ
	_[100] = "lisi3";
	_[200] = "lisi3";
	_.size();
	for (map<int,string>::iterator it = _.begin(); it != _.end(); it++)
	{
		//cout << it->first << "," << it->second << endl;
	}

	map<int,string>::iterator it=_.find(150);//���ص��ǵ�����
	if (it!=_.end())
	{
		cout << it->first << "," << it->second << endl;
		_.erase(it);//����
	}
	else{
		cout << "û�ҵ�" << endl;
	}
	_.erase(100);
	_.clear();
	system("pause");
}