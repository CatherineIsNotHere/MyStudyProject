#pragma once
#include <windows.h>
#include "configuration.hpp"
#include "g_cSprite.hpp"

class cObject{
private:
	CSprite o_spr;
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
	CSprite getSpr();
	void setNX(int x);
	void setNY(int y);
	void setOState(OBJSTATE os);
	void setSpr(CSprite spr);

};
