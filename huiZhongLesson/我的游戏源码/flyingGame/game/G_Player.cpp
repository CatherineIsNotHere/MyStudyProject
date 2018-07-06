#pragma once
#include "hge.h"
#include "hgeanim.h"
#include "hgeSprite.h" 
enum actionState
{
	P_COMMON = 0,
	P_LEFT_0 = 1,
	P_LEFT_1 = 2,
	P_RIGHT_0 = 3,
	//P_RIGHT_1 = 4
};
class G_Player{
public:
	hgeAnimation* p_animat[5];
	HTEXTURE p_tex;
	int p_state = P_COMMON;
	HGE *p_hge;
	G_Player(HGE *hge)
		:p_hge(hge)
	{
		p_tex = p_hge->Texture_Load("·É»ú1ºÅ.png");
		p_animat[P_COMMON] = new hgeAnimation(p_tex, 20, 20, 0, 0, 100, 90);
		p_animat[P_COMMON]->SetFrames(5);
		p_animat[P_LEFT_0] = new hgeAnimation(p_tex, 20, 20, 0, 90, 100, 90);
		p_animat[P_LEFT_0]->SetFrames(5);
		p_animat[P_LEFT_1] = new hgeAnimation(p_tex, 20, 20, 0, 180, 100, 90);
		p_animat[P_LEFT_1]->SetFrames(5);
		//p_animat[P_RIGHT_0] = new hgeAnimation(p_tex, 20, 20, 0, 0, 100, 90);
		p_animat[P_COMMON]->SetBlendMode(BLEND_COLORMUL | BLEND_ALPHAADD | BLEND_NOZWRITE);
		p_animat[P_COMMON]->SetSpeed(10);
		p_animat[P_COMMON]->Play();
		p_animat[P_LEFT_0]->SetBlendMode(BLEND_COLORMUL | BLEND_ALPHAADD | BLEND_NOZWRITE);
		p_animat[P_LEFT_0]->SetSpeed(10);
		p_animat[P_LEFT_0]->Play();
		p_animat[P_LEFT_1]->SetBlendMode(BLEND_COLORMUL | BLEND_ALPHAADD | BLEND_NOZWRITE);
		p_animat[P_LEFT_1]->SetSpeed(10);
		p_animat[P_LEFT_1]->Play();
		/*p_animat[P_RIGHT_0]->SetBlendMode(BLEND_COLORMUL | BLEND_ALPHAADD | BLEND_NOZWRITE);
		p_animat[P_RIGHT_0]->SetSpeed(10);
		p_animat[P_RIGHT_0]->Play();*/
	};

	void PlayerFrame(){
		float dt = p_hge->Timer_GetDelta();
		if (p_hge->Input_GetKeyState(HGEK_LEFT)){
			if (p_state != P_LEFT_0)
				p_state = P_LEFT_0;
		}
		else if (p_hge->Input_GetKeyState(HGEK_RIGHT)){
			if (p_state != P_RIGHT_0){
				p_state = P_RIGHT_0;
			}
			else{
				//p_state = P_RIGHT_1;
				p_animat[p_state]->SetFrame(2);
			}
		}
		else{
			p_state = P_COMMON;
		}
		p_animat[p_state]->Update(dt); // ¸üĞÂ
	}
};