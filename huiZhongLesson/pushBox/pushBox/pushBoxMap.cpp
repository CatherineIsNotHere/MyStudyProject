#include "pushBoxMap.h"

pushBoxMap::pushBoxMap(){

};

pushBoxMap::~pushBoxMap(){
	for (int i = 0; i < line; i++)
		delete[] m_imap[i];
	delete[] m_imap;
	m_imap = nullptr;
};

int pushBoxMap::getIstage(){
	return m_istage;
};

int pushBoxMap::getInumber(){
	return m_inumber;
};

int** pushBoxMap::getImap(){
	return m_imap;
};

void pushBoxMap::setIstage(int stage){
	this->m_istage = stage;
};

void pushBoxMap::setInumber(int number){
	this->m_inumber = number;
};

void pushBoxMap::setImap(int** map){
	this->m_imap = map;
};

void pushBoxMap::drawMap(){
	
};