#pragma once
#include <windows.h>
#include "configuration.hpp"

class cObject{
private:
	//CMySprite m_spr;
	//CMyRect m_rc;
	int o_nX;//所在x坐标
	int o_nY;//所在y坐标
	OBJSTATE o_state;//状态
public:
	cObject();
	~cObject();

	int getNX();
	int getNY();
	OBJSTATE getOState();
	void setNX(int x);
	void setNY(int y);
	void setOState(OBJSTATE os);

};
