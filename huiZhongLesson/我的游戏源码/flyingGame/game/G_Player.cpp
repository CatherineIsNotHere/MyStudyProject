#pragma once
#include "hge.h"
#include "hgeanim.h"
#include "hgeSprite.h" 
enum actionState
{
	P_COMMON = 0,
	P_LEFT = 1,
	P_RIGHT = 2
};
class G_Player{
public:
	hgeAnimation* p_animat[3];
	HTEXTURE p_tex[3];
	int p_state = P_COMMON;
	HGE *p_hge;
	G_Player(HGE *hge)
		:p_hge(hge)
	{
		p_tex[P_COMMON] = p_hge->Texture_Load("·É»ú1ºÅ.png");
		p_tex[P_LEFT] = p_hge->Texture_Load("·É»ú1ºÅ×ó·­.png");
		p_tex[P_RIGHT] = p_hge->Texture_Load("·É»ú1ºÅÓÒ·­.png");
		p_animat[P_COMMON] = new hgeAnimation(p_tex[P_COMMON], 20, 20, 0, 0, 100, 90);
		p_animat[P_LEFT] = new hgeAnimation(p_tex[P_LEFT], 20, 20, 0, 0, 100, 90);
		p_animat[P_RIGHT] = new hgeAnimation(p_tex[P_RIGHT], 20, 20, 0, 0, 100, 90);
		p_animat[P_COMMON]->SetBlendMode(BLEND_COLORMUL | BLEND_ALPHAADD | BLEND_NOZWRITE);
		p_animat[P_COMMON]->SetSpeed(10);
		p_animat[P_COMMON]->Play();
		p_animat[P_LEFT]->SetBlendMode(BLEND_COLORMUL | BLEND_ALPHAADD | BLEND_NOZWRITE);
		p_animat[P_LEFT]->SetSpeed(10);
		p_animat[P_LEFT]->Play();
		p_animat[P_RIGHT]->SetBlendMode(BLEND_COLORMUL | BLEND_ALPHAADD | BLEND_NOZWRITE);
		p_animat[P_RIGHT]->SetSpeed(10);
		p_animat[P_RIGHT]->Play();
	};


};