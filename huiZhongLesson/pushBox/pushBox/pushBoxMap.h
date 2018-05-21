#pragma once
#include "allSysInclude.h"
#include "pushBoxEnum.h"
#include "sysTools.h"

class pushBoxMap
{
public:
	pushBoxMap();
	~pushBoxMap();
	void drawMap();
	int getIstage();
	int getInumber();
	int** getImap();
	void setIstage(int stage);
	void setInumber(int number);
	void setImap(int** map);
private:
	int line = 13;
	int m_istage = 0;
	int** m_imap;
	int m_inumber=0;
};

