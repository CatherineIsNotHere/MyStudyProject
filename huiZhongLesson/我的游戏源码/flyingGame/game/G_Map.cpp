#pragma once
#include "hge.h"
#include "hgeanim.h"
#include "hgeSprite.h" 

class G_Map{
public:
	hgeSprite * m_spr;
	HTEXTURE m_tex;
	HGE * m_hge;
	G_Map(HGE* hge)
		:m_hge(hge)
	{
		m_tex = hge->Texture_Load("≤‚ ‘µÿÕº1.png");
		m_spr = new hgeSprite(m_tex,0,0,640,4096);
	}
	~G_Map(){
	
	}



};