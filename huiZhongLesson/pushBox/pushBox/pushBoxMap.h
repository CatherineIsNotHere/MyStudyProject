#pragma once
#include "allSysInclude.h"
#include "pushBoxEnum.h"
#include "sysTools.h"

class pushBoxMap
{
public:
	pushBoxMap();
	~pushBoxMap();
	//void drawMap();
	int getIstage();
	int getInumber();
	void setIstage(int stage);
	void setInumber(int number);
	void clearMap();
	int m_imap[13][14];
private:
	int line = 13;
	int m_istage = 0;
	int m_inumber=0;
};

