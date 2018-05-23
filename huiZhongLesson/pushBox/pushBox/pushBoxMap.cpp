#include "pushBoxMap.h"

pushBoxMap::pushBoxMap(){

};

pushBoxMap::~pushBoxMap(){
	/*for (int i = 0; i < line; i++)
		delete[] m_imap[i];
	delete[] m_imap;
	m_imap = nullptr;*/
};

int pushBoxMap::getIstage(){
	return m_istage;
};

int pushBoxMap::getInumber(){
	return m_inumber;
};

void pushBoxMap::setIstage(int stage){
	this->m_istage = stage;
};

void pushBoxMap::setInumber(int number){
	this->m_inumber = number;
};

void pushBoxMap::clearMap() {
	for (int i = 0; i < 14; i++)
	{
		for (int j = 0; j < 16; j++)
		{
			this->m_imap[i][j]=0;
		}
	}
	
}
