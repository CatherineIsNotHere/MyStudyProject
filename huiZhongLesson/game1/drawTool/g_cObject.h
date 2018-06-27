#pragma once
#include <windows.h>
#include "configuration.hpp"

class cObject{
private:
	//CMySprite m_spr;
	//CMyRect m_rc;
	int o_nX;//����x����
	int o_nY;//����y����
	OBJSTATE o_state;//״̬
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
