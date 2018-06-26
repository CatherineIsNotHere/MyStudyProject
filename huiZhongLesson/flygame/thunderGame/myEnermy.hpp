#pragma once;
#include <windows.h>
#include "myObject.hpp"
#include <time.h>
#include <iostream>
using namespace std;

class CMyEnermy :public CMyObject{
public:
	CMyEnermy(){

	}
	~CMyEnermy(){

	}
	void Update(){
		m_nY += 5;
		srand((int)time(NULL));
		int x=rand() % 10*(rand()%3-1);
		m_nX += x;
	}
};